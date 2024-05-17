/****************************************************************************
** Meta object code from reading C++ file 'level.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Documents/FeedingFrenzy/Feeding Frenzy/level.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'level.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSlevelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSlevelENDCLASS = QtMocHelpers::stringData(
    "level",
    "Play",
    "",
    "Stop"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSlevelENDCLASS_t {
    uint offsetsAndSizes[8];
    char stringdata0[6];
    char stringdata1[5];
    char stringdata2[1];
    char stringdata3[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSlevelENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSlevelENDCLASS_t qt_meta_stringdata_CLASSlevelENDCLASS = {
    {
        QT_MOC_LITERAL(0, 5),  // "level"
        QT_MOC_LITERAL(6, 4),  // "Play"
        QT_MOC_LITERAL(11, 0),  // ""
        QT_MOC_LITERAL(12, 4)   // "Stop"
    },
    "level",
    "Play",
    "",
    "Stop"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSlevelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x0a,    1 /* Public */,
       3,    0,   27,    2, 0x0a,    2 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject level::staticMetaObject = { {
    QMetaObject::SuperData::link<view::staticMetaObject>(),
    qt_meta_stringdata_CLASSlevelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSlevelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSlevelENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<level, std::true_type>,
        // method 'Play'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Stop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void level::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<level *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Play(); break;
        case 1: _t->Stop(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *level::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *level::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSlevelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return view::qt_metacast(_clname);
}

int level::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = view::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
