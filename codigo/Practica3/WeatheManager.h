#include <thread>    

static char getRain(int x, int frameRate, int world_width)
{
    int iXgota = rand() % (world_width-1);
    int test = frameRate % 3;
    if (x == iXgota)
    {
        switch (test) {
        case 0:
            return '\'';
            break;
        case 1:
            return '|';
            break;
        case 3:
            return ',';
            break;
        default:
            break;
        }
    }

    return '\0';

}