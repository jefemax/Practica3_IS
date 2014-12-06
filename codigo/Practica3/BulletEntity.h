#ifndef BULLETENTITY_H
#define BULLETENTITY_H

#include "BaseEntity.h"

class BulletEntity :virtual public BaseEntity
{
public:
    BulletEntity();
    virtual void update();
};
#endif