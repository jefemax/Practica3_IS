#include "ProtaEntity.h"
#include "Constants.h"
#include "World.h"

ProtaEntity::ProtaEntity(uint entityType)
{
    m_direction = RIGHT;
    m_character = PROTA_CHAR_RIGHT;
    m_posX = WORLD_WIDTH/2;
    m_entityType = World::Entities::PROTA;

}

/*ProtaEntity::~ProtaEntity()
{

}*/

void ProtaEntity::setDirection(bool direction)
{
    m_direction = direction;
    if (m_direction == RIGHT)
    {
        m_character = PROTA_CHAR_RIGHT;
    }
    if (m_direction == LEFT)
    {
        m_character = PROTA_CHAR_LEFT;
    }
}

void ProtaEntity::setIsDeath(bool isDeath)
{
    this->isDeath = isDeath;
}
bool ProtaEntity::getIsDeath()
{
    return isDeath;
}

