#include "ProcessManager.h"
#include <QtCore/QDebug>
#include "utils.h"

ProcessManager::ProcessManager(const QString &program, const QStringList &arguments)
    : QObject(nullptr), 
    _process(new QProcess()),
    _program(program),
    _arguments(arguments),
    _pid(0)
{
    connect(_process.get(), &QProcess::started, this, &ProcessManager::started);
    connect(_process.get(), static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, &ProcessManager::finished);
    //connect(_process.get(), &QProcess::stateChanged, this, &ProcessManager::stateChanged);

    _process->start(_program, _arguments);
}


ProcessManager::~ProcessManager()
{
}

void ProcessManager::started()
{
    QProcess *process = qobject_cast<QProcess*>(sender());
    _pid = getProcessID(process);
    qDebug() << QString(" [ProcessManager] : ") << QString("%1 started: %2").arg(_pid).arg(_program);
}

void ProcessManager::stateChanged(QProcess::ProcessState newState)
{
    qDebug() << QString(" [ProcessManager] : ") << QString("%1 stateChanged: %2.").arg(_pid).arg(newState);
}

void ProcessManager::finished(int exitCode, QProcess::ExitStatus exitStatus)
{
    QString status = exitStatus == QProcess::ExitStatus::NormalExit ? "Normal" : "Crash";
    qDebug() << QString(" [ProcessManager] : ") << QString("%1 finished: exit code %2 %3.").arg(_pid).arg(exitCode).arg(status);
}