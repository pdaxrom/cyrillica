#ifndef __LAUNCHER_CLOCK_H__
#define __LAUNCHER_CLOCK_H__


#include <qlabel.h>
#include <qdatetime.h>
#include <qcopchannel_qws.h>

class KeybShow : public QLabel
{
    Q_OBJECT
public:
    KeybShow( QWidget *parent );

public slots:
  void message( const QCString& );

protected:
    void mouseReleaseEvent( QMouseEvent * );
    int lang;
private:
    QCopChannel* _chanel;
    int maps[10];
    int nmaps;
    void load_config();
};


#endif // __LAUNCHER_CLOCK_H__
