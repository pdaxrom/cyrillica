#include <stdio.h>
#include "keyboardhandler.h"
//#include "xmlparser.h"
#include <qpe/global.h>
#include <qlabel.h>
#include <qtextstream.h>
#include <qfile.h>
#include <qpe/config.h>

#include <qnamespace.h>
#include <qpe/qcopenvelope_qws.h>
#include "../config.h"

KeyboardHandler::KeyboardHandler( QObject* parent, const char* name ) : QObject( parent, name ), _input(0),
nlayout(KBD_INIT), flagFn(false), meta_on(0), layoutSwitch(0)
{
  reread();
  _time.start();
}

#if (HKBD_JCUKEN == 1)
#include "keymap_jcuken.h"
#else
#include "keymap.h"
#endif

bool KeyboardHandler::filter(int uu/*unicode*/, int keycode, int modifiers, 
                             bool isPress, bool /*autoRepeat*/) 
{
  if ( !_active )
    return false;

/////////////////////////
//    FILE *of=fopen("/tmp/kbc.txt","a");
//    fprintf(of, "%02X, %02X, %04X, %04X\n", flagFn, modifiers, keycode, uu);
//    fclose(of);
/////////////////////////
  
  bool handled = false;
  if ( isPress ) {

    if (keycode == Qt::Key_Meta) {
	if (meta_on) meta_on = 0;
	else meta_on = isPress;
	return false;
    }

    if (meta_on) meta_on = 0;

#if (SLC700 == 1)
    // check for EURO
    if (flagFn && (keycode == 0x201b)) {
        emit key( 0x20ac, 0, 0, true, false );
        emit key( 0x20ac, 0, 0, false, false );
	_time.restart();
	return true;
    }

    //check for SHIFT
    if (flagFn && (keycode == 0x1020)) {
#ifndef KBD_DEMO
	layoutSwitch = 1;
#endif
    } else {
	if (layoutSwitch) layoutSwitch = 0;
    }
#endif

    if (keycode == 4165) {
        flagFn = true;
	return false;
    } 
    
    if (nlayout > 0) {

      bool match = false;
      ushort unicode = 0;
/////////////////////////
//    FILE *of=fopen("/tmp/kbc.txt","a");
//    fprintf(of, "%02X, %02X, %04X\n", flagFn, modifiers, keycode);
//    fclose(of);
/////////////////////////
      if (flagFn) {
        for (int i = 0; hkeymap_fn[nlayout-1][i].keycode != 0; i++) {
	    if (keycode == hkeymap_fn[nlayout-1][i].keycode) {
		unicode = (modifiers&8)?hkeymap_fn[nlayout-1][i].unicode:hkeymap_fn[nlayout-1][i].bunicode;
		match = true;
		break;
	    }
	}
      } else {
	for (int i = 0; hkeymap[nlayout-1][i].keycode != 0; i++) {
	    if (keycode == hkeymap[nlayout-1][i].keycode) {
		unicode = (modifiers&8)?hkeymap[nlayout-1][i].unicode:hkeymap[nlayout-1][i].bunicode;
		match = true;
		break;
	    }
	}
      }

      if ( match ) {
            emit key( /*replacement[i].unicode()*/unicode, 0, 0, true, false );
            emit key( /*replacement[i].unicode()*/unicode, 0, 0, false, false );
          handled = true; // Dont insert this characters
      }
    }
    _time.restart();
  } else {
    if (keycode == 4165) {
        flagFn = false;
	if (layoutSwitch) {
/////////////////////////
//    FILE *of=fopen("/tmp/kbc.txt","a");
//    fprintf(of, "Switch!\n");
//    fclose(of);
/////////////////////////
	    QCopEnvelope* env = new QCopEnvelope( "CyrInput/Private", "nextKbdLayout()");
	    delete env;
	    layoutSwitch = 0;
	}
    }
//    }
  }
  return handled;
}

void KeyboardHandler::message( const QCString& message )
{
    if ( message == "setusa()" ) nlayout = KBD_USA;
    else if (message == "setrus()" ) nlayout = KBD_RUS;
    else if (message == "setmak()" ) nlayout = KBD_MAK;
    else if (message == "setbel()" ) nlayout = KBD_BEL;
    else if (message == "setblg()" ) nlayout = KBD_BLG;
    else if (message == "setsrb()" ) nlayout = KBD_SRB;
    else if (message == "setukr()" ) nlayout = KBD_UKR;
}

void KeyboardHandler::reread()
{
  _active = true;
  _delay = 1000;
}

