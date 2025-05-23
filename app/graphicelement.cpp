// Copyright 2015 - 2025, GIBIS-UNIFESP and the wiRedPanda contributors
// SPDX-License-Identifier: GPL-3.0-or-later

#include "graphicelement.h"

#include "common.h"
#include "elementfactory.h"
#include "globalproperties.h"
#include "qneconnection.h"
#include "qneport.h"
#include "thememanager.h"

#include <QDir>
#include <QFileInfo>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QPainter>
#include <QPixmap>
#include <QStyleOptionGraphicsItem>
#include <cmath>

const int maximumValidInputSize = 256;

GraphicElement::GraphicElement(ElementType type, ElementGroup group, const QString &pixmapPath, const QString &titleText, const QString &translatedName, const int minInputSize, const int maxInputSize, const int minOutputSize, const int maxOutputSize, QGraphicsItem *parent)
    : QGraphicsObject(parent)
    , m_pixmapPath(pixmapPath)
    , m_titleText(titleText)
    , m_translatedName(translatedName)
    , m_elementGroup(group)
    , m_elementType(type)
    , m_maxInputSize(maxInputSize)
    , m_maxOutputSize(maxOutputSize)
    , m_minInputSize(minInputSize)
    , m_minOutputSize(minOutputSize)
{
    if (GlobalProperties::skipInit) {
        return;
    }

    qCDebug(four) << "Setting flags of elements.";
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges);

    qCDebug(four) << "Setting attributes.";
    m_label->hide();
    QFont font("SansSerif");
    font.setBold(true);
    m_label->setFont(font);
    m_label->setPos(0, 64);
    m_label->setParentItem(this);
    m_label->setDefaultTextColor(Qt::black);

    setPortName(m_translatedName);
    setToolTip(m_translatedName);

    qCDebug(four) << "Including input and output ports.";
    setInputSize(minInputSize);
    setOutputSize(minOutputSize);

    GraphicElement::updatePortsProperties();
    GraphicElement::updateTheme();

    setCacheMode(QGraphicsItem::DeviceCoordinateCache);
}

ElementType GraphicElement::elementType() const
{
    return m_elementType;
}

ElementGroup GraphicElement::elementGroup() const
{
    return m_elementGroup;
}

QPixmap GraphicElement::pixmap() const
{
    return m_pixmap;
}

void GraphicElement::setPixmap(const int index)
{
    setPixmap(m_usingDefaultSkin ? m_defaultSkins.at(index) : m_alternativeSkins.at(index));
}

void GraphicElement::setPixmap(const QString &pixmapPath)
{
    if (pixmapPath.isEmpty() || (pixmapPath == m_currentPixmapPath)) {
        return;
    }

    QString path = pixmapPath;

    if (not path.startsWith(":/")) {
        path.prepend(GlobalProperties::currentDir + "/");
    }

    if (!m_pixmap.load(path)) {
        const QFileInfo info(path);
        const QString reason = !info.exists()
                                   ? tr("File does not exist")
                                   : !info.isReadable()
                                         ? tr("File is not readable")
                                         : tr("Unknown reason");

        m_pixmap.load(m_defaultSkins.constFirst());
        qCDebug(zero) << "Problem loading pixmapPath: " << path;
        throw Pandaception(tr("Couldn't load pixmap: %1 (%2)").arg(path, reason));
    }

    setTransformOriginPoint(pixmapCenter());
    update();

    m_currentPixmapPath = pixmapPath;
}

const QVector<QNEOutputPort *> &GraphicElement::outputs() const
{
    return m_outputPorts;
}

void GraphicElement::setOutputs(const QVector<QNEOutputPort *> &outputs)
{
    m_outputPorts = outputs;
}

QNEInputPort *GraphicElement::inputPort(const int index)
{
    return m_inputPorts.at(index);
}

QNEOutputPort *GraphicElement::outputPort(const int index)
{
    return m_outputPorts.at(index);
}

void GraphicElement::save(QDataStream &stream) const
{
    qCDebug(four) << "Saving element. Type: " << objectName();

    QMap<QString, QVariant> map;
    map.insert("pos", pos());
    map.insert("rotation", rotation());
    map.insert("label", label());
    map.insert("minInputSize", m_minInputSize);
    map.insert("maxInputSize", m_maxInputSize);
    map.insert("minOutputSize", m_minOutputSize);
    map.insert("maxOutputSize", m_maxOutputSize);
    map.insert("trigger", m_trigger);
    map.insert("priority", m_priority);

    stream << map;

    // -------------------------------------------

    QList<QMap<QString, QVariant>> inputMap;

    for (auto *port : m_inputPorts) {
        QMap<QString, QVariant> tempMap;
        tempMap.insert("ptr", reinterpret_cast<quint64>(port));
        tempMap.insert("name", port->name());
        tempMap.insert("flags", port->portFlags());

        inputMap << tempMap;
    }

    stream << inputMap;

    // -------------------------------------------

    QList<QMap<QString, QVariant>> outputMap;

    for (auto *port : m_outputPorts) {
        QMap<QString, QVariant> tempMap;
        tempMap.insert("ptr", reinterpret_cast<quint64>(port));
        tempMap.insert("name", port->name());
        tempMap.insert("flags", port->portFlags());

        outputMap << tempMap;
    }

    stream << outputMap;

    // -------------------------------------------

    QList<QMap<QString, QVariant>> skinsMap;

    for (const auto &skinName : m_alternativeSkins) {
        QFileInfo fileInfo(skinName);
        QString skinName2 = skinName;

        if (!skinName.startsWith(":/") && (fileInfo.absoluteDir() != GlobalProperties::currentDir)) {
            const QString newFile = GlobalProperties::currentDir + "/" + fileInfo.fileName();
            QFile::copy(skinName, newFile);
            skinName2 = fileInfo.fileName();
        }

        // -------------------------------------------

        QMap<QString, QVariant> tempMap;
        tempMap.insert("skinName", skinName2);

        skinsMap << tempMap;
    }

    stream << skinsMap;

    // -------------------------------------------

    qCDebug(four) << "Finished saving element.";
}

void GraphicElement::load(QDataStream &stream, QMap<quint64, QNEPort *> &portMap, const QVersionNumber version)
{
    qCDebug(four) << "Loading element. Type: " << objectName();

    (version < VERSION("4.1")) ? loadOldFormat(stream, portMap, version) : loadNewFormat(stream, portMap);

    qCDebug(four) << "Updating port positions.";
    updatePortsProperties();
    setRotation(m_angle);

    qCDebug(four) << "Finished loading element.";
}

void GraphicElement::loadOldFormat(QDataStream &stream, QMap<quint64, QNEPort *> &portMap, const QVersionNumber version)
{
    loadPos(stream);
    loadRotation(stream, version);
    /* <Version1.2> */
    loadLabel(stream, version);
    /* <\Version1.2> */
    /* <Version1.3> */
    loadPortsSize(stream, version);
    /* <\Version1.3> */
    /* <Version1.9> */
    loadTrigger(stream, version);
    /* <\Version4.01> */
    loadPriority(stream, version);
    /* <\Version1.9> */
    loadInputPorts(stream, portMap);
    loadOutputPorts(stream, portMap);
    /* <\Version2.7> */
    loadPixmapSkinNames(stream, version);
}

void GraphicElement::loadNewFormat(QDataStream &stream, QMap<quint64, QNEPort *> &portMap)
{
    QMap<QString, QVariant> map; stream >> map;

    if (map.contains("pos")) {
        setPos(map.value("pos").toPointF());
    }

    if (map.contains("rotation")) {
        m_angle = map.value("rotation").toReal();
    }

    if (map.contains("label")) {
        setLabel(map.value("label").toString());
    }

    // -------------------------------------------

    const quint64 minInputSize = map.value("minInputSize").toULongLong();
    const quint64 maxInputSize = map.value("maxInputSize").toULongLong();
    const quint64 minOutputSize = map.value("minOutputSize").toULongLong();
    const quint64 maxOutputSize = map.value("maxOutputSize").toULongLong();

    if ((m_minInputSize != m_maxInputSize) || (m_minInputSize <= maxInputSize)) {
        m_minInputSize = minInputSize;
        m_maxInputSize = maxInputSize;
    }

    if ((m_minOutputSize != m_maxOutputSize) || (m_minOutputSize <= maxOutputSize)) {
        m_minOutputSize = minOutputSize;
        m_maxOutputSize = maxOutputSize;
    }

    // -------------------------------------------

    if (map.contains("trigger")) {
        setTrigger(map.value("trigger").toString());
    }

    if (map.contains("priority")) {
        setPriority(map.value("priority").toULongLong());
    }

    // -------------------------------------------

    QList<QMap<QString, QVariant>> inputMap; stream >> inputMap;
    int port = 0;

    for (const auto &input : std::as_const(inputMap)) {
        const quint64 ptr = input.value("ptr").toULongLong();
        const QString name = input.value("name").toString();

        if (port < m_inputPorts.size()) {
            m_inputPorts.value(port)->setPtr(ptr);

            if (elementType() == ElementType::IC) {
                m_inputPorts.value(port)->setName(name);
            }
        } else {
            addPort(name, false, static_cast<int>(ptr));
        }

        portMap[ptr] = m_inputPorts.value(port);

        ++port;
    }

    removeSurplusInputs(inputMap.size(), portMap);

    // -------------------------------------------

    QList<QMap<QString, QVariant>> outputMap; stream >> outputMap;
    port = 0;

    for (const auto &output : std::as_const(outputMap)) {
        const quint64 ptr = output.value("ptr").toULongLong();
        const QString name = output.value("name").toString();

        if (port < m_outputPorts.size()) {
            m_outputPorts.value(port)->setPtr(ptr);

            if (elementType() == ElementType::IC) {
                m_outputPorts.value(port)->setName(name);
            }
        } else {
            addPort(name, true, static_cast<int>(ptr));
        }

        portMap[ptr] = m_outputPorts.value(port);

        ++port;
    }

    removeSurplusOutputs(outputMap.size(), portMap);

    // -------------------------------------------

    QList<QMap<QString, QVariant>> skinsMap; stream >> skinsMap;
    int skin = 0;

    for (const auto &skinName : std::as_const(skinsMap)) {
        const QString name = skinName.value("skinName").toString();

        if (!name.startsWith(":/")) {
            m_alternativeSkins[skin] = name;
        }

        ++skin;
    }

    m_usingDefaultSkin = std::equal(
        m_defaultSkins.begin(), m_defaultSkins.end(),
        m_alternativeSkins.begin(), m_alternativeSkins.end()
        );

    refresh();
}

void GraphicElement::loadPos(QDataStream &stream)
{
    QPointF pos; stream >> pos;
    setPos(pos);
}

void GraphicElement::loadRotation(QDataStream &stream, const QVersionNumber version)
{
    qreal angle; stream >> angle;
    m_angle = angle;

    if (version < VERSION("4.1")) {
        if ((m_elementGroup == ElementGroup::Input) || (m_elementGroup == ElementGroup::StaticInput)) {
            m_angle += 90;
        }

        if ((m_elementGroup == ElementGroup::Output) || (m_elementGroup == ElementGroup::IC) || (m_elementGroup == ElementGroup::Gate)) {
            if ((m_elementType == ElementType::Display7) || (m_elementType == ElementType::Display14) || (m_elementType == ElementType::Display16) || (m_elementType == ElementType::Node)) {
                return;
            }

            m_angle -= 90;
        }
    }
}

void GraphicElement::loadLabel(QDataStream &stream, const QVersionNumber version)
{
    if (version >= VERSION("1.2")) {
        QString labelText; stream >> labelText;
        setLabel(labelText);
    }
}

void GraphicElement::loadPortsSize(QDataStream &stream, const QVersionNumber version)
{
    if (version >= VERSION("1.3")) {
        quint64 minInputSize;  stream >> minInputSize;
        quint64 maxInputSize;  stream >> maxInputSize;
        quint64 minOutputSize; stream >> minOutputSize;
        quint64 maxOutputSize; stream >> maxOutputSize;

        if ((m_minInputSize != m_maxInputSize) || (m_minInputSize <= maxInputSize)) {
            m_minInputSize = minInputSize;
            m_maxInputSize = maxInputSize;
        }

        if ((m_minOutputSize != m_maxOutputSize) || (m_minOutputSize <= maxOutputSize)) {
            m_minOutputSize = minOutputSize;
            m_maxOutputSize = maxOutputSize;
        }
    }
}

void GraphicElement::loadTrigger(QDataStream &stream, const QVersionNumber version)
{
    if (version >= VERSION("1.9")) {
        QKeySequence trigger; stream >> trigger;
        setTrigger(trigger);
    }
}

void GraphicElement::loadPriority(QDataStream &stream, const QVersionNumber version)
{
    if (version >= VERSION("4.01")) {
        quint64 priority; stream >> priority;
        setPriority(priority);
    }
}

void GraphicElement::loadInputPorts(QDataStream &stream, QMap<quint64, QNEPort *> &portMap)
{
    qCDebug(four) << "Loading input ports.";
    quint64 inputSize; stream >> inputSize;

    if (inputSize > maximumValidInputSize) {
        throw Pandaception(tr("Corrupted DataStream!"));
    }

    for (size_t port = 0; port < inputSize; ++port) {
        loadInputPort(stream, portMap, static_cast<int>(port));
    }

    removeSurplusInputs(inputSize, portMap);
}

void GraphicElement::loadInputPort(QDataStream &stream, QMap<quint64, QNEPort *> &portMap, const int port)
{
    quint64 ptr;  stream >> ptr;
    QString name; stream >> name;
    int flags;    stream >> flags;

    if (port < m_inputPorts.size()) {
        m_inputPorts.value(port)->setPtr(ptr);

        if (elementType() == ElementType::IC) {
            m_inputPorts.value(port)->setName(name);
        }
    } else {
        addPort(name, false, static_cast<int>(ptr));
    }

    portMap[ptr] = m_inputPorts.value(port);
}

void GraphicElement::removeSurplusInputs(const quint64 inputSize_, QMap<quint64, QNEPort *> &portMap)
{
    while ((inputSize() > static_cast<int>(inputSize_)) && (inputSize_ >= m_minInputSize)) {
        auto *deletedPort = m_inputPorts.constLast();
        removePortFromMap(deletedPort, portMap);
        delete deletedPort;
        m_inputPorts.removeLast();
    }
}

void GraphicElement::removeSurplusOutputs(const quint64 outputSize_, QMap<quint64, QNEPort *> &portMap)
{
    while ((outputSize() > static_cast<int>(outputSize_)) && (outputSize_ >= m_minOutputSize)) {
        auto *deletedPort = m_outputPorts.constLast();
        removePortFromMap(deletedPort, portMap);
        delete deletedPort;
        m_outputPorts.removeLast();
    }
}

void GraphicElement::setLogic(LogicElement *newLogic)
{
    m_logic = newLogic;
}

LogicElement *GraphicElement::logic() const
{
    return m_logic;
}

void GraphicElement::removePortFromMap(QNEPort *deletedPort, QMap<quint64, QNEPort *> &portMap)
{
    for (auto it = portMap.begin(); it != portMap.end();) {
        if (it.value() == deletedPort) {
            it = portMap.erase(it);
        } else {
            ++it;
        }
    }
}

void GraphicElement::loadOutputPorts(QDataStream &stream, QMap<quint64, QNEPort *> &portMap)
{
    qCDebug(four) << "Loading output ports.";
    quint64 outputSize; stream >> outputSize;

    if (outputSize > maximumValidInputSize) {
        throw Pandaception(tr("Corrupted DataStream!"));
    }

    for (size_t port = 0; port < outputSize; ++port) {
        loadOutputPort(stream, portMap, static_cast<int>(port));
    }

    removeSurplusOutputs(outputSize, portMap);
}

void GraphicElement::loadOutputPort(QDataStream &stream, QMap<quint64, QNEPort *> &portMap, const int port)
{
    quint64 ptr;  stream >> ptr;
    QString name; stream >> name;
    int flags;    stream >> flags;

    if (port < m_outputPorts.size()) {
        m_outputPorts.value(port)->setPtr(ptr);

        if (elementType() == ElementType::IC) {
            m_outputPorts.value(port)->setName(name);
        }
    } else {
        addPort(name, true, static_cast<int>(ptr));
    }

    portMap[ptr] = m_outputPorts.value(port);
}

void GraphicElement::loadPixmapSkinNames(QDataStream &stream, const QVersionNumber version)
{
    if (version >= VERSION("2.7")) {
        qCDebug(four) << tr("Loading pixmap skin names.");
        quint64 outputSize; stream >> outputSize;

        if (outputSize > maximumValidInputSize) {
            throw Pandaception(tr("Corrupted DataStream!"));
        }

        for (size_t skin = 0; skin < outputSize; ++skin) {
            loadPixmapSkinName(stream, static_cast<int>(skin));
        }

        m_usingDefaultSkin = std::equal(
            m_defaultSkins.begin(), m_defaultSkins.end(),
            m_alternativeSkins.begin(), m_alternativeSkins.end()
            );

        refresh();
    }
}

void GraphicElement::loadPixmapSkinName(QDataStream &stream, const int skin)
{
    QString name; stream >> name;

    if (skin >= m_alternativeSkins.size()) {
        qCDebug(zero) << "Could not load some of the skins.";
    }

    if (!name.startsWith(":/")) {
        m_alternativeSkins[skin] = name;
    }
}

const QVector<QNEInputPort *> &GraphicElement::inputs() const
{
    return m_inputPorts;
}

void GraphicElement::setInputs(const QVector<QNEInputPort *> &inputs)
{
    m_inputPorts = inputs;
}

QPointF GraphicElement::pixmapCenter() const
{
    return QRectF(pixmap().rect()).center();
}

QRectF GraphicElement::boundingRect() const
{
    return portsBoundingRect().united(pixmap().rect());
}

QRectF GraphicElement::portsBoundingRect() const
{
    QRectF rectChildren;
    const auto children = childItems();

    for (auto *child : children) {
        if (auto *port = qgraphicsitem_cast<QNEPort *>(child)) {
            rectChildren = rectChildren.united(mapRectFromItem(port, port->boundingRect()));
        }
    }

    return rectChildren;
}

void GraphicElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget)
    Q_UNUSED(option)

    if (isSelected()) {
        painter->save();
        painter->setBrush(m_selectionBrush);
        painter->setPen(QPen(m_selectionPen, 0.5, Qt::SolidLine));
        painter->drawRoundedRect(boundingRect(), 5, 5);
        painter->restore();
    }

    painter->drawPixmap(QPoint(0, 0), pixmap());
}

void GraphicElement::addPort(const QString &name, const bool isOutput, const int ptr)
{
    if (isOutput && (static_cast<quint64>(m_outputPorts.size()) >= m_maxOutputSize)) {
        return;
    }

    if (!isOutput && (static_cast<quint64>(m_inputPorts.size()) >= m_maxInputSize)) {
        return;
    }

    qCDebug(four) << "New port.";
    QNEPort *port = nullptr;

    if (isOutput) {
        m_outputPorts.push_back(new QNEOutputPort(this));
        port = m_outputPorts.constLast();
        port->setIndex(outputSize() - 1);
    } else {
        m_inputPorts.push_back(new QNEInputPort(this));
        port = m_inputPorts.constLast();
        port->setIndex(inputSize() - 1);
    }

    port->setGraphicElement(this);
    port->setPtr(ptr);
    port->setName(name);
    port->show();
}

void GraphicElement::addInputPort(const QString &name)
{
    addPort(name, false);
}

void GraphicElement::addOutputPort(const QString &name)
{
    addPort(name, true);
}

void GraphicElement::setPortName(const QString &name)
{
    setObjectName(name);
}

void GraphicElement::setPriority(const int value)
{
    m_priority = value;
}

void GraphicElement::setRotation(const qreal angle)
{
    m_angle = std::fmod(angle, 360);
    isRotatable() ? QGraphicsItem::setRotation(m_angle) : rotatePorts(m_angle);
}

void GraphicElement::rotatePorts(const qreal angle)
{
    for (auto *port : std::as_const(m_inputPorts)) {
        port->setTransformOriginPoint(mapToItem(port, pixmapCenter()));
        port->setRotation(angle);
        port->updateConnections();
    }

    for (auto *port : std::as_const(m_outputPorts)) {
        port->setTransformOriginPoint(mapToItem(port, pixmapCenter()));
        port->setRotation(angle);
        port->updateConnections();
    }
}

qreal GraphicElement::rotation() const
{
    return m_angle;
}

void GraphicElement::setSkin(const bool defaultSkin, const QString &fileName)
{
    if (defaultSkin) {
        m_alternativeSkins = m_defaultSkins;
    } else {
        m_alternativeSkins[0] = fileName;
    }

    m_usingDefaultSkin = defaultSkin;
    setPixmap(0);
}

void GraphicElement::updatePortsProperties()
{
    qCDebug(five) << "Updating port positions that belong to the IC.";

    const int step = GlobalProperties::gridSize / 2;

    if (!m_inputPorts.isEmpty()) {
        int y = 32 - (m_inputPorts.size() * step) + step;

        for (auto *port : std::as_const(m_inputPorts)) {
            qCDebug(five) << "Setting input at " << 0 << ", " << y;

            if (!isRotatable()) {
                port->setRotation(0);
            }

            port->setPos(0, y);

            if (!isRotatable()) {
                port->setTransformOriginPoint(mapToItem(port, pixmapCenter()));
                port->setRotation(m_angle);
            }

            y += step * 2;
        }
    }

    if (!m_outputPorts.isEmpty()) {
        int y = 32 - (m_outputPorts.size() * step) + step;

        for (auto *port : std::as_const(m_outputPorts)) {
            qCDebug(five) << "Setting output at " << 64 << ", " << y;

            if (!isRotatable()) {
                port->setRotation(0);
            }

            port->setPos(64, y);

            if (!isRotatable()) {
                port->setTransformOriginPoint(mapToItem(port, pixmapCenter()));
                port->setRotation(m_angle);
            }

            y += step * 2;
        }
    }
}

void GraphicElement::refresh()
{
    setPixmap(0);
}

QVariant GraphicElement::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (!scene()) {
        return QGraphicsItem::itemChange(change, value);
    }

    if (change == ItemPositionChange) {
        qCDebug(four) << "Align to grid.";
        QPointF newPos = value.toPointF();
        const int gridSize = GlobalProperties::gridSize / 2;
        const int xV = qRound(newPos.x() / gridSize) * gridSize;
        const int yV = qRound(newPos.y() / gridSize) * gridSize;
        return QPoint(xV, yV);
    }

    if ((change == ItemScenePositionHasChanged) || (change == ItemRotationHasChanged) || (change == ItemTransformHasChanged)) {
        qCDebug(four) << "Moves wires.";
        for (auto *port : std::as_const(m_outputPorts)) {
            port->updateConnections();
        }

        for (auto *port : std::as_const(m_inputPorts)) {
            port->updateConnections();
        }
    }

    if (change == ItemSelectedHasChanged) {
        m_selected = value.toBool();
        highlight(m_selected);
    }

    return QGraphicsItem::itemChange(change, value);
}

bool GraphicElement::sceneEvent(QEvent *event)
{
    if (event->type() == QEvent::GraphicsSceneMousePress || event->type() == QEvent::GraphicsSceneMouseRelease) {
        if (auto mouseEvent = dynamic_cast<QGraphicsSceneMouseEvent *>(event)) {
            if (mouseEvent->modifiers().testFlag(Qt::ControlModifier)) {
                return true;
            }
        }
    }

    return QGraphicsItem::sceneEvent(event);
}

bool GraphicElement::hasAudio() const
{
    return m_hasAudio;
}

void GraphicElement::setHasAudio(const bool hasAudio)
{
    m_hasAudio = hasAudio;
}

QKeySequence GraphicElement::trigger() const
{
    return m_trigger;
}

void GraphicElement::setTrigger(const QKeySequence &trigger)
{
    m_trigger = trigger;
    updateLabel();
}

QString GraphicElement::genericProperties()
{
    return {};
}

void GraphicElement::updateLabel()
{
    QString label = m_labelText;

    if (!hasTrigger() || trigger().toString().isEmpty()) {
        m_label->setPlainText(label);
    } else {
        if (!label.isEmpty()) {
            label += " ";
        }

        m_label->setPlainText(label + QString("(%1)").arg(trigger().toString()));
    }
}

void GraphicElement::setLabel(const QString &label)
{
    m_labelText = label;
    updateLabel();
}

QString GraphicElement::label() const
{
    return m_labelText;
}

QString GraphicElement::previousColor() const
{
    if (color() == "White") return "Purple";
    if (color() == "Red") return "White";
    if (color() == "Green") return "Red";
    if (color() == "Blue") return "Green";
    if (color() == "Purple") return "Blue";
    return "White"; // Standard
}

QString GraphicElement::nextColor() const
{
    if (color() == "White") return "Red";
    if (color() == "Red") return "Green";
    if (color() == "Green") return "Blue";
    if (color() == "Blue") return "Purple";
    if (color() == "Purple") return "White";
    return "White"; // Standard
}

QString GraphicElement::previousAudio() const
{
    if (audio() == "C6") return "C7";
    if (audio() == "D6") return "C6";
    if (audio() == "E6") return "D6";
    if (audio() == "F6") return "E6";
    if (audio() == "G6") return "F6";
    if (audio() == "A7") return "G6";
    if (audio() == "B7") return "A7";
    if (audio() == "C7") return "B7";
    return "C6";
}

QString GraphicElement::nextAudio() const
{
    if (audio() == "C6") return "D6";
    if (audio() == "D6") return "E6";
    if (audio() == "E6") return "F6";
    if (audio() == "F6") return "G6";
    if (audio() == "G6") return "A7";
    if (audio() == "A7") return "B7";
    if (audio() == "B7") return "C7";
    if (audio() == "C7") return "C6";
    return "C6";
}

void GraphicElement::updateTheme()
{
    const ThemeAttributes theme = ThemeManager::attributes();

    m_label->setDefaultTextColor(theme.m_graphicElementLabelColor);
    m_selectionBrush = theme.m_selectionBrush;
    m_selectionPen = theme.m_selectionPen;

    for (auto *input : std::as_const(m_inputPorts)) {
        input->updateTheme();
    }

    for (auto *output : std::as_const(m_outputPorts)) {
        output->updateTheme();
    }

    update();
}

bool GraphicElement::isValid()
{
    qCDebug(four) << "Checking if the element has the required signals to compute its value.";
    const bool valid = std::all_of(m_inputPorts.cbegin(), m_inputPorts.cend(),
                                   [](auto *input) { return input->isValid(); });

    if (!valid) {
        for (auto *output : std::as_const(m_outputPorts)) {
            for (auto *conn : output->connections()) {
                conn->setStatus(Status::Invalid);

                if (auto *port = conn->otherPort(output)) {
                    port->setStatus(Status::Invalid);
                }
            }
        }
    }

    return valid;
}

bool GraphicElement::hasColors() const
{
    return m_hasColors;
}

bool GraphicElement::hasTrigger() const
{
    return m_hasTrigger;
}

void GraphicElement::setColor(const QString &color)
{
    Q_UNUSED(color)
}

QString GraphicElement::color() const
{
    return {};
}

void GraphicElement::setAudio(const QString &audio)
{
    Q_UNUSED(audio)
}

QString GraphicElement::audio() const
{
    return {};
}

void GraphicElement::setHasColors(const bool hasColors)
{
    m_hasColors = hasColors;
}

void GraphicElement::setCanChangeSkin(const bool canChangeSkin)
{
    m_canChangeSkin = canChangeSkin;
}

void GraphicElement::setHasTrigger(const bool hasTrigger)
{
    m_hasTrigger = hasTrigger;
}

bool GraphicElement::hasFrequency() const
{
    return m_hasFrequency;
}

void GraphicElement::setHasFrequency(const bool hasFrequency)
{
    m_hasFrequency = hasFrequency;
}

bool GraphicElement::hasDelay() const
{
    return m_hasDelay;
}

void GraphicElement::setHasDelay(const bool hasDelay)
{
    m_hasDelay = hasDelay;
}

bool GraphicElement::hasLabel() const
{
    return m_hasLabel;
}

bool GraphicElement::hasTruthTable() const
{
    return m_hasTruthTable;
}

void GraphicElement::setHasTruthTable(const bool hasTruthTable)
{
    m_hasTruthTable = hasTruthTable;
}

void GraphicElement::setHasAudioBox(const bool hasAudioBox)
{
    m_hasAudioBox = hasAudioBox;
}

bool GraphicElement::hasAudioBox() const
{
    return m_hasAudioBox;
}

bool GraphicElement::canChangeSkin() const
{
    return m_canChangeSkin;
}

void GraphicElement::setHasLabel(const bool hasLabel)
{
    m_hasLabel = hasLabel;
    m_label->setVisible(hasLabel);
}

bool GraphicElement::isRotatable() const
{
    return m_rotatable;
}

void GraphicElement::setRotatable(const bool rotatable)
{
    m_rotatable = rotatable;
}

int GraphicElement::minOutputSize() const
{
    return static_cast<int>(m_minOutputSize);
}

int GraphicElement::inputSize() const
{
    return m_inputPorts.size();
}

void GraphicElement::setInputSize(const int size)
{
    if ((size >= minInputSize()) && (size <= maxInputSize())) {
        if (size > inputSize()) {
            while (size > inputSize()) {
                addInputPort();
            }
        } else {
            qDeleteAll(m_inputPorts.begin() + size, m_inputPorts.end());
            m_inputPorts.resize(size);
        }

        updatePortsProperties();
    }
}

int GraphicElement::outputSize() const
{
    return m_outputPorts.size();
}

int GraphicElement::priority() const
{
    return m_priority;
}

void GraphicElement::setOutputSize(const int size)
{
    if ((size >= minOutputSize()) && (size <= maxOutputSize())) {
        if (size > outputSize()) {
            while (size > outputSize()) {
                addOutputPort();
            }
        } else {
            qDeleteAll(m_outputPorts.begin() + size, m_outputPorts.end());
            m_outputPorts.resize(size);
        }

        updatePortsProperties();
    }
}

float GraphicElement::frequency() const
{
    return 0.0;
}

void GraphicElement::setFrequency(const float freq)
{
    Q_UNUSED(freq)
}

float GraphicElement::delay() const
{
    return 0.0;
}

void GraphicElement::setDelay(const float delay)
{
    Q_UNUSED(delay)
}

void GraphicElement::setMinOutputSize(const int minOutputSize)
{
    m_minOutputSize = minOutputSize;
}

int GraphicElement::minInputSize() const
{
    return static_cast<int>(m_minInputSize);
}

void GraphicElement::setMinInputSize(const int minInputSize)
{
    m_minInputSize = minInputSize;
}

int GraphicElement::maxOutputSize() const
{
    return static_cast<int>(m_maxOutputSize);
}

void GraphicElement::setMaxOutputSize(const int maxOutputSize)
{
    m_maxOutputSize = maxOutputSize;
}

int GraphicElement::maxInputSize() const
{
    return static_cast<int>(m_maxInputSize);
}

void GraphicElement::setMaxInputSize(const int maxInputSize)
{
    m_maxInputSize = maxInputSize;
}

void GraphicElement::highlight(const bool isSelected)
{
    QVector<QNEPort *> ports;

    for (auto *port : std::as_const(m_inputPorts)) {
        ports << port;
    }

    for (auto *port : std::as_const(m_outputPorts)) {
        ports << port;
    }

    for (auto *port : std::as_const(ports)) {
        for (auto *connection : port->connections()) {
            if (connection->highLight() == isSelected) {
                continue;
            }

            connection->setHighLight(isSelected);
        }
    }
}

void GraphicElement::retranslate()
{
    m_translatedName = ElementFactory::translatedName(m_elementType);

    setPortName(m_translatedName);
    setToolTip(m_translatedName);
}

QDataStream &operator<<(QDataStream &stream, const GraphicElement *item)
{
    qCDebug(four) << "Writing element.";
    const auto *elm = qgraphicsitem_cast<const GraphicElement *>(item);
    stream << GraphicElement::Type;
    stream << elm->elementType();
    elm->save(stream);
    return stream;
}
