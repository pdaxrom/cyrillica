#include <stdio.h>

#include "keyboard.h"

#include <qpe/fontmanager.h>

#include <qpe/global.h>

#include <qwindowsystem_qws.h>
#include <qpainter.h>
#include <qfontmetrics.h>
#include <qtimer.h>
#include <ctype.h>
#include "../config.h"

#define USE_SMALL_BACKSPACE

Keyboard::Keyboard(QWidget* parent, const char* name, WFlags f) :
    QFrame(parent, name, f),  shift(FALSE), lock(FALSE), ctrl(FALSE),
    alt(FALSE), useLargeKeys(TRUE), useOptiKeys(0), nlayout(KBD_INIT),
    pressedKey(-1), unicode(-1), qkeycode(0), modifiers(0)
{
    //  setPalette(QPalette(QColor(240,240,230))); // Beige!
    //  setFont( QFont( "Helvetica", 8 ) );
//    setPalette(QPalette(QColor(200,200,200))); // Gray
    setPalette(QPalette(QColor(220,220,220))); // Gray

#if (SLC700 == 1)
    setFont( QFont( "Helvetica", 18 ) );
#else
    setFont( QFont( "smallsmooth", 9 ) );
#endif
//    picks->setFont( FontManager::unicodeFont( FontManager::Fixed )/*QFont( "helvetica", 9 )*/ ); //FontManager::unicodeFont( FontManager::Fixed )
//    setFont( FontManager::unicodeFont( FontManager::Fixed )/*QFont( "helvetica", 9 )*/ );

    repeatTimer = new QTimer( this );
    connect( repeatTimer, SIGNAL(timeout()), this, SLOT(repeat()) );
}

void Keyboard::resizeEvent(QResizeEvent*)
{
    int ph = 0; //picks->sizeHint().height();
    keyHeight = (height()-ph)/5;
    int nk;
    if ( useOptiKeys ) {
	nk = 15;
    } else if ( useLargeKeys ) {
	nk = 15;
    } else {
	nk = 19;
    }
    defaultKeyWidth = width()/nk;
    xoffs = (width()-defaultKeyWidth*nk)/2;
}

//PC keyboard layout and scancodes

/*
  Format: length, code, length, code, ..., 0
  
  length is measured in half the width of a standard key.
  If code < 0x80 we have length/2 consecutive standard keys,
  starting with scancode code.
  
  Special keys are hardcoded, one at a time, with length of key
  and code >= 0x80, these are NOT standard PC scancodes, but are looked
  up in specialM[]. (The special keys are not keymappable.)
  
 */

static const uchar * const keyboard_opti[5] = { 
    (const uchar *const) "\001\223\003\240\002\20\002\41\002\26\002\62\002\56\002\45\002\54\003\200\001\223\002\226\002\235\002\234\002\236",
    (const uchar *const) "\001\223\003\201\004\207\002\30\002\24\002\43\004\207\003\203\001\223\006\002\002\065",
    (const uchar *const) "\001\223\003\202\002\60\002\37\002\23\002\22\002\36\002\21\002\55\003\203\001\223\006\005\002\055",
    (const uchar *const) "\001\223\003\205\004\207\002\27\002\61\002\40\004\207\003\204\001\223\006\010\002\014",
    (const uchar *const) "\001\223\003\206\002\44\002\31\002\57\002\42\002\46\002\25\002\207\003\204\001\223\002\013\002\064\002\015\002\230"
};


static const uchar * const keyboard_standard[5] = {

#ifdef USE_SMALL_BACKSPACE
    (const uchar *const)"\002\240\002\001\002\002\002\003\002\004\002\005\002\006\002\007\002\010\002\011\002\012\002\013\002\014\002\015\002\200\002\223\002\215\002\216\002\217",
#else
    (const uchar *const)"\002\051\0021\0022\0023\0024\0025\0026\0027\0028\0029\0020\002-\002=\004\200\002\223\002\215\002\216\002\217",
#endif
    //~ + 123...+ BACKSPACE //+ INSERT + HOME + PGUP

    (const uchar *const)"\003\201\002\016\002\017\002\020\002\021\002\022\002\023\002\024\002\025\002\026\002\027\002\030\002\031\002\032\001\224\002\223\002\221\002\220\002\222",
    //TAB + qwerty..  + backslash //+ DEL + END + PGDN

    (const uchar *const)"\004\202\002\033\002\034\002\035\002\036\002\037\002\040\002\041\002\042\002\043\002\044\002\045\004\203",
    //CAPS + asdf.. + RETURN 

    (const uchar *const)"\005\204\002\046\002\047\002\050\002\051\002\052\002\053\002\054\002\055\002\056\002\057\005\204\002\223\002\223\002\211",
    //SHIFT + zxcv... //+ UP

    (const uchar *const)"\003\205\003\206\022\207\003\206\003\205\002\223\002\212\002\213\002\214" 
    //CTRL + ALT + SPACE //+ LEFT + DOWN + RIGHT
    
};

int keymap[][47]={
//keymap_us[] = 
    {
    '`','1','2','3','4','5','6','7','8','9','0','-','=',
    'q','w','e','r','t','y','u','i','o','p','[',']','\\',
    'a','s','d','f','g','h','j','k','l',';','\'',
    'z','x','c','v','b','n','m',',','.','/'
    },
//keymap_ru[] = 
    {
    0x451,'1','2','3','4','5','6','7','8','9','0','-','=',
    0x439,0x446,0x443,0x43a,0x435,0x43d,0x433,0x448,0x449,0x437,0x445,0x44a,'\\',
    0x444,0x44b,0x432,0x430,0x43f,0x440,0x43e,0x43b,0x434,0x436,0x44d,
    0x44f,0x447,0x441,0x43c,0x438,0x442,0x44c,0x431,0x44e,'.'
    },
//keymap_mk[] = 
    {
    '`','1','2','3','4','5','6','7','8','9','0','-','=',
    0x459,0x45a,0x435,0x440,0x442,0x455,0x443,0x438,0x43e,0x43f,0x448,0x453,0x436,
    0x430,0x441,0x434,0x444,0x433,0x445,0x458,0x43a,0x43b,0x447,0x45c,
    0x437,0x45f,0x446,0x432,0x431,0x43d,0x43c,',','.','/'
    },
//keymap_be[] = 
    {
    0x451,'1','2','3','4','5','6','7','8','9','0','-','=',
    0x439,0x446,0x443,0x43a,0x435,0x43d,0x433,0x448,0x45e,0x437,0x445,0x44a,'\\',
    0x444,0x44b,0x432,0x430,0x43f,0x440,0x43e,0x43b,0x434,0x436,0x44d,
    0x44f,0x447,0x441,0x43c,0x456,0x442,0x44c,0x431,0x44e,'.'
    },
//int keymap_bg[] = 
    {
    '`','1','2','3','4','5','6','7','8','9','0','-','.',
    ',',0x443,0x435,0x438,0x448,0x449,0x43a,0x441,0x434,0x437,0x446,';','(',
    0x44c,0x44f,0x430,0x43e,0x436,0x433,0x442,0x43d,0x432,0x43c,0x447,
    0x44e,0x439,0x44a,0x44d,0x444,0x445,0x43f,0x440,0x43b,0x431
    },
//keymap_sr[] = 
    {
    '`','1','2','3','4','5','6','7','8','9','0','\'','+',
    0x459,0x45a,0x435,0x440,0x442,0x437,0x443,0x438,0x43e,0x43f,0x448,0x452,0x436,
    0x430,0x441,0x434,0x444,0x433,0x445,0x458,0x43a,0x43b,0x447,0x45b,
    0x455,0x45f,0x446,0x432,0x431,0x43d,0x43c,',','.','-'
    },
//keymap_uk[] = 
    {
    0x451,'1','2','3','4','5','6','7','8','9','0','-','=',
    0x439,0x446,0x443,0x43a,0x435,0x43d,0x433,0x448,0x449,0x437,0x445,0x457,'\\',
    0x444,0x456,0x432,0x430,0x43f,0x440,0x43e,0x43b,0x434,0x436,0x454,
    0x44f,0x447,0x441,0x43c,0x438,0x442,0x44c,0x431,0x44e,'.'
    },
};



int keymap_shift[][47]={
//keymap_us_shift[] = 
    {
    '~','!','@','#','$','%','^','&','*','(',')','_','+',
    'Q','W','E','R','T','Y','U','I','O','P','{','}','|',
    'A','S','D','F','G','H','J','K','L',':','"',
    'Z','X','C','V','B','N','M','<','>','?'
    },
//keymap_ru_shift[] = 
    {
    0x401,'!','"',0x2116,';','%',':','?','*','(',')','_','+',
    0x419,0x426,0x423,0x41a,0x415,0x41d,0x413,0x428,0x429,0x417,0x425,0x42a,'/',
    0x424,0x42b,0x412,0x410,0x41f,0x420,0x41e,0x41b,0x414,0x416,0x42d,
    0x42f,0x427,0x421,0x41c,0x418,0x422,0x42c,0x411,0x42e,','
    },
//keymap_mk_shift[] = 
    {
    '~','!',0x201e,0x201c,0x2019,'%',0x2018,'&','*','(',')','_','+',
    0x409,0x40a,0x415,0x420,0x422,0x405,0x423,0x418,0x41e,0x41f,0x428,0x403,0x416,
    0x410,0x421,0x414,0x424,0x413,0x425,0x408,0x41a,0x41b,0x427,0x40c,
    0x417,0x40f,0x426,0x412,0x411,0x41d,0x41c,';',':','?'
    },
//keymap_be_shift[] = 
    {
    0x401,'!','"',0x2116,';','%',':','?','*','(',')','_','+',
    0x419,0x426,0x423,0x41a,0x415,0x41d,0x413,0x428,0x40e,0x417,0x425,0x42a,'/',
    0x424,0x42b,0x412,0x410,0x41f,0x420,0x41e,0x41b,0x414,0x416,0x42d,
    0x42f,0x427,0x421,0x41c,0x406,0x422,0x42c,0x411,0x42e,','
    },
//keymap_bg_shift[] = 
    {
    '~','!','?','+','"','%','=',':','/','_',0x2116,0x406,'V',
    0x44b,0x423,0x415,0x418,0x428,0x429,0x41a,0x421,0x414,0x417,0x426,0xa7,')',
    0x42c,0x42f,0x410,0x41e,0x416,0x413,0x422,0x41d,0x412,0x41c,0x427,
    0x42e,0x419,0x42a,0x42d,0x424,0x425,0x41f,0x420,0x41b,0x411
    },
//keymap_sr_shift[] = 
    {
    '~','!','"','#','$','%','&','/','(',')','=','?','*',
    0x409,0x40a,0x415,0x420,0x422,0x417,0x423,0x418,0x41e,0x41f,0x428,0x402,0x416,
    0x410,0x421,0x414,0x424,0x413,0x425,0x408,0x41a,0x41b,0x427,0x40b,
    0x405,0x40f,0x426,0x412,0x411,0x41d,0x41c,';',':','_'
    },
//keymap_uk_shift[] = 
    {
    0x401,'!','"',0x2116,';','%',':','?','*','(',')','_','+',
    0x419,0x426,0x423,0x41a,0x415,0x41d,0x413,0x428,0x429,0x417,0x425,0x407,'/',
    0x424,0x406,0x412,0x410,0x41f,0x420,0x41e,0x41b,0x414,0x416,0x404,
    0x42f,0x427,0x421,0x41c,0x418,0x422,0x42c,0x411,0x42e,','
    },
};

/* XPM */
static const char * const uparrow_xpm[]={
"9 9 2 1",
"a c #000000",
". c None",
".........",
"....a....",
"...aaa...",
"..aaaaa..",
"....a....",
"....a....",
"....a....",
"....a....",
"........."};
/* XPM */
static const char * const leftarrow_xpm[]={
"9 9 2 1",
"a c #000000",
". c None",
".........",
".........",
"...a.....",
"..aa.....",
".aaaaaaa.",
"..aa.....",
"...a.....",
".........",
"........."};
/* XPM */
static const char * const downarrow_xpm[]={
"9 9 2 1",
"a c #000000",
". c None",
".........",
"....a....",
"....a....",
"....a....",
"....a....",
"..aaaaa..",
"...aaa...",
"....a....",
"........."};
/* XPM */
static const char * const rightarrow_xpm[]={
"9 9 2 1",
"a c #000000",
". c None",
".........",
".........",
".....a...",
".....aa..",
".aaaaaaa.",
".....aa..",
".....a...",
".........",
"........."};
/* XPM */
static const char * const insert_xpm[]={
"9 9 2 1",
"a c #000000",
". c None",
".........",
"a........",
"a.aaa.aaa",
"a.a.a.a..",
"a.a.a..a.",
"a.a.a...a",
"a.a.a.aaa",
".........",
"........."};
/* XPM */
static const char * const delete_xpm[]={
"9 9 2 1",
"a c #000000",
". c None",
".........",
"aa......a",
"a.a.aaa.a",
"a.a.a.a.a",
"a.a.aaa.a.",
"a.a.a...a",
"aaa.aaa.a",
".........",
"........."};
/* XPM */
static const char * const home_xpm[]={
"9 9 2 1",
"a c #000000",
". c None",
"....a....",
"...a.a...",
"..a...a..",
".a.....a.",
"aa.aaa.aa",
".a.a.a.a.",
".a.a.a.a.",
".aaaaaaa.",
"........."};
/* XPM */
static const char * const end_xpm[]={
"10 9 2 1",
"a c #000000",
". c None",
"..........",
"aa.......a",
"a..aaa.aaa",
"aa.a.a.a.a",
"a..a.a.a.a",
"a..a.a.a.a",
"aa.a.a.aaa",
"..........",
".........."};
/* XPM */
static const char * const pageup_xpm[]={
"9 9 2 1",
"a c #000000",
". c None",
".aaa.aaa.",
".a.a.a.a.",
".aaa..aa.",
".a...aaa.",
".........",
".a.a.aaa.",
".a.a.a.a.",
".aaa.aaa.",
".....a..."};
/* XPM */
static const char * const pagedown_xpm[]={
"9 9 2 1",
"a c #000000",
". c None",
".aaa.aaa.",
".a.a.a.a.",
".aaa..aa.",
".a...aaa.",
".........",
"...a.....",
".aaa.aaa.",
".a.a.a.a.",
".aaa.a.a."};
/* XPM */
static const char * const expand_xpm[]={
"4 9 2 1",
"a c #408040",
". c None",
"a...",
"aa..",
"aaa.",
"aaaa",
"aaaa",
"aaaa",
"aaa.",
"aa..",
"a..."};
/* XPM */
#ifdef USE_SMALL_BACKSPACE
static const char * const backspace_xpm[]={
"9 9 2 1",
"a c #000000",
". c None",
".........",
".........",
"...a.....",
"..aa.....",
".aaaaaaaa",
"..aa.....",
"...a.....",
".........",
"........."};
#else
static const char * const backspace_xpm[]={
"21 9 2 1",
"a c #000000",
". c None",
".....................",
".....................",
".....aaa..a..........",
".a...a..a.a.a.aaa.aaa",
"aaaa.aaa..aa..aa..a.a",
".a...a..a.aaa..aa.a.a",
".....aaaa.a.a.aaa.aa.",
"..................a..",
"....................."};
#endif
/* XPM */
static const char * const escape_xpm[]={
"9 9 2 1",
"a c #000000",
". c None",
".........",
".........",
".aa.aa.aa",
".a..a..a.",
".aa.aa.a.",
".a...a.a.",
".aa.aa.aa",
".........",
"........."};




enum { BSCode = 0x80, TabCode, CapsCode, RetCode, 
       ShiftCode, CtrlCode, AltCode, SpaceCode, BackSlash,
       UpCode, LeftCode, DownCode, RightCode, Blank, Expand,
       Opti, ResetDict,
       Divide, Multiply, Add, Subtract, Decimal, Equal,
       Percent, Sqrt, Inverse, Escape };

typedef struct SpecialMap {
    int qcode;
    ushort unicode;
    const char * label;
    const char * const * xpm;
};


static const SpecialMap specialM[] = {
    {	Qt::Key_Backspace,	8,	"BS",    NULL /* backspace_xpm */},
    {	Qt::Key_Tab,		9,	"Tab",   NULL },
    {	Qt::Key_CapsLock,	0,	"Caps",  NULL },
    {	Qt::Key_Return,		13,	"Ret",   NULL },
    {	Qt::Key_Shift,		0,	"Shift", NULL },
    {	Qt::Key_Control,	0,	"Ctrl",  NULL },
    {	Qt::Key_Alt,		0,	"Alt",   NULL },
    {	Qt::Key_Space,		' ',	"",      NULL },
    {	BackSlash,		43,	"\\",    NULL },

    // Need images?
    {	Qt::Key_Up,		0,	"Up",     NULL /*uparrow_xpm*/ },
    {	Qt::Key_Left,		0,	"Lt",     NULL /*leftarrow_xpm*/ },
    {	Qt::Key_Down,		0,	"Dn",     NULL /*downarrow_xpm*/ },
    {	Qt::Key_Right,		0,	"Rt",     NULL /*rightarrow_xpm*/ },
    {	Qt::Key_Insert,		0,	"Ins",    NULL /* insert_xpm*/ },
    {	Qt::Key_Home,		0,	"Hom",   NULL /*  home_xpm*/ },
    {	Qt::Key_PageUp,		0,	"PUp",   NULL /*  pageup_xpm*/ },
    {	Qt::Key_End,		0,	"End",    NULL /* end_xpm*/ },
    {	Qt::Key_Delete,		0,	"Del",    NULL /* delete_xpm*/ },
    {	Qt::Key_PageDown,	0,	"PDn",   NULL /*  pagedown_xpm*/ },
    {	Blank,			0,	" ",     NULL },
    {	Expand,			0,	"->",    expand_xpm },
    {	Opti,			0,	"#",     NULL },
    {	ResetDict,		0,	"R",     NULL },
   
    // number pad stuff
    {	Divide,			0,	"/",     NULL },
    {	Multiply,		0,	"*",     NULL },
    {	Add,			0,	"+",     NULL },
    {	Subtract,		0,	"-",     NULL },
    {	Decimal,		0,	".",     NULL },
    {	Equal,			0,	"=",     NULL },
    {	Percent,		0,	"%",     NULL },
    {	Sqrt,			0,	"^1/2",	 NULL },
    {	Inverse,		0,	"1/x",	 NULL },

    {	Escape,			27,	"ESC",	 NULL /*escape_xpm*/ },
    {	0,			0,	"Lng",	NULL }	//\241
};


static int keycode( int i2, int j, const uchar **keyboard )
{
    if ( j <0 || j >= 5 )
	return 0;
    
    const uchar *row = keyboard[j];

    while ( *row && *row <= i2 ) {
	i2 -= *row;
	row += 2;
    }

    if ( !*row ) return 0;
    
    int k;
    if ( row[1] >= 0x80 ) {
	k = row[1];
    } else {
	k = row[1]+i2/2;
    }
    
    return k;
}


/*
  return scancode and width of first key in row \a j if \a j >= 0,
  or next key on current row if \a j < 0.
  
*/

int Keyboard::getKey( int &w, int j ) {
    static const uchar *row = 0;
    static int key_i = 0;
    static int scancode = 0;
    static int half = 0;
    
    if ( j >= 0 && j < 5 ) {
	if (useOptiKeys)
    	    row = keyboard_opti[j];
	else
    	    row = keyboard_standard[j];
	half=0;
    }

    if ( !row || !*row ) {
	return 0;    
    } else if ( row[1] >= 0x80 ) {
	scancode = row[1];
	w = (row[0] * w + (half++&1)) / 2;
	row += 2;
	return scancode;
    } else if ( key_i <= 0 ) {
	key_i = row[0]/2;
	scancode = row[1];
    }
    key_i--;
    if ( key_i <= 0 )
	row += 2;
    return scancode++;
}
    

void Keyboard::paintEvent(QPaintEvent* e)
{
    QPainter painter(this);
    painter.setClipRect(e->rect());
    drawKeyboard( painter );
}


/*
  Draw the keyboard.

  If key >= 0, only the specified key is drawn.
*/
void Keyboard::drawKeyboard( QPainter &p, int key )
{
    const bool threeD = FALSE;
    const QColorGroup& cg = colorGroup();
    QColor keycolor = // cg.background();
		    	QColor(240,240,230); // Beige!
    QColor keycolor_pressed = cg.mid();
    QColor keycolor_lo = cg.dark();
    QColor keycolor_hi = cg.light();
    QColor textcolor = QColor(0,0,0); // cg.text();

    int margin = threeD ? 1 : 0;
    
//    p.fillRect( 0, , kw-1, keyHeight-2, keycolor_pressed );

    for ( int j = 0; j < 5; j++ ) {
	int y = j * keyHeight + 1;
	int x = xoffs;
	int kw = defaultKeyWidth;
	int k= getKey( kw, j );
	while ( k ) {
	    if ( key < 0 || k == key ) {
		QString s;
		bool pressed = (k == pressedKey);
		bool blank = (k == 0223);
		const char * const * xpm = NULL;
		
		if ( k >= 0x80) {
		    s = specialM[k - 0x80].label;

		    xpm = specialM[k - 0x80].xpm;
		    
		//    if (k == 0xA1) {
		//	if (!latcyr) s = "Cyr";
		//	else s = "Lat";
		//    } else 
		    if ( k == ShiftCode ) {
			pressed = shift;
		    } else if ( k == CapsCode ) {
			pressed = lock;
		    } else if ( k == CtrlCode ) {
			pressed = ctrl;
		    } else if ( k == AltCode ) {
			pressed = alt;
		    } 
		} else {
		    k--;
		    if (nlayout == 0) s = (shift^lock)?keymap_shift[nlayout][k]:keymap[nlayout][k];
		    else s = QChar ((shift^lock)?keymap_shift[nlayout][k]:keymap[nlayout][k]);
		}

		if (!blank) {
		    if ( pressed )
			p.fillRect( x+margin, y+margin, kw-margin, keyHeight-margin-1, keycolor_pressed );
		    else
			p.fillRect( x+margin, y+margin, kw-margin, keyHeight-margin-1, keycolor );

		    if ( threeD ) {
			p.setPen(pressed ? keycolor_lo : keycolor_hi);
			p.drawLine( x, y+1, x, y+keyHeight-2 );
			p.drawLine( x+1, y+1, x+1, y+keyHeight-3 );
			p.drawLine( x+1, y+1, x+1+kw-2, y+1 );
		    } else if ( j == 0 ) {
			p.setPen(pressed ? keycolor_hi : keycolor_lo);
			p.drawLine( x, y, x+kw, y );
		    }

		    // right
		    p.setPen(pressed ? keycolor_hi : keycolor_lo);
		    p.drawLine( x+kw-1, y, x+kw-1, y+keyHeight-2 );

		    if ( threeD ) {
			p.setPen(keycolor_lo.light());
			p.drawLine( x+kw-2, y+keyHeight-2, x+kw-2, y+1 );
			p.drawLine( x+kw-2, y+keyHeight-2, x+1, y+keyHeight-2 );
		    }

		    if (xpm) {
			p.drawPixmap( x + 1, y + 2, QPixmap((const char**)xpm) );
		    } else {
    			p.setPen(textcolor);
			p.drawText( x - 1, y, kw, keyHeight-2, AlignCenter, s );
		    }
	    
		    if ( threeD ) {
			p.setPen(keycolor_hi);
			p.drawLine( x, y, x+kw-1, y );
		    }

		    // bottom
		    p.setPen(keycolor_lo);
		    p.drawLine( x, y+keyHeight-1, x+kw-1, y+keyHeight-1 );
	    
		} else {
		    p.fillRect( x, y, kw, keyHeight, cg.background() );
		}
	    }

	    x += kw;
	    kw = defaultKeyWidth;
	    k = getKey( kw );
	}
    }
}


void Keyboard::mousePressEvent(QMouseEvent *e)
{
    clearHighlight(); // typing fast?

    int i2 = ((e->x() - xoffs) * 2) / defaultKeyWidth;
    int j = e->y() / keyHeight;

    int k = keycode( i2, j, (const uchar **)((useOptiKeys) ? keyboard_opti : keyboard_standard) );
    bool need_repaint = FALSE;
    unicode = -1;
    qkeycode = 0;
    if ( k >= 0x80 ) {
	if ( k == ShiftCode ) {
	    shift = !shift;
	    need_repaint = TRUE;
	} else if ( k == AltCode ){
	    alt = !alt;
	    need_repaint = TRUE;
	} else if ( k == CapsCode ) {
	    lock = !lock;
	    need_repaint = TRUE;
	} else if ( k == CtrlCode ) {
	    ctrl = !ctrl;
	    need_repaint = TRUE;
	} else if ( k == 0224 /* Expand */ ) {
	    useLargeKeys = !useLargeKeys;
	    resizeEvent(0);
	    repaint( TRUE ); // need it to clear first
	} else if ( k == 0225 /* Opti/Toggle */ ) {
	    useOptiKeys = !useOptiKeys;
	    resizeEvent(0);
	    repaint( TRUE ); // need it to clear first
	//} else if ( k == 0xA1 ) {
	//    latcyr = !latcyr;
	//    repaint( TRUE );
	} else {
	    qkeycode = specialM[ k - 0x80 ].qcode;
	    unicode = specialM[ k - 0x80 ].unicode;
	}
/*
	{
	    FILE *f = fopen("/tmp/keylog.txt", "a");
	    fprintf(f, "%02X, %02X, %02X\n", k, LatCyr, latcyr);
	    fclose(f);
	}
 */	
    } else {
#if defined(Q_WS_QWS) || defined(_WS_QWS_)

	if (nlayout == 0) {

	    char shifted = (shift^lock)?keymap_shift[nlayout][k-1]:keymap[nlayout][k-1];
	    QChar tempChar( shifted );
	    unicode = tempChar.unicode();
	} else {
	    unicode = (shift^lock)?keymap_shift[nlayout][k-1]:keymap[nlayout][k-1];
	}
#endif
    }
    if  ( unicode != -1 ) {
	modifiers = (shift ? Qt::ShiftButton : 0) | (ctrl ? Qt::ControlButton : 0) |
		  (alt ? Qt::AltButton : 0);
#if defined(Q_WS_QWS) || defined(_WS_QWS_)
	emit key( unicode, qkeycode, modifiers, true, false );
	repeatTimer->start( 500 );
#endif
	need_repaint = shift || alt || ctrl;
	shift = alt = ctrl = FALSE;
	//qDebug( "pressed %d -> %04x ('%c')", k, u, u&0xffff < 256 ? u&0xff : 0 );

    }
    pressedKey = k;
    if ( need_repaint ) {
	repaint( FALSE );
    } else {
	QPainter p(this);
	drawKeyboard( p, pressedKey );
    }
    pressTid = startTimer(80);
    pressed = TRUE;
}


void Keyboard::mouseReleaseEvent(QMouseEvent*)
{
    if ( pressTid == 0 )
	clearHighlight();
#if defined(Q_WS_QWS) || defined(_WS_QWS_)
    if ( unicode != -1 ) {
	emit key( unicode, qkeycode, modifiers, false, false );
	repeatTimer->stop();
    }
#endif
    pressed = FALSE;
}

void Keyboard::timerEvent(QTimerEvent* e)
{
    if ( e->timerId() == pressTid ) {
	killTimer(pressTid);
	pressTid = 0;
	if ( !pressed )
	    clearHighlight();
    }
}

void Keyboard::repeat()
{
    repeatTimer->start( 150 );
    emit key( unicode, qkeycode, modifiers, true, true );
}

void Keyboard::clearHighlight()
{
    if ( pressedKey >= 0 ) {
	int tmp = pressedKey;
	pressedKey = -1;
	QPainter p(this);
	drawKeyboard( p, tmp );
    }
}


QSize Keyboard::sizeHint() const
{
    QFontMetrics fm=fontMetrics();
    int keyHeight = fm.lineSpacing()+2;

    if (useOptiKeys)
    	keyHeight += 1;
    
    return QSize( 320, keyHeight * 5 + 1 );
}


void Keyboard::resetState()
{
}

void Keyboard::message( const QCString& message )
{
    if ( message == "setusa()" ) {
	nlayout = KBD_USA;
	repaint(TRUE);
    } else if (message == "setrus()" ) {
	nlayout = KBD_RUS;
	repaint(TRUE);
    } else if (message == "setmak()" ) {
	nlayout = KBD_MAK;
	repaint(TRUE);
    } else if (message == "setbel()" ) {
	nlayout = KBD_BEL;
	repaint(TRUE);
    } else if (message == "setblg()" ) {
	nlayout = KBD_BLG;
	repaint(TRUE);
    } else if (message == "setsrb()" ) {
	nlayout = KBD_SRB;
	repaint(TRUE);
    } else if (message == "setukr()" ) {
	nlayout = KBD_UKR;
	repaint(TRUE);
    } 
}
