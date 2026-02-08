#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // ---- Flag size (you can change these) ----
    int x1 = 100, y1 = 100;      // top-left of flag
    int x2 = 500, y2 = 340;      // bottom-right of flag

    // ---- Draw green rectangle (flag background) ----
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    bar(x1, y1, x2, y2);

    // ---- Red circle position (slightly left of center) ----
    int width  = x2 - x1;
    int height = y2 - y1;

    int cx = x1 + (width * 9) / 20;   // ~45% from left (slightly left)
    int cy = y1 + height / 2;         // center vertically
    int r  = height / 3;              // radius (looks good)

    // ---- Draw and fill red circle ----
    setcolor(RED);
    circle(cx, cy, r);
    setfillstyle(SOLID_FILL, RED);
    floodfill(cx, cy, RED);

    getch();
    closegraph();
    return 0;
}

