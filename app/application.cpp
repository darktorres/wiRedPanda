#include "application.h"

#include <QMessageBox>
#include "../thirdparty/sentry/include/sentry.h"

Application::Application(int &argc, char **argv)
    : QApplication(argc, argv)
{
}

bool Application::notify(QObject *receiver, QEvent *event)
{
    bool done = false;

    try {
        done = QApplication::notify(receiver, event);
    } catch (const std::exception &e) {
        QMessageBox::critical(mainWindow(), tr("Error!"), e.what());
        // sentry_capture_event(sentry_value_new_message_event(
        //     /*   level */ SENTRY_LEVEL_ERROR,
        //     /*  logger */ "custom",
        //     /* message */ e.what()
        //     ));
        sentry_value_t event_ = sentry_value_new_event();
        sentry_value_t exc = sentry_value_new_exception("Exception", e.what());
        sentry_value_set_stacktrace(exc, NULL, 0);
        sentry_event_add_exception(event_, exc);
        sentry_capture_event(event_);
    }

    return done;
}

MainWindow *Application::mainWindow() const
{
    return m_mainWindow;
}

void Application::setMainWindow(MainWindow *mainWindow)
{
    m_mainWindow = mainWindow;
}
