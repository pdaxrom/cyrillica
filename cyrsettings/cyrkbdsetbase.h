/****************************************************************************
** Form interface generated from reading ui file 'cyrkbdsetbase.ui'
**
** Created: Tue Jul 29 15:35:35 2003
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef CYRKBDSETBASE_H
#define CYRKBDSETBASE_H

#include <qvariant.h>
#include <qwidget.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QCheckBox;
class QLabel;
class QPushButton;

class CyrKbdSetBase : public QWidget
{ 
    Q_OBJECT

public:
    CyrKbdSetBase( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CyrKbdSetBase();

    QCheckBox* CheckBoxBE;
    QCheckBox* CheckBoxBG;
    QCheckBox* CheckBoxMK;
    QCheckBox* CheckBoxRU;
    QCheckBox* CheckBoxSR;
    QCheckBox* CheckBoxUK;
    QPushButton* ButtSave;
    QLabel* TextLabel1;

protected slots:
    virtual void save_config();

protected:
    bool event( QEvent* );
};

#endif // CYRKBDSETBASE_H
