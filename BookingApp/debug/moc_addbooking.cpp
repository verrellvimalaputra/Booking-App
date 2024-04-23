/****************************************************************************
** Meta object code from reading C++ file 'addbooking.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../addbooking.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addbooking.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_AddBooking_t {
    uint offsetsAndSizes[24];
    char stringdata0[11];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[25];
    char stringdata4[8];
    char stringdata5[15];
    char stringdata6[22];
    char stringdata7[38];
    char stringdata8[31];
    char stringdata9[30];
    char stringdata10[26];
    char stringdata11[31];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_AddBooking_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_AddBooking_t qt_meta_stringdata_AddBooking = {
    {
        QT_MOC_LITERAL(0, 10),  // "AddBooking"
        QT_MOC_LITERAL(11, 14),  // "bookingCreated"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 24),  // "std::shared_ptr<Booking>"
        QT_MOC_LITERAL(52, 7),  // "booking"
        QT_MOC_LITERAL(60, 14),  // "addToNewTravel"
        QT_MOC_LITERAL(75, 21),  // "on_buttonBox_accepted"
        QT_MOC_LITERAL(97, 37),  // "on_rentalCarReservationButton..."
        QT_MOC_LITERAL(135, 30),  // "on_flightBookingButton_clicked"
        QT_MOC_LITERAL(166, 29),  // "on_hotelBookingButton_clicked"
        QT_MOC_LITERAL(196, 25),  // "on_addToNewTravel_clicked"
        QT_MOC_LITERAL(222, 30)   // "on_addToSelectedTravel_clicked"
    },
    "AddBooking",
    "bookingCreated",
    "",
    "std::shared_ptr<Booking>",
    "booking",
    "addToNewTravel",
    "on_buttonBox_accepted",
    "on_rentalCarReservationButton_clicked",
    "on_flightBookingButton_clicked",
    "on_hotelBookingButton_clicked",
    "on_addToNewTravel_clicked",
    "on_addToSelectedTravel_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_AddBooking[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   56,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   61,    2, 0x08,    4 /* Private */,
       7,    0,   62,    2, 0x08,    5 /* Private */,
       8,    0,   63,    2, 0x08,    6 /* Private */,
       9,    0,   64,    2, 0x08,    7 /* Private */,
      10,    0,   65,    2, 0x08,    8 /* Private */,
      11,    0,   66,    2, 0x08,    9 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject AddBooking::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_AddBooking.offsetsAndSizes,
    qt_meta_data_AddBooking,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_AddBooking_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AddBooking, std::true_type>,
        // method 'bookingCreated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<Booking>, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_buttonBox_accepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rentalCarReservationButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_flightBookingButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_hotelBookingButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addToNewTravel_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addToSelectedTravel_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void AddBooking::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AddBooking *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->bookingCreated((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<Booking>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 1: _t->on_buttonBox_accepted(); break;
        case 2: _t->on_rentalCarReservationButton_clicked(); break;
        case 3: _t->on_flightBookingButton_clicked(); break;
        case 4: _t->on_hotelBookingButton_clicked(); break;
        case 5: _t->on_addToNewTravel_clicked(); break;
        case 6: _t->on_addToSelectedTravel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AddBooking::*)(std::shared_ptr<Booking> , bool );
            if (_t _q_method = &AddBooking::bookingCreated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *AddBooking::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddBooking::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AddBooking.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AddBooking::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void AddBooking::bookingCreated(std::shared_ptr<Booking> _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
