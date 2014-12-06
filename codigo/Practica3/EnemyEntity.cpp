#include "EnemyEntity.h"
#include "Constants.h"
#include <stdio.h>
#include "World.h"


EnemyEntity::EnemyEntity(uint randDirection, uint entityType)
{
    m_character = ENEMY_CHAR;
    m_incrementX = 0;

    if (randDirection == 5 || randDirection == 13)
    {
        setDirection(randDirection == 5 ? RIGHT : LEFT);

        if (getDirection() == RIGHT)
        {
            setPosX(WORLD_WIDTH);
        }
        else
        {
            setPosX(0);
        }
        setActive(true);
    }
    
    m_entityType = World::Entities::ENEMY;
}

void EnemyEntity::update()
{
    if (m_active) {
        m_incrementX += World::s_frameRate*m_speed;
        if (m_incrementX >= 1){
            m_incrementX = 0;
            if (m_direction == RIGHT)
            {
                m_posX -= 1;
            }
            else
            {
                m_posX += 1;
            }
            if (m_posX > WORLD_WIDTH || m_posX < 0)
            {
                m_active = false;
            }
        }
    }

}