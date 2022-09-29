#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include "qgraphicsscene.h"
#include <QMainWindow>
#include "pared.h"
#include "pacman.h"

#include <QDesktopWidget>
#include <QRectF>

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
//    int x ;
//    int y ;
    float x, y, ancho, alto;
    QTimer *timer;
    //int matriz[21][24];
//    vector<vector<int>> matriz;
    vector<vector<int>> matriz
        {
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

    void keyPressEvent(QKeyEvent *event);
    Pacman * pacman ;

public slots:
    void Actualizacion_puntuacion();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Pared *pared[24][21];
    //vector<vector<Pared>> pared;

    int puntaje;

};
#endif // MAINWINDOW_H













