#ifndef __KEYBOARDHANDLER_H
#define __KEYBOARDHANDLER_H

#include <qwindowsystem_qws.h>
#include <qlabel.h>
#include <qcstring.h>
#include <qdatetime.h>

class KeyboardHandler :public QObject, public QWSServer::KeyboardFilter 
{
Q_OBJECT
public:
  KeyboardHandler( QObject* parent, const char* name );
	virtual bool filter(int unicode, int keycode, int modifiers, bool isPress,
                      bool autoRepeat);
signals:
  void key(ushort,ushort,ushort,bool,bool);
public slots:
  void message( const QCString& );
protected:
  void reread();

private:
  int _prev;

  class Key
  {
  public:
    Key( int key, int state ) 
    {
      _key = key;
      _state = state;
    }
    Key() {}
    bool operator!=( Key& other ) 
    {
      return _key != other._key || _state != other._state;
    }
    
    int _key;
    int _state;
  };
  
  class Binding
  {
  public:
    void addKey( const Key& key ) 
    {
      _keys.append( key );
    }
    void setReplacement( const QString& replacement ) 
    {
      _replacement = replacement;
    }

    QValueList< Key > _keys;
    QString _replacement;
  };
  
  QValueList<Binding> _bindings;
  int _length;
  int _index;
  Key* _input;
  bool _active;
  QTime _time;
  int _delay;
  int nlayout;
  bool flagFn;
  bool meta_on;
  int layoutSwitch;
};


#endif // __KEYBOARDHANDLER_H
