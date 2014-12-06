#ifndef ENEMYENTITY_H
#define ENEMYENTITY_H
#include "BaseEntity.h"

class EnemyEntity : virtual public BaseEntity
{
public:
    EnemyEntity(uint randDirection, uint entityType);
    virtual void update();
};

#endif