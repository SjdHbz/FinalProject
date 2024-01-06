#include "land.h"
#include "ui_land.h"
#include "QTime"
#include "QTimer"
#include "player.h"
#include "worker.h"
#include "animals.h"
land::land(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::land)
{
    ui->setupUi(this);

    ui->CoinLineEdit->setEnabled(false);   //coin line edit
    ui->CoinLineEdit->setText("10");       //coin line edit

    ui->LandLineEdit->setEnabled(false);  //land line edit
    ui->LandLineEdit->setText("1");       //land line edit

    ui->WorkerLineEdit->setEnabled(false);  //worker line edit
    ui->WorkerLineEdit->setText("1");       //worker line edit


    QTimer *timer = new QTimer(this);    //timer
    timer->setInterval(3 * 60 * 1000);
    connect(timer, &QTimer::timeout, [=]() {});
    timer->start();                     //timer

}



land::~land()
{
    delete ui;
}
