TARGET = wiredpanda

TEMPLATE = app

include(../config.pri)
include(install.pri)

win32 {
    QMAKE_TARGET_COMPANY = GIBIS-UNIFESP
    QMAKE_TARGET_PRODUCT = wiRedPanda - Logic Circuit Simulator
    QMAKE_TARGET_DESCRIPTION = wiRedPanda - Logic Circuit Simulator
    QMAKE_TARGET_COPYRIGHT = GIBIS-UNIFESP and the wiRedPanda contributors

    RC_ICONS = ../common/resources/wpanda.ico
}

INCLUDEPATH += \
    ../common \
    ../common/arduino \
    ../common/element \
    ../common/logicelement \
    ../common/nodes

debug: LIBS += -L$$OUT_PWD/../common/debug -lcommon
release: LIBS += -L$$OUT_PWD/../common/release -lcommon

SOURCES += main.cpp

HEADERS += ../common/registertypes.h

DISTFILES += ../common/resources/postinst

TRANSLATIONS += \
    ../common/resources/translations/wpanda_en.ts \
    ../common/resources/translations/wpanda_pt_BR.ts \
    ../common/resources/translations/wpanda_es.ts

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
