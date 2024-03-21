
#include <QApplication>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include <QRect>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsView * view = new QGraphicsView;
    view -> setFixedSize(800,600);
    view -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    // *******  Create the View ********
    QGraphicsScene* scene = new QGraphicsScene;
    scene -> setSceneRect(0,0,800, 600);


    // ******* Create the Scene ********

    // *******  Create the Player ********
    Player * player1 = new Player;
    QPixmap pic(":/new/pics1/ship.png");
    player1 -> setPixmap(pic);
    scene -> addItem(player1);

    // *******  Setting the foucs to the Player ********
    player1 -> setFlags(QGraphicsItem::ItemIsFocusable);
    player1 -> setFocus();

    // *******  Adjust the location of the Player (middle of the screen) ********
    player1 -> setPos(view -> width()/2, view -> height()-player1->boundingRect().height());
    view -> setScene(scene);
    view -> show();


   // *******   Assign scene to the view   ***************


    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),player1,SLOT(createEnemy()));
    time->start(2000);


    return a.exec();
}
