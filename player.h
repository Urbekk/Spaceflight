#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsScene>


class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player();
    ~Player();
    //void keyPressEvent(QKeyEvent * event);
    /*!
     * \brief
     * Zamiana surowych danych z akcelerometru na sterowanie postacia gracza.
     * \param [in] x
     * Odczyt z osi x.
     * \param [in] y
     * Odczyt z osi y.
     */
    void moveACC(int & x, int & y);
signals:
    /*!
     * \brief
     * Sygnał połączony ze slotem odpowiedzialnym za zatrzymanie systemu zliczania punktów.
     */
    void stop();
    /*!
     * \brief
     * Sygnał połączony ze slotem odpowiedzialnym za pokazanie okna konca rozgrywki w przypadku przegranej.
     */
    void crash();
public slots:


};

#endif // MYRECT_H
