#include "Fractures.h"

#include <QApplication>
#include "Libs/App/App.h"
#include "Libs/ResourcesEmploy/ResourcesEmploy.h"
#include "Libs/Tray/Tray.h"
#include "Libs/Editor/Editor.h"
#include "Libs/Hook/Hook.h"
#include "Libs/Shortcut/Shortcut.h"
#include "Libs/SocketServer/SocketServer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    App::Instance()->Run();
    ResourcesEmploy::Instance()->Run();
    Tray::Instance()->Run();
    Editor::Instance()->Run();
    Hook::Instance()->Run();
    Shortcut::Instance()->Run();
    SocketServer::Instance()->Run();

    Fractures f;
    f.show();

    return a.exec();
}
