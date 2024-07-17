#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <dos.h>
#include <graphics.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include "C:\TURBOC3\Projects\HERE!!!\programs.h"
#include "C:\TURBOC3\Projects\HERE!!!\pcode.h"
#include "C:\TURBOC3\Projects\HERE!!!\qcode.h"
#include "C:\TURBOC3\Projects\HERE!!!\loading.h"
#include "C:\TURBOC3\Projects\HERE!!!\menuui.h"
#define p printf
#define g gotoxy
#define s scanf
#define sy strcpy
#define cp strcmp
#define sc strcmp

void main()
{
    int x, y, i, j, color, choice = 20, gm, gd=DETECT;

    g(2, 2); p("%c", 201); g(79, 2); p("%c", 187);
    g(2, 24); p("%c", 200); g(79, 24); p("%c", 188);

    for (x = 3; x <= 78; x++)
    {
        g(x, 2); p("%c", 205);
        g(x, 24); p("%c", 205);
    }
    for (y = 3; y <= 23; y++)
    {
        g(2, y); p("%c", 186);
        g(79, y); p("%c", 186);
    }

    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    setbkcolor(0);

    settextstyle(1,0,3);
    outtextxy(150, 120, "Data Structures and Algorithm");
    settextstyle(1,0,5);
    outtextxy(180,140, "FINAL PROJECT");
    settextstyle(3,0,1);
    outtextxy(205, 225, "Almario, Candido James C.");
    outtextxy(205, 245, "Benciang, Gienel Aubrey V.");
    outtextxy(225, 265, "Binasa, Kenneth Carl E.");
    outtextxy(245, 285, "De Leon, Novelle A. ");

    bordermenu(1);

    while (17)
    {
        setcolor(15);
        outtextxy(200, 345, "Press Any Key to Continue..."); delay(500);
        setcolor(0);
        outtextxy(200, 345, "Press Any Key to Continue..."); delay(500);

        if(kbhit())
        {
            getch();
            break;
        }
    }

    clrscr();
    menuUI();

}
