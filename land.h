#ifndef LAND_H
#define LAND_H

#include <QDialog>

namespace Ui {
class land;
}

class land : public QDialog
{
    Q_OBJECT

public:
    explicit land(QWidget *parent = nullptr);
    ~land();

private:
    Ui::land *ui;

};

#endif // LAND_H
