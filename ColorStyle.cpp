#include <graphics.h>
#include <conio.h>

int main()
{
    int gd, gm;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "");

    setcolor(WHITE);

    setfillstyle(SOLID_FILL, RED);
    circle(50,50,25);
    floodfill(50,50,WHITE);

    setfillstyle(CLOSE_DOT_FILL, GREEN);
    circle(100,50,25);
    floodfill(100,50,WHITE);

    setfillstyle(WIDE_DOT_FILL, BLUE);
    circle(150,50,25);
    floodfill(150,50,WHITE);

    setfillstyle(INTERLEAVE_FILL, YELLOW);
    circle(200,50,25);
    floodfill(200,50,WHITE);

    setfillstyle(XHATCH_FILL, CYAN);
    circle(250,50,25);
    floodfill(250,50,WHITE);

    setfillstyle(HATCH_FILL, LIGHTBLUE);
    circle(300,50,25);
    floodfill(300,50,WHITE);

    setfillstyle(LTBKSLASH_FILL, LIGHTGRAY);
    circle(350,50,25);
    floodfill(350,50,WHITE);

    setfillstyle(SLASH_FILL, MAGENTA);
    circle(400,50,25);
    floodfill(400,50,WHITE);

    setfillstyle(LTSLASH_FILL, LIGHTGREEN);
    circle(450,50,25);
    floodfill(450,50,WHITE);

    getch();
    closegraph();
    return 0;
}

