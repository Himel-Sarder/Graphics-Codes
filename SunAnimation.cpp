#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.141592653589793

// ---------- Small helpers ----------
void drawSun(int x, int y, int r){
    int sunColor = COLOR(255, 204, 0);
    int rayColor = COLOR(255, 170, 0);

    setcolor(rayColor);
    for(int a=0; a<360; a+=20){
        double rad = a * PI / 180.0;
        int x1 = x + (int)(r * 1.1 * cos(rad));
        int y1 = y + (int)(r * 1.1 * sin(rad));
        int x2 = x + (int)(r * 1.7 * cos(rad));
        int y2 = y + (int)(r * 1.7 * sin(rad));
        line(x1,y1,x2,y2);
    }

    setcolor(sunColor);
    setfillstyle(SOLID_FILL, sunColor);
    fillellipse(x, y, r, r);
}

void drawMoon(int x, int y, int r, int skyColor){
    int moonColor = COLOR(230,230,230);
    setcolor(moonColor);
    setfillstyle(SOLID_FILL, moonColor);
    fillellipse(x, y, r, r);

    setcolor(skyColor);
    setfillstyle(SOLID_FILL, skyColor);
    fillellipse(x + r/3, y - r/5, r, r);
}

void drawStars(int W, int H){
    setcolor(WHITE);
    for(int i=0;i<60;i++){
        int x = rand() % W;
        int y = rand() % (H/2);
        putpixel(x,y,WHITE);
    }
}

void drawBackground(int W,int H,int skyColor){
    setbkcolor(skyColor);
    cleardevice();
}

// ---------- Main ----------
int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int W = getmaxx();
    int H = getmaxy();

    int baseY = (int)(H*0.72);

    int sunX = (int)(W*0.12), sunR = 30;
    int sunStartY = (int)(H*0.15);
    int sunEndY   = baseY - 10;

    int moonX = (int)(W*0.18), moonR = 22;
    int moonStartY = baseY + 60;
    int moonEndY   = (int)(H*0.2);

    int skyDay   = COLOR(135, 206, 235);
    int skyNight = COLOR(10, 20, 60);

    // ---------- Sunset ----------
    for(int y = sunStartY; y <= sunEndY; y += 2){
        drawBackground(W,H, skyDay);
        drawSun(sunX, y, sunR);
        delay(20);
    }

    // ---------- Night ----------
    drawBackground(W,H, skyNight);
    drawStars(W,H);
    delay(400);

    // ---------- Moonrise ----------
    for(int y = moonStartY; y >= moonEndY; y -= 2){
        drawBackground(W,H, skyNight);
        drawStars(W,H);
        drawMoon(moonX, y, moonR, skyNight);
        delay(20);
    }

    delay(600);

    // ---------- Show image ----------
    cleardevice();
    readimagefile("image1.jpg", 50, 50, 350, 250);
    outtextxy(50, 320, (char*)"Press any key...");
    getch();

    // ---------- Vanish effect ----------
    for(int i=0;i<10;i++){
        setfillstyle(SOLID_FILL, BLACK);
        bar(0,0,W,H);
        delay(100);
    }

    closegraph();
    return 0;
}
