/****************************************************************************
** KeybShow meta object code from reading C++ file 'keybshow.h'
**
** Created: Thu Jul 31 13:13:14 2003
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.3   edited 2001-10-17 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "keybshow.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *KeybShow::className() const
{
    return "KeybShow";
}

QMetaObject *KeybShow::metaObj = 0;

void KeybShow::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QLabel::className(), "QLabel") != 0 )
	badSuperclassWarning("KeybShow","QLabel");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString KeybShow::tr(const char* s)
{
    return qApp->translate( "KeybShow", s, 0 );
}

QString KeybShow::tr(const char* s, const char * c)
{
    return qApp->translate( "KeybShow", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* KeybShow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QLabel::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (KeybShow::*m1_t0)(const QCString&);
    typedef void (QObject::*om1_t0)(const QCString&);
    m1_t0 v1_0 = &KeybShow::message;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "message(const QCString&)";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"KeybShow", "QLabel",
	slot_tbl, 1,
	0, 0,
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
