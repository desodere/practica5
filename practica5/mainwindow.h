#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qgraphicsscene.h"
#include <QMainWindow>
#include "pared.h"
#include "pacman.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int x ;
    int y ;
    //int matriz[21][24];
    int matriz[24][21];
    void keyPressEvent(QKeyEvent *event);
    Pacman * pacman ;


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Pared *pared[24][21];

    int puntaje;

};
#endif // MAINWINDOW_H













