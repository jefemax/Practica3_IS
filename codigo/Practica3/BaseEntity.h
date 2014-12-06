#ifndef BASEENTITY_H
#define BASEENTITY_H
typedef unsigned int uint;

class BaseEntity
{
public:
    virtual void update();
    virtual ~BaseEntity();
    virtual bool getDirection();
    virtual void setDirection(bool direction);
    virtual uint getPosX();
    virtual void setPosX(uint posX);
    virtual uint getSpeed();
    virtual void setSpeed(uint speed);
    virtual char getCharacter();
    virtual void setCharacter(char character);
    virtual void updatePosition(uint incX);
    virtual bool getActive();
    virtual void setActive(bool active);
    virtual double getIncrement();
    virtual void setEntityType(uint entityType);
    virtual uint getEntityType();
    virtual void setIncrement(double m_incrementX);


protected:

    bool m_direction;
    bool m_active;

    uint m_posX;
    uint m_entityType;
    uint m_speed;

    double m_incrementX;

    char m_character;
};

#endif 