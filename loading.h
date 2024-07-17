#ifndef LOADING_H
#define LOADING_H
#define p printf
#define g gotoxy
#define s scanf
#define p printf
#define g gotoxy
#define s scanf
#define sy strcpy
#define cp strcmp

void bordermenu(int color)
{
    setcolor(color); setlinestyle(0, 0x3333, 3);
    rectangle(5, 7, 6, 470);
    rectangle(7, 7, 8, 470);
    rectangle(9, 7, 10, 470);
    setcolor(15); setlinestyle(0, 0x3333, 1);
    rectangle(9, 7, 10, 470);

    setcolor(color); setlinestyle(0, 0x3333, 3);
    rectangle(5, 7, 630, 8);
    rectangle(5, 9, 630, 10);
    rectangle(5, 11, 630, 12);
    setcolor(15); setlinestyle(0, 0x3333, 1);
    rectangle(9, 11, 630, 12);

    setcolor(color); setlinestyle(0, 0x3333, 3);
    rectangle(630, 7, 629, 470);
    rectangle(628, 7, 627, 470);
    rectangle(626, 7, 625, 470);
    setcolor(15); setlinestyle(0, 0x3333, 1);
    rectangle(626, 12, 625, 470);

    setcolor(color); setlinestyle(0, 0x3333, 3);
    rectangle(5, 470, 630, 469);
    rectangle(5, 468, 630, 467);
    rectangle(5, 466, 630, 465);
    setcolor(15); setlinestyle(0, 0x3333, 1);
    rectangle(9, 466, 625, 465);
}

void loadingBar(int choice, int color, int colorLight)
{
    int i,y, r, gm,gd=DETECT;
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    setbkcolor(BLACK);
    rectangle(185,300,475,310);

    bordermenu(color);

    setcolor(15); setlinestyle(0, 0x3333, 3);

    rectangle(190, 80, 455, 250);

    if (choice == 1)
    {
        setlinestyle(0, 0x3333, 1);
        rectangle(235, 130, 410, 230);
        rectangle(220, 100, 425, 130);
        rectangle(270, 90, 375, 110);
        setfillstyle(0, 0);
        bar(271, 91, 374, 109);
        setfillstyle(SLASH_FILL, 15); bar(271, 91, 374, 109);
        setfillstyle(HATCH_FILL, 15); bar(240, 135, 405, 225);
    }

    else if (choice == 2)
    {
        setlinestyle(0, 0x3333, 1);
        rectangle(240, 150, 405, 180);
        bar(250, 160, 340, 170);
    }

    else if (choice == 3)
    {
        setlinestyle(0, 0x3333, 1);
        rectangle(273, 115, 373, 215);
        rectangle(283, 125, 363, 205);
        rectangle(293, 135, 353, 195);
        setfillstyle(SLASH_FILL, 15); bar(303, 145, 343, 185);
    }

    else if (choice == 4)
    {
        r=5;
        setlinestyle(0, 0x3333, 1);
        for(i=0;i<17;i++)
        for(i=0;i<17;i++)
        for(i=0;i<17;i++)
        {
            arc(323, 165, 0, 180,r=r+2);
            arc(325, 165, 180, 360,r=r+2);
        }
    }

    else if (choice == 5)
    {
        setlinestyle(0, 0x3333, 1);
        bar(210, 100, 280, 110);
        bar(210, 120, 350, 130);
        bar(210, 140, 270, 150);
        bar(210, 160, 320, 170);
        bar(210, 180, 390, 190);
        bar(210, 200, 290, 210);
        bar(210, 220, 400, 230);
    }

    else if (choice == 6)
    {
        setlinestyle(0, 0x3333, 1);
        for (y=90; y<=210; y+=30)
        {
            for (i=200; i<=432; i+=29)
            {
                settextstyle(3,0,1);
                outtextxy(i, y, "$");
                if (i<432)
                {
                    outtextxy(i+15, y, "P");
                }

                else
                {
                    break;
                }
            }
        }
    }

    else if (choice == 7)
    {
        setfillstyle(HATCH_FILL, 15);
        bar(225, 105, 420, 125);
        setlinestyle(0, 0x3333, 1);
        rectangle(220, 100, 425, 130);
        rectangle(220, 130, 425, 230);
        settextstyle(1,0,9);
        outtextxy(275, 120, "30");
    }

    else if (choice == 8)
    {
        setlinestyle(0, 0x3333, 1);
        settextstyle(1,0,9);
        outtextxy(230, 100, "X");
        outtextxy(305, 100, "O");
        outtextxy(370, 100, "X");
    }

    else if (choice == 9)
    {
        setlinestyle(0, 0x3333, 1);
        rectangle(235, 150, 255, 180);
        bar(275, 150, 295, 180);
        bar(315, 150, 335, 180);
        bar(355, 150, 375, 180);
        bar(395, 150, 415, 180);
    }

    else if (choice == 10)
    {
        for (y=90; y<=210; y+=30)
        {
            for (i=200; i<=432; i+=29)
            {
                settextstyle(3,0,1);
                outtextxy(i, y, "0");
                if (i<432)
                {
                    outtextxy(i+15, y, "1");
                }

                else
                {
                    break;
                }
            }
        }
    }

    else if (choice == 11)
    {
        setlinestyle(0, 0x3333, 1);
        settextstyle(1,0,9);
        outtextxy(230, 100, "9:41");
    }

    else if (choice == 12)
    {
        setlinestyle(0, 0x3333, 1);
        rectangle(240, 210, 405, 240);
        rectangle(260, 180, 385, 210);
        rectangle(280, 150, 365, 180);
        rectangle(300, 120, 345, 150);
        rectangle(320, 90, 325, 120);
        setfillstyle(3, 15);
        bar(245, 215, 400, 235);
        bar(265, 185, 380, 205);
        bar(285, 155, 360, 175);
        bar(305, 125, 340, 145);
        bar(321, 95, 324, 115);
    }

    else if (choice == 13)
    {
        setlinestyle(0, 0x3333, 1);
        bar(235, 150, 255, 180);
        bar(275, 150, 295, 180);
        bar(315, 150, 335, 180);
        bar(355, 150, 375, 180);
        rectangle(395, 150, 415, 180);
    }

    else if (choice == 14)
    {
        settextstyle(1,0,5);
        outtextxy(200,140, "THANK YOU!");
    }

    for(i=0;i<=320;i++)
    {
        setcolor(colorLight);
        rectangle(205,300,155+i,304);
        setcolor(15);
        rectangle(205,304,155+i,306);
        setcolor(color);
        rectangle(205,306,155+i,310); delay(1);
        setcolor(15);
        settextstyle(1, 0, 1);

        outtextxy(155, 270 , "Loading...");

        if (i<=300)
        {
            if (i%3 == 0)
            {
                g(57,18); p("%d%", (i/3));
            }
        }
    }
    cleardevice();
}

#endif
