#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    // соединяем сигнал нажатия на кнопку со слотом
    connect(ui->btnSubmit, SIGNAL(clicked()), this, SLOT(printNumber()));
}

Widget::~Widget()
{
    delete ui;
}

// метод получает массив из ввода
QList<int> Widget::getArrayFromEdit()
{
    // разбиваем введенный текст на строки (по \n, то есть каждая строка - число)
    QStringList list = ui->editArray->toPlainText().split("\n");

    // записываем числа в массив
    QList<int> array;
    for(const QString& string : list){
        array.push_back(string.toInt());
    }

    return array;
}

// метод определяет является ли число простым
bool Widget::isPrimeNumber(int number)
{
    /*
     * делим число от 2 до его предпоследнего,
     * если на что-то делится - значит не простое
    */
    bool result = true;
    for(int d=2; d < number; d++){
        if(number % d == 0){
            result = false;
            break;
        }
    }

    return result;
}

// слот печатает найденное число (если нету - выводит 0)
void Widget::printNumber()
{
    QList<int> array = getArrayFromEdit();

    QString outNumber = "0";

    for(int number : array){
        if(isPrimeNumber(number)){
            outNumber = QString::number(number);
            break;
        }
    }

    ui->labelOutput->setText(outNumber);
}


