/****************************************************************************
** Meta object code from reading C++ file 'Tray.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Libs/Tray/Tray.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Tray.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tray_t {
    QByteArrayData data[7];
    char stringdata0[56];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tray_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tray_t qt_meta_stringdata_Tray = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Tray"
QT_MOC_LITERAL(1, 5, 7), // "OnClose"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 7), // "OnClick"
QT_MOC_LITERAL(4, 22, 12), // "OnRightClick"
QT_MOC_LITERAL(5, 35, 9), // "OnDbClick"
QT_MOC_LITERAL(6, 45, 10) // "OnMidClick"

    },
    "Tray\0OnClose\0\0OnClick\0OnRightClick\0"
    "OnDbClick\0OnMidClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tray[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,
       5,    0,   42,    2, 0x06 /* Public */,
       6,    0,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Tray::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Tray *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnClose(); break;
        case 1: _t->OnClick(); break;
        case 2: _t->OnRightClick(); break;
        case 3: _t->OnDbClick(); break;
        case 4: _t->OnMidClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Tray::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tray::OnClose)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Tray::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tray::OnClick)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Tray::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tray::OnRightClick)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Tray::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tray::OnDbClick)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Tray::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tray::OnMidClick)) {
                *result = 4;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Tray::staticMetaObject = { {
    QMetaObject::SuperData::link<QSystemTrayIcon::staticMetaObject>(),
    qt_meta_stringdata_Tray.data,
    qt_meta_data_Tray,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Tray::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tray::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tray.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Singleton<Tray>"))
        return static_cast< Singleton<Tray>*>(this);
    return QSystemTrayIcon::qt_metacast(_clname);
}

int Tray::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSystemTrayIcon::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Tray::OnClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Tray::OnClick()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Tray::OnRightClick()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Tray::OnDbClick()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Tray::OnMidClick()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
