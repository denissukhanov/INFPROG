#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_pushButton_clicked()
{

        QString FirstString = ui -> lineEdit->text();
        for (int i=0;i<FirstString.size();i++)
        {
            ui->lineEdit_2->setText(QString(FirstString.at(i)));

        }


}

