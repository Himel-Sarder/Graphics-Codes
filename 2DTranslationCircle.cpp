#include <graphics.h>
#include <conio.h>
#include <dos.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 100, y = 200, r = 30;

    for (int i = 0; i <= 300; i += 5) {
        cleardevice();             // Clear previous frame
        circle(x + i, y, r);       // Translate circle along x-axis
        delay(50);                 // Control animation speed
    }

    getch();
    closegraph();
    return 0;
}




