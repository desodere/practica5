#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QMouseEvent>

#include "rectangulo.h"
#include <iostream>
//#include "pared.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


/*
    scene  = new Scene(this);
    scene->setSceneRect(-230,-270,471,520);// ejemplo
    //scene->setSceneRect(-10,-10,471,520);

    QGraphicsPixmapItem * pixItem = new QGraphicsPixmapItem(QPixmap(":/imagenes/mapa.png"));
    scene->addItem(pixItem);
    pixItem->setPos(
                QPointF(0,0)-QPointF(pixItem->boundingRect().width()/2,
                                     pixItem->boundingRect().height()/2)); //ejemplo
    scene->addLine(-400,0,400,0,QPen(Qt::blue));//linea
    scene->addLine(0,-400,0,400,QPen(Qt::blue));//linea

    Rectangulo * rect = new Rectangulo();
    scene->addItem(rect);


    ui->graphicsView->setScene(scene);
*/


    scene  = new QGraphicsScene(this);

    //scene->setSceneRect(0,0,400,400);
    scene->setSceneRect(0,0,820,950);
    //moob1->pintar();



//    pared[0]= new Pared(10.1,10.0,-110.0,-110.0);
//    scene->addItem(pared[0]);
//    pared[1]= new Pared(20,20,80,-120);
//    scene->addItem(pared[1]);
//    pared[2]= new Pared(30,20,70,70);
//    scene->addItem(pared[2]);
//    pared[3]= new Pared(40,40,-140,60);
//    scene->addItem(pared[3]);
//    pared[4]= new Pared(5,5,-5,-5);
//    scene->addItem(pared[4]);
    int in1 = 0;
    int in2 = 0;

    int matrizcopia[21][24]{
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1},
        {1,2,2,2,2,2,2,1,0,1,2,1,0,1,2,2,2,1,2,2,2,1},
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
        {1,2,2,2,2,2,2,1,0,1,2,1,0,1,2,2,2,1,2,2,2,1},
        {1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},


    };


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
    //scene  = new QGraphicsScene(this);
    //scene->setSceneRect(0,15,471,520);
    pacman = new Pacman(QPixmap(":/imagenes/pac2.png"));
    scene->addItem(pacman);

    ui->graphicsView->setScene(scene);

    x = 0;
    y = 0;

    /*
    pared[0]= new Pared(40,40,1,1);
    scene->addItem(pared[0]);
    pared[1]= new Pared(40,40,1,60);
    scene->addItem(pared[1]);
    pared[2]= new Pared(40,40,1,100);
    scene->addItem(pared[2]);
    pared[3]= new Pared(40,40,1,140);
    scene->addItem(pared[3]);
    pared[4]= new Pared(40,40,1,180);
    scene->addItem(pared[4]);
*/

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::keyPressEvent(QKeyEvent *event)
{
/*
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 23; ++j) {
            qDebug("%s=%d", "jum ",matriz[i][j]) ;
           // qDebug().nospace().noquote() <<matriz[j][i];



        }

    }
*/
int y2 = pacman->x()/40;
int x2 =(pacman->y())/40;
/*
qDebug() <<"p "<< matriz[x2][y2];
qDebug() <<"w "<< matriz[x2][y2+1];
qDebug() <<"s "<< matriz[x2][y2-1];
qDebug() <<"d "<< matriz[x2+1][y2];
qDebug() <<"a "<< matriz[x2-1][y2];


qDebug() << matriz[0][0]<<" "<< matriz[0][1]<<" "<< matriz[0][2]<<" "<< matriz[0][3]<<" "<< matriz[0][4]<<" "<< matriz[0][5]<<" "<< matriz[0][6];
qDebug() << matriz[1][0]<<" "<< matriz[1][1]<<" "<< matriz[1][2]<<" "<< matriz[1][3]<<" "<< matriz[1][4]<<" "<< matriz[1][5]<<" "<< matriz[1][6];
qDebug() << matriz[2][0]<<" "<< matriz[2][1]<<" "<< matriz[2][2]<<" "<< matriz[2][3]<<" "<< matriz[2][4]<<" "<< matriz[2][5]<<" "<< matriz[2][6];
qDebug() << matriz[3][0]<<" "<< matriz[3][1]<<" "<< matriz[3][2]<<" "<< matriz[3][3]<<" "<< matriz[3][4]<<" "<< matriz[3][5]<<" "<< matriz[3][6];
qDebug() << matriz[4][0]<<" "<< matriz[4][1]<<" "<< matriz[4][2]<<" "<< matriz[4][3]<<" "<< matriz[4][4]<<" "<< matriz[4][5]<<" "<< matriz[4][6];
qDebug() << matriz[5][0]<<" "<< matriz[5][1]<<" "<< matriz[5][2]<<" "<< matriz[5][3]<<" "<< matriz[5][4]<<" "<< matriz[5][5]<<" "<< matriz[5][6];
qDebug() << matriz[6][0]<<" "<< matriz[6][1]<<" "<< matriz[6][2]<<" "<< matriz[6][3]<<" "<< matriz[6][4]<<" "<< matriz[6][5]<<" "<< matriz[6][6];
qDebug() << matriz[7][0]<<" "<< matriz[7][1]<<" "<< matriz[7][2]<<" "<< matriz[7][3]<<" "<< matriz[7][4]<<" "<< matriz[7][5]<<" "<< matriz[7][6];
qDebug() << matriz[8][0]<<" "<< matriz[8][1]<<" "<< matriz[8][2]<<" "<< matriz[8][3]<<" "<< matriz[8][4]<<" "<< matriz[8][5]<<" "<< matriz[8][6];
*/

    switch (event->key()) {
    case Qt::Key_W:
        qDebug() <<"Pacman "<< pacman->x()<<" , "<< pacman->y();
        qDebug() <<"Pacman "<< x2<<" , "<< y2;

            if(matriz[x2-1][y2]==0){
                pacman->ir_arriba();
            }else if(matriz[x2-1][y2]==2){
                matriz[x2-1][y2]=0;
                pared[y2][x2-1]->setEstado(0);
                //scene->addItem(pared[i][j]);
                pacman->ir_arriba();
            }

        break;
    case Qt::Key_S:
       // qDebug()<<"abajo";
        //y = y+10;
        qDebug() <<"Pacman "<< pacman->x()<<" , "<< pacman->y();
        qDebug() <<"Pacman "<< x2<<" , "<< y2;
        qDebug() <<"Pacman "<< matriz[x2+1][y2];
        if(matriz[x2+1][y2]==0){
        pacman->ir_abajo();
        }else if(matriz[x2+1][y2]==2){
            matriz[x2+1][y2]=0;
            pared[y2][x2+1]->setEstado(0);
            //scene->addItem(pared[i][j]);
            pacman->ir_abajo();
            qDebug() <<"borrado ";
            if(x2>=21){
                matriz[x2+1][y2]=0;
                pared[y2][x2+1]->setEstado(0);
                qDebug() <<"borrado 2";
            }
        }else{

        }


        //ui->label->setGeometry(x,y,61,61);
        break;
    case Qt::Key_A:
        //x = x-10;
        //qDebug()<<"izquierda";
        qDebug() <<"Pacman "<< pacman->x()<<" , "<< pacman->y();
        qDebug() <<"Pacman "<< x2<<" , "<< y2;
        qDebug() <<"Pacman "<< matriz[x2][y2-1];
if(matriz[x2][y2-1]==0){
        pacman->ir_izquierda();
}else if(matriz[x2][y2-1]==2){
    matriz[x2][y2-1]=0;
    pared[y2-1][x2]->setEstado(0);
    //scene->addItem(pared[i][j]);
    pacman->ir_izquierda();
}
        //ui->label->setGeometry(x,y,61,61);
        break;
    case Qt::Key_D:
        //qDebug()<<"derecha";w
        //x = x+10;
        qDebug() <<"Pacman "<< pacman->x()<<" , "<< pacman->y();
        qDebug() <<"Pacman "<< x2<<" , "<< y2;
        qDebug() <<"Pacman "<< matriz[x2][y2+1];

        if(matriz[x2][y2+1]==0){
                pacman->ir_derecha();

        }else if(matriz[x2][y2+1]==2){
            matriz[x2][y2+1]=0;
            pared[y2+1][x2]->setEstado(0);
            pacman->ir_derecha();
        }
        //ui->label->setGeometry(x,y,61,61);
        break;
    default:
        break;
    }

}





