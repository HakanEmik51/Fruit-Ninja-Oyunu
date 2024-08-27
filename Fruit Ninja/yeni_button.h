#ifndef YENI_BUTTON_H
#define YENI_BUTTON_H

#include <QPushButton>
#include <QWidget>

#include <QTimer>

class yeni_button : public QPushButton
{
    Q_OBJECT
public:
    yeni_button(QWidget *parrent=0);
    bool tiklandimi;

public slots:
    void tikla();
    void cikis();
    void yerdegistir();
};

#endif // YENI_BUTTON_H
