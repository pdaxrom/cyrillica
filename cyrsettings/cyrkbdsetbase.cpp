/****************************************************************************
** Form implementation generated from reading ui file 'cyrkbdsetbase.ui'
**
** Created: Tue Jul 29 15:35:38 2003
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "cyrkbdsetbase.h"

#include <qcheckbox.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a CyrKbdSetBase which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 */
CyrKbdSetBase::CyrKbdSetBase( QWidget* parent,  const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "CyrKbdSetBase" );
    resize( 441, 290 ); 
    setCaption( tr( "CyrKeyboard" ) );

    CheckBoxBE = new QCheckBox( this, "CheckBoxBE" );
    CheckBoxBE->setGeometry( QRect( 10, 60, 230, 20 ) ); 
    CheckBoxBE->setText( tr( "(BE) Belorussian" ) );

    CheckBoxBG = new QCheckBox( this, "CheckBoxBG" );
    CheckBoxBG->setGeometry( QRect( 10, 90, 230, 20 ) ); 
    CheckBoxBG->setText( tr( "(BG) Bulgarian" ) );

    CheckBoxMK = new QCheckBox( this, "CheckBoxMK" );
    CheckBoxMK->setGeometry( QRect( 10, 120, 230, 20 ) ); 
    CheckBoxMK->setText( tr( "(MK) Macedonian" ) );

    CheckBoxRU = new QCheckBox( this, "CheckBoxRU" );
    CheckBoxRU->setGeometry( QRect( 10, 150, 230, 20 ) ); 
    CheckBoxRU->setText( tr( "(RU) Russian" ) );

    CheckBoxSR = new QCheckBox( this, "CheckBoxSR" );
    CheckBoxSR->setGeometry( QRect( 10, 180, 230, 20 ) ); 
    CheckBoxSR->setText( tr( "(SR) Serbian" ) );

    CheckBoxUK = new QCheckBox( this, "CheckBoxUK" );
    CheckBoxUK->setGeometry( QRect( 10, 210, 230, 20 ) ); 
    CheckBoxUK->setText( tr( "(UK) Ukrainian" ) );

    ButtSave = new QPushButton( this, "ButtSave" );
    ButtSave->setGeometry( QRect( 10, 240, 140, 32 ) ); 
    QFont ButtSave_font(  ButtSave->font() );
    ButtSave_font.setBold( TRUE );
    ButtSave->setFont( ButtSave_font ); 
    ButtSave->setText( tr( "Save" ) );

    TextLabel1 = new QLabel( this, "TextLabel1" );
    TextLabel1->setGeometry( QRect( 10, 20, 380, 20 ) ); 
    QFont TextLabel1_font(  TextLabel1->font() );
    TextLabel1_font.setBold( TRUE );
    TextLabel1->setFont( TextLabel1_font ); 
    TextLabel1->setText( tr( "Choose alternate keymap(s)" ) );

    // signals and slots connections
    connect( ButtSave, SIGNAL( pressed() ), this, SLOT( save_config() ) );

    // tab order
    setTabOrder( CheckBoxBE, CheckBoxBG );
    setTabOrder( CheckBoxBG, CheckBoxMK );
    setTabOrder( CheckBoxMK, CheckBoxRU );
    setTabOrder( CheckBoxRU, CheckBoxSR );
    setTabOrder( CheckBoxSR, CheckBoxUK );
    setTabOrder( CheckBoxUK, ButtSave );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
CyrKbdSetBase::~CyrKbdSetBase()
{
    // no need to delete child widgets, Qt does it all for us
}

/*  
 *  Main event handler. Reimplemented to handle application
 *  font changes
 */
bool CyrKbdSetBase::event( QEvent* ev )
{
    bool ret = QWidget::event( ev ); 
    if ( ev->type() == QEvent::ApplicationFontChange ) {
	QFont ButtSave_font(  ButtSave->font() );
	ButtSave_font.setBold( TRUE );
	ButtSave->setFont( ButtSave_font ); 
	QFont TextLabel1_font(  TextLabel1->font() );
	TextLabel1_font.setBold( TRUE );
	TextLabel1->setFont( TextLabel1_font ); 
    }
    return ret;
}

void CyrKbdSetBase::save_config()
{
    qWarning( "CyrKbdSetBase::save_config(): Not implemented yet!" );
}

