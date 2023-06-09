#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include "qlabel.h"
#include <QPixmap>
#include <QKeyEvent>
#include "granjero.h"
#include "plagaThread.h"
#include "tablero.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "mainwindow.h"
#include <QMutex>
#include "QComboBox"
#include "mercado.h"
#include "qhash.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

namespace Ui {
class Gamewindow;
}
class Gamewindow : public QDialog
{
    Q_OBJECT
    MainWindow *main_window;

public:
    explicit Gamewindow(QWidget *parent = nullptr, MainWindow *m = NULL);
    QLabel *parcelas[8][8];
    QLabel* granjeroLab;
    QLabel* plagaLab;
    QLabel * ovejaLab;
    QLabel * cuervoLab;
    QLabel * recordLab;

    QPixmap abb_;
    QPixmap arj_;
    QPixmap avl_;
    QPixmap heap_;

    int counter_trees;
    QHash<int,QVector<int>> * pos_trees;
    QTableWidget *tabla;
    QComboBox * table_pos;
    granjero * granjero;
    plagaThread * plagahilo;
    plagaThread * ovejahilo;
    plagaThread * cuervohilo;
    tablero * tab;
    QMutex * mutexTablero;
    Mercado* mercado;

    mercado_thread *mercado_thread;
    int t_mercado_abierto;
    int t_mercado_to_abrir;
    void generarLabels();
    void keyPressEvent( QKeyEvent * event);
    void verificarGranjero(int x, int y);
    QString toStringRecords();
    void  agregarRecord(string nombre, double dinero);
  ~Gamewindow();


  void modificar_tableros(int x,int y, int algomas);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_iniciarButton_clicked();

    void on_pushButton_5_clicked();

    void on_guardarButton_clicked();

private:


    Ui::Gamewindow *ui;
};

#endif // GAMEWINDOW_H
