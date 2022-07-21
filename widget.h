#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDir>
#include <QString>
#include "Person.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

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
    //CAMBIO DE ATRIBUTOS
    void changeImage(const QPixmap &);
    void changeName(const QString &);
    void changeAge(const QString &);
    void changeMajor(const QString &);
    void changeLikes(const QString &);
    void changeDislikes(const QString &);

    //CAMBIO DE PERFIL

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
    void profilePicLabel();


//SWIPING PAGE
    //CAMBIO DE ATRIBUTOS
    void buttonHandler();
    void nameSlot();
    void ageSlot();
    void majorSlot();
    void likesSlot();
    void dislikesSlot();

    //CAMBIO DE PERFIL
    void reject();
    void approve();

    //CAMBIO DE VISTA
    void messagesButton();
    void profileButton();
    void backButton();

//MESSAGES PAGE

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
