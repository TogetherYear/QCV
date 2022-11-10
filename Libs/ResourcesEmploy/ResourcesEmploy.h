#pragma once

#include "Templates/Singleton.hpp"
#include <QApplication>

class ResourcesEmploy : public Singleton<ResourcesEmploy>
{

public:
    explicit ResourcesEmploy();
    virtual ~ResourcesEmploy();

public:
    void Run();

    static QString GetResourcesByPath(const QString &path);
};