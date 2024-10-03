/****************************************************************************
** Meta object code from reading C++ file 'occupancy_grid_display.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/octomap_rviz_plugins/include/octomap_rviz_plugins/occupancy_grid_display.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'occupancy_grid_display.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_octomap_rviz_plugins__OccupancyGridDisplay_t {
    QByteArrayData data[8];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_octomap_rviz_plugins__OccupancyGridDisplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_octomap_rviz_plugins__OccupancyGridDisplay_t qt_meta_stringdata_octomap_rviz_plugins__OccupancyGridDisplay = {
    {
QT_MOC_LITERAL(0, 0, 42), // "octomap_rviz_plugins::Occupan..."
QT_MOC_LITERAL(1, 43, 15), // "updateTreeDepth"
QT_MOC_LITERAL(2, 59, 0), // ""
QT_MOC_LITERAL(3, 60, 22), // "updateOctreeRenderMode"
QT_MOC_LITERAL(4, 83, 21), // "updateOctreeColorMode"
QT_MOC_LITERAL(5, 105, 11), // "updateAlpha"
QT_MOC_LITERAL(6, 117, 15), // "updateMaxHeight"
QT_MOC_LITERAL(7, 133, 15) // "updateMinHeight"

    },
    "octomap_rviz_plugins::OccupancyGridDisplay\0"
    "updateTreeDepth\0\0updateOctreeRenderMode\0"
    "updateOctreeColorMode\0updateAlpha\0"
    "updateMaxHeight\0updateMinHeight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_octomap_rviz_plugins__OccupancyGridDisplay[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void octomap_rviz_plugins::OccupancyGridDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OccupancyGridDisplay *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateTreeDepth(); break;
        case 1: _t->updateOctreeRenderMode(); break;
        case 2: _t->updateOctreeColorMode(); break;
        case 3: _t->updateAlpha(); break;
        case 4: _t->updateMaxHeight(); break;
        case 5: _t->updateMinHeight(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject octomap_rviz_plugins::OccupancyGridDisplay::staticMetaObject = { {
    QMetaObject::SuperData::link<rviz_common::MessageFilterDisplay<octomap_msgs::msg::Octomap>::staticMetaObject>(),
    qt_meta_stringdata_octomap_rviz_plugins__OccupancyGridDisplay.data,
    qt_meta_data_octomap_rviz_plugins__OccupancyGridDisplay,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *octomap_rviz_plugins::OccupancyGridDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *octomap_rviz_plugins::OccupancyGridDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_octomap_rviz_plugins__OccupancyGridDisplay.stringdata0))
        return static_cast<void*>(this);
    return rviz_common::MessageFilterDisplay<octomap_msgs::msg::Octomap>::qt_metacast(_clname);
}

int octomap_rviz_plugins::OccupancyGridDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = rviz_common::MessageFilterDisplay<octomap_msgs::msg::Octomap>::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
