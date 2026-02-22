#include <graphics.h>
#include <conio.h>
#include <dos.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int maxY = getmaxy();
    int axisY = maxY / 2;   // X-axis reference (middle of screen)

    // Original triangle points (above the X-axis line)
    int x1 = 150, y1 = axisY - 60;
    int x2 = 100, y2 = axisY - 10;
    int x3 = 200, y3 = axisY - 10;

    // Draw X-axis reference line
    line(0, axisY, getmaxx(), axisY);

    // Draw original triangle
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    delay(1500);

    // Reflected triangle about X-axis
    int ry1 = 2 * axisY - y1;
    int ry2 = 2 * axisY - y2;
    int ry3 = 2 * axisY - y3;

    setcolor(YELLOW);
    line(x1, ry1, x2, ry2);
    line(x2, ry2, x3, ry3);
    line(x3, ry3, x1, ry1);

    getch();
    closegraph();
    return 0;
}
