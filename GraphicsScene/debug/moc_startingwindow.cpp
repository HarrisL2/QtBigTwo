/****************************************************************************
** Meta object code from reading C++ file 'startingwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../startingwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'startingwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StartingWindow_t {
    const uint offsetsAndSize[14];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_StartingWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_StartingWindow_t qt_meta_stringdata_StartingWindow = {
    {
QT_MOC_LITERAL(0, 14), // "StartingWindow"
QT_MOC_LITERAL(15, 21), // "on_CreateRoom_clicked"
QT_MOC_LITERAL(37, 0), // ""
QT_MOC_LITERAL(38, 19), // "on_JoinRoom_clicked"
QT_MOC_LITERAL(58, 24), // "on_CreditsButton_clicked"
QT_MOC_LITERAL(83, 14), // "clientRecieved"
QT_MOC_LITERAL(98, 22) // "clientConnectionFailed"

    },
    "StartingWindow\0on_CreateRoom_clicked\0"
    "\0on_JoinRoom_clicked\0on_CreditsButton_clicked\0"
    "clientRecieved\0clientConnectionFailed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StartingWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    1,   47,    2, 0x08,    4 /* Private */,
       6,    0,   50,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void,

       0        // eod
};

void StartingWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StartingWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_CreateRoom_clicked(); break;
        case 1: _t->on_JoinRoom_clicked(); break;
        case 2: _t->on_CreditsButton_clicked(); break;
        case 3: _t->clientRecieved((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 4: _t->clientConnectionFailed(); break;
        default: ;
        }
    }
}

const QMetaObject StartingWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_StartingWindow.offsetsAndSize,
    qt_meta_data_StartingWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_StartingWindow_t
, QtPrivate::TypeAndForceComplete<StartingWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *StartingWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StartingWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StartingWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int StartingWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
