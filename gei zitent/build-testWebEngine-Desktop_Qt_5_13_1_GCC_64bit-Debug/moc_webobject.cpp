/****************************************************************************
** Meta object code from reading C++ file 'webobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../testWebEngine/webobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'webobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WebObject_t {
    QByteArrayData data[13];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WebObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WebObject_t qt_meta_stringdata_WebObject = {
    {
QT_MOC_LITERAL(0, 0, 9), // "WebObject"
QT_MOC_LITERAL(1, 10, 15), // "sig_nameChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 4), // "name"
QT_MOC_LITERAL(4, 32, 14), // "sig_ageChanged"
QT_MOC_LITERAL(5, 47, 3), // "age"
QT_MOC_LITERAL(6, 51, 18), // "SigSendMessageToJS"
QT_MOC_LITERAL(7, 70, 6), // "result"
QT_MOC_LITERAL(8, 77, 10), // "slot_debug"
QT_MOC_LITERAL(9, 88, 3), // "msg"
QT_MOC_LITERAL(10, 92, 13), // "JSSendMessage"
QT_MOC_LITERAL(11, 106, 4), // "user"
QT_MOC_LITERAL(12, 111, 3) // "pwd"

    },
    "WebObject\0sig_nameChanged\0\0name\0"
    "sig_ageChanged\0age\0SigSendMessageToJS\0"
    "result\0slot_debug\0msg\0JSSendMessage\0"
    "user\0pwd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WebObject[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       2,   56, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       6,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   48,    2, 0x0a /* Public */,
      10,    2,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495003,
       5, QMetaType::Int, 0x00495003,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void WebObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WebObject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_nameChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->sig_ageChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->SigSendMessageToJS((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->slot_debug((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->JSSendMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WebObject::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebObject::sig_nameChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WebObject::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebObject::sig_ageChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WebObject::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebObject::SigSendMessageToJS)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<WebObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->m_name; break;
        case 1: *reinterpret_cast< int*>(_v) = _t->m_age; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<WebObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->m_name != *reinterpret_cast< QString*>(_v)) {
                _t->m_name = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->sig_nameChanged(_t->m_name);
            }
            break;
        case 1:
            if (_t->m_age != *reinterpret_cast< int*>(_v)) {
                _t->m_age = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->sig_ageChanged(_t->m_age);
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject WebObject::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_WebObject.data,
    qt_meta_data_WebObject,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WebObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WebObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WebObject.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WebObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void WebObject::sig_nameChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WebObject::sig_ageChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WebObject::SigSendMessageToJS(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
