#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
	
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setcolor(GREEN);
    line(20, 30, 400, 30);

    getch();
    closegraph();
    return 0;
}



