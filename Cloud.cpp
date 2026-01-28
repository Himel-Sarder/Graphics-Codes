#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setcolor(WHITE);  
    setfillstyle(SOLID_FILL, WHITE);

    // Draw cloud using filled ellipses
    fillellipse(200, 150, 30, 30);
    fillellipse(230, 150, 40, 40);
    fillellipse(270, 150, 35, 35);
    fillellipse(240, 120, 30, 30);
    fillellipse(210, 120, 25, 25);

    getch();
    closegraph();
    return 0;
}


