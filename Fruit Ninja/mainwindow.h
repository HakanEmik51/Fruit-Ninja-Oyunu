#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include<QFile>
#include<QMessageBox>
#include "yeni_button.h"
#include<QString>
#include <QList>
#include<QStringList>
#include <QTimer>

#include<QRandomGenerator>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



public slots:
void olustur();
void tikladimi();
void zaman();



private:
    Ui::MainWindow *ui;
 QList<yeni_button*>btn_list;
int sure=30;
};
#endif // MAINWINDOW_H
