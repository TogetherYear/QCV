#pragma once

#include <QObject>
#include <QDebug>
#include "Templates/Singleton.hpp"

class App : public QObject,public Singleton<App>
{
    Q_OBJECT
public:
    explicit App(QObject *parent = nullptr);
    virtual ~App();

signals:

public:
    void Run();

};

