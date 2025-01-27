include(../config.pri)

QT += testlib

CONFIG += testcase

TARGET = WPanda-test

DEFINES += CURRENTDIR=\"$$_PRO_FILE_PWD_\"

INCLUDEPATH += \
    ../common \
    ../common/arduino \
    ../common/element \
    ../common/logicelement \
    ../common/nodes

debug: LIBS += -L$$OUT_PWD/../common/debug -lcommon
release: LIBS += -L$$OUT_PWD/../common/release -lcommon

SOURCES += \
    testmain.cpp \
    testelements.cpp \
    testfiles.cpp \
    testcommands.cpp \
    testsimulation.cpp \
    testwaveform.cpp \
    testicons.cpp \
    testlogicelements.cpp

HEADERS += \
    ../common/registertypes.h \
    testelements.h \
    testfiles.h \
    testcommands.h \
    testsimulation.h \
    testwaveform.h \
    testicons.h \
    testlogicelements.h

RESOURCES += \
    ../common/resources/basic/basic.qrc \
    ../common/resources/dolphin/dolphin.qrc \
    ../common/resources/input/input.qrc \
    ../common/resources/memory/dark/memory_dark.qrc \
    ../common/resources/memory/light/memory_light.qrc \
    ../common/resources/misc/misc.qrc \
    ../common/resources/output/output.qrc \
    ../common/resources/toolbar/toolbar.qrc \
    ../common/resources/translations/translations.qrc
