cmake_minimum_required(VERSION 3.5)

project(Fractures VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)

set(CMAKE_AUTOMOC ON)

set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(OpenCV_DIR D:/OpenCV/opencv_build_msvc/install/x64/vc16/lib)

find_package(QT
    NAMES
    Qt5
    COMPONENTS
    Widgets
    WebEngineWidgets
    WebChannel
    WebSockets
    Network
    REQUIRED
)

find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
    Widgets
    WebEngineWidgets
    WebChannel
    WebSockets
    Network
    REQUIRED
)

find_package(OpenCV
    REQUIRED
)

include_directories(${OpenCV_INCLUDE_DIRS})

set(ImGui_SOURCES
    ImGui/imconfig.h
    ImGui/imgui.h
    ImGui/imgui.cpp
    ImGui/imgui_demo.cpp
    ImGui/imgui_draw.cpp
    ImGui/imgui_impl_dx11.h
    ImGui/imgui_impl_dx11.cpp
    ImGui/imgui_impl_win32.h
    ImGui/imgui_impl_win32.cpp
    ImGui/imgui_internal.h
    ImGui/imgui_tables.cpp
    ImGui/imgui_widgets.cpp
    ImGui/imstb_rectpack.h
    ImGui/imstb_textedit.h
    ImGui/imstb_truetype.h
)

set(PROJECT_SOURCES
    main.cpp
    Fractures.h
    Fractures.cpp
    Libs/App/App.h
    Libs/App/App.cpp
    Libs/Hook/Hook.h
    Libs/Hook/Hook.cpp
    Libs/Shortcut/Shortcut.h
    Libs/Shortcut/Shortcut.cpp
    Libs/SocketServer/SocketServer.h
    Libs/SocketServer/SocketServer.cpp
    Libs/Tray/Tray.h
    Libs/Tray/Tray.cpp
    Libs/Editor/Editor.h
    Libs/Editor/Editor.cpp
    Libs/ResourcesEmploy/ResourcesEmploy.h
    Libs/ResourcesEmploy/ResourcesEmploy.cpp
    Templates/Singleton.hpp
)

add_executable(Fractures

    # WIN32
    app.rc
    ${ImGui_SOURCES}
    ${PROJECT_SOURCES}
)

target_link_libraries(Fractures
    PRIVATE
    User32
    ${OpenCV_LIBS}
    d3d11.lib
    d3dcompiler.lib
    dxgi.lib
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::WebEngineWidgets
    Qt${QT_VERSION_MAJOR}::WebChannel
    Qt${QT_VERSION_MAJOR}::WebSockets
    Qt${QT_VERSION_MAJOR}::Network
)
