#ifndef MENUUI_H
#define MENUUI_H
#define p printf
#define g gotoxy
#define s scanf
#define sy strcpy
#define cp strcmp

void keysMenu(int barX1, int barY1, int barX2, int barY2, int color, int colorLight, char letter[1])
{
    setfillstyle(1, color);
    bar(barX1, barY1, barX2, barY2);
    setfillstyle(1, colorLight); settextstyle(3,0,4); setcolor(color);
    bar(barX1 + 5, barY1 + 5, barX2 - 5, barY2 - 5);
    if ((sc(letter, "J") == 0) || (sc(letter, "K") == 0) || (sc(letter, "L") ==0) || (sc(letter, "M") ==0))
    {
        outtextxy(barX1+10, barY1+55, letter);
    }

    else
    {
        outtextxy(barX1+10, barY1+15, letter);
    }
}

void mainUi(color, colorlight)
{
    int gm, gd=DETECT;

    initgraph(&gd,&gm,"c:\\turboc3\\bgi");

    setbkcolor(0);

    bordermenu(color);

    settextstyle(1,0,3);
    outtextxy(260,30, "Main Menu");

    settextstyle(3,0,1);
    setcolor(15); setlinestyle(0, 0x3333, 3);

    keysMenu(30, 80, 110, 140, color, colorlight, "A");
    keysMenu(120, 80, 200, 140, color, colorlight, "B");
    keysMenu(210, 80, 290, 140, color, colorlight, "C");
    keysMenu(30, 150, 110, 210, color, colorlight, "D");
    keysMenu(120, 150, 200, 210, color, colorlight, "E");
    keysMenu(210, 150, 290, 210, color, colorlight, "F");
    keysMenu(30, 220, 110, 280, color, colorlight, "G");
    keysMenu(120, 220, 200, 280, color, colorlight, "H");
    keysMenu(210, 220, 290, 280, color, colorlight, "I");
    keysMenu(30, 290, 85, 390, color, colorlight, "J");
    keysMenu(95, 290, 155, 390, color, colorlight, "K");
    keysMenu(165, 290, 225, 390, color, colorlight, "L");
    keysMenu(235, 290, 290, 390, color, colorlight, "M");


    setcolor(15);
    rectangle(320, 80, 610, 390);
    rectangle(320, 80, 610, 390);

    settextstyle(3,0,1);
    outtextxy(340, 90, "A  PUP Store Inventory");
    outtextxy(340, 112, "B  Loading Screen");
    outtextxy(340, 134, "C  Squares and Cubes");
    outtextxy(340, 156, "D  Spiral Maze Simulation");
    outtextxy(340, 178, "E  CPE Students Bar Graph");
    outtextxy(340, 200, "F  Monthly Salary Bonus");
    outtextxy(340, 222, "G  Zodiac Signs");
    outtextxy(340, 244, "H  TicTacToe");
    outtextxy(340, 266, "I  Stack Parking Garage");
    outtextxy(340, 288, "J  Binary Tree");
    outtextxy(340, 310, "K  Digital Clock");
    outtextxy(340, 332, "L  Tower of Hanoi");
    outtextxy(340, 354, "M  Queue Parking Garage");

    while (17)
    {
        setcolor(15);
        outtextxy(220, 410, "Press 'X' Key to Exit..."); delay(167);
        setcolor(colorlight);
        outtextxy(220, 410, "Press 'X' Key to Exit..."); delay(167);
        setcolor(15);
        outtextxy(220, 410, "Press 'X' Key to Exit..."); delay(167);

        if(kbhit())
        {
            break;
        }
    }
}



void menuUI()
{
    int x, c, y, i, j, color, choice = 20;


    while (choice > 0)
    {
        choice = 20;

        clrscr();

        mainUi(1, 9);
        choice = getch();

        bordermenu(2);
        setcolor(2);
        setlinestyle(0, 0x3333, 3);
        rectangle(320, 80, 610, 390);

        if (choice == 97 || choice == 65)
        {
            keysMenu(30, 80, 110, 140, 0, 0, "A");
            keysMenu(30, 90, 110, 150, 2, 10, "A");
            delay(200);
            keysMenu(30, 90, 110, 150, 0, 0, "A");
            keysMenu(30, 80, 110, 140, 2, 10, "A");

            settextstyle(3,0,1);

            setcolor(2);
            outtextxy(340, 90, "A  PUP Store Inventory");
            delay(700);

            loadingBar(1, 2, 10); closegraph();
            pupStore();

        }

        else if (choice == 98 || choice == 66)
        {
            keysMenu(120, 80, 200, 140, 0, 0, "B");
            keysMenu(120, 90, 200, 150, 2, 10, "B");
            delay(200);
            keysMenu(120, 90, 200, 150, 0, 0, "B");
            keysMenu(120, 80, 200, 140, 2, 10, "B");

            settextstyle(3,0,1);
            setcolor(2);
            outtextxy(340, 112, "B  Loading Screen");

            delay(700);
            loadingBar(2, 2, 10); closegraph();

            loadingScreen();

        }

        else if (choice == 99 || choice == 67)
        {
            keysMenu(210, 80, 290, 140, 0, 0, "C");
            keysMenu(210, 90, 290, 150, 2, 10, "C");
            delay(200);
            keysMenu(210, 90, 290, 150, 0, 0, "C");
            keysMenu(210, 80, 290, 140, 2, 10, "C");
            settextstyle(3,0,1);


            setcolor(2);
            outtextxy(340, 134, "C  Squares and Cubes");

            delay(700);

            loadingBar(3, 2, 10); closegraph();

            squaresCubes();

        }

        else if (choice == 100 || choice == 68)
        {
            keysMenu(30, 150, 110, 210, 0, 0, "D");
            keysMenu(30, 160, 110, 220, 2, 10, "D");
            delay(200);
            keysMenu(30, 160, 110, 220, 0, 0, "D");
            keysMenu(30, 150, 110, 210, 2, 10, "D");


            setfillstyle(1, 0);
            setcolor(2); settextstyle(3,0,1);
            outtextxy(340, 156, "D  Spiral Maze Simulation");

            delay(700);

            loadingBar(4, 2, 10); closegraph();
            spiralMaze();
            closegraph();
        }

        else if (choice == 101 || choice == 69)
        {
            keysMenu(120, 150, 200, 210, 0, 0, "E");
            keysMenu(120, 160, 200, 220, 2, 10, "E");
            delay(200);
            keysMenu(120, 160, 200, 220, 0, 0, "E");
            keysMenu(120, 150, 200, 210, 2, 10, "E");


            settextstyle(3,0,1);
            setcolor(2);
            outtextxy(340, 178, "E  CPE Students Bar Graph");
            delay(700);
            loadingBar(5, 2, 10); closegraph();
            barGraph();
        }

        else if (choice == 102|| choice == 70)
        {
            keysMenu(210, 150, 290, 210, 0, 0, "F");
            keysMenu(210, 160, 290, 220, 2, 10, "F");
            delay(200);
            keysMenu(210, 160, 290, 220, 0, 0, "F");
            keysMenu(210, 150, 290, 210, 2, 10, "F");

            delay(200);

            settextstyle(3,0,1);
            setcolor(2);
            outtextxy(340, 200, "F  Monthly Salary Bonus");

            delay(700);
            loadingBar(6, 2, 10); closegraph();
            salaryBonus();
        }

        else if (choice == 103|| choice == 71)
        {
            keysMenu(30, 220, 110, 280, 0, 0, "G");
            keysMenu(30, 230, 110, 290, 2, 10, "G");

            delay(200);

            keysMenu(30, 230, 110, 290, 0, 0, "G");
            keysMenu(30, 220, 110, 280, 2, 10, "G");

            settextstyle(3,0,1);
            setcolor(2);
            outtextxy(340, 222, "G  Zodiac Signs");

            delay(700);
            loadingBar(7, 2, 10); closegraph();
            zodiacSigns();
        }

        else if (choice == 104 || choice == 72)
        {
            keysMenu(120, 220, 200, 280, 0, 0, "H");
            keysMenu(120, 230, 200, 290, 2, 10, "H");
            delay(200);
            keysMenu(120, 230, 200, 290, 0, 0, "H");
            keysMenu(120, 220, 200, 280, 2, 10, "H");

            settextstyle(3,0,1);
            setcolor(2);
            outtextxy(340, 244, "H  TicTacToe");
            delay(700);
            loadingBar(8, 2, 10); closegraph();
            ticTacToe();
        }

        else if (choice == 105 || choice == 73)
        {
            keysMenu(210, 220, 290, 280, 0, 0, "I");
            keysMenu(210, 230, 290, 290, 2, 10, "I");
            delay(200);
            keysMenu(210, 230, 290, 290, 0, 0, "I");
            keysMenu(210, 220, 290, 280, 2, 10, "I");

            settextstyle(3,0,1);
            setcolor(2);
            outtextxy(340, 266, "I  Stack Parking Garage");

            delay(700);

            loadingBar(9, 2, 10); closegraph();
            parkingGarage();
        }

        else if (choice == 106 || choice == 74)
        {
            keysMenu(30, 290, 85, 390, 0, 0, "J");
            keysMenu(30, 300, 85, 400, 2, 10, "J");
            delay(200);
            keysMenu(30, 300, 85, 400, 0, 0, "J");
            keysMenu(30, 290, 85, 390, 2, 10, "J");

            settextstyle(3,0,1);
            setcolor(2);
            outtextxy(340, 288, "J  Binary Tree");

            delay(700);
            loadingBar(10, 2, 10); closegraph();
            binaryTree();

        }

        else if (choice == 107 || choice == 75)
        {
            keysMenu(95, 290, 155, 390, 0, 0, "K");
            keysMenu(95, 300, 155, 400, 2, 10, "K");
            delay(200);
            keysMenu(95, 300, 155, 400, 0, 0, "K");
            keysMenu(95, 290, 155, 390, 2, 10, "K");

            settextstyle(3,0,1);
            setcolor(2);
            outtextxy(340, 310, "K  Digital Clock");

            delay(700);

            loadingBar(11, 2, 10); closegraph();
            digitalClock();

        }

         else if (choice == 108 || choice == 76)
        {
            keysMenu(165, 290, 225, 390, 0, 0, "L");
            keysMenu(165, 300, 225, 400, 2, 10, "L");
            delay(200);
            keysMenu(165, 300, 225, 400, 0, 0, "L");
            keysMenu(165, 290, 225, 390, 2, 10, "L");

            setcolor(2);
            settextstyle(3,0,1);
            outtextxy(340, 332, "L  Tower of Hanoi");

            delay(700);
            settextstyle(3,0,1);
            loadingBar(12, 2, 10); closegraph();
            towerHanoi();

        }

        else if (choice == 109|| choice == 77)
        {
            keysMenu(235, 290, 290, 390, 0, 0, "M");
            keysMenu(235, 300, 290, 400, 2, 10, "M");
            delay(200);
            keysMenu(235, 300, 290, 400, 0, 0, "M");
            keysMenu(235, 290, 290, 390, 2, 10, "M");


            settextstyle(3,0,1);
            setcolor(2);
            outtextxy(340, 354, "M  Queue Parking Garage");
            delay(700);

            loadingBar(13, 2, 10); closegraph();
            queueParkingGarage();
        }

        else if (choice == 120 || choice == 88)
        {
            mainUi(4, 12);
            loadingBar(14, 4, 12);
            break;
        }

        else if (choice == 224 || choice == 0)
        {
            do
            {
                choice=getch();
            }
            while(choice==224);

            switch (choice)
            {
                case 72:
                    continue;
                case 75:
                    continue;
                case 77:
                    continue;
                case 80:
                    continue;
            }
        }

        else
        {
            continue;
        }
    }
    closegraph();
}
#endif
