#include "World.h"
#include <thread>       
#include <time.h>
#include "EnemyEntity.h"
#include "Constants.h"
#include "WeatheManager.h"

std::list<BaseEntity*> World::s_entityList;
double  World::s_frameRate = 0.0;
uint  World::s_frames = 0;

BaseEntity **g_colisionTable = new BaseEntity*[WORLD_WIDTH];

World::World()
{
    g_isQuit = false;
}

World::~World()
{
    //No es necesario eliminar al protaentity porque se elimina al momento de eliminar los punteros de la lista
    std::list<BaseEntity*>::iterator entity_Iterator;
    for (entity_Iterator = World::s_entityList.begin(); entity_Iterator != World::s_entityList.end(); ++entity_Iterator)
    {
        BaseEntity *bE = *entity_Iterator;
        delete bE;
    }

    delete m_kbInterface;
    delete m_game;
    delete *g_colisionTable;

    World::s_entityList.clear();
}

void World::execute(){
    init();
    update();
}

void World::update()
{
    while (!g_isQuit)
    {
        m_kbInterface->onKeyBoardInterface();
        if (!m_protaEntity->getIsDeath())
        {

            //reset extra characters
            for (int x = 0; x <= WORLD_WIDTH; x++)
            {
                m_addditionalCharsToDraw[x] = '\0';
            }

            m_random = rand() % 100;
            for (int x = 0; x <= WORLD_WIDTH; x++)
            {
                g_colisionTable[x] = NULL;
            }
            //update Enemys
            if (m_random == 5 || m_random == 13)
            {
                EnemyEntity *t_enem = new EnemyEntity(m_random, Entities::ENEMY);
                t_enem->setSpeed(m_enemy_speed);
                s_entityList.push_front(t_enem);
            }
            std::list<BaseEntity*>::iterator entity_Iterator;
            for (entity_Iterator = World::s_entityList.begin(); entity_Iterator != World::s_entityList.end(); ++entity_Iterator)
            {
                BaseEntity *bE = *entity_Iterator;
                if (bE->getActive())
                {
                    bE->update();
                    if (bE->getPosX() > 0 && bE->getPosX() <= WORLD_WIDTH)
                        g_colisionTable[bE->getPosX()] = bE;
                }
            }
            checkCollision();

            //Weather
            for (int x = 0; x <= WORLD_WIDTH; x++)
            {
                char aux = getRain(x, World::s_frames, WORLD_WIDTH);
                if (aux != '\0')
                    m_addditionalCharsToDraw[x] = aux;
            }
            m_game->setExtraChars(m_addditionalCharsToDraw);
            m_game->draw();
        }
        else
        {
            printf("Has muerto tu score es: %d Presiona barra para volver a jugar o q para salir", m_score);
            printf("\r");
            //input();
        }



        s_frames++;
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(SLEEP_MILISECS)));
    }


}

void World::init()
{
    m_addditionalCharsToDraw = new char[WORLD_WIDTH + 1];
    m_addditionalCharsToDraw[WORLD_WIDTH] = '\0';
    m_protaEntity = new ProtaEntity(Entities::PROTA);
    m_kbInterface = new KbInterface(m_protaEntity);
    m_kbInterface->setWorld(this);
    m_game = new Game();
    srand(time(NULL));
    s_frameRate = SLEEP_MILISECS / THOUSAND;
    m_random = 0;
    m_score = 0;
    m_enemy_speed = ENEMY_SPEED;
    s_entityList.push_front(m_protaEntity);
}

void World::reestart()
{
    m_protaEntity->setIsDeath(false);
    m_protaEntity->setPosX(WORLD_WIDTH/2);
    s_entityList.push_front(m_protaEntity);
    srand(time(NULL));
    s_frameRate = SLEEP_MILISECS / THOUSAND;
    m_random = 0;
    m_score = 0;
    m_enemy_speed = ENEMY_SPEED;
}

bool World::checkCollision()
{

    for (int x = 0; x <= WORLD_WIDTH; x++)
    {
        for (int y = 0; y <= WORLD_WIDTH; y++)
        {
            //Detecto colisiones entre la bala y el enemigo
            if (g_colisionTable[x] != NULL && g_colisionTable[y] != NULL) {
                BaseEntity *entity1 = g_colisionTable[x];
                BaseEntity *entity2 = g_colisionTable[y];
                if (entity1->getEntityType() == BULLET && entity2->getEntityType() == ENEMY)
                {
                    if (entity2->getDirection() == RIGHT)
                    {
                        if (entity1->getPosX() > entity2->getPosX())
                        {
                             entity1->setActive(false);
                             entity2->setActive(false);
                             updateDifficulty();
                             m_score++;
                        }
                    }
                    if (entity2->getDirection() == LEFT)
                    {
                        if (entity1->getPosX() < entity2->getPosX())
                        {
                            entity1->setActive(false);
                            entity2->setActive(false);
                            updateDifficulty();
                            m_score++;
                        }
                    }
                }
                //Detecto colisiones entre el enemigo y el prota
                if (entity2->getEntityType() == ENEMY)
                {
                    if (entity2->getDirection() == RIGHT )
                    {
                        if (entity2->getPosX() <= m_protaEntity->getPosX())
                        {
                            death();
                            return true;
                        }
                    }
                    if (entity2->getDirection() == LEFT)
                    {
                        if (entity2->getPosX() >= m_protaEntity->getPosX())
                        {
                            death();
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

void World::death()
{
    s_entityList.clear();
    cleanWorld();
    m_protaEntity->setIsDeath(true);
}

void World::cleanWorld()
{
    char *clean = new char[WORLD_WIDTH+1];
    for (int x = 0; x < WORLD_WIDTH; x++){
        clean[x] = ' ';
    }
    clean[WORLD_WIDTH] = '\0';
    printf("%s", clean);
    printf("\r");
    delete [] clean;
}

void World::updateDifficulty()
{
    if (m_score % 2 == 0)
    {
        m_enemy_speed += SPEED_INC;
    }
}

