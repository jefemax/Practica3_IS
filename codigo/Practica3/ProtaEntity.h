#ifndef PROTAENTITY_H
#define PROTAENTITY_H

#include "BaseEntity.h"

class ProtaEntity :virtual public BaseEntity
{
public:
    //~ProtaEntity();
    ProtaEntity(uint entityType);
    virtual void setDirection(bool direction);
    void setIsDeath(bool isDeath);
    bool getIsDeath();

private:
    bool isDeath = false;

};
#endif