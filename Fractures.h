#pragma once

#include <QWidget>
#include <QIcon>
#include "Libs/ResourcesEmploy/ResourcesEmploy.h"

class Fractures : public QWidget
{
    Q_OBJECT

public:
    explicit Fractures(QWidget *parent = nullptr);
    virtual ~Fractures();

    void Run();
};
