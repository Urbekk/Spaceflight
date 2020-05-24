#ifndef CRASHPOPUP_H
#define CRASHPOPUP_H

#include <QWidget>

namespace Ui {
class crashpopup;
}

class crashpopup : public QWidget
{
    Q_OBJECT

public:
    explicit crashpopup(QWidget *parent = nullptr);
    ~crashpopup();

private slots:
    void on_pushButton_clicked();

private:
    Ui::crashpopup *ui;
};

#endif // CRASHPOPUP_H
