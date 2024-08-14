/****************************************************************************
** Meta object code from reading C++ file 'bewaveddolphin.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../app/bewaveddolphin.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bewaveddolphin.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSignalModelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSignalModelENDCLASS = QtMocHelpers::stringData(
    "SignalModel"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSignalModelENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSignalModelENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSignalModelENDCLASS_t qt_meta_stringdata_CLASSSignalModelENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11)   // "SignalModel"
    },
    "SignalModel"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSignalModelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject SignalModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QStandardItemModel::staticMetaObject>(),
    qt_meta_stringdata_CLASSSignalModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSignalModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSignalModelENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SignalModel, std::true_type>
    >,
    nullptr
} };

void SignalModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *SignalModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SignalModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSignalModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QStandardItemModel::qt_metacast(_clname);
}

int SignalModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStandardItemModel::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSignalDelegateENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSignalDelegateENDCLASS = QtMocHelpers::stringData(
    "SignalDelegate"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSignalDelegateENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSignalDelegateENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSignalDelegateENDCLASS_t qt_meta_stringdata_CLASSSignalDelegateENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14)   // "SignalDelegate"
    },
    "SignalDelegate"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSignalDelegateENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject SignalDelegate::staticMetaObject = { {
    QMetaObject::SuperData::link<QItemDelegate::staticMetaObject>(),
    qt_meta_stringdata_CLASSSignalDelegateENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSignalDelegateENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSignalDelegateENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SignalDelegate, std::true_type>
    >,
    nullptr
} };

void SignalDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *SignalDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SignalDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSignalDelegateENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QItemDelegate::qt_metacast(_clname);
}

int SignalDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QItemDelegate::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSBewavedDolphinENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSBewavedDolphinENDCLASS = QtMocHelpers::stringData(
    "BewavedDolphin"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSBewavedDolphinENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSBewavedDolphinENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSBewavedDolphinENDCLASS_t qt_meta_stringdata_CLASSBewavedDolphinENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14)   // "BewavedDolphin"
    },
    "BewavedDolphin"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSBewavedDolphinENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject BewavedDolphin::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSBewavedDolphinENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSBewavedDolphinENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSBewavedDolphinENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<BewavedDolphin, std::true_type>
    >,
    nullptr
} };

void BewavedDolphin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *BewavedDolphin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BewavedDolphin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSBewavedDolphinENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int BewavedDolphin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
