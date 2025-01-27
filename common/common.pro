TEMPLATE = lib
CONFIG += staticlib

TARGET = common

equals(QT_MAJOR_VERSION, 5) : lessThan(QT_MINOR_VERSION, 12) {
    error("Use Qt 5.12 or newer")
}

equals(QT_MAJOR_VERSION, 6) : !versionAtLeast(QT_VERSION, 6.2.0) {
    error("For Qt6 the minimum version is 6.2.0")
}

!qtHaveModule(multimedia) {
    error("QtMultimedia is not installed. Please install with Qt Maintenance Tool or with system repository")
}

# INCLUDEPATH += $$PWD

VERSION = 4.2.0
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

QT += core gui printsupport multimedia widgets svg

CONFIG += c++17 warn_on strict_c strict_c++

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000
DEFINES += QT_MESSAGELOGCONTEXT

wasm {
    QMAKE_LFLAGS += -sASYNCIFY -Os
}

linux {
    MOLD_BIN = $$system(which mold)

    !isEmpty(MOLD_BIN) {
        QMAKE_LFLAGS += -fuse-ld=mold
    }
}

linux-g++ {
    contains(CONFIG, coverage) {
        QMAKE_CXXFLAGS += --coverage
        QMAKE_LFLAGS += --coverage
    }
}

linux-clang {
    contains(CONFIG, MemorySanitizer) {
        QMAKE_CXXFLAGS += -fsanitize=memory -fPIE
        QMAKE_LFLAGS += -fsanitize=memory -fPIE
    }

    contains(CONFIG, UBSan) {
        QMAKE_CXXFLAGS += -fsanitize=undefined,implicit-integer-truncation,implicit-integer-arithmetic-value-change,implicit-conversion,integer,nullability
        QMAKE_LFLAGS += -fsanitize=undefined,implicit-integer-truncation,implicit-integer-arithmetic-value-change,implicit-conversion,integer,nullability
    }

    contains(CONFIG, AddressSanitizer) {
        QMAKE_CXXFLAGS += -fsanitize=address
        QMAKE_LFLAGS += -fsanitize=address
    }

    contains(CONFIG, ThreadSanitizer) {
        QMAKE_CXXFLAGS += -fsanitize=thread
        QMAKE_LFLAGS += -fsanitize=thread
    }
}

unix: QMAKE_RPATHDIR += ${ORIGIN}/lib

linux | macx {
    CCACHE_BIN = $$system(which ccache)
}

win32 {
    !msvc {
        CCACHE_BIN = $$system(where ccache)
    }
}

!isEmpty(CCACHE_BIN) {
    QMAKE_CC = ccache $$QMAKE_CC
    QMAKE_CXX = ccache $$QMAKE_CXX
}

msvc {
    QMAKE_CXXFLAGS_WARN_ON ~= s/-W3/-W4
    QMAKE_CXXFLAGS += /permissive- /external:I $$[QT_INSTALL_PREFIX] /external:W0
    QMAKE_CXXFLAGS_DEBUG += /Ob1
    QMAKE_CXXFLAGS_RELEASE += /GL
    QMAKE_LFLAGS_RELEASE += /LTCG

    PRECOMPILED_HEADER = pch.h
    CONFIG += precompile_header
}

*-g++ {
    QMAKE_CXXFLAGS += -Wno-deprecated-copy -Wno-deprecated-enum-enum-conversion # can be removed after migrating to Qt6
}

*-clang {
    QMAKE_CXXFLAGS += -Wno-deprecated-enum-enum-conversion # can be removed after migrating to Qt6
}

mac {
    CONFIG += sdk_no_version_check
    QMAKE_LFLAGS += -ld_classic
}

MOC_DIR        = build_files/moc
UI_DIR         = build_files/ui
UI_HEADERS_DIR = build_files/ui
UI_SOURCES_DIR = build_files/ui
OBJECTS_DIR    = build_files/obj
RCC_DIR        = build_files/rcc

include(element/element.pri)
include(logicelement/logicelement.pri)

INCLUDEPATH += \
    app \
    arduino \
    element \
    logicelement \
    nodes

SOURCES += \
    application.cpp \
    arduino/codegenerator.cpp \
    bewaveddolphin.cpp \
    clockdialog.cpp \
    commands.cpp \
    common.cpp \
    elementeditor.cpp \
    elementfactory.cpp \
    elementlabel.cpp \
    elementmapping.cpp \
    enums.cpp \
    graphicelement.cpp \
    graphicsview.cpp \
    ic.cpp \
    itemwithid.cpp \
    lengthdialog.cpp \
    logicelement.cpp \
    mainwindow.cpp \
    nodes/qneconnection.cpp \
    nodes/qneport.cpp \
    recentfiles.cpp \
    scene.cpp \
    serialization.cpp \
    settings.cpp \
    simulation.cpp \
    simulationblocker.cpp \
    thememanager.cpp \
    trashbutton.cpp \
    workspace.cpp

HEADERS += \
    application.h \
    arduino/codegenerator.h \
    bewaveddolphin.h \
    clockdialog.h \
    commands.h \
    common.h \
    elementeditor.h \
    elementfactory.h \
    elementlabel.h \
    elementmapping.h \
    enums.h \
    globalproperties.h \
    graphicelement.h \
    graphicelementinput.h \
    graphicsview.h \
    ic.h \
    itemwithid.h \
    lengthdialog.h \
    logicelement.h \
    mainwindow.h \
    nodes/qneconnection.h \
    nodes/qneport.h \
    recentfiles.h \
    scene.h \
    serialization.h \
    settings.h \
    simulation.h \
    simulationblocker.h \
    thememanager.h \
    trashbutton.h \
    workspace.h

FORMS += \
    bewaveddolphin.ui \
    clockdialog.ui \
    elementeditor.ui \
    lengthdialog.ui \
    mainwindow.ui
