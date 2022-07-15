#include<QDir>
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //connect(ui->pushButton_2,&QPushButton::released(),this,&Widget::HandleButton);

    connect(ui->pushButton_2, SIGNAL(pressed()), this, SLOT( buttonHandler()));
    connect(this, SIGNAL(changeImage(const QPixmap &)), ui->label_6, SLOT(setPixmap(const QPixmap &)));

    //QImage *green = new QImage(":/Resources/1.jpg");
    //INVESTIGAR
}


void Widget::buttonHandler(){


    emit changeImage(QPixmap(":/main/1.jpg"));

}

Widget::~Widget()
{
    delete ui;
}

