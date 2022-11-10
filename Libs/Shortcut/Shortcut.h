#pragma once

#include <QObject>
#include <QDebug>
#include "Libs/Hook/Hook.h"
#include "Templates/Singleton.hpp"

class Shortcut : public QObject, public Singleton<Shortcut>
{
    Q_OBJECT
public:
    explicit Shortcut(QObject *parent = nullptr);
    virtual ~Shortcut();

signals:
    void OnYourShortcut();

public:
    void Run();

private:
    bool ctrl = false;
    bool alt = false;
    bool shift = false;
    bool win = false;
    void ListenEvents();
    void Define(KeyType type, const QString &key);
    void SetControllerCommand(KeyType type, const QString &key);
    void TriggerShortcut(KeyType type, const QString &key);

public:
};
