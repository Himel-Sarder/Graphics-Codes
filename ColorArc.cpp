#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setcolor(YELLOW);

    arc(200, 200, 0, 180, 100);

    getch();
    closegraph();
    return 0;
}


