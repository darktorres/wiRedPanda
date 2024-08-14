/****************************************************************************
** Meta object code from reading C++ file 'scene.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../app/scene.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSceneENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSceneENDCLASS = QtMocHelpers::stringData(
    "Scene",
    "circuitHasChanged",
    "",
    "contextMenuPos",
    "screenPos",
    "QGraphicsItem*",
    "itemAtMouse"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSceneENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[6];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[10];
    char stringdata5[15];
    char stringdata6[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSceneENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSceneENDCLASS_t qt_meta_stringdata_CLASSSceneENDCLASS = {
    {
        QT_MOC_LITERAL(0, 5),  // "Scene"
        QT_MOC_LITERAL(6, 17),  // "circuitHasChanged"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 14),  // "contextMenuPos"
        QT_MOC_LITERAL(40, 9),  // "screenPos"
        QT_MOC_LITERAL(50, 14),  // "QGraphicsItem*"
        QT_MOC_LITERAL(65, 11)   // "itemAtMouse"
    },
    "Scene",
    "circuitHasChanged",
    "",
    "contextMenuPos",
    "screenPos",
    "QGraphicsItem*",
    "itemAtMouse"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSceneENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x06,    1 /* Public */,
       3,    2,   27,    2, 0x06,    2 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint, 0x80000000 | 5,    4,    6,

       0        // eod
};

Q_CONSTINIT const QMetaObject Scene::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_meta_stringdata_CLASSSceneENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSceneENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSceneENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Scene, std::true_type>,
        // method 'circuitHasChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'contextMenuPos'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsItem *, std::false_type>
    >,
    nullptr
} };

void Scene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Scene *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->circuitHasChanged(); break;
        case 1: _t->contextMenuPos((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QGraphicsItem*>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QGraphicsItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Scene::*)();
            if (_t _q_method = &Scene::circuitHasChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Scene::*)(QPoint , QGraphicsItem * );
            if (_t _q_method = &Scene::contextMenuPos; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *Scene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Scene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSceneENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int Scene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Scene::circuitHasChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Scene::contextMenuPos(QPoint _t1, QGraphicsItem * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
