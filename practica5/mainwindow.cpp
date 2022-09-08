#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <iostream>
//#include "pared.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    x = 0;
    y = 0;

    puntaje=0;

    int in1 = 0;
    int in2 = 0;

    scene  = new QGraphicsScene(this);

    scene->setSceneRect(0,0,840,920);

    int matrizcopia[21][24]{
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1},
        {1,2,2,3,2,2,2,1,0,1,2,1,0,1,2,2,3,1,2,2,2,1},
        {1,2,1,1,2,1,2,1,0,1,2,1,0,1,2,1,2,2,2,1,2,1},
        {1,2,1,1,2,1,2,1,1,1,2,1,1,1,2,1,1,1,2,1,2,1},
        {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,1},
        {1,2,1,1,2,1,1,1,1,1,0,1,1,1,2,1,2,1,1,1,2,1},
        {1,2,1,1,2,2,2,1,0,0,0,0,0,0,2,1,2,2,2,1,2,1},
        {1,2,1,1,2,1,2,1,0,1,1,1,0,1,2,1,2,1,2,1,2,1},
        {1,2,2,2,2,1,2,0,0,1,0,1,0,1,2,2,2,1,2,2,2,1},
        {1,1,1,1,2,1,1,1,0,0,0,1,0,1,1,1,0,1,1,1,2,1},
        {1,2,2,2,2,1,2,0,0,1,0,1,0,1,2,2,2,1,2,2,2,1},
        {1,2,1,1,2,1,2,1,0,1,1,1,0,1,2,1,2,1,2,1,2,1},
        {1,2,1,1,2,2,2,1,0,0,0,0,0,0,2,1,2,2,2,1,2,1},
        {1,2,1,1,2,1,1,1,1,1,0,1,1,1,2,1,2,1,1,1,2,1},
        {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,1},
        {1,2,1,1,2,1,2,1,1,1,2,1,1,1,2,1,1,1,2,1,2,1},
        {1,2,1,1,2,1,2,1,0,1,2,1,0,1,2,1,2,2,2,1,2,1},
        {1,2,2,3,2,2,2,1,0,1,2,1,0,1,2,2,3,1,2,2,2,1},
        {1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };

    QGraphicsPixmapItem * pixItem = new QGraphicsPixmapItem(QPixmap(":/imagenes/mapa3.png"));
    pixItem->setPos(35,0);
    //pixItem->setPos(55,20);
    scene->addItem(pixItem);

    for (int i = 0; i < 21; ++i) {
        for (int j = 0; j < 24; ++j) {
            matriz[j][i]=matrizcopia[i][j];
            pared[i][j]= new Pared(matrizcopia[i][j],40,40,in2,in1);
            scene->addItem(pared[i][j]);
            in1= in1 +40;

        }
        in1 = 0;
        in2= in2 +40;
    }

    pacman = new Pacman(QPixmap(":/imagenes/pac2.png"));
    scene->addItem(pacman);

    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{

int y2 = pacman->x()/40;
int x2 =(pacman->y())/40;

    switch (event->key()) {
    case Qt::Key_W:
            if(matriz[x2-1][y2]==0){
                pacman->ir_arriba();

            }else if(matriz[x2-1][y2]==2){
                matriz[x2-1][y2]=0;
                pared[y2][x2-1]->setEstado(0);
                pacman->ir_arriba();
                puntaje+=10;

            }else if(matriz[x2-1][y2]==3){
                matriz[x2-1][y2]=0;
                pared[y2][x2-1]->setEstado(0);
                pacman->ir_arriba();
                puntaje+=50;
            }
        break;

    case Qt::Key_S:
        if(matriz[x2+1][y2]==0){
        pacman->ir_abajo();

        }else if(matriz[x2+1][y2]==2){
            matriz[x2+1][y2]=0;
            pared[y2][x2+1]->setEstado(0);
            pacman->ir_abajo();
            puntaje+=10;

        }else if(matriz[x2+1][y2]==3){
            matriz[x2+1][y2]=0;
            pared[y2][x2+1]->setEstado(0);
            pacman->ir_abajo();
            puntaje+=50;

        }
        break;
    case Qt::Key_A:
        if(matriz[x2][y2-1]==0){
                pacman->ir_izquierda();

        }else if(matriz[x2][y2-1]==2){
            matriz[x2][y2-1]=0;
            pared[y2-1][x2]->setEstado(0);
            pacman->ir_izquierda();
            puntaje+=10;

        }else if(matriz[x2][y2-1]==3){
            matriz[x2][y2-1]=0;
            pared[y2-1][x2]->setEstado(0);
            pacman->ir_izquierda();
            puntaje+=50;
        }
        break;

    case Qt::Key_D:
        if(matriz[x2][y2+1]==0){
                pacman->ir_derecha();

        }else if(matriz[x2][y2+1]==2){
            matriz[x2][y2+1]=0;
            pared[y2+1][x2]->setEstado(0);
            pacman->ir_derecha();
            puntaje+=10;

        }else if(matriz[x2][y2+1]==3){
            matriz[x2][y2+1]=0;
            pared[y2+1][x2]->setEstado(0);
            pacman->ir_derecha();
            puntaje+=50;

        }
        break;

    default:
        break;
    }

    ui->lcdNumber->display(puntaje);
}







