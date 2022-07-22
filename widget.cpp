
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
    //
    //connect(this,SIGNAL(getNewList(vector<Person>)),this,SLOT(swipingPage(vector<Person>)));

    //BOTONES LIKE NEXT
    connect(ui->yesButton, SIGNAL(pressed()), this, SLOT( like()));
    connect(ui->noButton, SIGNAL(pressed()), this, SLOT( pass()));
    connect(this,SIGNAL(nextProfile()),this,SLOT(meetPeopleButton()));
    //connect(this, SIGNAL(changeImage(QPixmap)), ui->label_6, SLOT(setPixmap(QPixmap)));
    //connect(this, SIGNAL(changeName(QString)), ui->label, SLOT(setText(QString)));

    //BOTONES CAMBIAR VISTA MENSAJES PERFIL
    connect(ui->backMessages, SIGNAL(pressed()), this, SLOT( backButton())); //back from messages
    //connect(ui->pushButton_10, SIGNAL(pressed()), this, SLOT( backButton())); //back from profile
    connect(ui->yourProfileButton, SIGNAL(pressed()), this, SLOT( profileButton())); //profile
    connect(ui->messagesButton, SIGNAL(pressed()), this, SLOT( messagesButton())); //messages


}

//Initializations
//Person mainPerson=Person();
/*
    string maleCSV=":/csv/csv/maleNames.csv";
    string femaleCSV=":/csv/csv/femaleNames.csv";
    string lastnamesCSV=":/csv/csv/lastnames.csv";
    string majorCSV=":/csv/csv/majors.csv";
    string likesCSV =":/csv/csv/likes.csv";


    ProfileCreator creator = ProfileCreator(maleCSV, femaleCSV, lastnamesCSV, majorCSV,likesCSV);

*/


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
    vector<string> likes={
        ui->likeBox_1->text().toStdString(),
        ui->likeBox_2->text().toStdString(),
        ui->likeBox_3->text().toStdString()
    };

    //dislikes
    vector<string> dislikes={
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
    mainUser.setName(name.toStdString());
    mainUser.setAge(age);
    mainUser.setMajor(major.toStdString());
    mainUser.setGender(gender.toStdString());
    mainUser.setSexPref(sexPref.toStdString());
    mainUser.setAgePref(agePref);
    mainUser.setLikes(likes);
    mainUser.setDislikes(dislikes);

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
        ui->mainProfilePic->setPixmap(QPixmap(":/yourProfile_Male/profilePics/male/16.jpg").scaled(w,w,Qt::KeepAspectRatio));
    }

    else if(QString::compare(gender,QString("Femenino"))==0){
        emit ypGenderSignal(QString("♀"));
        //emit ypPicSignal(QPixmap(":/yourProfileFemale/profilePics/67.jpg"));
        ui->mainProfilePic->setPixmap(QPixmap(":/yourProfileFemale/profilePics/female/1.jpg").scaled(w,w,Qt::KeepAspectRatio));
    }

    else if(QString::compare(gender,QString("No Binario"))==0){
        emit ypGenderSignal(QString("⚧"));
        //emit ypPicSignal(QPixmap(":/yourProfile_Male/profilePics/44.jpg"));
        ui->mainProfilePic->setPixmap(QPixmap(":/yourProfile_Male/profilePics/male/18.jpg").scaled(w,w,Qt::KeepAspectRatio));
    }

    //crear la lista de posibles denuevo
    //matchMake=MatchMaker(mainUser,dummies);

}


// PROFILE PAGE  /////////////////////////////////////////////////////////////////

void Widget::meetPeopleButton(){

    Person currentProfile=matchMake.GetNextPerson();
    ui->nameSwipeLabel->setText(QString::fromStdString(currentProfile.getName()));
    ui->ageSwipeLabel->setText(QString::number(currentProfile.getAge()));
    ui->majorSwipeLabel->setText(QString::fromStdString(currentProfile.getMajor()));

    //likes & dislikes
    string comma=",";
    string andy="&";
    string dash=" - ";
    vector<string> likes = currentProfile.getLikes();
    string strLikes=likes[0]+dash+likes[1]+dash+likes[2];
    ui->likesSwipeLabel->setText(QString::fromStdString(strLikes));

    vector<string> dislikes = currentProfile.getDisLikes();
    string strdisLikes=dislikes[0]+dash+dislikes[1]+dash+dislikes[2];
    ui->dislikesSwipeLabel->setText(QString::fromStdString(strdisLikes));

    //profile pic
    int w = ui->profilePicLabel->width();
    string basePath=":/female/profilePics/female";
    string extension=".jpg";
    string gender=currentProfile.getGender();
    //string id=to_string(currentProfile.getId());
    string id =to_string(8);
    string fullPath;

    if (gender=="Masculino"){
        basePath=":/male/profilePics/male";
    }
    if (gender=="Femenino"){
        basePath=":/female/profilePics/female";
    }
    if (gender=="No Binario"){
        basePath=":/nb/profilePics/nb";
    }
    fullPath=basePath+id+extension;

    QPixmap pic=QPixmap(QString::fromStdString(fullPath));
    ui->profilePicLabel->setPixmap(pic.scaled(w,w,Qt::KeepAspectRatio));

    emit changeView(int(3));

}





//SWIPING PAGE /////////////////////////////////////////////////////////////////



//CAMBIO DE PERFIL NEXT
void Widget::pass(){
    matchMake.Pass();
    emit nextProfile();

}

void Widget::like(){
    matchMake.Like();
    emit nextProfile();
}

//CAMBIO DE VISTA
void Widget::backButton(){
    emit changeView(int(3));
}

void Widget::profileButton(){
    emit changeView(int(1));
}

void Widget::messagesButton(){
    emit changeView(int(4));
}








//DESTRUCTOR
Widget::~Widget()
{
    delete ui;
}

