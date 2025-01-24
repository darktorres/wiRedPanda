// Copyright 2015 - 2025, GIBIS-UNIFESP and the wiRedPanda contributors
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "scene.h"

#include <QDialog>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QTableWidget>

namespace Ui
{
class ElementEditor;
}

class ElementEditor : public QWidget
{
    Q_OBJECT

public:
    explicit ElementEditor(QWidget *parent = nullptr);
    ~ElementEditor() override;

    bool eventFilter(QObject *obj, QEvent *event) override;
    void audioBox();
    void changeTriggerAction();
    void contextMenu(QPoint screenPos, QGraphicsItem *itemAtMouse);
    void fillColorComboBox();
    void renameAction();
    void retranslateUi();
    void setScene(Scene *scene);
    void truthTable();
    void update();
    void updateElementSkin();
    void updatePriorityAction();
    void updateTheme();
    void audioBox();

signals:
    void sendCommand(QUndoCommand *cmd);

private:
    Q_DISABLE_COPY(ElementEditor)

    void apply();
    void mapNode();
    void connectNode(const QString newText);
    void defaultSkin();
    void inputIndexChanged(const int index);
    void inputLocked(const bool value);
    void outputIndexChanged(const int index);
    void outputValueChanged(const QString &value);
    void priorityChanged(const int value);
    void selectionChanged();
    void setCurrentElements(const QList<GraphicElement *> &elements);
    void setTruthTableProposition(const int row, const int column);
    void triggerChanged(const QString &cmd);
    void updateSkins();

    Ui::ElementEditor *m_ui;
    QDialog *m_tableBox = nullptr;
    QList<GraphicElement *> m_elements;
    QString m_manyAudios = tr("<Many sounds>");
    QString m_manyColors = tr("<Many colors>");
    QString m_manyFreq = tr("<Many values>");
    QString m_manyDelay = tr("<Many values>");
    QString m_manyIS = tr("<Many values>");
    QString m_manyLabels = tr("<Many labels>");
    QString m_manyOS = tr("<Many values>");
    QString m_manyOV = tr("<Many values>");
    QString m_manyPriorities = tr("<Many priorities>");
    QString m_manyTriggers = tr("<Many triggers>");
    QString m_skinName;
    QTableWidget *m_table = nullptr;
    Scene *m_scene = nullptr;
    QDialog *m_tableBox = new QDialog(this);
    QVBoxLayout *m_tableLayout = new QVBoxLayout(m_tableBox);
    QTableWidget *m_table = new QTableWidget(m_tableBox);
    bool m_canChangeInputSize = false;
    bool m_canChangeOutputSize = false;
    bool m_canChangeSkin = false;
    bool m_canMorph = false;
    bool m_hasAnyProperty = false;
    bool m_hasAudio = false;
    bool m_hasAudioBox = false;
    bool m_hasColors = false;
    bool m_hasElements = false;
    bool m_hasFrequency = false;
    bool m_hasDelay = false;
    bool m_hasLabel = false;
    bool m_hasOnlyInputs = false;
    bool m_hasRotarySwitch = false;
    bool m_hasRotation = false;
    bool m_hasSameAudio = false;
    bool m_hasSameColors = false;
    bool m_hasSameFrequency = false;
    bool m_hasSameDelay = false;
    bool m_hasSameInputSize = false;
    bool m_hasSameLabel = false;
    bool m_hasSameOutputSize = false;
    bool m_hasSameOutputValue = false;
    bool m_hasSamePriority = false;
    bool m_hasSameTrigger = false;
    bool m_hasSameType = false;
    bool m_hasTrigger = false;
    bool m_hasTruthTable = false;
    bool m_isDefaultSkin = true;
    bool m_isUpdatingSkin = false;
    bool m_hasNodeConnection = false;
    unsigned int m_hasTruthTable = 0;
};
