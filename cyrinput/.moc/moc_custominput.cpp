/****************************************************************************
** CustomInput meta object code from reading C++ file 'custominput.h'
**
** Created: Thu Jul 31 13:16:51 2003
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.3   edited 2001-10-17 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../custominput.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *CustomInput::className() const
{
    return "CustomInput";
}

QMetaObject *CustomInput::metaObj = 0;

void CustomInput::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QObject::className(), "QObject") != 0 )
	badSuperclassWarning("CustomInput","QObject");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString CustomInput::tr(const char* s)
{
    return qApp->translate( "CustomInput", s, 0 );
}

QString CustomInput::tr(const char* s, const char * c)
{
    return qApp->translate( "CustomInput", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* CustomInput::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QObject::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (CustomInput::*m1_t0)(const QCString&);
    typedef void (QObject::*om1_t0)(const QCString&);
    m1_t0 v1_0 = &CustomInput::message;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "message(const QCString&)";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Protected;
    metaObj = QMetaObject::new_metaobject(
	"CustomInput", "QObject",
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
