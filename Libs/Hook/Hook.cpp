#include "Hook.h"

Hook::Hook()
{
}

Hook::~Hook()
{
}

void Hook::Run()
{
    ListenEvents();
    InstallHook();
}

void Hook::ListenEvents()
{
    connect(Tray::Instance(), &Tray::OnClose, this, &Hook::Close);
}

void Hook::Close()
{
    UnInstallHook();
}

LRESULT CALLBACK Hook::KeyProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    KBDLLHOOKSTRUCT *pkbhs = (KBDLLHOOKSTRUCT *)lParam;
    if (wParam == WM_KEYUP)
    {
        Hook::Instance()->KeyTrigger(KeyType::REALEASE, pkbhs);
    }
    else if (wParam == WM_KEYDOWN)
    {
        Hook::Instance()->KeyTrigger(KeyType::PRESS, pkbhs);
    }
    else
    {
        Hook::Instance()->KeyTrigger(KeyType::UNKNOWN, pkbhs);
    }
    return CallNextHookEx(Hook::Instance()->keyHook, nCode, wParam, lParam);
}

LRESULT CALLBACK Hook::MouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    MSLLHOOKSTRUCT *pmshs = (MSLLHOOKSTRUCT *)lParam;
    if (wParam == WM_LBUTTONDOWN)
    {
        Hook::Instance()->MouseTrigger(MouseType::LEFTDOWN, pmshs);
    }
    else if (wParam == WM_LBUTTONUP)
    {
        Hook::Instance()->MouseTrigger(MouseType::LEFTUP, pmshs);
    }
    else if (wParam == WM_MBUTTONDOWN)
    {
        Hook::Instance()->MouseTrigger(MouseType::MIDDOWN, pmshs);
    }
    else if (wParam == WM_MBUTTONUP)
    {
        Hook::Instance()->MouseTrigger(MouseType::MIDUP, pmshs);
    }
    else if (wParam == WM_RBUTTONDOWN)
    {
        Hook::Instance()->MouseTrigger(MouseType::RIGHTDOWN, pmshs);
    }
    else if (wParam == WM_RBUTTONUP)
    {
        Hook::Instance()->MouseTrigger(MouseType::RIGHTUP, pmshs);
    }
    else if (wParam == WM_MOUSEMOVE)
    {
        Hook::Instance()->MouseTrigger(MouseType::MOVE, pmshs);
    }
    else if (wParam == WM_MOUSEWHEEL)
    {
        Hook::Instance()->MouseTrigger(MouseType::WHEEL, pmshs);
    }
    else
    {
        Hook::Instance()->MouseTrigger(MouseType::UNKNOWN, pmshs);
    }
    return CallNextHookEx(Hook::Instance()->mouseHook, nCode, wParam, lParam);
}

void Hook::InstallHook()
{
    keyHook = SetWindowsHookEx(WH_KEYBOARD_LL, Hook::KeyProc, nullptr, 0);
    mouseHook = SetWindowsHookEx(WH_MOUSE_LL, Hook::MouseProc, nullptr, 0);
}

void Hook::UnInstallHook()
{
    UnhookWindowsHookEx(keyHook);
    UnhookWindowsHookEx(mouseHook);
    keyHook = nullptr;
    mouseHook = nullptr;
}

void Hook::KeyTrigger(KeyType type, KBDLLHOOKSTRUCT *pkbhs)
{
    QString r = ConvertKey(pkbhs->vkCode);
    emit OnKeyTrigger(type, r);
}

void Hook::MouseTrigger(MouseType type, MSLLHOOKSTRUCT *pmshs)
{
    QPoint r = type == MouseType::WHEEL ? QPoint(0, (int)pmshs->mouseData > 0 ? 1 : 0) : QPoint(pmshs->pt.x, pmshs->pt.y);
    emit OnMouseTrigger(type, r);
}

QString Hook::ConvertKey(const DWORD &key)
{
    switch (key)
    {
    case 0x30:
        return QString("0");
    case 0x31:
        return QString("1");
    case 0x32:
        return QString("2");
    case 0x33:
        return QString("3");
    case 0x34:
        return QString("4");
    case 0x35:
        return QString("5");
    case 0x36:
        return QString("6");
    case 0x37:
        return QString("7");
    case 0x38:
        return QString("8");
    case 0x39:
        return QString("9");
    case 0x60:
        return QString("0");
    case 0x61:
        return QString("1");
    case 0x62:
        return QString("2");
    case 0x63:
        return QString("3");
    case 0x64:
        return QString("4");
    case 0x65:
        return QString("5");
    case 0x66:
        return QString("6");
    case 0x67:
        return QString("7");
    case 0x68:
        return QString("8");
    case 0x69:
        return QString("9");
    case 0x41:
        return QString("A");
    case 0x42:
        return QString("B");
    case 0x43:
        return QString("C");
    case 0x44:
        return QString("D");
    case 0x45:
        return QString("E");
    case 0x46:
        return QString("F");
    case 0x47:
        return QString("G");
    case 0x48:
        return QString("H");
    case 0x49:
        return QString("I");
    case 0x4A:
        return QString("J");
    case 0x4B:
        return QString("K");
    case 0x4C:
        return QString("L");
    case 0x4D:
        return QString("M");
    case 0x4E:
        return QString("N");
    case 0x4F:
        return QString("O");
    case 0x50:
        return QString("P");
    case 0x51:
        return QString("Q");
    case 0x52:
        return QString("R");
    case 0x53:
        return QString("S");
    case 0x54:
        return QString("T");
    case 0x55:
        return QString("U");
    case 0x56:
        return QString("V");
    case 0x57:
        return QString("W");
    case 0x58:
        return QString("X");
    case 0x59:
        return QString("Y");
    case 0x5A:
        return QString("Z");
    case 0x25:
        return QString("Left");
    case 0x26:
        return QString("Up");
    case 0x27:
        return QString("Right");
    case 0x28:
        return QString("Down");
    case 0x09:
        return QString("Tab");
    case 0x0D:
        return QString("Enter");
    case 0x20:
        return QString("Space");
    case 0x1B:
        return QString("Esc");
    case 0x14:
        return QString("Caps");
    case 0x08:
        return QString("Back");
    case 0x70:
        return QString("F1");
    case 0x71:
        return QString("F2");
    case 0x72:
        return QString("F3");
    case 0x73:
        return QString("F4");
    case 0x74:
        return QString("F5");
    case 0x75:
        return QString("F6");
    case 0x76:
        return QString("F7");
    case 0x77:
        return QString("F8");
    case 0x78:
        return QString("F9");
    case 0x79:
        return QString("F10");
    case 0x7A:
        return QString("F11");
    case 0x7B:
        return QString("F12");
    case 0x6A:
        return QString("*");
    case 0x6B:
        return QString("+");
    case 0x90:
        return QString("Num");
    case 0x6F:
        return QString("/");
    case 0x6D:
        return QString("-");
    case 0xBA:
        return QString(";:");
    case 0xBB:
        return QString("=+");
    case 0xBC:
        return QString(",<");
    case 0xBD:
        return QString("-_");
    case 0xBE:
        return QString(".>");
    case 0xBF:
        return QString("/?");
    case 0xC0:
        return QString("`~");
    case 0xDB:
        return QString("[{");
    case 0xDC:
        return QString("\\|");
    case 0xDD:
        return QString("]}");
    case 0xDE:
        return QString("\"'");
    case 0x6E:
        return QString(".");
    case 0x5B:
        return QString("Win");
    case 0x5C:
        return QString("Win");
    case 0xA0:
        return QString("Shift");
    case 0xA1:
        return QString("Shift");
    case 0xA2:
        return QString("Ctrl");
    case 0xA3:
        return QString("Ctrl");
    case 0xA4:
        return QString("Alt");
    case 0xA5:
        return QString("Alt");
    default:
        return QString("UnKnown");
    }
}
