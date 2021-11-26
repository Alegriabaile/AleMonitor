#pragma once
#include <QtCore/QProcess>
#include <Windows.h>

quint64 getProcessID(const QProcess* proc)
{
#ifdef WIN64
    struct _PROCESS_INFORMATION* procinfo = proc->pid();
    return procinfo->dwProcessId;
#else
    return proc->pid();
#endif
}