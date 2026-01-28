#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setcolor(WHITE);

    circle(200, 200, 80);

    setfillstyle(SOLID_FILL, YELLOW);

    floodfill(200, 200, WHITE);

    getch();
    closegraph();
    return 0;
}

