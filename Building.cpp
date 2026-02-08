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

    // ---- BUILDING BODY ----
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    rectangle(200, 180, 440, 420);   // main building
    floodfill(210, 200, DARKGRAY);

    // ---- DOOR ----
    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    rectangle(300, 300, 350, 420);
    floodfill(310, 320, BROWN);

    // ---- WINDOWS ----
    setcolor(BLUE);
    setfillstyle(SOLID_FILL, CYAN);

    // left windows
    rectangle(230, 220, 270, 260);
    floodfill(235, 225, BLUE);

    rectangle(230, 270, 270, 310);
    floodfill(235, 275, BLUE);

    // right windows
    rectangle(370, 220, 410, 260);
    floodfill(375, 225, BLUE);

    rectangle(370, 270, 410, 310);
    floodfill(375, 275, BLUE);

    // ---- ROOF ----
	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	
	line(200, 180, 320, 120);
	line(320, 120, 440, 180);
	line(440, 180, 200, 180);   // close triangle
	
	floodfill(320, 160, RED);

    getch();
    closegraph();
    return 0;
}

