/****************************************************************************
** Meta object code from reading C++ file 'qbearerengine_impl.h'
**
** Created: Sat 5. May 02:40:02 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../qbearerengine_impl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qbearerengine_impl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QBearerEngineImpl[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   19,   18,   18, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_QBearerEngineImpl[] = {
    "QBearerEngineImpl\0\0id,error\0"
    "connectionError(QString,QBearerEngineImpl::ConnectionError)\0"
};

void QBearerEngineImpl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QBearerEngineImpl *_t = static_cast<QBearerEngineImpl *>(_o);
        switch (_id) {
        case 0: _t->connectionError((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QBearerEngineImpl::ConnectionError(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QBearerEngineImpl::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QBearerEngineImpl::staticMetaObject = {
    { &QBearerEngine::staticMetaObject, qt_meta_stringdata_QBearerEngineImpl,
      qt_meta_data_QBearerEngineImpl, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QBearerEngineImpl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QBearerEngineImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QBearerEngineImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QBearerEngineImpl))
        return static_cast<void*>(const_cast< QBearerEngineImpl*>(this));
    return QBearerEngine::qt_metacast(_clname);
}

int QBearerEngineImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QBearerEngine::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QBearerEngineImpl::connectionError(const QString & _t1, QBearerEngineImpl::ConnectionError _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE