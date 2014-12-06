#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game();
    ~Game();
    void setCharToDraw(char *charToDraw);
    char* getCharToDraw();
    void setExtraChars(char* extraChar);
    void draw();

private:

    char *m_extraChar;
    char *m_charToDraw;
    void createFloor();
    void initExtraChars();
};
#endif