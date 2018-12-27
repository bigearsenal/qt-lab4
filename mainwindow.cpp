#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfiledialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::save() {
    QString text = ui->plainTextEdit->toPlainText();

    if (text.isEmpty()) return;
    // Не сохранить в файл если текст пустой
        if (text.isEmpty()) return;

        // Открыть диалог для сохранения в файл
        QString fileName = QFileDialog::getSaveFileName(this,
                tr("Сохранить тесктовый файл"), "",
                tr("Тесктовый файл (*.txt)"));

        // Проверить имя файла и сохранить
        if (fileName.isEmpty()) return;
        else {
            QFile file(fileName);
            if(!file.open(QFile::WriteOnly | QFile::Text)){
                printf("Не мог бы открыть файл");
                return;
            }
            QDataStream out(&file);
            out << text;
            file.close();
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}
