/****************************************************************************
** KeyboardHandler meta object code from reading C++ file 'keyboardhandler.h'
**
** Created: Thu Jul 31 13:16:55 2003
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.3   edited 2001-10-17 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../keyboardhandler.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *KeyboardHandler::className() const
{
    return "KeyboardHandler";
}

QMetaObject *KeyboardHandler::metaObj = 0;

void KeyboardHandler::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QObject::className(), "QObject") != 0 )
	badSuperclassWarning("KeyboardHandler","QObject");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString KeyboardHandler::tr(const char* s)
{
    return qApp->translate( "KeyboardHandler", s, 0 );
}

QString KeyboardHandler::tr(const char* s, const char * c)
{
    return qApp->translate( "KeyboardHandler", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* KeyboardHandler::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QObject::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (KeyboardHandler::*m1_t0)(const QCString&);
    typedef void (QObject::*om1_t0)(const QCString&);
    m1_t0 v1_0 = &KeyboardHandler::message;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "message(const QCString&)";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Public;
    typedef void (KeyboardHandler::*m2_t0)(ushort,ushort,ushort,bool,bool);
    typedef void (QObject::*om2_t0)(ushort,ushort,ushort,bool,bool);
    m2_t0 v2_0 = &KeyboardHandler::key;
    om2_t0 ov2_0 = (om2_t0)v2_0;
    QMetaData *signal_tbl = QMetaObject::new_metadata(1);
    signal_tbl[0].name = "key(ushort,ushort,ushort,bool,bool)";
    signal_tbl[0].ptr = (QMember)ov2_0;
    metaObj = QMetaObject::new_metaobject(
	"KeyboardHandler", "QObject",
	slot_tbl, 1,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL key
void KeyboardHandler::key( ushort t0, ushort t1, ushort t2, bool t3, bool t4 )
{
    // No builtin function for signal parameter type ushort,ushort,ushort,bool,bool
    QConnectionList *clist = receivers("key(ushort,ushort,ushort,bool,bool)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef void (QObject::*RT1)(ushort);
    typedef void (QObject::*RT2)(ushort,ushort);
    typedef void (QObject::*RT3)(ushort,ushort,ushort);
    typedef void (QObject::*RT4)(ushort,ushort,ushort,bool);
    typedef void (QObject::*RT5)(ushort,ushort,ushort,bool,bool);
    RT0 r0;
    RT1 r1;
    RT2 r2;
    RT3 r3;
    RT4 r4;
    RT5 r5;
    QConnectionListIt it(*clist);
    QConnection   *c;
    QSenderObject *object;
    while ( (c=it.current()) ) {
	++it;
	object = (QSenderObject*)c->object();
	object->setSender( this );
	switch ( c->numArgs() ) {
	    case 0:
#ifdef Q_FP_CCAST_BROKEN
		r0 = reinterpret_cast<RT0>(*(c->member()));
#else
		r0 = (RT0)*(c->member());
#endif
		(object->*r0)();
		break;
	    case 1:
#ifdef Q_FP_CCAST_BROKEN
		r1 = reinterpret_cast<RT1>(*(c->member()));
#else
		r1 = (RT1)*(c->member());
#endif
		(object->*r1)(t0);
		break;
	    case 2:
#ifdef Q_FP_CCAST_BROKEN
		r2 = reinterpret_cast<RT2>(*(c->member()));
#else
		r2 = (RT2)*(c->member());
#endif
		(object->*r2)(t0, t1);
		break;
	    case 3:
#ifdef Q_FP_CCAST_BROKEN
		r3 = reinterpret_cast<RT3>(*(c->member()));
#else
		r3 = (RT3)*(c->member());
#endif
		(object->*r3)(t0, t1, t2);
		break;
	    case 4:
#ifdef Q_FP_CCAST_BROKEN
		r4 = reinterpret_cast<RT4>(*(c->member()));
#else
		r4 = (RT4)*(c->member());
#endif
		(object->*r4)(t0, t1, t2, t3);
		break;
	    case 5:
#ifdef Q_FP_CCAST_BROKEN
		r5 = reinterpret_cast<RT5>(*(c->member()));
#else
		r5 = (RT5)*(c->member());
#endif
		(object->*r5)(t0, t1, t2, t3, t4);
		break;
	}
    }
}
