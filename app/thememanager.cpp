// Copyright 2015 - 2025, GIBIS-UNIFESP and the wiRedPanda contributors
// SPDX-License-Identifier: GPL-3.0-or-later

#include "thememanager.h"

#include "settings.h"

#include <QDebug>
#if QT_VERSION >= QT_VERSION_CHECK(6, 8, 0)
#include <QStyleHints>
#endif

ThemeManager::ThemeManager(QObject *parent)
    : QObject(parent)
{
    if (Settings::contains("theme")) {
        m_theme = static_cast<Theme>(Settings::value("theme").toInt());
    }

    m_attributes.setTheme(m_theme);
}

QString ThemeManager::themePath()
{
    return (ThemeManager::theme() == Theme::Light) ? "light" : "dark";
}

Theme ThemeManager::theme()
{
    return instance().m_theme;
}

void ThemeManager::setTheme(const Theme theme)
{
    instance().m_attributes.setTheme(theme);

    if (instance().m_theme == theme) {
        return;
    }

    instance().m_theme = theme;
    Settings::setValue("theme", static_cast<int>(theme));
    emit instance().themeChanged();
}

ThemeAttributes ThemeManager::attributes()
{
    return instance().m_attributes;
}

void ThemeAttributes::setTheme(const Theme theme)
{
    switch (theme) {
    case Theme::Light: {
#if QT_VERSION >= QT_VERSION_CHECK(6, 8, 0)
        qApp->styleHints()->setColorScheme(Qt::ColorScheme::Light);
#endif

        m_sceneBgBrush = QColor(255, 255, 230);
        m_sceneBgDots = QColor(Qt::darkGray);

        m_selectionBrush = QColor(175, 0, 0, 80);
        m_selectionPen = QColor(175, 0, 0, 255);

        m_graphicElementLabelColor = QColor(Qt::black);

        m_connectionInactive = QColor(Qt::darkGreen);
        m_connectionActive = QColor(Qt::green);
        m_connectionSelected = m_selectionPen;

#ifndef Q_OS_MAC
        QPalette lightPalette = m_defaultPalette;
        lightPalette.setColor(QPalette::AlternateBase, QColor(233, 231, 227));

        qApp->setPalette(lightPalette);
#endif

        break;
    }

    case Theme::Dark: {
#if QT_VERSION >= QT_VERSION_CHECK(6, 8, 0)
        qApp->styleHints()->setColorScheme(Qt::ColorScheme::Dark);
#endif

        m_sceneBgBrush = QColor(64, 69, 82);
        m_sceneBgDots = QColor(Qt::lightGray);

        m_selectionBrush = QColor(230, 255, 85, 150);
        m_selectionPen = QColor(230, 255, 85, 255);

        m_graphicElementLabelColor = QColor(Qt::white);

        m_connectionInactive = QColor(65, 150, 130, 255);
        m_connectionActive = QColor(115, 255, 220, 255);
        m_connectionSelected = m_selectionPen;

#ifndef Q_OS_MAC
        QPalette darkPalette;
        darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::WindowText, Qt::white);
        darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
        darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
        darkPalette.setColor(QPalette::ToolTipText, Qt::white);
        darkPalette.setColor(QPalette::Text, Qt::white);
        darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::ButtonText, Qt::white);
        darkPalette.setColor(QPalette::BrightText, Qt::red);
        darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));

        darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));

        darkPalette.setColor(QPalette::Disabled, QPalette::ButtonText, QColor(120, 120, 120));
        darkPalette.setColor(QPalette::Disabled, QPalette::Base, QColor(120, 120, 120));
        darkPalette.setColor(QPalette::Disabled, QPalette::WindowText, QColor(120, 120, 120));

        qApp->setPalette(darkPalette);
#endif

        break;
    }
    }

#ifndef Q_OS_MAC
    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
#endif

    m_portInvalidBrush = m_connectionInvalid;
    m_portInactiveBrush = m_connectionInactive;
    m_portActiveBrush = m_connectionActive;
    m_portOutputBrush = QColor(243, 83, 105);

    m_portInvalidPen = QColor(Qt::red);
    m_portInactivePen = QColor(Qt::black);
    m_portActivePen = QColor(Qt::black);
    m_portOutputPen = QColor(Qt::darkRed);

    m_portHoverPort = QColor(Qt::yellow);
}
