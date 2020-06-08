#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
/*!
\mainpage Spaceflight
\section wstep Wprowadzenie
Gra w której sterowanie odbywa się pomocą dedykowanego kontrolera.
\section main Główne okno
W głównym oknie wyświetla się scena rozgrywki, oraz pozostałe informacje takie jak\n
aktualny stan paliwa oraz ilość zdobytych puntków. Pozatym istnieje możliwość\n
otwarcia innych okien poprzez przyciski. Klasa implementująca okno: MainWindow
\section settings Okno ustawień
Okno w którym można podłączyć bądź rozłączyć z wybranym portem do któRego jest\n
podłączony mikrokontroler. Klasa implementująca okno: Settings
\section graph Okno wykresów
Okno które zawiera wykres siły grawitacji jaka oddziałuje na poszczególne\n
osie akcelerometru. Klasa implementująca okno: Graphs
\section doc Dokumentacja
Dokumentacja została wygenerowana za pomocą aplikacji Doxygen.
*/
