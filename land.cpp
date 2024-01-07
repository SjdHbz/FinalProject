#include "land.h"
#include "QString"
#include "QMessageBox"
#include "ui_land.h"
#include <QSqldatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QTime"
#include "QTimer"
#include "player.h"
#include "worker.h"
#include "animals.h"

int wheat=0;

int managerNumbers;


land::land(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::land)
{
    ui->setupUi(this);

    QSqlDatabase database;                                                       //database opening
    database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("e:\\Codes\\Qt\\FinalProject\\FinalProject.db");
    database.open();                                                              //database opening

    QSqlQuery q;                                                                  //initializing manager number
    QString qry = QString("SELECT sw FROM ManagerNumber");
    q.prepare(qry);
    if(q.exec()){

    }
    else{
        QMessageBox::warning(this,"Err","Err");
    }                                                                            //initializing manager number



    ui->CoinLineEdit->setEnabled(false);   //coin line edit
    ui->CoinLineEdit->setText("10");       //coin line edit
    ui->LandLineEdit->setEnabled(false);  //land line edit
    ui->LandLineEdit->setText("1");       //land line edit

    ui->WorkerLineEdit->setEnabled(false);  //worker line edit
    ui->WorkerLineEdit->setText("1");       //worker line edit


 //   QTimer *timer = new QTimer(this);    //timer
 //   int initialTime = 180000;
  //  timer->setInterval(initialTime);


    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&land::updatetime);
    timer->start(1000);
                                         //timer
}

void land::updatetime(){
    static int secount=0;
    secount++;
    if (secount==181){
        secount=0;
        elepsedTimer.restart();
        QMessageBox::warning(this,"EROR","sjfjksdf");

    }
    int minutes=secount/60;
    int remainingsecount = secount % 60;
    ui->lcdNumber->display(QString("%1:%2").arg(minutes,2,10,QChar('0')).arg(remainingsecount,2,10,QChar('0')));
}



land::~land()
{
    delete ui;
}

void land::on_GreenLandAddPushButton_clicked()     //adding new green land
{
    int coins=ui->CoinLineEdit->text().toInt();
    if(coins>=3){
        coins-=3;
        string newCoin= to_string(coins);
        QString NewCoin = QString::fromStdString(newCoin);
        ui->CoinLineEdit->setText(NewCoin);

        int newLandNumber=ui->LandLineEdit->text().toInt();
        newLandNumber++;
        string NewLandNumber = to_string(newLandNumber);
        QString NLN = QString::fromStdString(NewLandNumber);
        ui->LandLineEdit->setText(NLN);

    }
    else{
        QMessageBox::warning(this,"Nope!","You do not have enough coins to add new land","Ok!");
    }
}                                                  //adding new green land


void land::on_WorkerAddPushButton_clicked()        //adding new worker
{
    int coins=ui->CoinLineEdit->text().toInt();
    if(coins>=5){
        coins-=5;
        string newCoin= to_string(coins);
        QString NewCoin = QString::fromStdString(newCoin);
        ui->CoinLineEdit->setText(NewCoin);

        int newWorkerNumber = ui->WorkerLineEdit->text().toInt();
        newWorkerNumber++;
        string NewWorkerNumber = to_string(newWorkerNumber);
        QString NWN = QString::fromStdString(NewWorkerNumber);
        ui->WorkerLineEdit->setText(NWN);
    }
    else{
        QMessageBox::warning(this,"Nope!","You do not have enough coins to add new worker","Ok!");
    }
}                                                 //adding new worker


void land::on_storePushButton_clicked()
{

}

int land::buy(int price){
    QString s= ui->CoinLineEdit->text();
    int n = s.toInt();
    if(price>n){
        QMessageBox::warning(this,"Oops!","You do not have enough money to buy this item");
        return 0;
    }
    else{
        n-=price;
        ui->CoinLineEdit->setText(QString::number(n));
        return 1;
    }
}

void land::on_WheatBuy_clicked()
{

    if(buy(2)!=0){
        wheat++;
        QString s = QString::number(wheat);
        ui->WheatNumberLabel->setText(s);

    }

}


