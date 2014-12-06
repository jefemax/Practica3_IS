#include <conio.h>
#include "Constants.h"
#include "BulletEntity.h"
#include "KbInterface.h"
#include "World.h"

KbInterface::KbInterface(BaseEntity *protaEntity)
{
    this->g_protaEntity = protaEntity;
}

KbInterface::~KbInterface()
{

}

void KbInterface::setWorld(World *world)
{
    this->world = world;
}

bool KbInterface::getInput(char *c)
{
    if (_kbhit())
    {
        *c = _getch();
        return true;
    }
    return false;
}

char KbInterface::onKeyBoardInterface()
{
    char key = '\0';
    if (getInput(&key))
    {
        switch (key)
        {
        case 's':
        {
            g_protaEntity->setDirection(RIGHT);
            g_protaEntity->updatePosition(1);
            break;
        }
        case 'a':
        {
            g_protaEntity->setDirection(LEFT);
            g_protaEntity->updatePosition(1);
            break;
        }

        case 'd':
        {
            BulletEntity *bE = new BulletEntity();
            if (g_protaEntity->getDirection() == LEFT){
                bE->setDirection(LEFT);
                bE->setPosX(g_protaEntity->getPosX() - 1);
            }
            else if (g_protaEntity->getDirection() == RIGHT){
                bE->setDirection(RIGHT);
                bE->setPosX(g_protaEntity->getPosX() + 1);
            }
            bE->setActive(true);

            World::s_entityList.push_front(bE);
            break;
        }

        case 32:
        {
            world->reestart();
            break;
        }
        case 'q':
        {
            world->setIsQuit(true);
            break;
        }
        default:
            break;
        }

    }
    return key;
}

