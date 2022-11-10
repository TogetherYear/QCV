#include "Tray.h"

Tray::Tray(QObject *parent) : QSystemTrayIcon(parent)
{
}

Tray::~Tray()
{
}

void Tray::Run()
{
    CreateTray();
}

void Tray::Close()
{
    emit OnClose();
    qApp->quit();
}

void Tray::CreateTray()
{
    setIcon(QIcon(ResourcesEmploy::GetResourcesByPath("/Images/icon.ico")));
    setToolTip("Fractures # Together");

    pauseAction = new QAction("Pause");
    pauseAction->setIcon(QIcon(ResourcesEmploy::GetResourcesByPath("/Images/pause.ico")));
    connect(pauseAction, &QAction::triggered, this, [&]() {});

    startAction = new QAction("Start");
    startAction->setIcon(QIcon(ResourcesEmploy::GetResourcesByPath("/Images/start.ico")));
    connect(startAction, &QAction::triggered, this, [&]() {});

    preferenceAction = new QAction("Preference");
    preferenceAction->setIcon(QIcon(ResourcesEmploy::GetResourcesByPath("/Images/preference.ico")));
    connect(this->preferenceAction, &QAction::triggered, this, [&]() {});

    closeA = new QAction(QString("Close"), this);
    closeA->setIcon(QIcon(ResourcesEmploy::GetResourcesByPath("/Images/icon.ico")));
    connect(closeA, &QAction::triggered, this, &Tray::Close);

    menu = new QMenu();

    QString style =
        "QMenu {background:#212121;border: 1px solid #555555;}\
             QMenu::icon {margin:2px 2px 2px 24px;}\
             QMenu::separator {background:#363636;height:1px;border-radius:1px;margin:2px 10px 2px 10px;}\
             QMenu::item {min-width:120px;min-height:24px;line-height:24px;background:#212121;color:#eeeeee;border-radius:1px;padding:2px 2px 2px 18px;margin:2px 3px 2px 3px;}\
             QMenu::item:selected {background:#555555;color:#ffffff;}\
             QMenu::item:pressed {background:#555555;color:#ffffff;}";

    menu->setStyleSheet(style);
    menu->addAction(pauseAction);
    menu->addAction(startAction);
    menu->addAction(preferenceAction);
    menu->addSeparator();
    menu->addAction(closeA);
    setContextMenu(menu);

    connect(this, &Tray::activated, this, &Tray::TrayActivated);
    show();
}

void Tray::TrayActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
    case QSystemTrayIcon::Trigger: //鼠标左键
        emit OnClick();
        break;
    case QSystemTrayIcon::Context: //鼠标右键
        emit OnRightClick();
        break;
    case QSystemTrayIcon::DoubleClick: //鼠标双击
        emit OnDbClick();
        break;
    case QSystemTrayIcon::MiddleClick: //鼠标中键
        emit OnMidClick();
        break;
    default:
        break;
    }
}
