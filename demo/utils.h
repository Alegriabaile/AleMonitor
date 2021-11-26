#pragma once
#include <QtCore/QProcess>
#include <Windows.h>

quint64 getProcessID(const QProcess* proc)
{
#ifdef WIN64
    struct _PROCESS_INFORMATION* procinfo = proc->pid();
    return procinfo->dwProcessId;
#else // Linux
    return proc->pid();
#endif // Q_WS_WIN
}