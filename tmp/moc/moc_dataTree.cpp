/****************************************************************************
** Meta object code from reading C++ file 'dataTree.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/tree/dataTree.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataTree.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_tree__DataTree_t {
    QByteArrayData data[7];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tree__DataTree_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tree__DataTree_t qt_meta_stringdata_tree__DataTree = {
    {
QT_MOC_LITERAL(0, 0, 14), // "tree::DataTree"
QT_MOC_LITERAL(1, 15, 17), // "signalItemChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 5), // "_item"
QT_MOC_LITERAL(4, 40, 15), // "slotItemClicked"
QT_MOC_LITERAL(5, 56, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(6, 73, 7) // "_column"

    },
    "tree::DataTree\0signalItemChanged\0\0"
    "_item\0slotItemClicked\0QTreeWidgetItem*\0"
    "_column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tree__DataTree[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    3,    6,

       0        // eod
};

void tree::DataTree::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataTree *_t = static_cast<DataTree *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalItemChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->slotItemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DataTree::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataTree::signalItemChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject tree::DataTree::staticMetaObject = {
    { &base::BaseWidget::staticMetaObject, qt_meta_stringdata_tree__DataTree.data,
      qt_meta_data_tree__DataTree,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *tree::DataTree::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tree::DataTree::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_tree__DataTree.stringdata0))
        return static_cast<void*>(this);
    return base::BaseWidget::qt_metacast(_clname);
}

int tree::DataTree::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = base::BaseWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void tree::DataTree::signalItemChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
