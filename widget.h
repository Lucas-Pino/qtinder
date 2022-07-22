#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDir>
#include <QString>
#include "Person.h"
#include "ProfileCreator.h"
#include "MatchMaker.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //MAIN USER
    Person mainUser=Person();

    //CREATING THE OTHER USERS
    string maleCSV="/Users/lucas/School/Programacion Orientada A Objetos/Proyectos/qtinder/qtinder/csv/maleNames.csv";
    string femaleCSV="/Users/lucas/School/Programacion Orientada A Objetos/Proyectos/qtinder/qtinder/csv/femaleNames.csv";
    string lastnamesCSV="/Users/lucas/School/Programacion Orientada A Objetos/Proyectos/qtinder/qtinder/csv/lastnames.csv";
    string majorCSV="/Users/lucas/School/Programacion Orientada A Objetos/Proyectos/qtinder/qtinder/csv/majors.csv";
    string likesCSV ="/Users/lucas/School/Programacion Orientada A Objetos/Proyectos/qtinder/qtinder/csv/likes.csv";

    ProfileCreator creator = ProfileCreator(maleCSV, femaleCSV, lastnamesCSV, majorCSV,likesCSV);
    vector<Person> dummies=creator.createDummies();
    MatchMaker matchMake=MatchMaker(dummies);
    //MatchMaker matchList=MatchMaker(mainUser,dummies);
    //Descomentar este y comentar el de arriba cuando este lista la funcion full de matchmaker

    //tambien hay que descomentar la linea 192 en "widget.cpp"

signals:
//STACKED WIDGET
    void changeView(int index);
//PROFILE PAGE
    // yp = Your Profile
    void ypNameSignal(const QString &); // yp = Your Profile
    void ypAgeSignal(const QString &);
    void ypGenderSignal(const QString &);
    void ypMajorSignal(const QString &);

    void ypSexPrefSignal(const QString &);

    void ypPicSignal(const QPixmap &);

    void ypLikeSignal_1(const QString &);
    void ypLikeSignal_2(const QString &);
    void ypLikeSignal_3(const QString &);

    void ypDislikeSignal_1(const QString &);
    void ypDislikeSignal_2(const QString &);
    void ypDislikeSignal_3(const QString &);


//SWIPING PAGE
    //CREAR NUEVA LISTA DE PERSONAS
    void getNewList(vector<Person>);

    //CAMBIO DE ATRIBUTOS
    void changeImage(const QPixmap &);
    void changeName(const QString &);
    void changeAge(const QString &);
    void changeMajor(const QString &);
    void changeLikes(const QString &);
    void changeDislikes(const QString &);

    //CAMBIO DE PERFIL
    void nextProfile();

    //CAMBIO DE VISTA

    //TEST SIGNAL
    void testSignal(std::string testStr);

public slots:

//LANDING PAGE
    void createProfileButton();
    void settingsButton();

//FORMULARIO PAGE

    void minAgeBox(int age);


    void finishProfileButton();

//PROFILE PAGE
    void meetPeopleButton();



//SWIPING PAGE

    //CAMBIO DE PERFIL
    void pass();
    void like();

    //CAMBIO DE VISTA
    void messagesButton();
    void profileButton();
    void backButton();

//MESSAGES PAGE



private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
