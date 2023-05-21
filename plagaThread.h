#ifndef PLAGATHREAD_H
#define PLAGATHREAD_H
#include <QThread>
#include <QLabel>
#include <QRandomGenerator>
#include "tablero.h"
class plagaThread : public QThread{
public:
    bool activas;
    bool running;
    QLabel *plagaLabel;
    int probabilidad;
    int cant;
    int tiempoSeg;
    int frutosComen;
    int tiempoSegComen;
    int tipo;
    tablero *tab;
    plagaThread(QLabel *plagaLabel, int probabilidad, int cant, int tiempoSeg, int frutosComen, int tiempoSegComen, int tipo, tablero *tab){
        activas = false;
        this->plagaLabel = plagaLabel;
        this->probabilidad = probabilidad;
        this->cant = cant;
        this->tiempoSeg = tiempoSeg;
        this->frutosComen = frutosComen;
        this->tiempoSegComen = tiempoSegComen;
        this->tab = tab;
        this->tipo = tipo;
    }
    bool pregunteProbabilidad();
    void aparecerPlaga();
    void esconderPlaga();
    void verificarGranjero(int, int);

    void run();
};
#endif // PLAGATHREAD_H

