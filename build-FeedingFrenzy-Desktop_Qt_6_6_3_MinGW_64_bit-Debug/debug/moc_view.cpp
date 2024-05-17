/****************************************************************************
** Meta object code from reading C++ file 'view.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Documents/FeedingFrenzy/Feeding Frenzy/view.h"
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
#error "The header file 'view.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSviewENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSviewENDCLASS = QtMocHelpers::stringData(
    "view",
    "mediaPlay",
    "",
    "mediaStop"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSviewENDCLASS_t {
    uint offsetsAndSizes[8];
    char stringdata0[5];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSviewENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSviewENDCLASS_t qt_meta_stringdata_CLASSviewENDCLASS = {
    {
        QT_MOC_LITERAL(0, 4),  // "view"
        QT_MOC_LITERAL(5, 9),  // "mediaPlay"
        QT_MOC_LITERAL(15, 0),  // ""
        QT_MOC_LITERAL(16, 9)   // "mediaStop"
    },
    "view",
    "mediaPlay",
    "",
    "mediaStop"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSviewENDCLASS[] = {

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

Q_CONSTINIT const QMetaObject view::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_CLASSviewENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSviewENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSviewENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<view, std::true_type>,
        // method 'mediaPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mediaStop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void view::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<view *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->mediaPlay(); break;
        case 1: _t->mediaStop(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *view::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *view::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSviewENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int view::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
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
