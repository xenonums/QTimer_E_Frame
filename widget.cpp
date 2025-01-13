#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer = new QTimer;

    picID = 2;

    QImage img;
    img.load("C:\\Users\\xenonums\\Desktop\\QT6_learn\\re_try\\QTimer\\1.jpeg");

    ui->label->setPixmap(QPixmap::fromImage(img));

    //定时器时间到，发出timeout信号
    connect(timer, &QTimer::timeout, this, &Widget::timeoutslot);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startButton_clicked()
{
    timer->start(TIMEOUT);

}

void Widget::timeoutslot()
{
    QString path("C:\\Users\\xenonums\\Desktop\\QT6_learn\\re_try\\QTimer\\");

    path += QString::number(picID);
    path += ".jpeg";
    QImage img;
    img.load(path);
    ui->label->setPixmap(QPixmap::fromImage(img));

    picID++;
    if(5 == picID){
        picID = 1;
    }
}


void Widget::on_stopButton_clicked()
{
    timer->stop();
}

//循环一次
void Widget::on_singleButton_clicked()
{
    QTimer::singleShot(0, this, SLOT(timeoutslot()));
}

