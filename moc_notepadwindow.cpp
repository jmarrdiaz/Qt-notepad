/****************************************************************************
** Meta object code from reading C++ file 'notepadwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Qt-notepad/notepadwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notepadwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NotepadWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      25,   14,   14,   14, 0x08,
      37,   14,   14,   14, 0x08,
      48,   14,   14,   14, 0x08,
      59,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NotepadWindow[] = {
    "NotepadWindow\0\0alAbrir()\0alGuardar()\0"
    "alFuente()\0alCerrar()\0alAcercade()\0"
};

void NotepadWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NotepadWindow *_t = static_cast<NotepadWindow *>(_o);
        switch (_id) {
        case 0: _t->alAbrir(); break;
        case 1: _t->alGuardar(); break;
        case 2: _t->alFuente(); break;
        case 3: _t->alCerrar(); break;
        case 4: _t->alAcercade(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData NotepadWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NotepadWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_NotepadWindow,
      qt_meta_data_NotepadWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NotepadWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NotepadWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NotepadWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NotepadWindow))
        return static_cast<void*>(const_cast< NotepadWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int NotepadWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
