/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "elementeditor.h"
#include "trashbutton.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionDelete;
    QAction *actionNew;
    QAction *actionZoomIn;
    QAction *actionZoomOut;
    QAction *actionWires;
    QAction *actionGates;
    QAction *actionAbout;
    QAction *actionExit;
    QAction *actionRotateRight;
    QAction *actionRotateLeft;
    QAction *actionAboutQt;
    QAction *actionSelectAll;
    QAction *actionReloadFile;
    QAction *actionExportToArduino;
    QAction *actionResetZoom;
    QAction *actionExportToPdf;
    QAction *actionEnglish;
    QAction *actionPortuguese;
    QAction *actionPlay;
    QAction *actionRename;
    QAction *actionChangeTrigger;
    QAction *actionClearSelection;
    QAction *actionFastMode;
    QAction *actionLightTheme;
    QAction *actionDarkTheme;
    QAction *actionWaveform;
    QAction *actionExportToImage;
    QAction *actionFlipHorizontally;
    QAction *actionFlipVertically;
    QAction *actionFullscreen;
    QAction *actionMute;
    QAction *actionLabelsUnderIcons;
    QAction *actionAboutThisVersion;
    QAction *actionRestart;
    QWidget *centralWidget;
    QGridLayout *gridLayout_8;
    QSplitter *splitter;
    QWidget *leftPannel;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout;
    QTabWidget *tabElements;
    QWidget *io;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollAreaInOut;
    QWidget *scrollAreaWidgetContents_InOut;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_InOut;
    QWidget *gates;
    QGridLayout *gridLayout_6;
    QScrollArea *scrollAreaGates;
    QWidget *scrollAreaWidgetContents_Gates;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_Gates;
    QWidget *memory;
    QGridLayout *gridLayout_5;
    QScrollArea *scrollAreaMemory;
    QWidget *scrollAreaWidgetContents_Memory;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_Memory;
    QWidget *ic;
    QGridLayout *gridLayout_4;
    QScrollArea *scrollArea_Box;
    QWidget *scrollAreaWidgetContents_IC;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_IC;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonAddIC;
    TrashButton *pushButtonRemoveIC;
    QWidget *misc;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea_Misc;
    QWidget *scrollAreaWidgetContents_Misc;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_Misc;
    QWidget *search;
    QGridLayout *gridLayout_9;
    QScrollArea *scrollArea_Search;
    QWidget *scrollAreaWidgetContents_Search;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_Search;
    ElementEditor *elementEditor;
    QLabel *label;
    QLineEdit *lineEditSearch;
    QTabWidget *tab;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuRecentFiles;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QMenu *menuView;
    QMenu *menuTheme;
    QMenu *menuLanguage;
    QMenu *menuSimulation;
    QMenu *menuExamples;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(886, 765);
        MainWindow->setMinimumSize(QSize(0, 150));
        MainWindow->setWindowTitle(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/toolbar/wpanda.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/toolbar/folder.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/toolbar/save.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName("actionSaveAs");
        actionSaveAs->setIcon(icon2);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName("actionCut");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/toolbar/cut.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon3);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName("actionCopy");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/toolbar/copy.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon4);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName("actionPaste");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/toolbar/paste.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon5);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName("actionDelete");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/toolbar/delete.svg"), QSize(), QIcon::Normal, QIcon::On);
        actionDelete->setIcon(icon6);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/toolbar/new.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon7);
        actionZoomIn = new QAction(MainWindow);
        actionZoomIn->setObjectName("actionZoomIn");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/toolbar/zoomIn.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomIn->setIcon(icon8);
        actionZoomOut = new QAction(MainWindow);
        actionZoomOut->setObjectName("actionZoomOut");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/toolbar/zoomOut.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomOut->setIcon(icon9);
        actionWires = new QAction(MainWindow);
        actionWires->setObjectName("actionWires");
        actionWires->setCheckable(true);
        actionWires->setChecked(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/toolbar/wires.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionWires->setIcon(icon10);
        actionGates = new QAction(MainWindow);
        actionGates->setObjectName("actionGates");
        actionGates->setCheckable(true);
        actionGates->setChecked(true);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/basic/nor.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionGates->setIcon(icon11);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/toolbar/help.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon12);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/toolbar/exit.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon13);
        actionRotateRight = new QAction(MainWindow);
        actionRotateRight->setObjectName("actionRotateRight");
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/toolbar/rotateR.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotateRight->setIcon(icon14);
        actionRotateLeft = new QAction(MainWindow);
        actionRotateLeft->setObjectName("actionRotateLeft");
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/toolbar/rotateL.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotateLeft->setIcon(icon15);
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName("actionAboutQt");
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/toolbar/helpQt.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionAboutQt->setIcon(icon16);
        actionSelectAll = new QAction(MainWindow);
        actionSelectAll->setObjectName("actionSelectAll");
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/toolbar/selectAll.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectAll->setIcon(icon17);
        actionReloadFile = new QAction(MainWindow);
        actionReloadFile->setObjectName("actionReloadFile");
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/toolbar/reloadFile.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionReloadFile->setIcon(icon18);
        actionExportToArduino = new QAction(MainWindow);
        actionExportToArduino->setObjectName("actionExportToArduino");
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/toolbar/arduino.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionExportToArduino->setIcon(icon19);
        actionResetZoom = new QAction(MainWindow);
        actionResetZoom->setObjectName("actionResetZoom");
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/toolbar/zoomReset.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionResetZoom->setIcon(icon20);
        actionExportToPdf = new QAction(MainWindow);
        actionExportToPdf->setObjectName("actionExportToPdf");
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/toolbar/pdf.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionExportToPdf->setIcon(icon21);
        actionEnglish = new QAction(MainWindow);
        actionEnglish->setObjectName("actionEnglish");
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/toolbar/usa.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnglish->setIcon(icon22);
        actionPortuguese = new QAction(MainWindow);
        actionPortuguese->setObjectName("actionPortuguese");
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/toolbar/brasil.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPortuguese->setIcon(icon23);
        actionPlay = new QAction(MainWindow);
        actionPlay->setObjectName("actionPlay");
        actionPlay->setCheckable(true);
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/toolbar/play.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon24.addFile(QString::fromUtf8(":/toolbar/pause.svg"), QSize(), QIcon::Normal, QIcon::On);
        actionPlay->setIcon(icon24);
        actionRename = new QAction(MainWindow);
        actionRename->setObjectName("actionRename");
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/toolbar/rename.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionRename->setIcon(icon25);
        actionChangeTrigger = new QAction(MainWindow);
        actionChangeTrigger->setObjectName("actionChangeTrigger");
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/input/buttonOff.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionChangeTrigger->setIcon(icon26);
        actionClearSelection = new QAction(MainWindow);
        actionClearSelection->setObjectName("actionClearSelection");
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/toolbar/clearSelection.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionClearSelection->setIcon(icon27);
        actionFastMode = new QAction(MainWindow);
        actionFastMode->setObjectName("actionFastMode");
        actionFastMode->setCheckable(true);
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/toolbar/fast.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionFastMode->setIcon(icon28);
        actionLightTheme = new QAction(MainWindow);
        actionLightTheme->setObjectName("actionLightTheme");
        actionLightTheme->setCheckable(true);
        actionLightTheme->setChecked(true);
        actionDarkTheme = new QAction(MainWindow);
        actionDarkTheme->setObjectName("actionDarkTheme");
        actionDarkTheme->setCheckable(true);
        actionWaveform = new QAction(MainWindow);
        actionWaveform->setObjectName("actionWaveform");
        QIcon icon29;
        icon29.addFile(QString::fromUtf8(":/toolbar/dolphin_icon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionWaveform->setIcon(icon29);
        actionExportToImage = new QAction(MainWindow);
        actionExportToImage->setObjectName("actionExportToImage");
        QIcon icon30;
        icon30.addFile(QString::fromUtf8(":/toolbar/png.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionExportToImage->setIcon(icon30);
        actionFlipHorizontally = new QAction(MainWindow);
        actionFlipHorizontally->setObjectName("actionFlipHorizontally");
        actionFlipVertically = new QAction(MainWindow);
        actionFlipVertically->setObjectName("actionFlipVertically");
        actionFullscreen = new QAction(MainWindow);
        actionFullscreen->setObjectName("actionFullscreen");
        actionMute = new QAction(MainWindow);
        actionMute->setObjectName("actionMute");
        actionMute->setCheckable(true);
        QIcon icon31;
        icon31.addFile(QString::fromUtf8(":/output/buzzer/BuzzerOff.svg"), QSize(), QIcon::Normal, QIcon::Off);
        icon31.addFile(QString::fromUtf8(":/toolbar/mute.svg"), QSize(), QIcon::Normal, QIcon::On);
        actionMute->setIcon(icon31);
        actionLabelsUnderIcons = new QAction(MainWindow);
        actionLabelsUnderIcons->setObjectName("actionLabelsUnderIcons");
        actionLabelsUnderIcons->setCheckable(true);
        actionAboutThisVersion = new QAction(MainWindow);
        actionAboutThisVersion->setObjectName("actionAboutThisVersion");
        actionRestart = new QAction(MainWindow);
        actionRestart->setObjectName("actionRestart");
        QIcon icon32;
        icon32.addFile(QString::fromUtf8(":/toolbar/reset.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionRestart->setIcon(icon32);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        gridLayout_8 = new QGridLayout(centralWidget);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName("gridLayout_8");
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName("splitter");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setFrameShape(QFrame::NoFrame);
        splitter->setLineWidth(1);
        splitter->setMidLineWidth(2);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setOpaqueResize(false);
        splitter->setHandleWidth(8);
        splitter->setChildrenCollapsible(false);
        leftPannel = new QWidget(splitter);
        leftPannel->setObjectName("leftPannel");
        leftPannel->setMinimumSize(QSize(280, 0));
        leftPannel->setMaximumSize(QSize(600, 16777215));
        verticalLayout_5 = new QVBoxLayout(leftPannel);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName("gridLayout");
        tabElements = new QTabWidget(leftPannel);
        tabElements->setObjectName("tabElements");
        sizePolicy.setHeightForWidth(tabElements->sizePolicy().hasHeightForWidth());
        tabElements->setSizePolicy(sizePolicy);
        tabElements->setMinimumSize(QSize(220, 0));
        tabElements->setStyleSheet(QString::fromUtf8("QTabBar::tab:disabled {\n"
"	 width: 0;\n"
"	 height: 0;\n"
"	 margin: 0;\n"
"	 padding: 0;\n"
"	 border: none; \n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"	margin: 0px 0px 0px 0px; \n"
"}\n"
""));
        io = new QWidget();
        io->setObjectName("io");
        gridLayout_2 = new QGridLayout(io);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        scrollAreaInOut = new QScrollArea(io);
        scrollAreaInOut->setObjectName("scrollAreaInOut");
        scrollAreaInOut->setFrameShape(QFrame::NoFrame);
        scrollAreaInOut->setWidgetResizable(true);
        scrollAreaWidgetContents_InOut = new QWidget();
        scrollAreaWidgetContents_InOut->setObjectName("scrollAreaWidgetContents_InOut");
        scrollAreaWidgetContents_InOut->setGeometry(QRect(0, 0, 260, 581));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents_InOut);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_InOut = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_InOut);

        scrollAreaInOut->setWidget(scrollAreaWidgetContents_InOut);

        gridLayout_2->addWidget(scrollAreaInOut, 0, 0, 1, 1);

        tabElements->addTab(io, icon26, QString());
        gates = new QWidget();
        gates->setObjectName("gates");
        gridLayout_6 = new QGridLayout(gates);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName("gridLayout_6");
        scrollAreaGates = new QScrollArea(gates);
        scrollAreaGates->setObjectName("scrollAreaGates");
        scrollAreaGates->setFrameShape(QFrame::NoFrame);
        scrollAreaGates->setWidgetResizable(true);
        scrollAreaWidgetContents_Gates = new QWidget();
        scrollAreaWidgetContents_Gates->setObjectName("scrollAreaWidgetContents_Gates");
        scrollAreaWidgetContents_Gates->setGeometry(QRect(0, 0, 260, 581));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_Gates);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer_Gates = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_Gates);

        scrollAreaGates->setWidget(scrollAreaWidgetContents_Gates);

        gridLayout_6->addWidget(scrollAreaGates, 0, 1, 1, 1);

        QIcon icon33;
        icon33.addFile(QString::fromUtf8(":/basic/xor.svg"), QSize(), QIcon::Normal, QIcon::Off);
        tabElements->addTab(gates, icon33, QString());
        memory = new QWidget();
        memory->setObjectName("memory");
        gridLayout_5 = new QGridLayout(memory);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName("gridLayout_5");
        scrollAreaMemory = new QScrollArea(memory);
        scrollAreaMemory->setObjectName("scrollAreaMemory");
        scrollAreaMemory->setFrameShape(QFrame::NoFrame);
        scrollAreaMemory->setWidgetResizable(true);
        scrollAreaWidgetContents_Memory = new QWidget();
        scrollAreaWidgetContents_Memory->setObjectName("scrollAreaWidgetContents_Memory");
        scrollAreaWidgetContents_Memory->setGeometry(QRect(0, 0, 260, 581));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents_Memory);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer_Memory = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_Memory);

        scrollAreaMemory->setWidget(scrollAreaWidgetContents_Memory);

        gridLayout_5->addWidget(scrollAreaMemory, 0, 1, 1, 1);

        QIcon icon34;
        icon34.addFile(QString::fromUtf8(":/memory/light/D-flipflop.svg"), QSize(), QIcon::Normal, QIcon::Off);
        tabElements->addTab(memory, icon34, QString());
        ic = new QWidget();
        ic->setObjectName("ic");
        gridLayout_4 = new QGridLayout(ic);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName("gridLayout_4");
        scrollArea_Box = new QScrollArea(ic);
        scrollArea_Box->setObjectName("scrollArea_Box");
        scrollArea_Box->setFrameShape(QFrame::NoFrame);
        scrollArea_Box->setWidgetResizable(true);
        scrollAreaWidgetContents_IC = new QWidget();
        scrollAreaWidgetContents_IC->setObjectName("scrollAreaWidgetContents_IC");
        scrollAreaWidgetContents_IC->setGeometry(QRect(0, 0, 260, 549));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents_IC);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalSpacer_IC = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_IC);

        scrollArea_Box->setWidget(scrollAreaWidgetContents_IC);

        gridLayout_4->addWidget(scrollArea_Box, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButtonAddIC = new QPushButton(ic);
        pushButtonAddIC->setObjectName("pushButtonAddIC");

        horizontalLayout->addWidget(pushButtonAddIC);

        pushButtonRemoveIC = new TrashButton(ic);
        pushButtonRemoveIC->setObjectName("pushButtonRemoveIC");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButtonRemoveIC->sizePolicy().hasHeightForWidth());
        pushButtonRemoveIC->setSizePolicy(sizePolicy1);
        QIcon icon35;
        icon35.addFile(QString::fromUtf8(":/toolbar/trashcan.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonRemoveIC->setIcon(icon35);

        horizontalLayout->addWidget(pushButtonRemoveIC);


        gridLayout_4->addLayout(horizontalLayout, 0, 0, 1, 1);

        QIcon icon36;
        icon36.addFile(QString::fromUtf8(":/basic/ic-panda.svg"), QSize(), QIcon::Normal, QIcon::Off);
        tabElements->addTab(ic, icon36, QString());
        misc = new QWidget();
        misc->setObjectName("misc");
        gridLayout_3 = new QGridLayout(misc);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName("gridLayout_3");
        scrollArea_Misc = new QScrollArea(misc);
        scrollArea_Misc->setObjectName("scrollArea_Misc");
        scrollArea_Misc->setFrameShape(QFrame::NoFrame);
        scrollArea_Misc->setWidgetResizable(true);
        scrollAreaWidgetContents_Misc = new QWidget();
        scrollAreaWidgetContents_Misc->setObjectName("scrollAreaWidgetContents_Misc");
        scrollAreaWidgetContents_Misc->setGeometry(QRect(0, 0, 260, 581));
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollAreaWidgetContents_Misc->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_Misc->setSizePolicy(sizePolicy2);
        verticalLayout_6 = new QVBoxLayout(scrollAreaWidgetContents_Misc);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalSpacer_Misc = new QSpacerItem(210, 227, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_Misc);

        scrollArea_Misc->setWidget(scrollAreaWidgetContents_Misc);

        gridLayout_3->addWidget(scrollArea_Misc, 0, 0, 1, 1);

        QIcon icon37;
        icon37.addFile(QString::fromUtf8(":/misc/text.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabElements->addTab(misc, icon37, QString());
        search = new QWidget();
        search->setObjectName("search");
        gridLayout_9 = new QGridLayout(search);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName("gridLayout_9");
        scrollArea_Search = new QScrollArea(search);
        scrollArea_Search->setObjectName("scrollArea_Search");
        scrollArea_Search->setWidgetResizable(true);
        scrollAreaWidgetContents_Search = new QWidget();
        scrollAreaWidgetContents_Search->setObjectName("scrollAreaWidgetContents_Search");
        scrollAreaWidgetContents_Search->setGeometry(QRect(0, 0, 258, 579));
        verticalLayout_7 = new QVBoxLayout(scrollAreaWidgetContents_Search);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalSpacer_Search = new QSpacerItem(20, 234, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_Search);

        scrollArea_Search->setWidget(scrollAreaWidgetContents_Search);

        gridLayout_9->addWidget(scrollArea_Search, 0, 0, 1, 1);

        tabElements->addTab(search, QString());

        gridLayout->addWidget(tabElements, 1, 0, 1, 3);

        elementEditor = new ElementEditor(leftPannel);
        elementEditor->setObjectName("elementEditor");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(elementEditor->sizePolicy().hasHeightForWidth());
        elementEditor->setSizePolicy(sizePolicy3);
        elementEditor->setMinimumSize(QSize(0, 0));
        elementEditor->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(elementEditor, 2, 0, 1, 3);

        label = new QLabel(leftPannel);
        label->setObjectName("label");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditSearch = new QLineEdit(leftPannel);
        lineEditSearch->setObjectName("lineEditSearch");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(lineEditSearch->sizePolicy().hasHeightForWidth());
        lineEditSearch->setSizePolicy(sizePolicy5);
        lineEditSearch->setClearButtonEnabled(true);

        gridLayout->addWidget(lineEditSearch, 0, 1, 1, 2);


        verticalLayout_5->addLayout(gridLayout);

        splitter->addWidget(leftPannel);
        tab = new QTabWidget(splitter);
        tab->setObjectName("tab");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy6.setHorizontalStretch(255);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy6);
        tab->setMinimumSize(QSize(570, 0));
        tab->setMaximumSize(QSize(16777215, 16777215));
        tab->setTabsClosable(true);
        splitter->addWidget(tab);

        gridLayout_8->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        mainToolBar->setContextMenuPolicy(Qt::PreventContextMenu);
        mainToolBar->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 886, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        menuFile->setToolTipsVisible(false);
        menuRecentFiles = new QMenu(menuFile);
        menuRecentFiles->setObjectName("menuRecentFiles");
        menuRecentFiles->setEnabled(false);
        QIcon icon38;
        icon38.addFile(QString::fromUtf8(":/toolbar/recentFiles.svg"), QSize(), QIcon::Normal, QIcon::Off);
        menuRecentFiles->setIcon(icon38);
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName("menuEdit");
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        menuView = new QMenu(menuBar);
        menuView->setObjectName("menuView");
        menuTheme = new QMenu(menuView);
        menuTheme->setObjectName("menuTheme");
        menuLanguage = new QMenu(menuBar);
        menuLanguage->setObjectName("menuLanguage");
        menuSimulation = new QMenu(menuBar);
        menuSimulation->setObjectName("menuSimulation");
        menuExamples = new QMenu(menuBar);
        menuExamples->setObjectName("menuExamples");
        MainWindow->setMenuBar(menuBar);
        QWidget::setTabOrder(lineEditSearch, tabElements);
        QWidget::setTabOrder(tabElements, scrollAreaInOut);
        QWidget::setTabOrder(scrollAreaInOut, scrollAreaMemory);
        QWidget::setTabOrder(scrollAreaMemory, scrollArea_Box);
        QWidget::setTabOrder(scrollArea_Box, scrollAreaGates);

        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionRotateLeft);
        mainToolBar->addAction(actionRotateRight);
        mainToolBar->addAction(actionCut);
        mainToolBar->addAction(actionCopy);
        mainToolBar->addAction(actionPaste);
        mainToolBar->addAction(actionDelete);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionZoomIn);
        mainToolBar->addAction(actionZoomOut);
        mainToolBar->addAction(actionResetZoom);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionPlay);
        mainToolBar->addAction(actionRestart);
        mainToolBar->addAction(actionWaveform);
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuSimulation->menuAction());
        menuBar->addAction(menuExamples->menuAction());
        menuBar->addAction(menuLanguage->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(menuRecentFiles->menuAction());
        menuFile->addAction(actionReloadFile);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addAction(actionExportToArduino);
        menuFile->addAction(actionExportToPdf);
        menuFile->addAction(actionExportToImage);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuFile->addSeparator();
        menuRecentFiles->addSeparator();
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionDelete);
        menuEdit->addSeparator();
        menuEdit->addAction(actionRename);
        menuEdit->addAction(actionChangeTrigger);
        menuEdit->addSeparator();
        menuEdit->addAction(actionRotateLeft);
        menuEdit->addAction(actionRotateRight);
        menuEdit->addAction(actionFlipHorizontally);
        menuEdit->addAction(actionFlipVertically);
        menuEdit->addSeparator();
        menuEdit->addAction(actionSelectAll);
        menuEdit->addAction(actionClearSelection);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAboutQt);
        menuHelp->addAction(actionAboutThisVersion);
        menuView->addAction(actionZoomIn);
        menuView->addAction(actionZoomOut);
        menuView->addAction(actionResetZoom);
        menuView->addSeparator();
        menuView->addAction(actionWires);
        menuView->addAction(actionGates);
        menuView->addSeparator();
        menuView->addAction(actionFastMode);
        menuView->addSeparator();
        menuView->addAction(menuTheme->menuAction());
        menuView->addAction(actionFullscreen);
        menuView->addAction(actionLabelsUnderIcons);
        menuTheme->addAction(actionLightTheme);
        menuTheme->addAction(actionDarkTheme);
        menuLanguage->addAction(actionEnglish);
        menuLanguage->addAction(actionPortuguese);
        menuSimulation->addAction(actionPlay);
        menuSimulation->addAction(actionRestart);
        menuSimulation->addAction(actionWaveform);
        menuSimulation->addAction(actionMute);

        retranslateUi(MainWindow);

        tabElements->setCurrentIndex(0);
        tab->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        actionOpen->setText(QCoreApplication::translate("MainWindow", "&Open...", nullptr));
#if QT_CONFIG(tooltip)
        actionOpen->setToolTip(QCoreApplication::translate("MainWindow", "Open", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "&Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSaveAs->setText(QCoreApplication::translate("MainWindow", "Save &As...", nullptr));
#if QT_CONFIG(shortcut)
        actionSaveAs->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCut->setText(QCoreApplication::translate("MainWindow", "Cu&t", nullptr));
#if QT_CONFIG(shortcut)
        actionCut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy->setText(QCoreApplication::translate("MainWindow", "&Copy", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste->setText(QCoreApplication::translate("MainWindow", "&Paste", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDelete->setText(QCoreApplication::translate("MainWindow", "&Delete", nullptr));
#if QT_CONFIG(shortcut)
        actionDelete->setShortcut(QCoreApplication::translate("MainWindow", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew->setText(QCoreApplication::translate("MainWindow", "&New", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZoomIn->setText(QCoreApplication::translate("MainWindow", "Zoom &in", nullptr));
#if QT_CONFIG(shortcut)
        actionZoomIn->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+=", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZoomOut->setText(QCoreApplication::translate("MainWindow", "Zoom &out", nullptr));
#if QT_CONFIG(shortcut)
        actionZoomOut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+-", nullptr));
#endif // QT_CONFIG(shortcut)
        actionWires->setText(QCoreApplication::translate("MainWindow", "&Wires", nullptr));
#if QT_CONFIG(shortcut)
        actionWires->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionGates->setText(QCoreApplication::translate("MainWindow", "&Gates", nullptr));
#if QT_CONFIG(shortcut)
        actionGates->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+2", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "&About", nullptr));
#if QT_CONFIG(shortcut)
        actionAbout->setShortcut(QCoreApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "&Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRotateRight->setText(QCoreApplication::translate("MainWindow", "R&otate right", nullptr));
#if QT_CONFIG(shortcut)
        actionRotateRight->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRotateLeft->setText(QCoreApplication::translate("MainWindow", "Rotate &left", nullptr));
#if QT_CONFIG(shortcut)
        actionRotateLeft->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAboutQt->setText(QCoreApplication::translate("MainWindow", "About &Qt", nullptr));
        actionSelectAll->setText(QCoreApplication::translate("MainWindow", "&Select all", nullptr));
#if QT_CONFIG(shortcut)
        actionSelectAll->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionReloadFile->setText(QCoreApplication::translate("MainWindow", "Re&load File", nullptr));
#if QT_CONFIG(shortcut)
        actionReloadFile->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F5", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExportToArduino->setText(QCoreApplication::translate("MainWindow", "E&xport to Arduino", nullptr));
#if QT_CONFIG(shortcut)
        actionExportToArduino->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Alt+I", nullptr));
#endif // QT_CONFIG(shortcut)
        actionResetZoom->setText(QCoreApplication::translate("MainWindow", "&Reset Zoom", nullptr));
#if QT_CONFIG(shortcut)
        actionResetZoom->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+0", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExportToPdf->setText(QCoreApplication::translate("MainWindow", "Export to &PDF", nullptr));
#if QT_CONFIG(shortcut)
        actionExportToPdf->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEnglish->setText(QCoreApplication::translate("MainWindow", "&English", nullptr));
        actionPortuguese->setText(QCoreApplication::translate("MainWindow", "&Portuguese", nullptr));
        actionPlay->setText(QCoreApplication::translate("MainWindow", "&Play/Pause", nullptr));
#if QT_CONFIG(tooltip)
        actionPlay->setToolTip(QCoreApplication::translate("MainWindow", "Play or Pause simulation.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionPlay->setShortcut(QCoreApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRename->setText(QCoreApplication::translate("MainWindow", "&Rename", nullptr));
#if QT_CONFIG(shortcut)
        actionRename->setShortcut(QCoreApplication::translate("MainWindow", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
        actionChangeTrigger->setText(QCoreApplication::translate("MainWindow", "Cha&nge Trigger", nullptr));
#if QT_CONFIG(shortcut)
        actionChangeTrigger->setShortcut(QCoreApplication::translate("MainWindow", "F3", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClearSelection->setText(QCoreApplication::translate("MainWindow", "Cl&ear selection", nullptr));
#if QT_CONFIG(shortcut)
        actionClearSelection->setShortcut(QCoreApplication::translate("MainWindow", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFastMode->setText(QCoreApplication::translate("MainWindow", "&Fast Mode", nullptr));
        actionLightTheme->setText(QCoreApplication::translate("MainWindow", "&Panda Light", nullptr));
        actionDarkTheme->setText(QCoreApplication::translate("MainWindow", "Panda &Dark", nullptr));
        actionWaveform->setText(QCoreApplication::translate("MainWindow", "&Waveform", nullptr));
#if QT_CONFIG(shortcut)
        actionWaveform->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+W", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExportToImage->setText(QCoreApplication::translate("MainWindow", "Export to &Image", nullptr));
#if QT_CONFIG(shortcut)
        actionExportToImage->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFlipHorizontally->setText(QCoreApplication::translate("MainWindow", "&Flip horizontally", nullptr));
#if QT_CONFIG(shortcut)
        actionFlipHorizontally->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFlipVertically->setText(QCoreApplication::translate("MainWindow", "Flip &vertically", nullptr));
        actionFullscreen->setText(QCoreApplication::translate("MainWindow", "F&ullscreen", nullptr));
#if QT_CONFIG(shortcut)
        actionFullscreen->setShortcut(QCoreApplication::translate("MainWindow", "F11", nullptr));
#endif // QT_CONFIG(shortcut)
        actionMute->setText(QCoreApplication::translate("MainWindow", "Mute", nullptr));
#if QT_CONFIG(statustip)
        actionMute->setStatusTip(QCoreApplication::translate("MainWindow", "Mutes and unmutes circuit buzzers", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actionMute->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+M", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLabelsUnderIcons->setText(QCoreApplication::translate("MainWindow", "Labels under icons", nullptr));
        actionAboutThisVersion->setText(QCoreApplication::translate("MainWindow", "About this version", nullptr));
        actionRestart->setText(QCoreApplication::translate("MainWindow", "&Restart", nullptr));
#if QT_CONFIG(tooltip)
        actionRestart->setToolTip(QCoreApplication::translate("MainWindow", "Restart simulation.", nullptr));
#endif // QT_CONFIG(tooltip)
        tabElements->setTabText(tabElements->indexOf(io), QString());
#if QT_CONFIG(tooltip)
        tabElements->setTabToolTip(tabElements->indexOf(io), QCoreApplication::translate("MainWindow", "Inputs/Outputs", nullptr));
#endif // QT_CONFIG(tooltip)
        tabElements->setTabText(tabElements->indexOf(gates), QString());
#if QT_CONFIG(tooltip)
        tabElements->setTabToolTip(tabElements->indexOf(gates), QCoreApplication::translate("MainWindow", "Gates", nullptr));
#endif // QT_CONFIG(tooltip)
        tabElements->setTabText(tabElements->indexOf(memory), QString());
#if QT_CONFIG(tooltip)
        tabElements->setTabToolTip(tabElements->indexOf(memory), QCoreApplication::translate("MainWindow", "Memory", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonAddIC->setText(QCoreApplication::translate("MainWindow", "Add IC files", nullptr));
        pushButtonRemoveIC->setText(QCoreApplication::translate("MainWindow", "Remove IC", nullptr));
        tabElements->setTabText(tabElements->indexOf(ic), QString());
#if QT_CONFIG(tooltip)
        tabElements->setTabToolTip(tabElements->indexOf(ic), QCoreApplication::translate("MainWindow", "Integrated Circuits", nullptr));
#endif // QT_CONFIG(tooltip)
        tabElements->setTabText(tabElements->indexOf(misc), QString());
#if QT_CONFIG(tooltip)
        tabElements->setTabToolTip(tabElements->indexOf(misc), QCoreApplication::translate("MainWindow", "Miscellaneous", nullptr));
#endif // QT_CONFIG(tooltip)
        tabElements->setTabText(tabElements->indexOf(search), QString());
        label->setText(QCoreApplication::translate("MainWindow", "Search:", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
        menuRecentFiles->setTitle(QCoreApplication::translate("MainWindow", "&Recent files:", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "&Edit", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "&Help", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "&View", nullptr));
        menuTheme->setTitle(QCoreApplication::translate("MainWindow", "&Theme", nullptr));
        menuLanguage->setTitle(QCoreApplication::translate("MainWindow", "&Language", nullptr));
        menuSimulation->setTitle(QCoreApplication::translate("MainWindow", "Sim&ulation", nullptr));
        menuExamples->setTitle(QCoreApplication::translate("MainWindow", "Examples", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
