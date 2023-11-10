/****************************************************************************
** Meta object code from reading C++ file 'mygl.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../assignment_package/src/mygl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mygl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyGL_t {
    const uint offsetsAndSize[64];
    char stringdata0[365];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MyGL_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MyGL_t qt_meta_stringdata_MyGL = {
    {
QT_MOC_LITERAL(0, 4), // "MyGL"
QT_MOC_LITERAL(5, 18), // "sig_sendVertexData"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 5), // "Mesh*"
QT_MOC_LITERAL(31, 4), // "mesh"
QT_MOC_LITERAL(36, 16), // "sig_sendFaceData"
QT_MOC_LITERAL(53, 20), // "sig_sendHalfEdgeData"
QT_MOC_LITERAL(74, 13), // "sig_sendJoint"
QT_MOC_LITERAL(88, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(105, 13), // "slot_vertPosX"
QT_MOC_LITERAL(119, 1), // "x"
QT_MOC_LITERAL(121, 13), // "slot_vertPosY"
QT_MOC_LITERAL(135, 1), // "y"
QT_MOC_LITERAL(137, 13), // "slot_vertPosZ"
QT_MOC_LITERAL(151, 1), // "z"
QT_MOC_LITERAL(153, 12), // "slot_faceRed"
QT_MOC_LITERAL(166, 3), // "red"
QT_MOC_LITERAL(170, 14), // "slot_faceGreen"
QT_MOC_LITERAL(185, 5), // "green"
QT_MOC_LITERAL(191, 13), // "slot_faceBlue"
QT_MOC_LITERAL(205, 4), // "blue"
QT_MOC_LITERAL(210, 22), // "slot_setSelectedVertex"
QT_MOC_LITERAL(233, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(250, 1), // "v"
QT_MOC_LITERAL(252, 20), // "slot_setSelectedFace"
QT_MOC_LITERAL(273, 1), // "f"
QT_MOC_LITERAL(275, 24), // "slot_setSelectedHalfEdge"
QT_MOC_LITERAL(300, 2), // "he"
QT_MOC_LITERAL(303, 14), // "slot_importOBJ"
QT_MOC_LITERAL(318, 14), // "slot_subdivide"
QT_MOC_LITERAL(333, 14), // "slot_addvertex"
QT_MOC_LITERAL(348, 16) // "slot_triangulate"

    },
    "MyGL\0sig_sendVertexData\0\0Mesh*\0mesh\0"
    "sig_sendFaceData\0sig_sendHalfEdgeData\0"
    "sig_sendJoint\0QTreeWidgetItem*\0"
    "slot_vertPosX\0x\0slot_vertPosY\0y\0"
    "slot_vertPosZ\0z\0slot_faceRed\0red\0"
    "slot_faceGreen\0green\0slot_faceBlue\0"
    "blue\0slot_setSelectedVertex\0"
    "QListWidgetItem*\0v\0slot_setSelectedFace\0"
    "f\0slot_setSelectedHalfEdge\0he\0"
    "slot_importOBJ\0slot_subdivide\0"
    "slot_addvertex\0slot_triangulate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGL[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  116,    2, 0x06,    1 /* Public */,
       5,    1,  119,    2, 0x06,    3 /* Public */,
       6,    1,  122,    2, 0x06,    5 /* Public */,
       7,    1,  125,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    1,  128,    2, 0x0a,    9 /* Public */,
      11,    1,  131,    2, 0x0a,   11 /* Public */,
      13,    1,  134,    2, 0x0a,   13 /* Public */,
      15,    1,  137,    2, 0x0a,   15 /* Public */,
      17,    1,  140,    2, 0x0a,   17 /* Public */,
      19,    1,  143,    2, 0x0a,   19 /* Public */,
      21,    1,  146,    2, 0x0a,   21 /* Public */,
      24,    1,  149,    2, 0x0a,   23 /* Public */,
      26,    1,  152,    2, 0x0a,   25 /* Public */,
      28,    0,  155,    2, 0x0a,   27 /* Public */,
      29,    0,  156,    2, 0x0a,   28 /* Public */,
      30,    0,  157,    2, 0x0a,   29 /* Public */,
      31,    0,  158,    2, 0x0a,   30 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 8,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Double,   18,
    QMetaType::Void, QMetaType::Double,   20,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, 0x80000000 | 22,   25,
    QMetaType::Void, 0x80000000 | 22,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyGL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyGL *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sig_sendVertexData((*reinterpret_cast< std::add_pointer_t<Mesh*>>(_a[1]))); break;
        case 1: _t->sig_sendFaceData((*reinterpret_cast< std::add_pointer_t<Mesh*>>(_a[1]))); break;
        case 2: _t->sig_sendHalfEdgeData((*reinterpret_cast< std::add_pointer_t<Mesh*>>(_a[1]))); break;
        case 3: _t->sig_sendJoint((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1]))); break;
        case 4: _t->slot_vertPosX((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 5: _t->slot_vertPosY((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 6: _t->slot_vertPosZ((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 7: _t->slot_faceRed((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 8: _t->slot_faceGreen((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 9: _t->slot_faceBlue((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 10: _t->slot_setSelectedVertex((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 11: _t->slot_setSelectedFace((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 12: _t->slot_setSelectedHalfEdge((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 13: _t->slot_importOBJ(); break;
        case 14: _t->slot_subdivide(); break;
        case 15: _t->slot_addvertex(); break;
        case 16: _t->slot_triangulate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyGL::*)(Mesh * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGL::sig_sendVertexData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyGL::*)(Mesh * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGL::sig_sendFaceData)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyGL::*)(Mesh * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGL::sig_sendHalfEdgeData)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyGL::*)(QTreeWidgetItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGL::sig_sendJoint)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject MyGL::staticMetaObject = { {
    QMetaObject::SuperData::link<OpenGLContext::staticMetaObject>(),
    qt_meta_stringdata_MyGL.offsetsAndSize,
    qt_meta_data_MyGL,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MyGL_t
, QtPrivate::TypeAndForceComplete<MyGL, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Mesh *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Mesh *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Mesh *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MyGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGL::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyGL.stringdata0))
        return static_cast<void*>(this);
    return OpenGLContext::qt_metacast(_clname);
}

int MyGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = OpenGLContext::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MyGL::sig_sendVertexData(Mesh * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyGL::sig_sendFaceData(Mesh * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyGL::sig_sendHalfEdgeData(Mesh * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyGL::sig_sendJoint(QTreeWidgetItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
