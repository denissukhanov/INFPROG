#include "mywidget.h"
#include "ui_mywidget.h"
#include <QCoreApplication>
#include <QLabel>
#include <QString>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{

    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}


void MyWidget::on_MyPushButton2_clicked()
{
    QString FirstString = ui -> MyLineEdit1->text();
    QString SecondString = ui -> MyLineEdit2->text();
    if (FirstString.contains(SecondString))
    {

        int coutRepeats = 0;
         QChar ch =  SecondString.at(0);
         QString::const_iterator it =  FirstString.begin();
         for (; it !=  FirstString.end(); ++it)
           if (*it == ch)
             ++coutRepeats;
         //ui->MyLabel->setText(ch);
         ui->MyLabel->setText(QString::number(coutRepeats));
    }
    else
    {
        ui->MyLabel->setText("No, it doesn't!");
    }
}

