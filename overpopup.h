#ifndef OVERPOPUP_H
#define OVERPOPUP_H

#include <QWidget>

namespace Ui {
class overpopup;
}

class overpopup : public QWidget
{
    Q_OBJECT

public:
    explicit overpopup(QWidget *parent = nullptr);
    ~overpopup();

private slots:
    void on_pushButton_clicked();

private:
    Ui::overpopup *ui;
};

#endif // OVERPOPUP_H
