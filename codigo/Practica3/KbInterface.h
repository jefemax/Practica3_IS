#ifndef KBINTERFACE_H
#define KBINTERFACE_H
class World;

class KbInterface
{
public:
    KbInterface(BaseEntity *protaEntity);
    ~KbInterface();
    char onKeyBoardInterface();
    void setWorld(World *world);

private:
    BaseEntity *g_protaEntity;
    bool getInput(char *c);
    World *world;
};
#endif
