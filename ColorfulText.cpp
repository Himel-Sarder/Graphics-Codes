#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set text style
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);

    // Display colorful texts
    setcolor(RED);
    outtextxy(50, 50, "Red Text");

    setcolor(GREEN);
    outtextxy(50, 100, "Green Text");

    setcolor(BLUE);
    outtextxy(50, 150, "Blue Text");

    setcolor(YELLOW);
    outtextxy(50, 200, "Yellow Text");

    setcolor(WHITE);
    outtextxy(50, 250, "White Text");

    getch();
    closegraph();
    return 0;
}

