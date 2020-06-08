#ifndef FUEL_H
#define FUEL_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QGraphicsScene>
#include <player.h>

class Fuel: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    /*!
     * \brief
     * \param [in] size
     * Wielkość zbiornika z paliwem, liczba skalująca jego obraz.
     * \param [in] velocity
     * Prędkość zbiornika z paliwem, czyli częstotliwość timera odpowiedzialnego za jego ruch.
     */
    Fuel(int size, int velocity);
signals:
    /*!
     * \brief
     * Sygnał połączony ze slotem odpowiedzialnym za dodanie paliwa
     */
    void collect();
public slots:
    /*!
     * \brief
     * Slot poruszający zbiornikami z paliwem, wyzwalany timerem.
     * Ponado sprawdza kolizje zbiorników z postacią gracza.
     */
    void move();
    /*!
     * \brief
     * Zatrzymuje timer odpowiedzialny za ruch paliwa.
     */
    void stopmove();
    /*!
     * \brief
     * Wznawia timer odpowiedzialny za ruch.
     */
    void startmove();
private:
    /*!
     * \brief
     * Wskaźnik na timer odpowiedzialny za ruch.
     */
    QTimer * timer123;
};

#endif // FUEL_H
