#include "keybshow.h"

#include <qpe/global.h>
#include <qpe/qpeapplication.h>
#include <qpe/config.h>

#include <qmainwindow.h>
#include <qlayout.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qdatetime.h>
#include <qtimer.h>
#include <qpopupmenu.h>
#include <stdlib.h>
#include <qpe/qcopenvelope_qws.h>
#include <qcopchannel_qws.h>
#include "../config.h"

#include <stdio.h>

char *kMsg[] = {
    "setusa()",
    "setrus()",
    "setmak()",
    "setbel()",
    "setblg()",
    "setsrb()",
    "setukr()",
    NULL
};

char *kName[] = {
    "EN",
    "RU",
    "MK",
    "BE",
    "BG",
    "SR",
    "UK",
    NULL
};

KeybShow::KeybShow( QWidget *parent ) : QLabel( parent )
{
    _chanel = new QCopChannel( "CyrInput/Private", this );
    connect( _chanel, SIGNAL( received(const QCString &, const QByteArray &)),
           this, SLOT(message( const QCString& )) );

#if (SLC700 == 1)
    setFont( QFont( "Helvetica", 18, QFont::Normal ) );
#else
    setFont( QFont( "Helvetica", 10, QFont::Normal ) );
#endif
    load_config();
    lang = 0;
    setText("EN");
    QCopEnvelope* env = new QCopEnvelope( "CyrInput/Private", kMsg[0]);
    delete env;
    show();
}

void KeybShow::mouseReleaseEvent( QMouseEvent * )
{
#ifndef KBD_DEMO
    lang++;
    
    if (lang >= nmaps) {
	lang = 0;
    }

    QCopEnvelope* env = new QCopEnvelope( "CyrInput/Private", kMsg[maps[lang]]);
    delete env;
    setText(kName[maps[lang]]);
#endif
}

void KeybShow::message( const QCString& message )
{
    int i = 0;

    if (message == "reload()") {
	load_config();
	lang = 0;
	setText("EN");
        QCopEnvelope* env = new QCopEnvelope( "CyrInput/Private", kMsg[0]);
	delete env;
	return ;
    }

    if (message == "nextKbdLayout()") {
	lang++;
	if (lang >= nmaps) lang = 0;
//FILE *fo=fopen("/tmp/applog.txt","a");
//fprintf(fo, "lang = %d\n", lang);
//fclose(fo);
	QCopEnvelope* env = new QCopEnvelope( "CyrInput/Private", kMsg[maps[lang]]);
	delete env;
	setText(kName[maps[lang]]);
    }

    while (kMsg[i] != NULL) {
	if (message == kMsg[i]) {
	    lang = i;
	    setText(kName[lang]);
	    return;
	}
	i++;
    }
}

void KeybShow::load_config()
{
    int f, i;
    Config cfg("cyrkbd");
    cfg.setGroup("Keymaps");
    
    i=0;
    maps[i++]=0;
    if ((f = cfg.readNumEntry("RU",1)) != 0) {
	maps[i++]=KBD_RUS;
    }
    if ((f = cfg.readNumEntry("MK",0)) != 0) {
	maps[i++]=KBD_MAK;
    }
    if ((f = cfg.readNumEntry("BE",0)) != 0) {
	maps[i++]=KBD_BEL;
    }
    if ((f = cfg.readNumEntry("BG",0)) != 0) {
	maps[i++]=KBD_BLG;
    }
    if ((f = cfg.readNumEntry("SR",0)) != 0) {
	maps[i++]=KBD_SRB;
    }
    if ((f = cfg.readNumEntry("UK",0)) != 0) {
	maps[i++]=KBD_UKR;
    }
    maps[i]=0;
    nmaps = i;

//FILE *fo=fopen("/tmp/applog.txt","a");
//fprintf(fo, "nmap = %d\n", i);
//fclose(fo);

}
