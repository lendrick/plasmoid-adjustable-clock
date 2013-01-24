/****************************************************************************
** Meta object code from reading C++ file 'PlaceholderDialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../applet/PlaceholderDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PlaceholderDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AdjustableClock__PlaceholderDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      48,   36,   35,   35, 0x05,

 // slots: signature, parameters, type, tag, flags
      75,   35,   35,   35, 0x09,
      88,   35,   35,   35, 0x09,
     110,  104,   35,   35, 0x09,
     133,  104,   35,   35, 0x09,
     167,  157,   35,   35, 0x09,
     198,  186,   35,   35, 0x09,
     235,  219,   35,   35, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_AdjustableClock__PlaceholderDialog[] = {
    "AdjustableClock::PlaceholderDialog\0\0"
    "placeholder\0insertPlaceholder(QString)\0"
    "sendSignal()\0updatePreview()\0index\0"
    "selectPlaceholder(int)\0selectTimezoneMode(int)\0"
    "shortForm\0setShortForm(bool)\0textualForm\0"
    "setTextualForm(bool)\0alternativeForm\0"
    "setAlternativeForm(bool)\0"
};

void AdjustableClock::PlaceholderDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PlaceholderDialog *_t = static_cast<PlaceholderDialog *>(_o);
        switch (_id) {
        case 0: _t->insertPlaceholder((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendSignal(); break;
        case 2: _t->updatePreview(); break;
        case 3: _t->selectPlaceholder((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->selectTimezoneMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setShortForm((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->setTextualForm((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setAlternativeForm((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AdjustableClock::PlaceholderDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AdjustableClock::PlaceholderDialog::staticMetaObject = {
    { &KDialog::staticMetaObject, qt_meta_stringdata_AdjustableClock__PlaceholderDialog,
      qt_meta_data_AdjustableClock__PlaceholderDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AdjustableClock::PlaceholderDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AdjustableClock::PlaceholderDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AdjustableClock::PlaceholderDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AdjustableClock__PlaceholderDialog))
        return static_cast<void*>(const_cast< PlaceholderDialog*>(this));
    return KDialog::qt_metacast(_clname);
}

int AdjustableClock::PlaceholderDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = KDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void AdjustableClock::PlaceholderDialog::insertPlaceholder(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
