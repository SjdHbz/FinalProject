#ifndef PROJECT_H
#define PROJECT_H
#include <cstring>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Project; }
QT_END_NAMESPACE

int strl(QString a);
int EmailCheck(QString email);

class Project : public QMainWindow
{
    Q_OBJECT

public:
    Project(QWidget *parent = nullptr);
    ~Project();

private slots:
    void on_StartingMenuButton_clicked();

    void on_EmailHelp_clicked();

    void on_EmailConfirm_clicked();

    void on_PasswordHelp_clicked();

    void on_PasswordConfirm_clicked();

    void on_UsernameHelpPushButton_clicked();

    void on_UsernamePushButton_clicked();

    void on_PasswordSwButton_clicked();

    void on_BudgetHelpPushButton_clicked();

    void on_BudgetPushButton_clicked();

    void on_PhoneNumberHelpPushButton_clicked();


    void on_PhoneNumberComboBox_activated(int index);

    void on_FinalConfirmPushButton_clicked();

    void on_PhoneNumberushButton_clicked();

    void on_CaptchaGeneratePushButton_clicked();

    void on_CaptchaConfirmPushButton_clicked();


private:
    Ui::Project *ui;
};
#endif // PROJECT_H
