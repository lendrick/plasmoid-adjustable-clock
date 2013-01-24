/****************************************************************************
** Meta object code from reading C++ file 'Configuration.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../applet/Configuration.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Configuration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AdjustableClock__Configuration[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      32,   31,   31,   31, 0x05,
      43,   31,   31,   31, 0x05,

 // slots: signature, parameters, type, tag, flags
      56,   31,   31,   31, 0x09,
      63,   31,   31,   31, 0x09,
      72,   31,   31,   31, 0x09,
      88,   31,   31,   31, 0x09,
     105,   31,   31,   31, 0x09,
     137,  125,   31,   31, 0x09,
     170,  164,   31,   31, 0x09,
     209,  195,   31,   31, 0x09,
     224,   31,   31,   31, 0x29,
     235,   31,   31,   31, 0x09,
     249,   31,   31,   31, 0x09,
     269,  263,   31,   31, 0x09,
     292,  288,   31,   31, 0x09,
     308,  288,   31,   31, 0x09,
     326,   31,   31,   31, 0x09,
     342,   31,   31,   31, 0x09,
     357,   31,   31,   31, 0x09,
     376,  371,   31,   31, 0x09,
     405,  400,   31,   31, 0x09,
     435,  429,   31,   31, 0x09,
     453,  371,   31,   31, 0x09,
     474,  400,   31,   31, 0x09,
     502,  497,   31,   31, 0x09,
     524,  515,   31,   31, 0x09,
     554,   31,   31,   31, 0x09,
     569,   31,   31,   31, 0x09,
     589,   31,   31,   31, 0x09,
     607,   31,   31,   31, 0x09,
     623,   31,   31,   31, 0x09,
     651,  646,   31,   31, 0x09,
     678,   31,   31,   31, 0x29,
     688,   31,   31,   31, 0x09,
     700,   31,   31,   31, 0x09,
     715,  712,   31,   31, 0x09,
     729,   31,   31,   31, 0x09,
     741,   31,   31,   31, 0x09,
     759,  755,   31,   31, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_AdjustableClock__Configuration[] = {
    "AdjustableClock::Configuration\0\0"
    "accepted()\0clearCache()\0save()\0modify()\0"
    "enableUpdates()\0disableUpdates()\0"
    "insertPlaceholder()\0placeholder\0"
    "insertPlaceholder(QString)\0index\0"
    "selectTheme(QModelIndex)\0automatically\0"
    "newTheme(bool)\0newTheme()\0deleteTheme()\0"
    "renameTheme()\0theme\0updateTheme(Theme)\0"
    "tab\0updateView(int)\0updateEditor(int)\0"
    "triggerAction()\0fixSelection()\0"
    "selectColor()\0size\0selectFontSize(QString)\0"
    "font\0selectFontFamily(QFont)\0color\0"
    "setColor(QString)\0setFontSize(QString)\0"
    "setFontFamily(QString)\0zoom\0setZoom(int)\0"
    "position\0showEditorContextMenu(QPoint)\0"
    "themeChanged()\0backgroundChanged()\0"
    "richTextChanged()\0sourceChanged()\0"
    "itemSelectionChanged()\0item\0"
    "editRow(QTableWidgetItem*)\0editRow()\0"
    "insertRow()\0deleteRow()\0up\0moveRow(bool)\0"
    "moveRowUp()\0moveRowDown()\0row\0"
    "updateRow(int)\0"
};

void AdjustableClock::Configuration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Configuration *_t = static_cast<Configuration *>(_o);
        switch (_id) {
        case 0: _t->accepted(); break;
        case 1: _t->clearCache(); break;
        case 2: _t->save(); break;
        case 3: _t->modify(); break;
        case 4: _t->enableUpdates(); break;
        case 5: _t->disableUpdates(); break;
        case 6: _t->insertPlaceholder(); break;
        case 7: _t->insertPlaceholder((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->selectTheme((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->newTheme((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->newTheme(); break;
        case 11: _t->deleteTheme(); break;
        case 12: _t->renameTheme(); break;
        case 13: _t->updateTheme((*reinterpret_cast< const Theme(*)>(_a[1]))); break;
        case 14: _t->updateView((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->updateEditor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->triggerAction(); break;
        case 17: _t->fixSelection(); break;
        case 18: _t->selectColor(); break;
        case 19: _t->selectFontSize((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->selectFontFamily((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 21: _t->setColor((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->setFontSize((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 23: _t->setFontFamily((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 24: _t->setZoom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->showEditorContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 26: _t->themeChanged(); break;
        case 27: _t->backgroundChanged(); break;
        case 28: _t->richTextChanged(); break;
        case 29: _t->sourceChanged(); break;
        case 30: _t->itemSelectionChanged(); break;
        case 31: _t->editRow((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 32: _t->editRow(); break;
        case 33: _t->insertRow(); break;
        case 34: _t->deleteRow(); break;
        case 35: _t->moveRow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 36: _t->moveRowUp(); break;
        case 37: _t->moveRowDown(); break;
        case 38: _t->updateRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AdjustableClock::Configuration::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AdjustableClock::Configuration::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AdjustableClock__Configuration,
      qt_meta_data_AdjustableClock__Configuration, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AdjustableClock::Configuration::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AdjustableClock::Configuration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AdjustableClock::Configuration::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AdjustableClock__Configuration))
        return static_cast<void*>(const_cast< Configuration*>(this));
    return QObject::qt_metacast(_clname);
}

int AdjustableClock::Configuration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    }
    return _id;
}

// SIGNAL 0
void AdjustableClock::Configuration::accepted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void AdjustableClock::Configuration::clearCache()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
