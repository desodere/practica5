#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <iostream>
#include <QTimer>
//#include "pared.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer();

    timer->start(50);

    connect(timer, &QTimer::timeout, this, &MainWindow::Actualizacion_puntuacion);

    x = 0;
    y = 0;

    puntaje=0;

    int in1 = 0;
    int in2 = 0;

    QRect Desktop = QApplication::desktop()->screenGeometry();

    x = Desktop.x();
    y = Desktop.y();
    qDebug() << Desktop.width();
    ancho = Desktop.width()/2.3;
    alto = Desktop.height()-200;

    scene = new QGraphicsScene(x, y, ancho, alto);
    scene->setBackgroundBrush(Qt::black);
//    int matrizcopia[21][24]{
//    vector<vector<int>> matriz
//        {
//        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//        {1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1},
//        {1,2,2,3,2,2,2,1,0,1,2,1,0,1,2,2,3,1,2,2,2,1},
//        {1,2,1,1,2,1,2,1,0,1,2,1,0,1,2,1,2,2,2,1,2,1},
//        {1,2,1,1,2,1,2,1,1,1,2,1,1,1,2,1,1,1,2,1,2,1},
//        {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,1},
//        {1,2,1,1,2,1,1,1,1,1,0,1,1,1,2,1,2,1,1,1,2,1},
//        {1,2,1,1,2,2,2,1,0,0,0,0,0,0,2,1,2,2,2,1,2,1},
//        {1,2,1,1,2,1,2,1,0,1,1,1,0,1,2,1,2,1,2,1,2,1},
//        {1,2,2,2,2,1,2,0,0,1,0,1,0,1,2,2,2,1,2,2,2,1},
//        {1,1,1,1,2,1,1,1,0,0,0,1,0,1,1,1,0,1,1,1,2,1},
//        {1,2,2,2,2,1,2,0,0,1,0,1,0,1,2,2,2,1,2,2,2,1},
//        {1,2,1,1,2,1,2,1,0,1,1,1,0,1,2,1,2,1,2,1,2,1},
//        {1,2,1,1,2,2,2,1,0,0,0,0,0,0,2,1,2,2,2,1,2,1},
//        {1,2,1,1,2,1,1,1,1,1,0,1,1,1,2,1,2,1,1,1,2,1},
//        {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,1},
//        {1,2,1,1,2,1,2,1,1,1,2,1,1,1,2,1,1,1,2,1,2,1},
//        {1,2,1,1,2,1,2,1,0,1,2,1,0,1,2,1,2,2,2,1,2,1},
//        {1,2,2,3,2,2,2,1,0,1,2,1,0,1,2,2,3,1,2,2,2,1},
//        {1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1},
//        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//    };

    QGraphicsPixmapItem * pixItem = new QGraphicsPixmapItem(QPixmap(":/imagenes/mapa3.png"));
    pixItem->setPos(35,0);
    //pixItem->setPos(55,20);
   // scene->addItem(pixItem);

//    for (int i = 0; i < 21; ++i) {
//        for (int j = 0; j < 24; ++j) {
//            matriz[j][i]=matrizcopia[i][j];
//            pared[i][j]= new Pared(matrizcopia[i][j],40,40,in2,in1);
//            scene->addItem(pared[i][j]);
//            in1= in1 +40;

//        }
//        in1 = 0;
//        in2= in2 +40;
//    }

    for (int i = 0; i < matriz.size(); i++)
        {

            for (int j = 0; j < matriz[i].size(); j++)
            {

//                pared[i][j]= new Pared(matriz[i][j],40,40,in2,in1);
//                            scene->addItem(pared[i][j]);
                pared[i][j]= new Pared(matriz[i][j],40,40,in2,in1);
                            scene->addItem(pared[i][j]);
                            in1= in1 +40;
                //qDebug()  << matriz[i][j] << " ";
            }
            in1 = 0;
            in2= in2 +40;
        }
//    copy(matrizcopia.begin(), matrizcopia.end(), matriz.begin());
//    for (int i = 0; i < matriz.size(); i++)
//        {
//            for (int j = 0; j < matriz[i].size(); j++)
//            {
//                qDebug()  << matriz[i][j] << " ";
//            }
//            cout << endl;
//        }

  //  pacman = new Pacman();
    pacman = new Pacman(QPixmap(":/imagenes/spt1_40.png"));

    scene->addItem(pacman);
//    pacman->setPos(400,640);
    pacman->setPos(420,660);

    ui->graphicsView->setScene(scene);

    ui->lcdNumber->display(pacman->puntaje);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{

//    int y2 = pacman->x()/40;
//    int x2 =(pacman->y())/40;

    switch (event->key()) {
        case Qt::Key_S://Arriba
        pacman->direccion=2;
            qDebug()<<" 2";
            break;
        case Qt::Key_D://derecha
        pacman->direccion=0;
            qDebug()<<" 0";
            break;
        case Qt::Key_Z://abajo
        pacman->direccion=3;
            qDebug()<<" 3";
            break;
        case Qt::Key_A://Izquierda
        pacman->direccion=1;
            qDebug()<<" 1";
            break;
        default:
           break;
    }



}

void MainWindow::Actualizacion_puntuacion()
{

    int y2 = pacman->x()/40;
    int x2 =(pacman->y())/40;
    if(matriz[y2][x2]!=1){
        pacman->matriz[y2][x2]=0;
        matriz[y2][x2]=0;
      //  matriz[x2][y2+1]=0;
      //  pared[x2][y2+1]->setEstado(0);
        pared[y2][x2]->setEstado(0);
    }


     ui->lcdNumber->display(pacman->puntaje);
}







