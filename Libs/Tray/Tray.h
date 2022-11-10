#pragma once

#include <QApplication>
#include <QSystemTrayIcon>
#include <QDebug>
#include <QMenu>
#include <QAction>
#include "Libs/ResourcesEmploy/ResourcesEmploy.h"
#include "Templates/Singleton.hpp"

class Tray : public QSystemTrayIcon, public Singleton<Tray>
{
    Q_OBJECT
public:
    explicit Tray(QObject *parent = nullptr);
    virtual ~Tray();

signals:
    void OnClose();
    void OnClick();
    void OnRightClick();
    void OnDbClick();
    void OnMidClick();

public:
    void Run();
    void Close();

private:
    void CreateTray();
    void TrayActivated(QSystemTrayIcon::ActivationReason reason);

private:
    QMenu *menu;
    QAction *closeA;
    QAction *pauseAction;
    QAction *startAction;
    QAction *preferenceAction;
};
