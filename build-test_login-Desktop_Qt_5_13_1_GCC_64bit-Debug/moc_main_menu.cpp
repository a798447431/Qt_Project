/****************************************************************************
** Meta object code from reading C++ file 'main_menu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../test_login/main_menu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_main_menu_t {
    QByteArrayData data[9];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_main_menu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_main_menu_t qt_meta_stringdata_main_menu = {
    {
QT_MOC_LITERAL(0, 0, 9), // "main_menu"
QT_MOC_LITERAL(1, 10, 28), // "on_btn_mainmenu_help_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 32), // "on_btn_mainmenu_minimize_clicked"
QT_MOC_LITERAL(4, 73, 28), // "on_btn_mainmenu_exit_clicked"
QT_MOC_LITERAL(5, 102, 30), // "on_btn_userinfo_manage_clicked"
QT_MOC_LITERAL(6, 133, 22), // "main_init_system_state"
QT_MOC_LITERAL(7, 156, 16), // "main_timerUpdate"
QT_MOC_LITERAL(8, 173, 16) // "return_main_menu"

    },
    "main_menu\0on_btn_mainmenu_help_clicked\0"
    "\0on_btn_mainmenu_minimize_clicked\0"
    "on_btn_mainmenu_exit_clicked\0"
    "on_btn_userinfo_manage_clicked\0"
    "main_init_system_state\0main_timerUpdate\0"
    "return_main_menu"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_main_menu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void main_menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<main_menu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_mainmenu_help_clicked(); break;
        case 1: _t->on_btn_mainmenu_minimize_clicked(); break;
        case 2: _t->on_btn_mainmenu_exit_clicked(); break;
        case 3: _t->on_btn_userinfo_manage_clicked(); break;
        case 4: _t->main_init_system_state(); break;
        case 5: _t->main_timerUpdate(); break;
        case 6: _t->return_main_menu(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject main_menu::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_main_menu.data,
    qt_meta_data_main_menu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *main_menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *main_menu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_main_menu.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int main_menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
