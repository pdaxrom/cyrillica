#include "keybshow.h"
#include "kbdappletimpl.h"


KbdAppletImpl::KbdAppletImpl()
    : kbd(0), ref(0)
{
}

KbdAppletImpl::~KbdAppletImpl()
{
    delete kbd;
}

QWidget *KbdAppletImpl::applet( QWidget *parent )
{
    if ( !kbd )
	kbd = new KeybShow( parent );
    return kbd;
}

int KbdAppletImpl::position() const
{
    return 10;
}

#ifndef QT_NO_COMPONENT
QRESULT KbdAppletImpl::queryInterface( const QUuid &uuid, QUnknownInterface **iface )
{
    *iface = 0;
    if ( uuid == IID_QUnknown )
	*iface = this;
    else if ( uuid == IID_TaskbarApplet )
	*iface = this;

    if ( *iface )
	(*iface)->addRef();
    return QS_OK;
}

Q_EXPORT_INTERFACE()
{
    Q_CREATE_INSTANCE( KbdAppletImpl )
}
#endif

