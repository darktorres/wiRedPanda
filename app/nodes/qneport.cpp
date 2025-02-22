/* Copyright (c) 2012, STANISLAW ADASZEWSKI
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * Neither the name of STANISLAW ADASZEWSKI nor the
 *    names of its contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL STANISLAW ADASZEWSKI BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */

#include "enums.h"
#include "graphicelement.h"
#include "qneconnection.h"
#include "qneport.h"
#include "thememanager.h"

#include <QCursor>
#include <QDebug>
#include <QFontMetrics>
#include <QGraphicsScene>
#include <QPen>

QNEPort::QNEPort(QGraphicsItem *parent)
    : QGraphicsPathItem(parent)
{
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
    setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    QPainterPath path;

    path.addPolygon(QRectF(QPointF(-m_radius, -m_radius), QPointF(m_radius, m_radius)));
    setPath(path);
}

LogicElement *QNEPort::logic() const
{
    return graphicElement() ? graphicElement()->logic() : nullptr;
}

const QList<QNEConnection *> &QNEPort::connections() const
{
    return m_connections;
}

void QNEPort::connect(QNEConnection *conn)
{
    if (!conn) {
        return;
    }

    if (!m_connections.contains(conn)) {
        m_connections.append(conn);
    }

    updateConnections();
}

void QNEPort::disconnect(QNEConnection *conn)
{
    m_connections.removeAll(conn);

    if (conn->startPort() == this) {
        conn->setStartPort(nullptr);
    }

    if (conn->endPort() == this) {
        conn->setEndPort(nullptr);
    }

    updateConnections();
}

int QNEPort::portFlags() const
{
    return m_portFlags;
}

void QNEPort::setPtr(const quint64 ptr)
{
    m_ptr = ptr;
}

bool QNEPort::isConnected(QNEPort *otherPort)
{
    return std::any_of(m_connections.cbegin(), m_connections.cend(),
                       [&](auto *conn) { return (conn->startPort() == otherPort) || (conn->endPort() == otherPort); });
}

void QNEPort::updateConnections()
{
    for (auto *conn : std::as_const(m_connections)) {
        conn->updatePosFromPorts();
    }

    if (!isValid()) {
        setStatus(Status::Invalid);
        return;
    }

    if (m_connections.empty() && isInput()) {
        setStatus(defaultValue());
    }
}

QVariant QNEPort::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemScenePositionHasChanged) {
        updateConnections();
    }

    return QGraphicsPathItem::itemChange(change, value);
}

int QNEPort::index() const
{
    return m_index;
}

void QNEPort::setIndex(const int index)
{
    m_index = index;
}

QString QNEPort::name() const
{
    return m_name;
}

void QNEPort::setName(const QString &name)
{
    m_name = name;
    setToolTip(name);
}

Status QNEPort::defaultValue() const
{
    return m_defaultStatus;
}

void QNEPort::setDefaultStatus(const Status defaultStatus)
{
    m_defaultStatus = defaultStatus;
    setStatus(defaultStatus);
}

QBrush QNEPort::currentBrush() const
{
    return m_currentBrush;
}

void QNEPort::setCurrentBrush(const QBrush &currentBrush)
{
    m_currentBrush = currentBrush;

    if (brush().color() != Qt::yellow) {
        setBrush(currentBrush);
    }
}

bool QNEPort::isRequired() const
{
    return m_required;
}

void QNEPort::setRequired(const bool required)
{
    m_required = required;
    setDefaultStatus(required ? Status::Invalid : Status::Inactive);
}

Status QNEPort::status() const
{
    return m_status;
}

GraphicElement *QNEPort::graphicElement() const
{
    return m_graphicElement;
}

void QNEPort::setGraphicElement(GraphicElement *graphicElement)
{
    m_graphicElement = graphicElement;
}

void QNEPort::hoverLeave()
{
    setBrush(currentBrush());
}

void QNEPort::hoverEnter()
{
    setBrush(QBrush(ThemeManager::attributes().m_portHoverPort));
}

QNEInputPort::QNEInputPort(QGraphicsItem *parent)
    : QNEPort(parent)
{
    m_label->setPos(-m_radius - m_margin - m_label->boundingRect().width(),
                    -m_label->boundingRect().height() / 2);

    QNEInputPort::setStatus(defaultValue());
}

QNEInputPort::~QNEInputPort()
{
    while (!m_connections.isEmpty()) {
        auto *conn = m_connections.constLast();
        m_connections.removeAll(conn);
        conn->setEndPort(nullptr);
        delete conn;
    }
}

void QNEInputPort::setStatus(const Status status)
{
    if (status == m_status) {
        return;
    }

    m_status = QNEInputPort::isValid() ? status : Status::Invalid;

    const auto theme = ThemeManager::attributes();

    switch (m_status) {
    case Status::Invalid: {
        setPen(theme.m_portInvalidPen);
        setCurrentBrush(theme.m_portInvalidBrush);
        break;
    }
    case Status::Inactive: {
        setPen(theme.m_portInactivePen);
        setCurrentBrush(theme.m_portInactiveBrush);
        break;
    }
    case Status::Active: {
        setPen(theme.m_portActivePen);
        setCurrentBrush(theme.m_portActiveBrush);
        break;
    }
    }
}

bool QNEInputPort::isInput() const
{
    return true;
}

bool QNEInputPort::isOutput() const
{
    return false;
}

bool QNEInputPort::isValid() const
{
    return m_connections.isEmpty() ? !isRequired() : (m_connections.size() == 1);
}

void QNEInputPort::updateTheme()
{
}

QNEOutputPort::QNEOutputPort(QGraphicsItem *parent)
    : QNEPort(parent)
{
    m_label->setPos(m_radius + m_margin,
                    -m_label->boundingRect().height() / 2);

    QNEOutputPort::updateTheme();
}

QNEOutputPort::~QNEOutputPort()
{
    while (!m_connections.isEmpty()) {
        auto *conn = m_connections.constLast();
        m_connections.removeAll(conn);
        conn->setStartPort(nullptr);
        delete conn;
    }
}

void QNEOutputPort::setStatus(const Status status)
{
    if (status == m_status) {
        return;
    }

    m_status = status;

    for (auto *conn : connections()) {
        conn->setStatus(status);
    }
}

bool QNEOutputPort::isInput() const
{
    return false;
}

bool QNEOutputPort::isOutput() const
{
    return true;
}

bool QNEOutputPort::isValid() const
{
    return (m_status != Status::Invalid);
}

void QNEOutputPort::updateTheme()
{
    const auto theme = ThemeManager::attributes();
    setPen(theme.m_portOutputPen);
    setCurrentBrush(theme.m_portOutputBrush);
}
