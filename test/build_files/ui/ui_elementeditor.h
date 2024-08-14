/********************************************************************************
** Form generated from reading UI file 'elementeditor.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELEMENTEDITOR_H
#define UI_ELEMENTEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ElementEditor
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *labelInputs;
    QLabel *labelValue;
    QLabel *labelAudio;
    QLabel *labelTrigger;
    QLabel *labelOutputs;
    QLabel *labelFrequency;
    QLabel *labelLabels;
    QLabel *labelColor;
    QLineEdit *lineEditTrigger;
    QComboBox *comboBoxAudio;
    QComboBox *comboBoxColor;
    QDoubleSpinBox *doubleSpinBoxFrequency;
    QComboBox *comboBoxValue;
    QComboBox *comboBoxOutputSize;
    QComboBox *comboBoxInputSize;
    QLineEdit *lineEditElementLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonChangeSkin;
    QPushButton *pushButtonDefaultSkin;
    QCheckBox *checkBoxLocked;
    QLabel *labelLocked;
    QLabel *labelPriority;
    QSpinBox *spinBoxPriority;

    void setupUi(QWidget *ElementEditor)
    {
        if (ElementEditor->objectName().isEmpty())
            ElementEditor->setObjectName("ElementEditor");
        ElementEditor->resize(205, 346);
        gridLayout = new QGridLayout(ElementEditor);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(ElementEditor);
        groupBox->setObjectName("groupBox");
        QFont font;
        font.setBold(true);
        groupBox->setFont(font);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        labelInputs = new QLabel(groupBox);
        labelInputs->setObjectName("labelInputs");

        gridLayout_2->addWidget(labelInputs, 2, 0, 1, 1);

        labelValue = new QLabel(groupBox);
        labelValue->setObjectName("labelValue");

        gridLayout_2->addWidget(labelValue, 6, 0, 1, 1);

        labelAudio = new QLabel(groupBox);
        labelAudio->setObjectName("labelAudio");

        gridLayout_2->addWidget(labelAudio, 13, 0, 1, 1);

        labelTrigger = new QLabel(groupBox);
        labelTrigger->setObjectName("labelTrigger");

        gridLayout_2->addWidget(labelTrigger, 15, 0, 1, 1);

        labelOutputs = new QLabel(groupBox);
        labelOutputs->setObjectName("labelOutputs");

        gridLayout_2->addWidget(labelOutputs, 4, 0, 1, 1);

        labelFrequency = new QLabel(groupBox);
        labelFrequency->setObjectName("labelFrequency");

        gridLayout_2->addWidget(labelFrequency, 9, 0, 1, 1);

        labelLabels = new QLabel(groupBox);
        labelLabels->setObjectName("labelLabels");

        gridLayout_2->addWidget(labelLabels, 0, 0, 1, 1);

        labelColor = new QLabel(groupBox);
        labelColor->setObjectName("labelColor");

        gridLayout_2->addWidget(labelColor, 11, 0, 1, 1);

        lineEditTrigger = new QLineEdit(groupBox);
        lineEditTrigger->setObjectName("lineEditTrigger");

        gridLayout_2->addWidget(lineEditTrigger, 15, 1, 1, 1);

        comboBoxAudio = new QComboBox(groupBox);
        comboBoxAudio->addItem(QString());
        comboBoxAudio->addItem(QString());
        comboBoxAudio->addItem(QString());
        comboBoxAudio->addItem(QString());
        comboBoxAudio->addItem(QString());
        comboBoxAudio->addItem(QString());
        comboBoxAudio->addItem(QString());
        comboBoxAudio->addItem(QString());
        comboBoxAudio->setObjectName("comboBoxAudio");

        gridLayout_2->addWidget(comboBoxAudio, 13, 1, 1, 1);

        comboBoxColor = new QComboBox(groupBox);
        comboBoxColor->setObjectName("comboBoxColor");

        gridLayout_2->addWidget(comboBoxColor, 11, 1, 1, 1);

        doubleSpinBoxFrequency = new QDoubleSpinBox(groupBox);
        doubleSpinBoxFrequency->setObjectName("doubleSpinBoxFrequency");
        doubleSpinBoxFrequency->setDecimals(1);
        doubleSpinBoxFrequency->setMinimum(0.000000000000000);
        doubleSpinBoxFrequency->setMaximum(50.000000000000000);
        doubleSpinBoxFrequency->setSingleStep(0.100000000000000);

        gridLayout_2->addWidget(doubleSpinBoxFrequency, 9, 1, 1, 1);

        comboBoxValue = new QComboBox(groupBox);
        comboBoxValue->setObjectName("comboBoxValue");

        gridLayout_2->addWidget(comboBoxValue, 6, 1, 1, 1);

        comboBoxOutputSize = new QComboBox(groupBox);
        comboBoxOutputSize->setObjectName("comboBoxOutputSize");

        gridLayout_2->addWidget(comboBoxOutputSize, 4, 1, 1, 1);

        comboBoxInputSize = new QComboBox(groupBox);
        comboBoxInputSize->setObjectName("comboBoxInputSize");

        gridLayout_2->addWidget(comboBoxInputSize, 2, 1, 1, 1);

        lineEditElementLabel = new QLineEdit(groupBox);
        lineEditElementLabel->setObjectName("lineEditElementLabel");

        gridLayout_2->addWidget(lineEditElementLabel, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        pushButtonChangeSkin = new QPushButton(groupBox);
        pushButtonChangeSkin->setObjectName("pushButtonChangeSkin");

        horizontalLayout->addWidget(pushButtonChangeSkin);

        pushButtonDefaultSkin = new QPushButton(groupBox);
        pushButtonDefaultSkin->setObjectName("pushButtonDefaultSkin");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonDefaultSkin->sizePolicy().hasHeightForWidth());
        pushButtonDefaultSkin->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/toolbar/default.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDefaultSkin->setIcon(icon);
        pushButtonDefaultSkin->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(pushButtonDefaultSkin);


        gridLayout_2->addLayout(horizontalLayout, 17, 0, 1, 2);

        checkBoxLocked = new QCheckBox(groupBox);
        checkBoxLocked->setObjectName("checkBoxLocked");

        gridLayout_2->addWidget(checkBoxLocked, 7, 1, 1, 1);

        labelLocked = new QLabel(groupBox);
        labelLocked->setObjectName("labelLocked");

        gridLayout_2->addWidget(labelLocked, 7, 0, 1, 1);

        labelPriority = new QLabel(groupBox);
        labelPriority->setObjectName("labelPriority");

        gridLayout_2->addWidget(labelPriority, 16, 0, 1, 1);

        spinBoxPriority = new QSpinBox(groupBox);
        spinBoxPriority->setObjectName("spinBoxPriority");
        spinBoxPriority->setMaximum(9);

        gridLayout_2->addWidget(spinBoxPriority, 16, 1, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(ElementEditor);

        QMetaObject::connectSlotsByName(ElementEditor);
    } // setupUi

    void retranslateUi(QWidget *ElementEditor)
    {
        ElementEditor->setWindowTitle(QCoreApplication::translate("ElementEditor", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ElementEditor", "Title", nullptr));
        labelInputs->setText(QCoreApplication::translate("ElementEditor", "Input Ports:", nullptr));
        labelValue->setText(QCoreApplication::translate("ElementEditor", "Value:", nullptr));
        labelAudio->setText(QCoreApplication::translate("ElementEditor", "Audio:", nullptr));
        labelTrigger->setText(QCoreApplication::translate("ElementEditor", "Trigger:", nullptr));
        labelOutputs->setText(QCoreApplication::translate("ElementEditor", "Output Ports:", nullptr));
        labelFrequency->setText(QCoreApplication::translate("ElementEditor", "Frequency:", nullptr));
        labelLabels->setText(QCoreApplication::translate("ElementEditor", "Label:", nullptr));
        labelColor->setText(QCoreApplication::translate("ElementEditor", "Color:", nullptr));
        comboBoxAudio->setItemText(0, QCoreApplication::translate("ElementEditor", "C6", nullptr));
        comboBoxAudio->setItemText(1, QCoreApplication::translate("ElementEditor", "D6", nullptr));
        comboBoxAudio->setItemText(2, QCoreApplication::translate("ElementEditor", "E6", nullptr));
        comboBoxAudio->setItemText(3, QCoreApplication::translate("ElementEditor", "F6", nullptr));
        comboBoxAudio->setItemText(4, QCoreApplication::translate("ElementEditor", "G6", nullptr));
        comboBoxAudio->setItemText(5, QCoreApplication::translate("ElementEditor", "A7", nullptr));
        comboBoxAudio->setItemText(6, QCoreApplication::translate("ElementEditor", "B7", nullptr));
        comboBoxAudio->setItemText(7, QCoreApplication::translate("ElementEditor", "C7", nullptr));

        comboBoxColor->setCurrentText(QString());
        doubleSpinBoxFrequency->setSpecialValueText(QString());
        doubleSpinBoxFrequency->setSuffix(QCoreApplication::translate("ElementEditor", " Hz", nullptr));
        pushButtonChangeSkin->setText(QCoreApplication::translate("ElementEditor", "Change skin to ...", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonDefaultSkin->setToolTip(QCoreApplication::translate("ElementEditor", "Default", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonDefaultSkin->setText(QString());
        checkBoxLocked->setText(QString());
        labelLocked->setText(QCoreApplication::translate("ElementEditor", "Locked:", nullptr));
        labelPriority->setText(QCoreApplication::translate("ElementEditor", "Priority:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ElementEditor: public Ui_ElementEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELEMENTEDITOR_H
