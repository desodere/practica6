#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QTimer>
#include <fstream>
#include <sstream>


#include "cuerpo.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QGraphicsScene *scene;

    // temporizador para el pulso
    QTimer *timer;

    //limites
    QGraphicsLineItem *l1;
    QGraphicsLineItem *l2;
    QGraphicsLineItem *l3;
    QGraphicsLineItem *l4;

    cuerpo *c1;
    //lista de objetos
    QList <cuerpo*> sistema;

    void Actualizacion();
    int cont ;
    ifstream fin;               //stream de entrada, lectura
    ofstream fout;              //stream de salida, escritura
    string str2 = "";

    //booleano para controlar la simulación
    bool secuencia;
    void limpiar();
private slots:
    void on_lanzamiento1_btn_clicked();

    void on_lanzamiento2_btn_clicked();

    void on_finalizar_btn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
