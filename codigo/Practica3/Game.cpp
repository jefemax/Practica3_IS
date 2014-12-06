#include "Constants.h"
#include <stdio.h>
#include <list>
#include "World.h"

Game::Game(){
    printf("\n\n\n");
    printf("PRACTICA 3 INGENIERIA DE SOFTWARE\n");
    printf("PARA JUGAR USAR LAS TECLAS:\n");
    printf("A MUEVE A LA IZQUIERDA\n");
    printf("B MUEVE A LA DERECHA\n");
    printf("D DISPARA\n");
    printf("PARA SALIR PRESIONA q\n");
    printf("OBJETIVO DEL JUEGO:\n");
    printf("DEBES DESTRUIR A LOS ENEMIGOS QUE VAN SALIENDO A AMBOS LADOS DE LA PANTALLA\n");
    printf("CADA VEZ QUE DESTRUYES 2 ENEMIGOS LA VELOCIDAD AUMENTA\n");
    printf("\n\n\n");
    m_charToDraw = new char[WORLD_WIDTH+1];
    m_extraChar = new char[WORLD_WIDTH+1];
    createFloor();
    initExtraChars();
}

Game::~Game()
{
    delete [] m_charToDraw;
}

void Game::draw()
{
    createFloor();
 
    std::list<BaseEntity*>::iterator entity_Iterator;
    for (int x = 0; x < WORLD_WIDTH; x++){
        for (entity_Iterator = World::s_entityList.begin(); entity_Iterator != World::s_entityList.end(); ++entity_Iterator)
        {
            BaseEntity *bE = *entity_Iterator;
            if (bE->getActive()){
                if (x == bE->getPosX())
                    m_charToDraw[x] = bE->getCharacter();
               }
        }

        if (m_extraChar[x] != '\0')
        {
            m_charToDraw[x] = m_extraChar[x];
        }

    }
    printf("%s", m_charToDraw);
    printf("\r");
}

void Game::createFloor()
{
    for (int x = 0; x < WORLD_WIDTH; x++)
    {
        m_charToDraw[x] = '_';
    }
    m_charToDraw[WORLD_WIDTH] = '\0';
}

void Game::initExtraChars()
{
    for (int x = 0; x < WORLD_WIDTH; x++)
    {
        m_extraChar[x] = '\0';
    }
    m_extraChar[WORLD_WIDTH] = '\0';
}

void Game::setExtraChars(char *extraChar)
{
    this->m_extraChar = extraChar;
}
