#ifndef CLOCKAPPLETIMPL_H
#define CLOCKAPPLETIMPL_H

#include <qpe/taskbarappletinterface.h>

class KeybShow;

class KbdAppletImpl : public TaskbarAppletInterface
{
public:
    KbdAppletImpl();
    virtual ~KbdAppletImpl();

#ifndef QT_NO_COMPONENT
    QRESULT queryInterface( const QUuid&, QUnknownInterface** );
    Q_REFCOUNT
#endif

    virtual QWidget *applet( QWidget *parent );
    virtual int position() const;

private:
    KeybShow *kbd;
    ulong ref;
};

#endif
