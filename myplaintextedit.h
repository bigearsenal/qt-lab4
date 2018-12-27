#ifndef MYPLAINTEXTEDIT_H
#define MYPLAINTEXTEDIT_H

#include "qplaintextedit.h"

class MyPlainTextEdit: public QPlainTextEdit
{
public:
    MyPlainTextEdit(QWidget *parent = nullptr);

protected:
    virtual void keyPressEvent(QKeyEvent *);
};

#endif // MYPLAINTEXTEDIT_H
