/****************************************************************************
** Meta object code from reading C++ file 'Applet.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../applet/Applet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Applet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AdjustableClock__Applet[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      41,   25,   24,   24, 0x09,
     102,   92,   24,   24, 0x29,
     148,   24,   24,   24, 0x09,
     169,   24,   24,   24, 0x09,
     191,   24,   24,   24, 0x09,
     209,   24,   24,   24, 0x09,
     230,   24,   24,   24, 0x09,
     253,  246,   24,   24, 0x09,
     279,   24,   24,   24, 0x09,
     301,   24,   24,   24, 0x09,
     324,   24,   24,   24, 0x09,
     337,   24,   24,   24, 0x09,
     351,   24,   24,   24, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_AdjustableClock__Applet[] = {
    "AdjustableClock::Applet\0\0name,data,force\0"
    "dataUpdated(QString,Plasma::DataEngine::Data,bool)\0"
    "name,data\0dataUpdated(QString,Plasma::DataEngine::Data)\0"
    "clockConfigChanged()\0clockConfigAccepted()\0"
    "copyToClipboard()\0toolTipAboutToShow()\0"
    "toolTipHidden()\0action\0copyToClipboard(QAction*)\0"
    "updateClipboardMenu()\0updateToolTipContent()\0"
    "updateSize()\0updateTheme()\0repaint()\0"
};

void AdjustableClock::Applet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Applet *_t = static_cast<Applet *>(_o);
        switch (_id) {
        case 0: _t->dataUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const Plasma::DataEngine::Data(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->dataUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const Plasma::DataEngine::Data(*)>(_a[2]))); break;
        case 2: _t->clockConfigChanged(); break;
        case 3: _t->clockConfigAccepted(); break;
        case 4: _t->copyToClipboard(); break;
        case 5: _t->toolTipAboutToShow(); break;
        case 6: _t->toolTipHidden(); break;
        case 7: _t->copyToClipboard((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 8: _t->updateClipboardMenu(); break;
        case 9: _t->updateToolTipContent(); break;
        case 10: _t->updateSize(); break;
        case 11: _t->updateTheme(); break;
        case 12: _t->repaint(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AdjustableClock::Applet::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AdjustableClock::Applet::staticMetaObject = {
    { &ClockApplet::staticMetaObject, qt_meta_stringdata_AdjustableClock__Applet,
      qt_meta_data_AdjustableClock__Applet, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AdjustableClock::Applet::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AdjustableClock::Applet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AdjustableClock::Applet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AdjustableClock__Applet))
        return static_cast<void*>(const_cast< Applet*>(this));
    return ClockApplet::qt_metacast(_clname);
}

int AdjustableClock::Applet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ClockApplet::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
