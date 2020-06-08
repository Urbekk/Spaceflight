#ifndef ASTEROID_H
#define ASTEROID_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <player.h>

class Asteroid: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    /*!
     * \brief
     * \param[in] size
     * Wielkość asteroidy, liczba która skaluje jej obraz.
     * \param[in] velocity
     * Prędkość asteroidy, czyli częstotliwość timera odpowiedzialnego za jej ruch.
     */
    Asteroid(int size, int velocity);
private:
    /*!
     * \brief
     * Wskaźnik na timer odpowiedzialny za ruch asteroid.
     */
    QTimer * timer;
public slots:
    /*!
     * \brief
     * Slot odpowiedzialny za ruch asteroid po scenie, wyzwalany timerem.
     * Ponado sprawdza kolizje asteroid z graczem.
     */
    void move();
    /*!
     * \brief
     * Slot zatrzymujacy timer odpowiedzialny za ruch asteroid.
     */
    void stopmove();
    /*!
     * \brief
     * Slot wznawaiający timer odpowiedzialny za ruch.
     */
    void startmove();
signals:


};

#endif // ASTEROID_H
