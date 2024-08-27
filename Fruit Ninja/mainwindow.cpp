#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"yeni_button.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{   ui->setupUi(this);



    QTimer *timer=new QTimer(this);
timer->start(750);
    connect(timer,&QTimer::timeout,this,&MainWindow::olustur);
QTimer *timer2=new QTimer(this);
timer2->start(25);
connect(timer2,&QTimer::timeout,this,&MainWindow::tikladimi);

QTimer *timer3=new QTimer(this);
timer3->start(1000);
connect(timer3,&QTimer::timeout,this,&MainWindow::zaman);
















}






MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::olustur()
{if(sure>0){
    QStringList konum;
    QFile my_file("konumlar.txt");
         if(!my_file.open(QIODevice::ReadOnly)){

             QMessageBox::critical(this,"hata",my_file.errorString() );
                     return;
     }
         QTextStream dosya(&my_file);
          while(!dosya.atEnd()){


              QString satir=dosya.readLine();

              konum.append(satir);






}
          my_file.close();
yeni_button *btn=new yeni_button(this);
     QStringList gecici;
     int i=QRandomGenerator::global()->bounded(0,29);
     gecici=konum[i].split(" ");
     int x=gecici[0].toInt();
     int y=gecici[1].toInt();
               btn->setGeometry(x,y,50,50);
               btn->setStyleSheet("border-image: url(:/karpuz/1 (1).png);");
btn_list.push_back(btn);

btn->show();}
}
void MainWindow::tikladimi()
{if(sure>=0){
    int z=0;
    int kacan=0;
    int btn_sayi=btn_list.size();
   for (int var = 0; var < btn_sayi; ++var) {
       if(!btn_list[var]->tiklandimi && btn_list[var]->y()>950)
       {++kacan;
       }
        if(btn_list[var]->tiklandimi){
         z++;
         //kacan=btn_sayi-z;

        }

    }

   ui->lbl->setText("kesilen karpuz sayisi:"+QString::number(z)+"\nkaçırılan karpuz sayısı:"
                  +QString::number(kacan));
    QStringList skor;
    QFile my_file("skorlar.txt");
         if(!my_file.open(QIODevice::ReadOnly)){

             QMessageBox::critical(this,"hata",my_file.errorString() );
                     return;
     }
         QTextStream dosya(&my_file);
          while(!dosya.atEnd()){


              QString satir=dosya.readLine();

              skor.append(satir);






}
          my_file.close();
int en_byk=skor[1].toInt();

for(int i=0;i<skor.size();i++){
if(skor[i].toInt()>en_byk)
{
    en_byk=skor[i].toInt();
}
}
skor.append(QString::number(z));
    if(sure==0){
    if(en_byk>z){
        QFile my_file3("skorlar.txt");
        if(!my_file3.open(QIODevice::WriteOnly)){

            QMessageBox::critical(this,"hata",my_file.errorString() );
                    return;
    }
        QTextStream dosya3(&my_file3);
        for (int var = 0; var < skor.size(); ++var) {
            dosya3 << skor[var]+"\n";
        }
        my_file3.close();
       QMessageBox::information(this,"bilgi","Oyun Bitti! Maksimum Skoru Geçemediniz!"
                               "\nkesilen karrpuz sayisi:"+QString::number(z)+
                                 "\nkaçırılan karpuz sayisi:"+QString::number(kacan)+
                                 "\nmaximum skor:"+QString::number(en_byk));
       close();

    }
   else{
        QFile my_file3("skorlar.txt");
        if(!my_file3.open(QIODevice::WriteOnly)){

            QMessageBox::critical(this,"hata",my_file.errorString() );
                    return;
    }
        QTextStream dosya3(&my_file3);
        for (int var = 0; var < skor.size(); ++var) {
            dosya3 << skor[var]+"\n";
        }
        my_file3.close();
        QMessageBox::information(this,"bilgi","Oyun Bitti!Tebrikler Maksimum Skor Sizde!"
                                                      "\nKesilen Karpuz Sayısı:"+QString::number(z)+
                                                         "\nKaçırılan Karpuz Sayısı:"+QString::number(kacan)+
                                                         "\nMaximum Skor:"+QString::number(en_byk));
                               close();


   }

}}

}

void MainWindow::zaman()
{sure--;
if(sure>=0){

    ui->label->setText("süre:"+QString::number(sure));}
    }














