#include <graphics.h>
#include <conio.h>
#include <dos.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 320;        // Horizontal center
    int startY = 400;  // Start from bottom
    int endY = 100;    // Move to top

    for (int y = startY; y >= endY; y -= 5) {
        cleardevice();

        // Draw ground
        setcolor(GREEN);
        line(0, 450, 640, 450);

        // Draw sun
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        circle(x, y, 30);
        floodfill(x, y, YELLOW);

        // Draw sun rays
        line(x, y - 30, x, y - 60);
        line(x, y + 30, x, y + 60);
        line(x - 30, y, x - 60, y);
        line(x + 30, y, x + 60, y);
        line(x - 20, y - 20, x - 40, y - 40);
        line(x + 20, y - 20, x + 40, y - 40);
        line(x - 20, y + 20, x - 40, y + 40);
        line(x + 20, y + 20, x + 40, y + 40);

        delay(80);
    }

    getch();
    closegraph();
    return 0;
}

