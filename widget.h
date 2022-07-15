#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QDir>

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
   void changeImage(const QPixmap &);

//CAMBIO DEL PERFIL
   void changeName();
   void changeAge();
   void changeMajor();
   void changeLikes();



public slots:
    void buttonHandler();



private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
