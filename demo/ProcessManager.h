#pragma once
#include <Qtcore/QObject>
#include <QtCore/QProcess>
#include <QtCore/QSharedPointer>

class ProcessManager :
    public QObject
{
Q_OBJECT
public:
    ProcessManager(const QString &program, const QStringList &arguments);
    virtual ~ProcessManager();

    public slots:
    void started();
    void stateChanged(QProcess::ProcessState newState);
    void finished(int exitCode, QProcess::ExitStatus exitStatus);

private:
    QSharedPointer<QProcess> _process;
    const QString _program;
    const QStringList _arguments;
    quint64 _pid;
};

