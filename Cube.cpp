#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Front square
    rectangle(150, 150, 300, 300);

    // Back square (shifted)
    rectangle(200, 100, 350, 250);

    // Connecting edges
    line(150, 150, 200, 100);
    line(300, 150, 350, 100);
    line(150, 300, 200, 250);
    line(300, 300, 350, 250);

    getch();
    closegraph();
    return 0;
}

