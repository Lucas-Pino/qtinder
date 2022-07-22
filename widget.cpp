
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //connect(ui->pushButton_2,&QPushButton::released(),this,&Widget::HandleButton);

// STACKED WIDGET
    //setCurrentIndex(int index)
     connect(this, SIGNAL(changeView(int)), ui->stackedWidget, SLOT(setCurrentIndex(int)));

//LANDING PAGE /////////////////////////////////////////////////////////////////
    //botones
    connect(ui->pushButton_8, SIGNAL(pressed()), this, SLOT( createProfileButton()));
    connect(ui->pushButton_11, SIGNAL(pressed()), this, SLOT( settingsButton()));

//FORMULARIO PAGE /////////////////////////////////////////////////////////////////
    //boxes
    connect(ui->minAgeBox, SIGNAL(valueChanged(int)), this, SLOT( minAgeBox(int)));

    //button
    connect(ui->finishProfileButton, SIGNAL(pressed()), this, SLOT( finishProfileButton()));


//PROFILE PAGE  /////////////////////////////////////////////////////////////////
    connect(ui->meetPeopleButton, SIGNAL(pressed()), this, SLOT( meetPeopleButton()));

    connect(this, SIGNAL(ypNameSignal(QString)), ui->nameLabel, SLOT( setText(QString)));
    connect(this, SIGNAL(ypAgeSignal(QString)), ui->ageLabel, SLOT( setText(QString)));
    connect(this, SIGNAL(ypGenderSignal(QString)), ui->genderLabel, SLOT(setText(QString)));
    connect(this, SIGNAL(ypMajorSignal(QString)), ui->majorLabel, SLOT(setText(QString)));
    connect(this, SIGNAL(ypSexPrefSignal(QString)), ui->sexPrefLabel, SLOT(setText(QString)));

    connect(this, SIGNAL(ypPicSignal(QPixmap)), ui->mainProfilePic, SLOT( setPixmap(QPixmap)));

    connect(this, SIGNAL(ypLikeSignal_1(QString)), ui->likeLabel_1, SLOT( setText(QString)));
    connect(this, SIGNAL(ypLikeSignal_2(QString)), ui->likeLabel_2, SLOT( setText(QString)));
    connect(this, SIGNAL(ypLikeSignal_3(QString)), ui->likeLabel_3, SLOT( setText(QString)));

    connect(this, SIGNAL(ypDislikeSignal_1(QString)), ui->dislikeLabel_1, SLOT( setText(QString)));
    connect(this, SIGNAL(ypDislikeSignal_2(QString)), ui->dislikeLabel_2, SLOT( setText(QString)));
    connect(this, SIGNAL(ypDislikeSignal_3(QString)), ui->dislikeLabel_3, SLOT( setText(QString)));

//SWIPING PAGE //////////////////////////////////////////////////////////////////
    //BOTONES LIKE NEXT
    //connect(ui->yesButton, SIGNAL(pressed()), this, SLOT( buttonHandler()));
    //connect(ui->pushButton_2, SIGNAL(pressed()), this, SLOT( nameSlot()));
    //connect(this, SIGNAL(changeImage(QPixmap)), ui->label_6, SLOT(setPixmap(QPixmap)));
    //connect(this, SIGNAL(changeName(QString)), ui->label, SLOT(setText(QString)));

    //BOTONES CAMBIAR VISTA MENSAJES PERFIL
    //connect(ui->pushButton_9, SIGNAL(pressed()), this, SLOT( backButton())); //back from messages
    //connect(ui->pushButton_10, SIGNAL(pressed()), this, SLOT( backButton())); //back from profile
    connect(ui->yourProfileButton, SIGNAL(pressed()), this, SLOT( profileButton())); //profile
    //connect(ui->pushButton_4, SIGNAL(pressed()), this, SLOT( messagesButton())); //messages


}


Person mainPerson=Person("lucas","male",20,"ELO");




//LANDING PAGE /////////////////////////////////////////////////////////////////
void Widget::createProfileButton(){
    emit changeView(int(1));
}
void Widget::settingsButton(){
    emit changeView(int(5));
}


//FORMULARIO PAGE /////////////////////////////////////////////////////////////////
//basic info

//age preference
void Widget::minAgeBox(int age){
    ui->maxAgeBox->setMinimum(age+1);
}



//finish button
void Widget::finishProfileButton(){
    //basic info
    QString name = ui->nameBox->text();
    int age = ui->ageBox->value();
    QString qAge = QString::number(age);
    QString major = ui->majorBox->currentText();
    QString gender = ui->genderBox->currentText();
    QString sexPref = ui->sexPrefBox->currentText();

    //preferencias
    int minAge = ui->minAgeBox->value();
    int maxAge = ui->maxAgeBox->value();
    int agePref[]={minAge,maxAge};

    //QString majorPref= ui->majorPrefBox->currentText();

    //likes
    string likes[]={
        ui->likeBox_1->text().toStdString(),
        ui->likeBox_2->text().toStdString(),
        ui->likeBox_3->text().toStdString()
    };

    //dislikes
    string dislikes[]={
        ui->dislikeBox_1->text().toStdString(),
        ui->dislikeBox_2->text().toStdString(),
        ui->dislikeBox_3->text().toStdString()
    };

    QString like1 = ui->likeBox_1->text();
    QString like2 = ui->likeBox_2->text();
    QString like3 = ui->likeBox_3->text();

    QString dislike1 = ui->dislikeBox_1->text();
    QString dislike2 = ui->dislikeBox_2->text();
    QString dislike3 = ui->dislikeBox_3->text();

    //setting on the person
    mainPerson.setName(name.toStdString());
    mainPerson.setAge(age);
    mainPerson.setMajor(major.toStdString());
    mainPerson.setGender(gender.toStdString());
    mainPerson.setSexPref(sexPref.toStdString());
    mainPerson.setAgePref(agePref);
    mainPerson.setLikes(likes);
    mainPerson.setDislikes(dislikes);

    emit changeView(int(2));

    emit ypNameSignal(QString(name));
    emit ypAgeSignal(qAge);
    emit ypMajorSignal(major);

    emit ypSexPrefSignal(sexPref);

    emit ypLikeSignal_1(like1);
    emit ypLikeSignal_2(like2);
    emit ypLikeSignal_3(like3);

    emit ypDislikeSignal_1(dislike1);
    emit ypDislikeSignal_2(dislike2);
    emit ypDislikeSignal_3(dislike3);


    // get label dimensions
    int w = ui->mainProfilePic->width();


    //gender icon logic and profile pic
    if( QString::compare(gender,QString("Masculino"))==0){
        emit ypGenderSignal(QString("♂︎"));
        //emit ypPicSignal(QPixmap(":/yourProfile_Male/profilePics/44.jpg"));
        //emit ypPicSignal(p.scaled(w,h,Qt::KeepAspectRatio));
        //emit ypPicSignal(p.scaled(w,w,Qt::KeepAspectRatio));
        ui->mainProfilePic->setPixmap(QPixmap(":/yourProfile_Male/profilePics/44.jpg").scaled(w,w,Qt::KeepAspectRatio));
    }

    else if(QString::compare(gender,QString("Femenino"))==0){
        emit ypGenderSignal(QString("♀"));
        //emit ypPicSignal(QPixmap(":/yourProfileFemale/profilePics/67.jpg"));
        ui->mainProfilePic->setPixmap(QPixmap(":/yourProfileFemale/profilePics/67.jpg").scaled(w,w,Qt::KeepAspectRatio));
    }

    else if(QString::compare(gender,QString("No Binario"))==0){
        emit ypGenderSignal(QString("⚧"));
        //emit ypPicSignal(QPixmap(":/yourProfile_Male/profilePics/44.jpg"));
        ui->mainProfilePic->setPixmap(QPixmap(":/yourProfile_Male/profilePics/44.jpg").scaled(w,w,Qt::KeepAspectRatio));
    }
}

// PROFILE PAGE  /////////////////////////////////////////////////////////////////

void Widget::meetPeopleButton(){
    emit changeView(int(3));
}

void Widget::profilePicLabel(){
    //:/yourProfile/profilePics/44.jpg
}





//SWIPING PAGE /////////////////////////////////////////////////////////////////
//CAMBIO DE ATRIBUTOS
void Widget::buttonHandler(){
    emit changeImage(QPixmap(":/female/profilePics/44.jpg"));
}

void Widget::nameSlot(){
    //std::string str="Dani,";
    std::string str=mainPerson.getName();
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
    emit changeView(int(3));
}








//DESTRUCTOR
Widget::~Widget()
{
    delete ui;
}

