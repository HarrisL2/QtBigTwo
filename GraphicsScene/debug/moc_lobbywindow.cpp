/****************************************************************************
** Meta object code from reading C++ file 'lobbywindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../client/lobbywindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lobbywindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LobbyWindow_t {
    const uint offsetsAndSize[16];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_LobbyWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_LobbyWindow_t qt_meta_stringdata_LobbyWindow = {
    {
QT_MOC_LITERAL(0, 11), // "LobbyWindow"
QT_MOC_LITERAL(12, 14), // "clientRecieved"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 26), // "on_GameStartButton_clicked"
QT_MOC_LITERAL(55, 26), // "on_IncreasePlayers_clicked"
QT_MOC_LITERAL(82, 26), // "on_DecreasePlayers_clicked"
QT_MOC_LITERAL(109, 21), // "on_IncreaseAI_clicked"
QT_MOC_LITERAL(131, 21) // "on_DecreaseAI_clicked"

    },
    "LobbyWindow\0clientRecieved\0\0"
    "on_GameStartButton_clicked\0"
    "on_IncreasePlayers_clicked\0"
    "on_DecreasePlayers_clicked\0"
    "on_IncreaseAI_clicked\0on_DecreaseAI_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LobbyWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x08,    1 /* Private */,
       3,    0,   53,    2, 0x08,    3 /* Private */,
       4,    0,   54,    2, 0x08,    4 /* Private */,
       5,    0,   55,    2, 0x08,    5 /* Private */,
       6,    0,   56,    2, 0x08,    6 /* Private */,
       7,    0,   57,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LobbyWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LobbyWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->clientRecieved((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 1: _t->on_GameStartButton_clicked(); break;
        case 2: _t->on_IncreasePlayers_clicked(); break;
        case 3: _t->on_DecreasePlayers_clicked(); break;
        case 4: _t->on_IncreaseAI_clicked(); break;
        case 5: _t->on_DecreaseAI_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject LobbyWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_LobbyWindow.offsetsAndSize,
    qt_meta_data_LobbyWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_LobbyWindow_t
, QtPrivate::TypeAndForceComplete<LobbyWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *LobbyWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LobbyWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LobbyWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int LobbyWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
