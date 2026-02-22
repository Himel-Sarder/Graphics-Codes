#include <graphics.h>
#include <conio.h>
#include <dos.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 150, y = 150;   // Top-left corner
    int size = 50;         // Initial size

    for (int s = 50; s <= 200; s += 5) {
        cleardevice();

        rectangle(x, y, x + s, y + s);   // Draw scaled square

        delay(60);
    }

    getch();
    closegraph();
    return 0;
}


