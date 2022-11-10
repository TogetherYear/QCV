/****************************************************************************
** Meta object code from reading C++ file 'SocketServer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Libs/SocketServer/SocketServer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SocketServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SocketServer_t {
    QByteArrayData data[8];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SocketServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SocketServer_t qt_meta_stringdata_SocketServer = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SocketServer"
QT_MOC_LITERAL(1, 13, 15), // "OnNewConnection"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 9), // "OnMessage"
QT_MOC_LITERAL(4, 40, 3), // "msg"
QT_MOC_LITERAL(5, 44, 14), // "OnDisconnected"
QT_MOC_LITERAL(6, 59, 7), // "OnClose"
QT_MOC_LITERAL(7, 67, 13) // "OnResetSocket"

    },
    "SocketServer\0OnNewConnection\0\0OnMessage\0"
    "msg\0OnDisconnected\0OnClose\0OnResetSocket"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SocketServer[] = {

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
       3,    1,   40,    2, 0x06 /* Public */,
       5,    0,   43,    2, 0x06 /* Public */,
       6,    0,   44,    2, 0x06 /* Public */,
       7,    0,   45,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SocketServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SocketServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnNewConnection(); break;
        case 1: _t->OnMessage((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 2: _t->OnDisconnected(); break;
        case 3: _t->OnClose(); break;
        case 4: _t->OnResetSocket(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SocketServer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SocketServer::OnNewConnection)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SocketServer::*)(const QJsonObject & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SocketServer::OnMessage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SocketServer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SocketServer::OnDisconnected)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SocketServer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SocketServer::OnClose)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SocketServer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SocketServer::OnResetSocket)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SocketServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SocketServer.data,
    qt_meta_data_SocketServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SocketServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SocketServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SocketServer.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Singleton<SocketServer>"))
        return static_cast< Singleton<SocketServer>*>(this);
    return QObject::qt_metacast(_clname);
}

int SocketServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void SocketServer::OnNewConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SocketServer::OnMessage(const QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SocketServer::OnDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SocketServer::OnClose()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SocketServer::OnResetSocket()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
