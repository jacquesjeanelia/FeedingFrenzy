/****************************************************************************
** Meta object code from reading C++ file 'player.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Feeding Frenzy/player.h"
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
#error "The header file 'player.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSplayerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSplayerENDCLASS = QtMocHelpers::stringData(
    "player",
    "over",
    "",
    "win",
    "lose",
    "createEnemy",
    "keyPressEvent",
    "QKeyEvent*",
    "event"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSplayerENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[7];
    char stringdata1[5];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[5];
    char stringdata5[12];
    char stringdata6[14];
    char stringdata7[11];
    char stringdata8[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSplayerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSplayerENDCLASS_t qt_meta_stringdata_CLASSplayerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "player"
        QT_MOC_LITERAL(7, 4),  // "over"
        QT_MOC_LITERAL(12, 0),  // ""
        QT_MOC_LITERAL(13, 3),  // "win"
        QT_MOC_LITERAL(17, 4),  // "lose"
        QT_MOC_LITERAL(22, 11),  // "createEnemy"
        QT_MOC_LITERAL(34, 13),  // "keyPressEvent"
        QT_MOC_LITERAL(48, 10),  // "QKeyEvent*"
        QT_MOC_LITERAL(59, 5)   // "event"
    },
    "player",
    "over",
    "",
    "win",
    "lose",
    "createEnemy",
    "keyPressEvent",
    "QKeyEvent*",
    "event"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSplayerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    1 /* Public */,
       3,    0,   45,    2, 0x06,    2 /* Public */,
       4,    0,   46,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   47,    2, 0x0a,    4 /* Public */,
       6,    1,   48,    2, 0x0a,    5 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject player::staticMetaObject = { {
    QMetaObject::SuperData::link<seaCreature::staticMetaObject>(),
    qt_meta_stringdata_CLASSplayerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSplayerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSplayerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<player, std::true_type>,
        // method 'over'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'win'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'lose'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createEnemy'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'keyPressEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QKeyEvent *, std::false_type>
    >,
    nullptr
} };

void player::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<player *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->over(); break;
        case 1: _t->win(); break;
        case 2: _t->lose(); break;
        case 3: _t->createEnemy(); break;
        case 4: _t->keyPressEvent((*reinterpret_cast< std::add_pointer_t<QKeyEvent*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (player::*)();
            if (_t _q_method = &player::over; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (player::*)();
            if (_t _q_method = &player::win; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (player::*)();
            if (_t _q_method = &player::lose; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *player::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *player::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSplayerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return seaCreature::qt_metacast(_clname);
}

int player::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = seaCreature::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void player::over()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void player::win()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void player::lose()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
