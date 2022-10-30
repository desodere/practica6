#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();

  //  timer->start(1);


    connect(timer, &QTimer::timeout, this, &MainWindow::Actualizacion);

    scene = new QGraphicsScene(-450, -450, 900, 900);
    ui->graphicsView->setScene(scene);

    /*ui->graphicsView->setRenderHint(QPainter::Antialiasing);*/

    // limites de la escena
    l1 = new QGraphicsLineItem(-450,-450,450,-450);
    l2 = new QGraphicsLineItem(-450,450,450,450);
    l3 = new QGraphicsLineItem(-450,-450,-450,450);
    l4 = new QGraphicsLineItem(450,-450,450,450);

    // Se agregan los limites a la escena
    scene->addItem(l1);
    scene->addItem(l2);
    scene->addItem(l3);
    scene->addItem(l4);
        //sistema.append(new cuerpo(-200,200,100,50,1,1));
    cont = 0;

    //sistema 1 de tres cuerpo
//    c1 = new cuerpo(0,-7000,70,120,2,0);
//    sistema.append(c1);
//    scene->addItem(sistema.last());

//    c1 = new cuerpo(0,0,70000,300,0,0);
//    sistema.append(c1);
//    scene->addItem(sistema.last());

//    c1 = new cuerpo(4000,5000,25,100,-1.6,1.2);
//    sistema.append(c1);
//    scene->addItem(sistema.last());

    secuencia = false;
//sistema 2 de 5 cuerpos
//    c1 = new cuerpo(0,0,50000,200,0,0);
//    sistema.append(c1);
//    scene->addItem(sistema.last());
//    scene->addItem(c1);

//    c1 = new cuerpo(-5000,0,70,70,0,-2);
//    sistema.append(c1);
//    scene->addItem(sistema.last());
//    scene->addItem(c1);

//    c1 = new cuerpo(5000,0,70,70,0,2);
//    sistema.append(c1);
//    scene->addItem(sistema.last());
//    scene->addItem(c1);

//    c1 = new cuerpo(0,-5000,70,70,2,0);
//    sistema.append(c1);
//    scene->addItem(sistema.last());
//    scene->addItem(c1);

//    c1 = new cuerpo(0,5000,70,70,-2,0);
//    sistema.append(c1);
//    scene->addItem(sistema.last());
//    scene->addItem(c1);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Actualizacion()
{
    if (secuencia){
    cont++;


    double axt=0, ayt=0;
    if(cont<10000){


        qDebug()<< cont;
        for (int i=0 ; i < sistema.length() ; i++){
            str2 = str2 + to_string(sistema[i]->x) + "\t" + to_string(sistema[i]->y)+ "\t";
           // str2 = str2 + to_string(sistema[i]->x) + " " + to_string(sistema[i]->y) + " ";
            qDebug() << i << "------  "<< sistema[i]->x<< " " << sistema[i]->y;
            for (int j=0 ; j < sistema.length() ; j++){
                if(i!=j){

                    sistema[i]->aceleracion(sistema[j]);
                    axt = axt + sistema[i]->ax;
                    ayt = ayt + sistema[i]->ay;

                }

            }
            sistema[i]->aceleracion(axt, ayt);
            sistema[i]->velocidades();
            sistema[i]->posiciones();
            axt = 0;
            ayt = 0;
        }
        fout << str2 << endl;
        str2 =  "";
    }else if(cont==10000){
        qDebug()<< cont;
        secuencia = false;
        fout.close();
    }else{

    }
    }
}

void MainWindow::limpiar()
{
    int i=0;
    cont = 0;
    str2 =  "";
    timer->stop();

    for (i=0 ; i < sistema.length() ; i++)
        scene->removeItem(sistema[i]);

    sistema.clear();

    secuencia = false;
}

void MainWindow::on_lanzamiento1_btn_clicked()
// Lanza el cuerpo 1 en mvto parabolico
{

    limpiar();
    if (!secuencia)
    {
        fout.open("ejercicio1.txt");
        if (!fout)
        {
           qDebug() << "Error al abrir ejemplo.dat\n";
          exit(EXIT_FAILURE);
        }
        //sistema 1 de tres cuerpo
        c1 = new cuerpo(0,-7000,70,120,2,0);
        sistema.append(c1);
        scene->addItem(sistema.last());

        c1 = new cuerpo(0,0,70000,300,0,0);
        sistema.append(c1);
        scene->addItem(sistema.last());

        c1 = new cuerpo(4000,5000,25,100,-1.6,1.2);
        sistema.append(c1);
        scene->addItem(sistema.last());

        secuencia = true;
    }
    timer->start(1);

}


void MainWindow::on_lanzamiento2_btn_clicked()
//Lanza el cuerpo 2 en mvto parabolico
{

    limpiar();
    if (!secuencia)
    {
        fout.open("ejercicio2.txt");
        if (!fout)
        {
           qDebug() << "Error al abrir ejemplo.dat\n";
          exit(EXIT_FAILURE);
        }
        //sistema 2 de 5 cuerpos
            c1 = new cuerpo(0,0,50000,200,0,0);
            sistema.append(c1);
            scene->addItem(sistema.last());
            scene->addItem(c1);

            c1 = new cuerpo(-5000,0,70,70,0,-2);
            sistema.append(c1);
            scene->addItem(sistema.last());
            scene->addItem(c1);

            c1 = new cuerpo(5000,0,70,70,0,2);
            sistema.append(c1);
            scene->addItem(sistema.last());
            scene->addItem(c1);

            c1 = new cuerpo(0,-5000,70,70,2,0);
            sistema.append(c1);
            scene->addItem(sistema.last());
            scene->addItem(c1);

            c1 = new cuerpo(0,5000,70,70,-2,0);
            sistema.append(c1);
            scene->addItem(sistema.last());
            scene->addItem(c1);

        secuencia = true;
    }
     timer->start(1);
}


void MainWindow::on_finalizar_btn_clicked()
//para finalizar la simulacion
{
    limpiar();
}

