#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 0, y = 200;

    while (!kbhit()) {
        cleardevice();
        outtextxy(x, y, "Hello Sir, This is ID 22111121. Sorry for late Submission. I was on my sister's Wedding");
        delay(50);
        x += 5;
        if (x > getmaxx()) x = 0;
    }

    getch();
    closegraph();
    return 0;
}


