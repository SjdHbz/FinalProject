#include "project.h"
#include <cstring>
#include <QString>
#include "ui_project.h"
#include "QMessageBox"
#include "QRegExpValidator"
#include <QSqldatabase>
#include "QSqlDriver"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "land.h"



Project::Project(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Project)
{
    ui->setupUi(this);
    ui->CaptchaGenerateLineEdit->hide();
    ui->CaptchaGeneratePushButton->hide();
    ui->CaptchaLabel->hide();
    ui->CaptchaLineEdit->hide();
    ui->CaptchaConfirmPushButton->hide();
    ui->BudgetHelpPushButton->hide();
    ui->BudgetLable->hide();
    ui->BudgetLineEdit->hide();
    ui->BudgetPushButton->hide();
    ui->PhoneNumberComboBox->hide();
    ui->PhoneNumberHelpPushButton->hide();
    ui->PhoneNumberLabel->hide();
    ui->PhoneNumberLineEdit->hide();
    ui->PhoneNumberHelpPushButton->hide();
    ui->PhoneNumberushButton->hide();
    ui->AreaCodeLabel->hide();
    ui->FinalConfirmPushButton->hide();

    ui->CaptchaGenerateLineEdit->setReadOnly(true);          //cpatcha generating line edit

    QString s="0";                         //the number of managers and switch of begining

    ui->AreaCodeLabel->setStyleSheet("background-color: rgb(128,128,128);");         //Area code label background



    ui->SignUpBox->hide();
    QRegExp rx("[A-Z a-z 0-9]+");
    QRegExpValidator *validator2=new QRegExpValidator(rx,this);   //validator of password line edit
    ui->PasswordLineEdit->setValidator(validator2);

    QValidator *validator4 = new QIntValidator(10000,99999,this);
    ui->CaptchaLineEdit->setValidator(validator4);

    QValidator *validator3 = new QIntValidator(this);      //validator of budget line edit
    ui->BudgetLineEdit->setValidator(validator3);

    ui->PhoneNumberLineEdit->setValidator(validator3);     //validator of phone number line edit

    ui->ManagerNumber->hide();             //objects of starting menu
    ui->StartingMenuLable->hide();
    ui->StartingMenuButton->hide();
    ui->StartingMenu->hide();              //objects of starting menu



    ui->PhoneNumberComboBox->addItem("Iran");          //items of area code combo box
    ui->PhoneNumberComboBox->addItem("USA");
    ui->PhoneNumberComboBox->addItem("Mexico");
    ui->PhoneNumberComboBox->addItem("UK");
    ui->PhoneNumberComboBox->addItem("China");
    ui->PhoneNumberComboBox->addItem("Russia");
    ui->PhoneNumberComboBox->addItem("India");
    ui->PhoneNumberComboBox->addItem("Brazil");
    ui->PhoneNumberComboBox->addItem("Australia");
    ui->PhoneNumberComboBox->addItem("Germany");      //items of area code combo box



    QSqlDatabase database;                                                       //database opening
    database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("e:\\Codes\\Qt\\FinalProject\\FinalProject.db");
    database.open();                                                              //database opening



    QValidator *validator = new QIntValidator( this);     //setting validation of managernumber
    ui->ManagerNumber->setValidator(validator);



    QSqlQuery q;                                                             //menu of first time running
    q.exec("SELECT sw FROM ManagerNumber WHERE sw = '"+s+"' ");
    if(q.first()){
        QMessageBox::information(this , "Welcome","Hello! Please enter the number of managers"
                                 "<li>"
                                 "Obviously it can not be zero!"
                                 "<li>");
        ui->ManagerNumber->show();
        ui->StartingMenuButton->show();
        ui->StartingMenuLable->show();
        ui->StartingMenu->show();

                                                                              //menu of first time running
    }
}

Project::~Project()
{
    delete ui;
}


int strl(QString a){                   //strlen for string
    int i=0;
    while(a[i]!='\0'){
        i++;
    }
    return i;
}                                     //strlen for string

int EmailCheck(QString email){              //0 no              1 find           checking email validity
    int i,j,sw=0;
    QString a="@gmail.com",b="@email.com",c="@mail.um.ac";
    for(i=strl(email)-1,j=9;i>strl(email)-11;i--,j--){
        if(email[i]!=a[j]){
            break;
        }
    }
    if(i==strl(email)-11){
        sw=1;
        return sw;
    }
    for(i=strl(email)-1,j=9;i>strl(email)-11;i--,j--){
        if(email[i]!=b[j]){
            break;
        }
    }
    if(i==strl(email)-11){
        sw=1;
        return sw;
    }
    for(i=strl(email)-1,j=10;i>strl(email)-12;i--,j--){
        if(email[i]!=c[j]){
            break;
        }
    }
    if(i==strl(email)-12){
        sw=1;
        return sw;
    }
    return 0;                                               //checking email validity
}

void Project::on_StartingMenuButton_clicked()                //first time running push button
{
    QSqlQuery q;
    QString s=ui->ManagerNumber->text();
    if(s=="0"){
        QMessageBox::warning(this , "Error ","Invalid value");
    }
    else{
        q.exec("UPDATE ManagerNumber SET sw='"+s+"'");
        QMessageBox::information(this , "Hi guys!","The number of managers is set");
        ui->StartingMenuLable->hide();
        ui->StartingMenuButton->hide();
        ui->StartingMenu->hide();
        ui->ManagerNumber->hide();
        ui->SignUpBox->show();
        ui->PasswordConfirm->hide();
        ui->PasswordHelp->hide();
        ui->PasswordLable->hide();
        ui->PasswordLineEdit->hide();
        ui->PasswordSwButton->hide();
        ui->UsernameHelpPushButton->hide();
        ui->UsernameLabel->hide();
        ui->UsernameLineEdit->hide();
        ui->UsernamePushButton->hide();
    }

                                                              //first time running push button
}


void Project::on_EmailHelp_clicked()                                   //hints of email(Email help push button)
{
    QMessageBox::information(this , "Hints","Your email adress cannot include belowing characters:"
                             "<li>"
                             "<ul>"
                             "*+-/$#^%"
                             "</ul>"
                             "<li>"
                             "Your email adress should ends whith one of belowing phrases:"

                             "<ul>"
                             "<li>"
                             "@gmail.com"
                             "<li>"
                             "@email.com"
                             "<li>"
                             "@mail.um.ac"
                             "<li>"
                             "</ul>");                               //hints of email(Email help push button)
}


void Project::on_EmailConfirm_clicked()             //Confirming email and inserting it into database
{

    QString email=ui->EmaillineEdit->text(),forbid="*+-/$#^%";
    if(strl(email)==0){
        QMessageBox::warning(this , "Error","This feild is necessary");
    }
    QSqlQuery p;
    p.exec("SELECT Email FROM Information WHERE Email='"+email+"'");
    if(p.first()){
        QMessageBox::warning(this , "Error","This email already exists."
                             "<li>"
                             "Please try again"
                             "<li>");
    }

    else{
        QSqlQuery q;
        int sw=0,i,j,forbidsw=0;
        for(i=0;i<strl(email) && forbidsw==0;i++){
            for(j=0;j<8;j++){
                if(email[i]==forbid[j]){
                    forbidsw=1;

                }
            }
        }
        if(forbidsw==1){
            QMessageBox::warning(this , "Error","Your email adress cannot include belowing characters:"
                                 "<li>"
                                 "*+-/$#^%"
                                 "<li>");
        }
        sw=EmailCheck(email);
        if(sw==0){
            QMessageBox::warning(this , "Error","Your email adress is invalid. Please try again");
        }
        if(sw==1 && forbidsw==0){
//            q.exec("INSERT INTO Information(Email) VALUES('"+email+"') ");

            ui->PasswordConfirm->show();
            ui->PasswordSwButton->show();
            ui->PasswordHelp->show();
            ui->PasswordLable->show();
            ui->PasswordLineEdit->show();
            ui->PasswordSwButton->setStyleSheet("image: url(:/Hide.jpg);");
            QMessageBox::information(this , "Done!", "Your email adress is successfully set");
        }
    }
}                                                   //Confirming email and inserting it into database


void Project::on_PasswordHelp_clicked()            //help of password
{
    QMessageBox::information(this,"Hint","Your password can only contain letters and numbers"
                             "<li>"
                             "Your password should have at least 4 characters or numbers"
                             "<li>");
}                                                   //help of password


void Project::on_PasswordConfirm_clicked()        //confirming password bottun
{
    QSqlQuery q;
    QString pass=ui->PasswordLineEdit->text(),email=ui->EmaillineEdit->text();
    if(strl(pass)==0){
        QMessageBox::warning(this , "Error","This feild is necessary");
    }
    else{
        if(strl(pass)<4){
            QMessageBox::warning(this , "Error","The least valid length for password is 4");
        }
        else{

//                q.exec("INSERT INTO Information(Password) VALUES('"+pass+"') WHERE Email='"+email+"'");
                ui->UsernameHelpPushButton->show();
                ui->UsernameLabel->show();
                ui->UsernameLineEdit->show();
                ui->UsernamePushButton->show();
                QMessageBox::information(this ,"Done!", "Your password is succesfully set");

        }
    }
                                                     //confirming password bottun
}






void Project::on_UsernameHelpPushButton_clicked()
{
    QMessageBox::information(this , "Have fun!","There is no limit"
                             "<li>"
                             "You can use all available characters in your keyboard"
                             "<li>");
}


void Project::on_UsernamePushButton_clicked()   //Confirming username
{
    QSqlQuery q,p;
    QString s=ui->UsernameLineEdit->text(),email=ui->EmaillineEdit->text();
    if(strl(s)==0){
        QMessageBox::warning(this , "Error","This feild is necessary");
    }
    else{
        p.exec("SELECT username FROM Information WHERE username='"+s+"'");
        if(p.first()){
            QMessageBox::warning(this,"Error","This username already exists"
                                 "<li>"
                                 "Please try again"
                                 "<li>");
        }

        else{

//                q.exec("INSERT INTO Information(username) VALUES('"+s+"') WHERE Email='"+email+"'");
                QMessageBox::information(this ,"Done!", "Your username is succesfully set");
                ui->BudgetHelpPushButton->show();
                ui->BudgetLable->show();
                ui->BudgetLineEdit->show();
                ui->BudgetPushButton->show();

        }
    }

}                                                //Confirming username


void Project::on_PasswordSwButton_clicked()
{
    static bool check=true;
    if(check){
        ui->PasswordSwButton->setStyleSheet("image: url(:/Show.jpg);");
        ui->PasswordLineEdit->setEchoMode(QLineEdit::Password);
        check=false;
    }
    else{
        ui->PasswordSwButton->setStyleSheet("image: url(:/Hide.jpg);");
        ui->PasswordLineEdit->setEchoMode(QLineEdit::Normal);
        check=true;
    }
}


void Project::on_BudgetHelpPushButton_clicked()
{
    QMessageBox::information(this,"Hint","Enter the budget that you wanna invest in the farm"
                             "<li>"
                             "(It cant be zero)"
                                         "<li>");
}


void Project::on_BudgetPushButton_clicked()
{
    QString Budget=ui->BudgetLineEdit->text();
    long int budgetCheck=ui->BudgetLineEdit->text().toInt();
    QSqlQuery q;
    if(strl(Budget)==0){
        QMessageBox::warning(this,"Error","This feild is necessary");
    }
    else{
        if(budgetCheck<=0){
            QMessageBox::warning(this , "Error","Invalid budget. Please try again");
        }
        else{
//            q.exec("INSERT INTO Information(budget) VALUES('"+Budget+"')");
            QMessageBox::information(this,"Done!","The budget is successfully set.");
            ui->AreaCodeLabel->show();
            ui->PhoneNumberComboBox->show();
            ui->PhoneNumberHelpPushButton->show();
            ui->PhoneNumberLabel->show();
            ui->PhoneNumberLineEdit->show();
            ui->PhoneNumberushButton->show();
        }
    }
}


void Project::on_PhoneNumberHelpPushButton_clicked()
{
    QMessageBox::information(this , "Hint","First choose your area code from combo box"
                             "<li>"
                             "Then enter your phone number in the line edit"
                             "<li>");
}





void Project::on_PhoneNumberComboBox_activated(int index)     //Area code lable
{
    switch (index) {
    case 0:
            ui->AreaCodeLabel->setText("0098");
     break;
     case 1:
           ui->AreaCodeLabel->setText("001");
    break;
    case 2:
           ui->AreaCodeLabel->setText("0052");
        break;
    case 3:
        ui->AreaCodeLabel->setText("0044");
        break;
    case 4:
        ui->AreaCodeLabel->setText("0086");
        break;
    case 5:
        ui->AreaCodeLabel->setText("007");
        break;
    case 6:
        ui->AreaCodeLabel->setText("0091");
        break;
    case 7:
        ui->AreaCodeLabel->setText("0055");
        break;
    case 8:
        ui->AreaCodeLabel->setText("0061");
        break;
    case 9:
        ui->AreaCodeLabel->setText("0049");
        break;
    }
}                                                              //Area code lable







void Project::on_FinalConfirmPushButton_clicked()       //Final Confirm push button
{
    QSqlQuery q;
    static int i=0;
    int n=ui->ManagerNumber->text().toInt();
    QString phone=ui->PhoneNumberLineEdit->text();
    QString email=ui->EmaillineEdit->text();
    QString user=ui->UsernameLineEdit->text();
    QString pass=ui->PasswordLineEdit->text();
    QString money=ui->BudgetLineEdit->text();
    QString Acode=ui->AreaCodeLabel->text();

        q.exec("INSERT INTO Information(Email,Password,username,budget,PhoneNumber,AreaCode)VALUES('"+email+"','"+pass+"','"+user+"','"+money+"','"+phone+"','"+Acode+"')");
        i++;
        if(i>=n){
            QMessageBox::information(this,"Done!","Thanks! Lets start the game!");
            land *myLand= new land;
            myLand->show();
            this->close();
         //   land *Land= new land();

        }
        else{
                ui->PhoneNumberLineEdit->setText("");
                ui->EmaillineEdit->setText("");
                ui->UsernameLineEdit->setText("");
                ui->PasswordLineEdit->setText("");
                ui->BudgetLineEdit->setText("");
                ui->CaptchaLineEdit->setText("");

                ui->FinalConfirmPushButton->hide();
                ui->CaptchaConfirmPushButton->hide();
                ui->CaptchaGenerateLineEdit->hide();
                ui->CaptchaGeneratePushButton->hide();
                ui->CaptchaLabel->hide();
                ui->CaptchaLineEdit->hide();
                ui->PasswordConfirm->hide();
                ui->PasswordHelp->hide();
                ui->PasswordLable->hide();
                ui->PasswordLineEdit->hide();
                ui->PasswordSwButton->hide();
                ui->UsernameHelpPushButton->hide();
                ui->UsernameLabel->hide();
                ui->UsernameLineEdit->hide();
                ui->UsernamePushButton->hide();
                ui->BudgetHelpPushButton->hide();
                ui->BudgetLable->hide();
                ui->BudgetLineEdit->hide();
                ui->BudgetPushButton->hide();
                ui->PhoneNumberComboBox->hide();
                ui->PhoneNumberushButton->hide();
                ui->PhoneNumberHelpPushButton->hide();
                ui->PhoneNumberLabel->hide();
                ui->PhoneNumberLineEdit->hide();
                ui->AreaCodeLabel->hide();
                QMessageBox::information(this,"Done!","All informatios are successfully set"
                                         "<li>"
                                         "Lets go for the next manager"
                                         "<li>");
        }
        i++;

}                                                                      //Final Confirm push button


void Project::on_PhoneNumberushButton_clicked()       //Phone number confirm button
{
    QString phone=ui->PhoneNumberLineEdit->text();
    if(strl(phone)==0){
        QMessageBox::warning(this , "Error","This feild is necessary");
    }
    else{
        ui->CaptchaGenerateLineEdit->show();
        ui->CaptchaGeneratePushButton->show();
        ui->CaptchaLabel->show();
        ui->CaptchaLineEdit->show();
        ui->CaptchaConfirmPushButton->show();
    }
}                                                       //Phone number confirm button


void Project::on_CaptchaGeneratePushButton_clicked()
{
    int random= rand()%90000+10000;
    ui->CaptchaGenerateLineEdit->setText(QString::number(random));
}


void Project::on_CaptchaConfirmPushButton_clicked()
{
    QString c=ui->CaptchaGenerateLineEdit->text(),d=ui->CaptchaLineEdit->text();

    if(c==d){
        ui->FinalConfirmPushButton->show();
    }
    else{
        QMessageBox::warning(this,"Error","Incorrect code"
                             "<li>"
                             "Please try again"
                             "<li>");
        int random= rand()%90000+10000;
        ui->CaptchaGenerateLineEdit->setText(QString::number(random));
    }
}




