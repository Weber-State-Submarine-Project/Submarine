/****************************************************************************
** Meta object code from reading C++ file 'occupancy_map_display.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/octomap_rviz_plugins/include/octomap_rviz_plugins/occupancy_map_display.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'occupancy_map_display.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_octomap_rviz_plugins__OccupancyMapDisplay_t {
    QByteArrayData data[10];
    char stringdata0[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_octomap_rviz_plugins__OccupancyMapDisplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_octomap_rviz_plugins__OccupancyMapDisplay_t qt_meta_stringdata_octomap_rviz_plugins__OccupancyMapDisplay = {
    {
QT_MOC_LITERAL(0, 0, 41), // "octomap_rviz_plugins::Occupan..."
QT_MOC_LITERAL(1, 42, 10), // "mapUpdated"
QT_MOC_LITERAL(2, 53, 0), // ""
QT_MOC_LITERAL(3, 54, 7), // "showMap"
QT_MOC_LITERAL(4, 62, 11), // "updateAlpha"
QT_MOC_LITERAL(5, 74, 15), // "updateDrawUnder"
QT_MOC_LITERAL(6, 90, 13), // "updatePalette"
QT_MOC_LITERAL(7, 104, 15), // "updateTreeDepth"
QT_MOC_LITERAL(8, 120, 12), // "transformMap"
QT_MOC_LITERAL(9, 133, 20) // "updateMapUpdateTopic"

    },
    "octomap_rviz_plugins::OccupancyMapDisplay\0"
    "mapUpdated\0\0showMap\0updateAlpha\0"
    "updateDrawUnder\0updatePalette\0"
    "updateTreeDepth\0transformMap\0"
    "updateMapUpdateTopic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_octomap_rviz_plugins__OccupancyMapDisplay[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x09 /* Protected */,
       5,    0,   57,    2, 0x09 /* Protected */,
       6,    0,   58,    2, 0x09 /* Protected */,
       7,    0,   59,    2, 0x09 /* Protected */,
       8,    0,   60,    2, 0x09 /* Protected */,
       9,    0,   61,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void octomap_rviz_plugins::OccupancyMapDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OccupancyMapDisplay *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->mapUpdated(); break;
        case 1: _t->showMap(); break;
        case 2: _t->updateAlpha(); break;
        case 3: _t->updateDrawUnder(); break;
        case 4: _t->updatePalette(); break;
        case 5: _t->updateTreeDepth(); break;
        case 6: _t->transformMap(); break;
        case 7: _t->updateMapUpdateTopic(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OccupancyMapDisplay::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OccupancyMapDisplay::mapUpdated)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject octomap_rviz_plugins::OccupancyMapDisplay::staticMetaObject = { {
    QMetaObject::SuperData::link<rviz_common::MessageFilterDisplay<octomap_msgs::msg::Octomap>::staticMetaObject>(),
    qt_meta_stringdata_octomap_rviz_plugins__OccupancyMapDisplay.data,
    qt_meta_data_octomap_rviz_plugins__OccupancyMapDisplay,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *octomap_rviz_plugins::OccupancyMapDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *octomap_rviz_plugins::OccupancyMapDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_octomap_rviz_plugins__OccupancyMapDisplay.stringdata0))
        return static_cast<void*>(this);
    return rviz_common::MessageFilterDisplay<octomap_msgs::msg::Octomap>::qt_metacast(_clname);
}

int octomap_rviz_plugins::OccupancyMapDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = rviz_common::MessageFilterDisplay<octomap_msgs::msg::Octomap>::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void octomap_rviz_plugins::OccupancyMapDisplay::mapUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
