#ifndef CYRKBDSET_H
#define CYRKBDSET_H
#include "cyrkbdsetbase.h"

class CyrKbdSet : public CyrKbdSetBase
{ 
    Q_OBJECT

public:
    CyrKbdSet( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CyrKbdSet();
private:
    void save_config();

private slots:
    void goodBye();
};

#endif // CYRKBDSET_H
