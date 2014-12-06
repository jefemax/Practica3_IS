#include "BulletEntity.h"
#include "Constants.h"
#include "World.h"

BulletEntity::BulletEntity()
{
    m_character = BULLET_CHAR;
    m_incrementX = 0;
    m_entityType = World::Entities::BULLET;
}

void BulletEntity::update()
{
    if (m_active)
    {
        m_incrementX += World::s_frameRate*m_speed;
        if (m_direction == RIGHT)
        {
            if (m_incrementX >= 1)
            {
                m_posX += 1;

            }
        }
        else if (m_direction == LEFT)
        {
            if (m_incrementX >= 1)
            {
                m_posX -= 1;
            }
        }
        if (m_posX > WORLD_WIDTH || m_posX < 0)
            m_active = false;
        m_incrementX = 0;
    }
    /*   

            else if (bala->m_direccion_bala == IZQUIERDA)
            {
                if (bala->m_incrementoBala >= 1)
                {
                    bala->m_posxBala -= 1;
                    bala->m_incrementoBala = 0;
                }
            }
            if (bala->m_posxBala > ANCHO_MUNDO || bala->m_posxBala < 0)
                bala->m_balaActiva = false;
            if (bala->m_posxBala > ANCHO_MUNDO || bala->m_posxBala < 0)
                bala->m_balaActiva = false;
        }*/

}