#include <stdio.h>
#include "custominput.h"
#include <qpixmap.h>
#include <qapplication.h>
#include <qwindowsystem_qws.h>
#include "keyboardhandler.h"
#include <qcopchannel_qws.h>

/* XPM */
static const char * pb_xpm[]={
"28 7 3 1",
"# c #303030",
"@ c #00FF00",
"  c None",
" #############   ##### ## # ",
" #@@@#@@@#@@@#   #@@@#      ",
" #@@@#@@@#@@@#   #####  ##  ",
" ###############            ",
" #@@@@@#@@@#@@@#            ",
" #@@@@@#@@@#@@@#            ",
" ###############            "};

CustomInput::CustomInput() : input(0), _icn(0), ref(0)
{
  _keyboardHandler =  new KeyboardHandler( this, "_keyboardHandler" );
  qwsServer->setKeyboardFilter( _keyboardHandler ); 
  _chanel = new QCopChannel( "CyrInput/Private", this );
  connect( _chanel, SIGNAL( received(const QCString &, const QByteArray &)),
           _keyboardHandler, SLOT(message( const QCString& )) );
  connect( _chanel, SIGNAL( received(const QCString &, const QByteArray &)),
           this, SLOT(message( const QCString& )) );
}

CustomInput::~CustomInput()
{
  qwsServer->setKeyboardFilter( 0 );
  delete input;
  delete _icn;
  input = 0;
  _icn = 0;
}

void CustomInput::message( const QCString& message ) 
{
  if ( message == "enable()" ) {
    qwsServer->setKeyboardFilter( _keyboardHandler );
  }
  else if ( message == "disable()" ) {
    qwsServer->setKeyboardFilter( 0 );
  }
}

QWidget* CustomInput::inputMethod( QWidget *parent, Qt::WFlags f ) 
{
  if ( ! input ) {
    input = new Keyboard( parent, "CyrKeyboard", f );
    connect( _chanel, SIGNAL( received(const QCString &, const QByteArray &)),
             input, SLOT(message( const QCString & )) );
  }

  return input;
}

void CustomInput::resetState() 
{
    if (input)
	input->resetState();
}

QPixmap* CustomInput::icon()
{    
  if ( !_icn )
	_icn = new QPixmap( (const char **)pb_xpm );
    return _icn;
}

QString CustomInput::name()
{
  return qApp->translate( "InputMethods", "CyrKeyboard" );
}

void CustomInput::onKeyPress( QObject *receiver, const char *slot )
{   
  if ( input )
    QObject::connect( input, SIGNAL(key(ushort,ushort,ushort,bool,bool)), receiver, slot );
    QObject::connect( _keyboardHandler, SIGNAL(key(ushort,ushort,ushort,bool,bool)), receiver, slot );
}


QRESULT CustomInput::queryInterface( const QUuid &uuid, QUnknownInterface **iface )
{
  *iface = 0;
  if ( uuid == IID_QUnknown )
    *iface = this;
  else if ( uuid == IID_InputMethod )
    *iface = this;
  
  if ( *iface )
    (*iface)->addRef();
  return QS_OK;
}

Q_EXPORT_INTERFACE()
{
  Q_CREATE_INSTANCE( CustomInput )
}

