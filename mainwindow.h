#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <player.h>
#include <QGraphicsView>
#include <QObject>
#include <QVector>
#include <asteroid.h>
#include <fuel.h>
#include <settings.h>
#include <overpopup.h>
#include <crashpopup.h>
#include <graphs.h>
#include <settings.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /*!
     * \brief
     *Inicjalizacja sceny oraz timerów które obsługują główne elementy rozgrywki.
     */
    void gameInit();
    /*!
     * \brief
     *Powtorne wywolywane parametry inicjalizujace obiekty na scenie, funkcja ta wykorzystywana jest przy rozpoczynaniu nowej gry.
     */
    void repeatableParameters();
signals:
    /*!
     * \brief
     * Syngał połączony ze slotem odpowiedzialnym za zapuazowanie asteroid i paliwa.
     */
    void freeze();
    /*!
     * \brief
     * Sygnał połączony ze slotem wznawiającym ruch po pauzie.
     */
    void resume();
    /*!
     * \brief
     *Sygnał połączony ze slotem odpowiedzialnym za rysowanie nowej paczki danych na wykresie.
     */
    void sendNow(QVector<int> &);
private slots:
    /*!
     * \brief
     * Slot wyzwalany przez timer, tworzy nowe asteroidy na scenie.
     */
    void spawnA();
    /*!
     * \brief
     * Slot wyzwalany przez timer, tworzy nowe obiekty paliwa na scenie.
     */
    void spawnF();
    /*!
     * \brief
     * Slot aktualizuje informacje na ekranie o punktach i pliwie, wywoływany przez timer.
     */
    void countpoints();
    /*!
     * \brief
     * Zatrzymanie wszystkich timerów, używany podczas pauzy.
     */
    void stoptimers();
    /*!
     * \brief
     * Wywoływany w momencie kolizji gracza ze zbiornikiem paliwa, akutalizuje informacje na ekranie o stanie paliwa
     */
    void collectFuel();
    /*!
     * \brief
     * Wywołanie odpowiedniego okna końca gry.
     */
    void gameover();
    /*!
     * \brief
     * Podłączenie aplikacji pod przekazaną nazwe portu od okna ustawień.
     */
    void connection(QString string);
    /*!
     * \brief
     * Odłączenie aplikacji od bieżącego portu.
     */
    void disconnect();
    /*!
     * \brief
     * Odczytywanie danych z urządzenia, przekazywanie ich przez sygnał do okna wykresu.
     */
    void readFromPort();
    /*!
     * \brief
     * Rozpoczęcie nowej rozgrywki.
     */
    void on_pushButtonNewGame_clicked();
    /*!
     * \brief
     * Włącza bądź wyłącza tryb pauzy.
     */
    void on_pushButtonPause_toggled(bool checked);
    /*!
     * \brief
     * Otwarcie okna ustawień.
     */
    void on_pushButtonSettings_clicked();
    /*!
     * \brief
     * Otwarcie okna wykresu.
     */
    void on_pushButtonGraph_clicked();
private:
    /*!
     * \brief
     * Wskaźnik na główne okno.
     */
    Ui::MainWindow * ui;
    /*!
     * \brief
     * Wskaźnik na urządzenie z którego pobierane są dane.
     */
    QSerialPort * device;
    /*!
     * \brief
     * Wskaźnik na okno które wyskakuje jeśli zabraknie paliwa.
     */
    Overpopup * windowFuel;
    /*!
     * \brief
     * Wskaźnik na okno ustawień.
     */
    Settings * windowSettings;
    /*!
     * \brief
     * Wskaźnik na okno które wyskakuje w momencie kolizji z asteroidą.
     */
    Crashpopup * windowCrash;
    /*!
     * \brief
     * Wskaźnik na okno z wykresem.
     */
    Graphs * windowGraph;
    /*!
     * \brief
     * Wskaźnik na scene na którą dodawane są wszystkie obiekty.
     */
    QGraphicsScene * scene;
    /*!
     * \brief
     * Wskaźnik na postać gracza jaką jest rakieta.
     */
    Player * player;
    /*!
     * \brief
     * Wskaźnik na timer odpowiedzialny za tworzenie asteroid.
     */
    QTimer * timer;
    /*!
     * \brief
     * Wskaźnik na timer odpowiedzialny za zliczanie punktów.
     */
    QTimer * timerpoints;
    /*!
     * \brief
     * Wskaźnik na timer odpowiedzialny za tworzenie paliwa.
     */
    QTimer * timerfuel;
    /*!
     * \brief
     * Wskaźnik na obiekty paliwa.
     */
    Fuel * fuel;
    /*!
     * \brief
     * Wskaźnik na obiekty asteroid.
     */
    Asteroid * asteroid;
    /*!
     * \brief
     * Liczba punktów zebranych przez gracza
     */
    int points;
    /*!
     * \brief
     * Aktualny stan paliwa.
     */
    int gas;
    /*!
     * \brief
     * Flaga uniemożliwiająca poruszanie się gracza w momencie trwania pauzy.
     */
    int flag = 0;
    /*!
     * \brief
     * Flaga uniemożliwiająca przesył danych do okna z wykresami jeśli jest zamknięte.
     */
    int drawing = 0;
    /*!
     * \brief
     * Dwu wymiarowy wektor który przechowuje wszystkie dane z akcelerometru od moemntu otwarcia komunikacji z urządzeniem.
     */
    QVector <QVector<int>> pastdata;
};
#endif // MAINWINDOW_H
