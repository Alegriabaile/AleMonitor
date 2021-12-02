#include <QtCore/QCoreApplication>
#include <QtCore/QProcess>
#include <QtCore/QObject>

#include "ProcessManager.h"
#include "WSServerManager.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    QString program("../electron/electron-v16.0.2-win32-x64/electron.exe");
    QStringList arguments;
    QString electron_res = QString::fromLocal8Bit("C:/Users/ale-ljj/Desktop/–À»§∞Æ∫√/windows/VS2019/AleMonitor/electron/electron-quick-start/");
    arguments.push_back(electron_res);
    ProcessManager process_manager(program, arguments);
    WSServerManager ws_server_manager;

    return a.exec();
}
