#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Background
    setbkcolor(LIGHTCYAN);
    cleardevice();

    // Ground
    setcolor(GREEN);
    setlinestyle(SOLID_LINE, 0, 3);
    line(0, 420, getmaxx(), 420);

    // ---- TREE TRUNK ----
    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    rectangle(290, 260, 350, 420);
    floodfill(300, 300, BROWN);

    // ---- LEAF CANOPY (FILLED) ----
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);

    fillellipse(320, 200, 90, 60);   // top
    fillellipse(260, 230, 70, 50);   // left
    fillellipse(380, 230, 70, 50);   // right
    fillellipse(300, 260, 75, 45);   // bottom left
    fillellipse(340, 260, 75, 45);   // bottom right

    // ---- Fruits ----
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    fillellipse(280, 240, 6, 6);
    fillellipse(360, 255, 6, 6);
    fillellipse(320, 225, 6, 6);

    getch();
    closegraph();
    return 0;
}

