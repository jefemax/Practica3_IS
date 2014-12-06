#include "BaseEntity.h"
#include "Constants.h"

BaseEntity::~BaseEntity()
{
}
bool BaseEntity::getDirection(){ return m_direction; }
void BaseEntity::setDirection(bool direction){ this->m_direction = direction; }
uint BaseEntity::getPosX(){ return m_posX; }
void BaseEntity::setPosX(uint posX){ this->m_posX = posX; }
uint BaseEntity::getSpeed(){ return m_speed; }
void BaseEntity::setSpeed(uint speed){ this->m_speed = speed; }
char BaseEntity::getCharacter() { return m_character; }
void BaseEntity::setCharacter(char character) { this->m_character = character; }
bool BaseEntity::getActive(){ return m_active; }
void BaseEntity::setActive(bool active){ this->m_active = active;  }
void BaseEntity::setEntityType(uint entityType){ this->m_entityType = entityType; }
uint BaseEntity::getEntityType(){ return m_entityType; }
double BaseEntity::getIncrement(){ return m_incrementX; }
void BaseEntity::setIncrement(double incrementX){ this->m_incrementX = incrementX; }
void BaseEntity::updatePosition(uint incX)
{
    if (m_direction == RIGHT)
        this->m_posX = m_posX + incX;
    else if (m_direction == LEFT)
        this->m_posX = m_posX - incX;
}
void BaseEntity::update(){}