#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Add image from file (jpg/png/bmp)
    readimagefile("image1.jpg", 50, 50, 350, 250);

    getch();
    closegraph();
    return 0;
}

