#include<QDir>
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //connect(ui->pushButton_2,&QPushButton::released(),this,&Widget::HandleButton);

//BOTONES LIKE NEXT
    connect(ui->pushButton_2, SIGNAL(pressed()), this, SLOT( buttonHandler()));
    connect(ui->pushButton_2, SIGNAL(pressed()), this, SLOT( nameSlot()));
    connect(this, SIGNAL(changeImage(QPixmap)), ui->label_6, SLOT(setPixmap(QPixmap)));
    connect(this, SIGNAL(changeName(QString)), ui->label, SLOT(setText(QString)));

//BOTONES CAMBIAR VISTA MENSAJES PERFIL
    connect(ui->pushButton_9, SIGNAL(pressed()), this, SLOT( backButton())); //back from messages
    //connect(ui->pushButton_10, SIGNAL(pressed()), this, SLOT( backButton())); //back from profile
    connect(ui->pushButton_6, SIGNAL(pressed()), this, SLOT( profileButton())); //profile
    connect(ui->pushButton_4, SIGNAL(pressed()), this, SLOT( messagesButton())); //messages
   //setCurrentIndex(int index)
    connect(this, SIGNAL(changeView(int)), ui->stackedWidget, SLOT(setCurrentIndex(int)));

}

Person testPerson=Person("lucas","male",20,"ELO");


//LANDING PAGE
void Widget::createProfileButton(){
    emit changeView(int(1));
}

//FORMULARIO PAGE

//SWIPING PAGE
//CAMBIO DE ATRIBUTOS
void Widget::buttonHandler(){
    emit changeImage(QPixmap(":/female/profilePics/44.jpg"));
}

void Widget::nameSlot(){
    //std::string str="Dani,";
    std::string str=testPerson.getName();
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

//CAMBIO DE VISTA
void Widget::backButton(){
    emit changeView(int(0));
}

void Widget::profileButton(){
    emit changeView(int(1));
}

void Widget::messagesButton(){
    emit changeView(int(2));
}








//DESTRUCTOR
Widget::~Widget()
{
    delete ui;
}

