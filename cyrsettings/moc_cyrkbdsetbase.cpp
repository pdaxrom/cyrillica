/****************************************************************************
** CyrKbdSetBase meta object code from reading C++ file 'cyrkbdsetbase.h'
**
** Created: Tue Jul 29 15:35:41 2003
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.3   edited 2001-10-17 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "cyrkbdsetbase.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *CyrKbdSetBase::className() const
{
    return "CyrKbdSetBase";
}

QMetaObject *CyrKbdSetBase::metaObj = 0;

void CyrKbdSetBase::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("CyrKbdSetBase","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString CyrKbdSetBase::tr(const char* s)
{
    return qApp->translate( "CyrKbdSetBase", s, 0 );
}

QString CyrKbdSetBase::tr(const char* s, const char * c)
{
    return qApp->translate( "CyrKbdSetBase", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* CyrKbdSetBase::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (CyrKbdSetBase::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    m1_t0 v1_0 = &CyrKbdSetBase::save_config;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "save_config()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Protected;
    metaObj = QMetaObject::new_metaobject(
	"CyrKbdSetBase", "QWidget",
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
