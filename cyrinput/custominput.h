#ifndef __custominput
#define __custominput
#include <qpe/inputmethodinterface.h>
#include <qobject.h>
#include "keyboardhandler.h"
#include "keyboard.h"
#include <qcstring.h>

class InputWidget;
class QPixmap;
class QCopChannel;

class CustomInput :public QObject, public InputMethodInterface
{
  Q_OBJECT
public:
  CustomInput();
  virtual ~CustomInput();

  QRESULT queryInterface( const QUuid&, QUnknownInterface** );
  Q_REFCOUNT

  virtual QWidget *inputMethod( QWidget *parent, Qt::WFlags f );
  virtual void resetState();
  virtual QPixmap *icon();
  virtual QString name();
  virtual void onKeyPress( QObject *receiver, const char *slot );

protected slots:
  void message( const QCString& );

private:
  Keyboard* input;
  KeyboardHandler* _keyboardHandler;
  QCopChannel* _chanel;

  QPixmap* _icn;
  ulong ref;
};


#endif /* custominput */

