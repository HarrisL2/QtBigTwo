/****************************************************************************
** Meta object code from reading C++ file 'startingwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../startingwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'startingwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StartingWindow_t {
    QByteArrayData data[6];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StartingWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StartingWindow_t qt_meta_stringdata_StartingWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "StartingWindow"
QT_MOC_LITERAL(1, 15, 21), // "on_CreateRoom_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 19), // "on_JoinRoom_clicked"
QT_MOC_LITERAL(4, 58, 14), // "clientRecieved"
QT_MOC_LITERAL(5, 73, 22) // "clientConnectionFailed"

    },
    "StartingWindow\0on_CreateRoom_clicked\0"
    "\0on_JoinRoom_clicked\0clientRecieved\0"
    "clientConnectionFailed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StartingWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    1,   36,    2, 0x08 /* Private */,
       5,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
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
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_CreateRoom_clicked(); break;
        case 1: _t->on_JoinRoom_clicked(); break;
        case 2: _t->clientRecieved((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 3: _t->clientConnectionFailed(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject StartingWindow::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_StartingWindow.data,
    qt_meta_data_StartingWindow,
    qt_static_metacall,
    nullptr,
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
