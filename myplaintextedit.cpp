#include "myplaintextedit.h"
#include "mainwindow.h"

MyPlainTextEdit::MyPlainTextEdit(QWidget *parent):
    QPlainTextEdit(parent)
{
}

void MyPlainTextEdit::keyPressEvent(QKeyEvent *event) {
    if (event->key()==Qt::Key_Tab) {
        ((MainWindow *) parent()->parent())->save();
        return;
    }
    QPlainTextEdit::keyPressEvent(event);

}
