#include "cyrkbdset.h"
#include <qpushbutton.h>

#include <qpe/qpeapplication.h>

#include <qlistbox.h>
#include <qpushbutton.h>
#include <qlayout.h>

#include <qcheckbox.h>

#include <qpe/config.h>

#include <qpe/qcopenvelope_qws.h>
#include <qcopchannel_qws.h>


/* 
 *  Constructs a MobileMsg which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 */
CyrKbdSet::CyrKbdSet( QWidget* parent,  const char* name, WFlags fl )
    : CyrKbdSetBase( parent, name, fl )
{
    Config cfg("cyrkbd");
    cfg.setGroup("Keymaps");
    CheckBoxRU->setChecked(cfg.readNumEntry("RU",0));
    CheckBoxMK->setChecked(cfg.readNumEntry("MK",0));
    CheckBoxBE->setChecked(cfg.readNumEntry("BE",0));
    CheckBoxBG->setChecked(cfg.readNumEntry("BG",0));
    CheckBoxSR->setChecked(cfg.readNumEntry("SR",0));
    CheckBoxUK->setChecked(cfg.readNumEntry("UK",0));
}

/*  
 *  Destroys the object and frees any allocated resources
 */
CyrKbdSet::~CyrKbdSet()
{
    // no need to delete child widgets, Qt does it all for us
    QCopEnvelope* env = new QCopEnvelope( "CyrInput/Private", "reload()");
    delete env;
}

/*
 *  A simple slot... not very interesting.
 */
void CyrKbdSet::goodBye()
{
    close();
}

void CyrKbdSet::save_config()
{
    Config cfg("cyrkbd");
    cfg.setGroup("Keymaps");
    cfg.writeEntry("RU",CheckBoxRU->isChecked());
    cfg.writeEntry("MK",CheckBoxMK->isChecked());
    cfg.writeEntry("BE",CheckBoxBE->isChecked());
    cfg.writeEntry("BG",CheckBoxBG->isChecked());
    cfg.writeEntry("SR",CheckBoxSR->isChecked());
    cfg.writeEntry("UK",CheckBoxUK->isChecked());
}
