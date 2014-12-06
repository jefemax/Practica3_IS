#ifndef WORLD_H
#define WORLD_H

#include "ProtaEntity.h"
#include "KbInterface.h"
#include "Game.h"
#include <list>

class World{
public:
    World();
    ~World();
    void execute();
    void reestart();
    void setIsQuit(bool isQuit) { this->g_isQuit = isQuit; }
    static std::list<BaseEntity*> s_entityList;
    static enum Entities { PROTA, ENEMY, BULLET };
    static double s_frameRate;
    static uint s_frames;


private:

    KbInterface *m_kbInterface;
    ProtaEntity *m_protaEntity;

    bool g_isQuit;
    uint m_random;
    uint m_score;
    Game *m_game;
    char *m_addditionalCharsToDraw;
    double m_enemy_speed;

    void update();
    void init();
    void death();
    bool checkCollision();
    void cleanWorld();
    void updateDifficulty();

};
#endif