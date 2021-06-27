/****************************************************************************
** Meta object code from reading C++ file 'exec_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../exec_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'exec_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_exec_window_t {
    QByteArrayData data[7];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_exec_window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_exec_window_t qt_meta_stringdata_exec_window = {
    {
QT_MOC_LITERAL(0, 0, 11), // "exec_window"
QT_MOC_LITERAL(1, 12, 20), // "select_schedule_mode"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 4), // "mode"
QT_MOC_LITERAL(4, 39, 12), // "get_job_list"
QT_MOC_LITERAL(5, 52, 13), // "NodeList<Job>"
QT_MOC_LITERAL(6, 66, 12) // "ret_previous"

    },
    "exec_window\0select_schedule_mode\0\0"
    "mode\0get_job_list\0NodeList<Job>\0"
    "ret_previous"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_exec_window[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       4,    1,   32,    2, 0x08 /* Private */,
       6,    0,   35,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,

       0        // eod
};

void exec_window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        exec_window *_t = static_cast<exec_window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->select_schedule_mode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->get_job_list((*reinterpret_cast< NodeList<Job>(*)>(_a[1]))); break;
        case 2: _t->ret_previous(); break;
        default: ;
        }
    }
}

const QMetaObject exec_window::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_exec_window.data,
      qt_meta_data_exec_window,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *exec_window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *exec_window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_exec_window.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int exec_window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
