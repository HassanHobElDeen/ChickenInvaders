#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include "enemy.h"
Player::Player()
{
    QPixmap pix(":/new/pics1/chicken.png");
    setPixmap(pix);

}

void Player::keyPressEvent(QKeyEvent *event)
{
        // *******  Event Handling for the Player ********
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0) // to prevent the player from getting out of the screen
        {
        setPos(x()-10,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+100<800) // to prevent the player from getting out of the screen
        setPos(x()+10,y());
    }
    else if(event->key()== Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+30,y());
        scene()->addItem(bullet);

    }


}
 // CreateEnemy function used to create the eneimes
void Player::createEnemy()
{ Enemy* enemy = new Enemy();
  scene()->addItem(enemy);

}
