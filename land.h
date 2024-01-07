#ifndef LAND_H
#define LAND_H

#include <QDialog>
#include "QTimer"
#include "QTime"
#include "QElapsedTimer"
namespace Ui {
class land;
}

class land : public QDialog
{
    Q_OBJECT

public:
    int buy(int);
    explicit land(QWidget *parent = nullptr);
    ~land();

private slots:
    void updatetime();

    void on_GreenLandAddPushButton_clicked();

    void on_WorkerAddPushButton_clicked();

    void on_storePushButton_clicked();

    void on_WheatBuy_clicked();


private:
    Ui::land *ui;
    QTimer *timer;
    QElapsedTimer elepsedTimer;
};

#endif // LAND_H
