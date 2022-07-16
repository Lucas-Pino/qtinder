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
    connect(ui->pushButton_2, SIGNAL(pressed()), this, SLOT( nameSlot()));
    connect(this, SIGNAL(changeImage(QPixmap)), ui->label_6, SLOT(setPixmap(QPixmap)));

    connect(this, SIGNAL(changeName(QString)), ui->label, SLOT(setText(QString)));


}



//CAMBIO DE ATRIBUTOS
void Widget::buttonHandler(){
    emit changeImage(QPixmap(":/female/profilePics/44.jpg"));
}

void Widget::nameSlot(){
    std::string str="Dani,";
    const QString qstr = QString::fromStdString(str);
    emit changeName(QString(qstr));
}

void Widget::ageSlot(){
    emit changeAge(QString("23"));
}

void Widget::majorSlot(){
    emit changeMajor(QString("Civil"));
}

void Widget::likesSlot(){
    emit changeLikes(QString("Puppies,Pan & friends."));
}

void Widget::dislikesSlot(){
    emit changeDislikes(QString("Mayo, winter, blue."));
}


//CAMBIO DE PERFIL NEXT
void Widget::reject(){

}

void Widget::approve(){

}


Widget::~Widget()
{
    delete ui;
}

