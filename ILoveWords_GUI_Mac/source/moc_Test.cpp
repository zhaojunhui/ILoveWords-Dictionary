/****************************************************************************
** Meta object code from reading C++ file 'Test.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ILoveWords 3/Test.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Test.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Test_t {
    QByteArrayData data[7];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Test_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Test_t qt_meta_stringdata_Test = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Test"
QT_MOC_LITERAL(1, 5, 8), // "AnsRight"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 8), // "AnsWrong"
QT_MOC_LITERAL(4, 24, 8), // "NextPage"
QT_MOC_LITERAL(5, 33, 8), // "ExitQuiz"
QT_MOC_LITERAL(6, 42, 10) // "ShowDetail"

    },
    "Test\0AnsRight\0\0AnsWrong\0NextPage\0"
    "ExitQuiz\0ShowDetail"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Test[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,
       5,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Test::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Test *_t = static_cast<Test *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AnsRight(); break;
        case 1: _t->AnsWrong(); break;
        case 2: _t->NextPage(); break;
        case 3: _t->ExitQuiz(); break;
        case 4: _t->ShowDetail(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Test::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Test::AnsRight)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Test::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Test::AnsWrong)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Test::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Test::NextPage)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Test::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Test::ExitQuiz)) {
                *result = 3;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Test::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Test.data,
      qt_meta_data_Test,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Test::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Test::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Test.stringdata0))
        return static_cast<void*>(const_cast< Test*>(this));
    return QWidget::qt_metacast(_clname);
}

int Test::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Test::AnsRight()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Test::AnsWrong()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Test::NextPage()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Test::ExitQuiz()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
