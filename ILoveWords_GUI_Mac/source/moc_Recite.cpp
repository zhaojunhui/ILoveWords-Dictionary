/****************************************************************************
** Meta object code from reading C++ file 'Recite.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ILoveWords 3/Recite.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Recite.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Recite_t {
    QByteArrayData data[9];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Recite_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Recite_t qt_meta_stringdata_Recite = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Recite"
QT_MOC_LITERAL(1, 7, 5), // "Step0"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 7), // "StepYes"
QT_MOC_LITERAL(4, 22, 6), // "StepNo"
QT_MOC_LITERAL(5, 29, 4), // "Next"
QT_MOC_LITERAL(6, 34, 4), // "Undo"
QT_MOC_LITERAL(7, 39, 11), // "StartRecite"
QT_MOC_LITERAL(8, 51, 13) // "AddToWordBook"

    },
    "Recite\0Step0\0\0StepYes\0StepNo\0Next\0"
    "Undo\0StartRecite\0AddToWordBook"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Recite[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

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

void Recite::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Recite *_t = static_cast<Recite *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Step0(); break;
        case 1: _t->StepYes(); break;
        case 2: _t->StepNo(); break;
        case 3: _t->Next(); break;
        case 4: _t->Undo(); break;
        case 5: _t->StartRecite(); break;
        case 6: _t->AddToWordBook(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Recite::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Recite.data,
      qt_meta_data_Recite,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Recite::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Recite::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Recite.stringdata0))
        return static_cast<void*>(const_cast< Recite*>(this));
    return QWidget::qt_metacast(_clname);
}

int Recite::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
