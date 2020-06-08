#ifndef GRAPHS_H
#define GRAPHS_H

#include <QWidget>
#include <QVector>
#include <QTime>

namespace Ui {
class graphs;
}

class Graphs : public QWidget
{
    Q_OBJECT
private:
    /*!
     * \brief
     * Dolna granica osi czasu (zakres wykresu)
     */
    double start;
public:
    /*!
     * \brief
     * Przeliczanie danych wejściowych na jednostke [g] oraz dodanie wszystkich zaległych pomiarów na wykres.
     * \param [in] data
     * Dwu wymiarowy wektor przechowujący wszystkie surowe dane otrzymane od mikrokontrolera.
     */
    explicit Graphs(QVector<QVector<int>> & data,QWidget *parent = nullptr);
    ~Graphs();
signals:
private slots:
    /*!
     * \brief
     * Dodawanie nowych punktów na wykres, przeliczanie danych na jednostke [g]
     * \param [in] data
     * Wektor surowych danych z akcelerometru (oś x, y, z)
     */
    void newData(QVector<int> & data);


private:
    /*!
     * \brief
     * Wskaźnik na okno wykresów.
     */
    Ui::graphs *ui;
};

#endif // GRAPHS_H
