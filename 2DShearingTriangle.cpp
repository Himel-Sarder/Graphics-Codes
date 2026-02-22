#include <graphics.h>
#include <conio.h>
#include <dos.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Original triangle
    int x1 = 150, y1 = 150;
    int x2 = 100, y2 = 250;
    int x3 = 200, y3 = 250;

    // Draw original triangle
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    delay(1500);

    // Shear factor (X-direction)
    float shx = 0.5;

    // Apply X-shear
    int sx1 = x1 + shx * y1;
    int sy1 = y1;

    int sx2 = x2 + shx * y2;
    int sy2 = y2;

    int sx3 = x3 + shx * y3;
    int sy3 = y3;

    // Draw sheared triangle
    setcolor(YELLOW);
    line(sx1, sy1, sx2, sy2);
    line(sx2, sy2, sx3, sy3);
    line(sx3, sy3, sx1, sy1);

    getch();
    closegraph();
    return 0;
}
