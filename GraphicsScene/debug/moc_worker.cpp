/****************************************************************************
** Meta object code from reading C++ file 'worker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../server/worker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'worker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Worker_t {
    const uint offsetsAndSize[12];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Worker_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Worker_t qt_meta_stringdata_Worker = {
    {
QT_MOC_LITERAL(0, 6), // "Worker"
QT_MOC_LITERAL(7, 12), // "dataRecieved"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 18), // "clientDisconnected"
QT_MOC_LITERAL(40, 8), // "readData"
QT_MOC_LITERAL(49, 10) // "disconnect"

    },
    "Worker\0dataRecieved\0\0clientDisconnected\0"
    "readData\0disconnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Worker[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,
       3,    0,   41,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   42,    2, 0x08,    4 /* Private */,
       5,    0,   43,    2, 0x08,    5 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Worker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->dataRecieved((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 1: _t->clientDisconnected(); break;
        case 2: _t->readData(); break;
        case 3: _t->disconnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Worker::*)(const QJsonObject & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::dataRecieved)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Worker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::clientDisconnected)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Worker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Worker.offsetsAndSize,
    qt_meta_data_Worker,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Worker_t
, QtPrivate::TypeAndForceComplete<Worker, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Worker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Worker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Worker::dataRecieved(const QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Worker::clientDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
