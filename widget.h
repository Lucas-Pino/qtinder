#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QDir>

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

//CAMBIO DE ATRIBUTOS
   void changeImage(const QPixmap &);
   void changeName(const QString &);
   void changeAge(const QString &);
   void changeMajor(const QString &);
   void changeLikes(const QString &);
   void changeDislikes(const QString &);
   void changeView(int index);

//CAMBIO DE PERFIL

//CAMBIO DE VISTA

public slots:

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

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
