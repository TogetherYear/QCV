#include "Fractures.h"

Fractures::Fractures(QWidget *parent)
    : QWidget(parent)
{
    Run();
}

Fractures::~Fractures()
{
}

void Fractures::Run()
{
    setFixedSize(0, 0);
    setWindowIcon(QIcon(ResourcesEmploy::GetResourcesByPath("/Images/icon.ico")));
}
