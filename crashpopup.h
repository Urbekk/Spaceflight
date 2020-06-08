#ifndef CRASHPOPUP_H
#define CRASHPOPUP_H

#include <QWidget>

namespace Ui {
class crashpopup;
}

class Crashpopup : public QWidget
{
    Q_OBJECT

public:
    explicit Crashpopup(QWidget *parent = nullptr);
    ~Crashpopup();

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
    Ui::crashpopup *ui;
};

#endif // CRASHPOPUP_H
