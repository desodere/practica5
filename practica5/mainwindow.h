#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qgraphicsscene.h"
#include <QMainWindow>
//#include "scene.h"
#include "pared.h"
#include "moob1.h"
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
    int matriz[26][24];
    void keyPressEvent(QKeyEvent *event);
    Pacman * pacman ;


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Pared *pared[24][21];
    moob1 *moob1;


//    Scene *scene;

};
#endif // MAINWINDOW_H













