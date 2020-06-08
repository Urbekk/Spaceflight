#ifndef OVERPOPUP_H
#define OVERPOPUP_H

#include <QWidget>

namespace Ui {
class overpopup;
}

class Overpopup : public QWidget
{
    Q_OBJECT

public:
    explicit Overpopup(QWidget *parent = nullptr);
    ~Overpopup();

private slots:
    /*!
     * \brief
     * Zamknięcie informacyjnego okna.
     */
    void on_pushButton_clicked();

private:
    /*!
     * \brief
     * Wskaźnik na okno końca rozgrywki.
     */
    Ui::overpopup *ui;
};

#endif // OVERPOPUP_H
