#include "App.h"

App::App(QObject *parent) : QObject(parent)
{

}

App::~App()
{

}

void App::Run()
{
   qDebug()<<"App";
}
