#include "Shortcut.h"

Shortcut::Shortcut(QObject *parent) : QObject(parent)
{
}

Shortcut::~Shortcut()
{
}

void Shortcut::Run()
{
    ListenEvents();
}

void Shortcut::ListenEvents()
{
    connect(Hook::Instance(), &Hook::OnKeyTrigger, this, &Shortcut::Define);
}

void Shortcut::Define(KeyType type, const QString &key)
{
    SetControllerCommand(type, key);
    TriggerShortcut(type, key);
}

void Shortcut::SetControllerCommand(KeyType type, const QString &key)
{
    if (key == "Ctrl")
    {
        ctrl = type == KeyType::PRESS;
    }
    else if (key == "Alt")
    {
        alt = type == KeyType::PRESS;
    }
    else if (key == "Shift")
    {
        shift = type == KeyType::PRESS;
    }
    else if (key == "Win")
    {
        win = type == KeyType::PRESS;
    }
}

void Shortcut::TriggerShortcut(KeyType type, const QString &key)
{
    if (type == KeyType::REALEASE)
    {
        if (key == "Down" && ctrl)
        {
            emit OnYourShortcut();
        }
    }
}