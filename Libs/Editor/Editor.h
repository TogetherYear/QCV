#pragma once

#include <QThread>
#include <QDebug>

#include "Libs/Tray/Tray.h"

#include "ImGui/imconfig.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx11.h"
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_internal.h"
#include "ImGui/imstb_rectpack.h"
#include "ImGui/imstb_textedit.h"
#include "ImGui/imstb_truetype.h"

#include <tchar.h>
#include <d3d11.h>
#include <Windows.h>
#include <iostream>

#include "Templates/Singleton.hpp"

/**
 * 要新建一个线程 否则会卡着主线程不运行 我这方面知识不行 你自己看情况改
 */
class Editor : public QThread, public Singleton<Editor>
{
    Q_OBJECT
public:
    explicit Editor(QObject *parent = nullptr);
    virtual ~Editor();

signals:

public:
    void Run();
    void ListenEvents();
    void CreateImGui();
    void Close();
    void DrawCustom();

protected:
    /**
     * 自己去查 QThread 我的 Run 和这个重了 还好我是大驼峰 还好
     */
    void run() override;

public:
};