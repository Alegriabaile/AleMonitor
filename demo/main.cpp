#include <QtCore/QCoreApplication>
#include <QtCore/QProcess>
#include <QtCore/QObject>

#include "ProcessManager.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    QString program("../electron/electron-v16.0.2/electron.exe");
    QStringList arguments;
    ProcessManager process_manager(program, arguments);

    return a.exec();
}
