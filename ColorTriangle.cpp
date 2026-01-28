#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setcolor(WHITE);

    line(200, 100, 100, 250);   // Left side
    line(200, 100, 300, 250);   // Right side
    line(100, 250, 300, 250);   // Base

    setfillstyle(SOLID_FILL, GREEN);

    floodfill(200, 200, WHITE);

    getch();
    closegraph();
    return 0;
}


