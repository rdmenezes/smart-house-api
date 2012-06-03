/****************************************************************************
** Meta object code from reading C++ file 'cQServer.h'
**
** Created: Sat 2. Jun 14:41:51 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cQServer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cQServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_cQServer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   10,    9,    9, 0x05,
      42,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      58,    9,    9,    9, 0x08,
      77,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_cQServer[] = {
    "cQServer\0\0responce\0ServerMessage(QString)\0"
    "ServerStarted()\0OnDataFromClient()\0"
    "OnClientConnected()\0"
};

void cQServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        cQServer *_t = static_cast<cQServer *>(_o);
        switch (_id) {
        case 0: _t->ServerMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->ServerStarted(); break;
        case 2: _t->OnDataFromClient(); break;
        case 3: _t->OnClientConnected(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData cQServer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject cQServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cQServer,
      qt_meta_data_cQServer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &cQServer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *cQServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *cQServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_cQServer))
        return static_cast<void*>(const_cast< cQServer*>(this));
    return QObject::qt_metacast(_clname);
}

int cQServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void cQServer::ServerMessage(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void cQServer::ServerStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
