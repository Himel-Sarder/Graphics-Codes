#include <graphics.h>
#include <conio.h>

// ---------- Helpers ----------
void drawLineThick(int x1,int y1,int x2,int y2,int thickness,int color){
    setcolor(color);
    for(int t=-thickness/2; t<=thickness/2; t++){
        line(x1, y1+t, x2, y2+t);
    }
}

void fillPoly(int *pts, int n, int borderColor, int fillColor){
    setcolor(borderColor);
    setfillstyle(SOLID_FILL, fillColor);
    fillpoly(n, pts);
}

int pillarEdgeX(int cx, int topY, int baseY, int halfWidth, int y, int side){
    if(y < topY)  y = topY;
    if(y > baseY) y = baseY;
    double t = (double)(y - topY) / (double)(baseY - topY);
    return (int)(cx + side * (halfWidth * t));
}

void pointOnLine(int x1,int y1,int x2,int y2,double r,int *xo,int *yo){
    *xo = (int)(x1 + (x2 - x1)*r);
    *yo = (int)(y1 + (y2 - y1)*r);
}

// Fill a gray quad between two boundaries (no geometry changes)
void fillBetween(int xBaseA,int yBaseA,int xTopA,int yTopA,
                 int xBaseB,int yBaseB,int xTopB,int yTopB,
                 int fillColor){
    int pts[8] = { xBaseA,yBaseA,  xTopA,yTopA,  xTopB,yTopB,  xBaseB,yBaseB };
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, fillColor);
    fillpoly(4, pts);
}

// Filled circle
void fillCircle(int x,int y,int r,int borderColor,int fillColor){
    setcolor(borderColor);
    setfillstyle(SOLID_FILL, fillColor);
    circle(x,y,r);
    floodfill(x,y,borderColor);
}

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int W = getmaxx();
    int H = getmaxy();

    setbkcolor(WHITE);
    cleardevice();

    int cx    = W/2;
    int baseY = (int)(H*0.72);
    int topY  = (int)(H*0.12);

    int dark  = COLOR(80,80,80);
    int mid   = COLOR(140,140,140);
    int light = COLOR(210,210,210);

    int pillarHalf = 60;

    // ---------------- Base line ----------------
    drawLineThick(cx-380, baseY, cx+380, baseY, 3, dark);

    // ---------------- Ribs data ----------------
    int baseX[9] = { 260, 235, 210, 185, 160, 140, 120, 105, 90 };
    int attachY[9] = {
        topY+235, topY+220, topY+205, topY+190, topY+175,
        topY+160, topY+145, topY+130, topY+115
    };

    int directToPillarStart = 7;

    int xEndL[9], yEndL[9], xEndR[9], yEndR[9];
    for(int i=0;i<9;i++){
        int yA = attachY[i];
        xEndL[i] = pillarEdgeX(cx, topY, baseY, pillarHalf, yA, -1);
        yEndL[i] = yA;
        xEndR[i] = pillarEdgeX(cx, topY, baseY, pillarHalf, yA, +1);
        yEndR[i] = yA;
    }

    int ribTopXL[9], ribTopYL[9], ribTopXR[9], ribTopYR[9];
    for(int i=8;i>=0;i--){
        if(i >= directToPillarStart){
            ribTopXL[i] = xEndL[i]; ribTopYL[i] = yEndL[i];
            ribTopXR[i] = xEndR[i]; ribTopYR[i] = yEndR[i];
        } else {
            int tx, ty;
            pointOnLine(cx - baseX[i+1], baseY, xEndL[i+1], yEndL[i+1], 0.55, &tx, &ty);
            ribTopXL[i] = tx; ribTopYL[i] = ty;

            pointOnLine(cx + baseX[i+1], baseY, xEndR[i+1], yEndR[i+1], 0.55, &tx, &ty);
            ribTopXR[i] = tx; ribTopYR[i] = ty;
        }
    }

    // ---------------- Fill ribs panels ----------------
    int grayFill = COLOR(220,220,220);

    for(int i=0;i<8;i++){
        fillBetween(cx - baseX[i], baseY, ribTopXL[i], ribTopYL[i],
                    cx - baseX[i+1], baseY, ribTopXL[i+1], ribTopYL[i+1],
                    grayFill);

        fillBetween(cx + baseX[i], baseY, ribTopXR[i], ribTopYR[i],
                    cx + baseX[i+1], baseY, ribTopXR[i+1], ribTopYR[i+1],
                    grayFill);
    }

    // closest strip to pillar
    {
        int i = 8;
        fillBetween(cx - baseX[i], baseY, ribTopXL[i], ribTopYL[i],
                    cx - pillarHalf, baseY, xEndL[i], yEndL[i], grayFill);

        fillBetween(cx + baseX[i], baseY, ribTopXR[i], ribTopYR[i],
                    cx + pillarHalf, baseY, xEndR[i], yEndR[i], grayFill);
    }

    // ---------------- Main pillar on top ----------------
    setcolor(dark);
    setlinestyle(SOLID_LINE,0,3);
    line(cx, topY, cx-pillarHalf, baseY);
    line(cx, topY, cx+pillarHalf, baseY);

    int inner1[8] = { cx,topY+60, cx-25,baseY-20, cx,baseY-70, cx+25,baseY-20 };
    fillPoly(inner1, 4, WHITE, light);

    setcolor(mid);
    setlinestyle(SOLID_LINE,0,2);
    line(cx, topY, cx-35, baseY);
    line(cx, topY, cx+35, baseY);

    setcolor(dark);
    setlinestyle(SOLID_LINE,0,2);
    rectangle(cx-22, topY+170, cx+22, topY+190);
    rectangle(cx-26, topY+165, cx+26, topY+195);

    line(cx-20, baseY-20, cx, baseY-40);
    line(cx, baseY-40, cx+20, baseY-20);

    // ---------------- Draw ribs lines ----------------
    setcolor(dark);
    setlinestyle(SOLID_LINE,0,2);
    for(int i=8;i>=0;i--){
        if(i >= directToPillarStart){
            line(cx - baseX[i], baseY, xEndL[i], yEndL[i]);
            line(cx + baseX[i], baseY, xEndR[i], yEndR[i]);
        } else {
            int tx, ty;
            pointOnLine(cx - baseX[i+1], baseY, xEndL[i+1], yEndL[i+1], 0.55, &tx, &ty);
            line(cx - baseX[i], baseY, tx, ty);

            pointOnLine(cx + baseX[i+1], baseY, xEndR[i+1], yEndR[i+1], 0.55, &tx, &ty);
            line(cx + baseX[i], baseY, tx, ty);
        }
    }

    // ---------------- Bangladesh Flag (near main pillar, no square below) ----------------
    // Put the pole closer to the main pillar
    int poleX = cx + 160;     // was cx+260, now closer
    int poleBottom = baseY;   // touches base line
    int poleTop    = topY + 10;

    setcolor(dark);
    setlinestyle(SOLID_LINE, 0, 3);
    line(poleX, poleTop, poleX, poleBottom);

    // Flag rectangle (attached to pole)
    int flagW = 130;
    int flagH = 75;

    int fx1 = poleX;              // attached edge
    int fy1 = poleTop + 25;
    int fx2 = fx1 + flagW;
    int fy2 = fy1 + flagH;

    // Green fill
    setcolor(dark);
    setfillstyle(SOLID_FILL, COLOR(0,106,78));
    rectangle(fx1, fy1, fx2, fy2);
    floodfill((fx1+fx2)/2, (fy1+fy2)/2, dark);

    // Red circle
    int circleX = fx1 + (int)(flagW * 0.45);
    int circleY = fy1 + flagH/2;
    int radius  = (int)(flagH * 0.28);

    fillCircle(circleX, circleY, radius, dark, COLOR(218,41,28));

    getch();
    closegraph();
    return 0;
}
