#include "yeni_button.h"
#include <mainwindow.h>

yeni_button::yeni_button(QWidget *parrent): QPushButton(parrent)
{

    tiklandimi=false;

    QTimer *timer=new QTimer(this);
    timer->start(50);

    connect(timer,&QTimer::timeout,this,&yeni_button::yerdegistir);
connect(this,&QPushButton::clicked,this,&yeni_button::tikla);

}
void yeni_button::tikla()
{
setStyleSheet("border-image: url(:/kesmekarpuz/2 (1).png);");
QTimer *timer=new QTimer(this);
timer->start(500);
tiklandimi=true;
connect(timer,&QTimer::timeout,this,&yeni_button::cikis);

}

void yeni_button::cikis()
{close();

}

void yeni_button::yerdegistir()
{
setGeometry(x(),y()+5,50,50);
}
