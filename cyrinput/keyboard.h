#include <qframe.h>
//#include "../pickboard/pickboardcfg.h"
//#include "../pickboard/pickboardpicks.h"

class QTimer;

class Keyboard : public QFrame
{
    Q_OBJECT
public:
    Keyboard( QWidget* parent=0, const char* name=0, WFlags f=0 );

    void resetState();

    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void resizeEvent(QResizeEvent*);
    void paintEvent(QPaintEvent* e);
    void timerEvent(QTimerEvent* e);
    void drawKeyboard( QPainter &p, int key = -1 );

    void setMode(int mode) { useOptiKeys = mode; }

    QSize sizeHint() const;

signals:
    void key( ushort scancode, ushort unicode, ushort modifiers, bool, bool );

public slots:
    void message( const QCString& );

private slots:
    void repeat();
    
private:
    int getKey( int &w, int j = -1 );
    void clearHighlight();

    uint shift:1;
    uint lock:1;
    uint ctrl:1;
    uint alt:1;
    uint useLargeKeys:1;
    uint useOptiKeys:1;
//    uint latcyr:1;

    int nlayout;
    
    int pressedKey;

    int keyHeight;
    int defaultKeyWidth;
    int xoffs;

    int unicode;
    int qkeycode;
    int modifiers;

    int pressTid;
    bool pressed;

    QTimer *repeatTimer;
};
