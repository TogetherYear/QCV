#include "ResourcesEmploy.h"

ResourcesEmploy::ResourcesEmploy()
{
}

ResourcesEmploy::~ResourcesEmploy()
{
}

void ResourcesEmploy::Run()
{
}

QString ResourcesEmploy::GetResourcesByPath(const QString &path)
{
    return QString(QCoreApplication::applicationDirPath() + "/Resources/" + path);
}