/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WeirdPaint/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[432];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 24), // "on_actionL_piz_triggered"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 24), // "on_actionColor_triggered"
QT_MOC_LITERAL(4, 62, 25), // "on_actionGrosor_triggered"
QT_MOC_LITERAL(5, 88, 27), // "on_actionBorrador_triggered"
QT_MOC_LITERAL(6, 116, 33), // "on_actionGuardar_Imagen_trigg..."
QT_MOC_LITERAL(7, 150, 29), // "on_actionRect_ngulo_triggered"
QT_MOC_LITERAL(8, 180, 32), // "on_actionCargar_Imagen_triggered"
QT_MOC_LITERAL(9, 213, 27), // "on_actionLapicero_triggered"
QT_MOC_LITERAL(10, 241, 30), // "on_actionColorPicker_triggered"
QT_MOC_LITERAL(11, 272, 27), // "on_actionNegativo_triggered"
QT_MOC_LITERAL(12, 300, 45), // "on_actionIntercambio_de_azul_..."
QT_MOC_LITERAL(13, 346, 33), // "on_actionBlanco_y_negro_trigg..."
QT_MOC_LITERAL(14, 380, 25), // "on_actionC_lido_triggered"
QT_MOC_LITERAL(15, 406, 25) // "on_actionFiltro_triggered"

    },
    "MainWindow\0on_actionL_piz_triggered\0"
    "\0on_actionColor_triggered\0"
    "on_actionGrosor_triggered\0"
    "on_actionBorrador_triggered\0"
    "on_actionGuardar_Imagen_triggered\0"
    "on_actionRect_ngulo_triggered\0"
    "on_actionCargar_Imagen_triggered\0"
    "on_actionLapicero_triggered\0"
    "on_actionColorPicker_triggered\0"
    "on_actionNegativo_triggered\0"
    "on_actionIntercambio_de_azul_y_rojo_triggered\0"
    "on_actionBlanco_y_negro_triggered\0"
    "on_actionC_lido_triggered\0"
    "on_actionFiltro_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionL_piz_triggered(); break;
        case 1: _t->on_actionColor_triggered(); break;
        case 2: _t->on_actionGrosor_triggered(); break;
        case 3: _t->on_actionBorrador_triggered(); break;
        case 4: { bool _r = _t->on_actionGuardar_Imagen_triggered();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->on_actionRect_ngulo_triggered(); break;
        case 6: _t->on_actionCargar_Imagen_triggered(); break;
        case 7: _t->on_actionLapicero_triggered(); break;
        case 8: _t->on_actionColorPicker_triggered(); break;
        case 9: _t->on_actionNegativo_triggered(); break;
        case 10: _t->on_actionIntercambio_de_azul_y_rojo_triggered(); break;
        case 11: _t->on_actionBlanco_y_negro_triggered(); break;
        case 12: _t->on_actionC_lido_triggered(); break;
        case 13: _t->on_actionFiltro_triggered(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
