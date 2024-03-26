
#include <cstdio>
#include "miosix.h"

using namespace std;
using namespace miosix;


int main()
{
    //iprintf("Hello world, write your application here\n");

    LCD_DISPLAY[120+80*240] = 0x001F;
    LCD_DISPLAY[136+80*240] = 0x03E0;
    LCD_DISPLAY[120+96*240] = 0x7C00;

    while(1) {}
}
