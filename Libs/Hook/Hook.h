#pragma once

#include <Windows.h>
#include <QObject>
#include <QDebug>
#include <iostream>
#include "Templates/Singleton.hpp"
#include "Libs/Tray/Tray.h"

enum class KeyType
{
    PRESS,
    REALEASE,
    UNKNOWN
};

enum class MouseType
{
    LEFTDOWN,
    LEFTUP,
    MIDDOWN,
    MIDUP,
    RIGHTDOWN,
    RIGHTUP,
    MOVE,
    WHEEL,
    UNKNOWN
};

class Hook : public QObject, public Singleton<Hook>
{
    Q_OBJECT
public:
    Hook();
    virtual ~Hook();

signals:
    void OnKeyTrigger(KeyType type, const QString &key);
    void OnMouseTrigger(MouseType type, const QPoint &point);

public:
    void Run();

    void ListenEvents();
    void Close();

    void KeyTrigger(KeyType type, KBDLLHOOKSTRUCT *pkbhs);
    void MouseTrigger(MouseType type, MSLLHOOKSTRUCT *pmshs);

public:
    static LRESULT CALLBACK KeyProc(int nCode, WPARAM wParam, LPARAM lParam);
    static LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam);

public:
    HHOOK keyHook = nullptr;
    HHOOK mouseHook = nullptr;

    void InstallHook();
    void UnInstallHook();

private:
    QString ConvertKey(const DWORD &key);
};
