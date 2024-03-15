#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    money+=diff;
    ui->lcdNumber->display(money);
    ui->pbCoffee->setEnabled(money>=100);
    ui->pbTea->setEnabled(money>=150);
    ui->pbMilk->setEnabled(money>=200);
}


void Widget::on_pbCoin10_clicked()
{
    this->changeMoney(10);
}


void Widget::on_pbCoin50_clicked()
{
    this->changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    this->changeMoney(100);
}


void Widget::on_pbCoin500_clicked()
{
    this->changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    this->changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    this->changeMoney(-150);
}

void Widget::on_pbMilk_clicked()
{
    this->changeMoney(-200);
}

void Widget::on_pbRESET_clicked()
{
    QMessageBox msgBox;
    QString qstr = "500won : " + QString::number(money / 500)+
                   "\n100won : "+ QString::number(money%500 /100)+
                   "\n50won : " + QString::number(money%100 /50)+
                   "\n10won : " + QString::number(money%50 /10);
    msgBox.setInformativeText(qstr);
    msgBox.exec();
}




