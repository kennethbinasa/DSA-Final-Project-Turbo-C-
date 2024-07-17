#ifndef PROGRAMSTWO_H
#define PROGRAMSTWO_H
#define p printf
#define g gotoxy
#define s scanf
#define p printf
#define g gotoxy
#define s scanf
#define sy strcpy
#define cp strcmp
#define sc strcmp

//for parkingGarage
void parkingSpace(road)
{
    int x, y, z;

    clrscr();

    for (y = 1; y <= 11; y++)
    {
        g(5, 2 * y); p("%c", 186);
        g(10, 2 * y); p("%c", 186);

        for (z = 1; z <= 6; z++)
        {
            g(5 + (z - 1), (2 * y - 1)); p("%c", 205);
            g(5, (2 * y - 1)); p("%c", 206);
            g(10, (2 * y - 1)); p("%c", 206);
        }
    }

    for (x=11; x<=78; x++)
    {
        g(x, road); p("%c", 205);
        g(x, road+2); p("%c", 205);
    }

    g(5, 22); p(" ");
    g(10, 22); p(" ");
}

void parkingGarage()
{
    char ad[1], plate[3], garage[12][3], diff;

    int top = -1, arrivedn = 0, departn = 0, i, j, found = 0, k, chosen, q, foundA=0, dtime=75;

    parkingSpace(1);

    while (17)
    {
        g(30, 8); p("Type 'Q'/'q' to quit the program.");
        g(30, 12); p("NO. OF TIMES ARRIVED: %d", arrivedn);
        g(30, 13); p("NO. OF TIMES DEPART: %d", departn); g(30, 11); p("CAR PLATE NO.: ");
        g(30, 10); p("ARRIVAL/DEPARTURE (A/D): "); g(55, 10); s("%s", &ad);

        if (cp(ad, "A") == 0 || cp(ad, "a") == 0)
        {
            g(15, 16); p("                                                                 ");

            while (17)
            {
                g(46, 11); s("%s", plate);

                if (strlen(plate)<=2)
                {
                    break;
                }

                else
                {
                    g(46, 11); p("2 CHAR ONLY    "); getch(); g(46, 11); p("                                  ");
                }
            }

            for (i = top; i >= 0; i--)
            {
                if (strcmp(garage[i], plate) == 0)
                {
                    g(30, 16); p("The car is already in the garage.\n");
                    foundA = 1;
                }
            }

            if (foundA == 0)
            {
                if (top < 9)
                {
                    top++;
                    for (i=9; i>=top; i--)
                    {
                        if (i == top)
                        {
                            g(7, 22 - ((i+1) * 2)); p(plate);
                        }

                        else
                        {
                            g(7, 22 - ((i+1) * 2)); p(plate); delay(dtime);
                            g(7, 22 - ((i+1) * 2)); p("   ");
                        }
                    }
                    sy(garage[top], plate);
                    arrivedn++;
                }

                else
                {
                    g(30, 16); p("Sorry, the parking garage is full.\n");
                    break;
                }
            }

            else
            {
                foundA = 0;
            }
        }

        else if (cp(ad, "D") == 0 || cp(ad, "d") == 0)
        {
            g(15, 16); p("                                                                 ");


            while (17)
            {
                g(46, 11); s("%s", plate);

                if (strlen(plate)<=2)
                {
                    break;
                }

                else
                {
                    g(46, 11); p("2 CHAR ONLY    "); getch(); g(46, 11); p("                                  ");
                }
            }

            for (i = top; i >= 0; i--)
            {
                if (strcmp(garage[i], plate) == 0)
                {
                    g(15, 15); p("                                                                 ");
                    chosen = i;
                    found = 1;
                    diff = top;
                    departn = departn + ((top-i)+1);
                    arrivedn = arrivedn + (top-i);
                    while (diff >= chosen)
                    {
                        for (i=diff; i<=9; i++)
                        {
                            if (i == 9)
                            {
                                g(7, 22 - ((i+1) * 2)); p(garage[diff]);
                                g(7, 22 - ((i+1) * 2)); p("    ");

                                for (q=0; q<=(diff-chosen); q++)
                                {
                                    if (q == (diff-chosen))
                                    {
                                        g(7+(q+1)*5, 2); p(garage[diff]);
                                    }
                                    else
                                    {
                                        g(7+(q+1)*5, 2); p(garage[diff]); delay(dtime);
                                        g(7+(q+1)*5, 2); p("    ");
                                    }
                                }
                            }

                            else
                            {
                                g(7, 22 - ((i+1) * 2)); p(garage[diff]); delay(dtime);
                                g(7, 22 - ((i+1) * 2)); p("   ");
                            }
                        }
                        diff--;
                    }

                    for (i=9; i>=0; i--)
                    {
                        if (i == 9)
                        {
                            g(12, 22 - ((i+1) * 2)); p(garage[diff+1]);
                            g(12, 22 - ((i+1) * 2)); p("   ");
                        }

                        else
                        {
                            g(12, 22 - ((i+1) * 2)); p(garage[diff+1]); delay(dtime);
                            g(12, 22 - ((i+1) * 2)); p("   ");
                        }
                    }

                    while (diff < top-1)
                    {
                        diff++;
                        for (q=(diff-chosen); q>=0; q--)
                        {
                            if (q == 0)
                            {
                                g(7+(q+2)*5, 2); p(garage[diff+1]);
                                g(7+(q+2)*5, 2); p("    ");

                                for (i=9; i>=diff; i--)
                                {
                                    if (i == diff)
                                    {
                                        g(7, 22 - ((i+1) * 2)); p(garage[diff+1]);
                                    }

                                    else
                                    {
                                        g(7+(q+2)*5, 2); p("    ");
                                        g(7, 22 - ((i+1) * 2)); p(garage[diff+1]); delay(dtime);
                                        g(7, 22 - ((i+1) * 2)); p("   ");
                                    }
                                }
                            }

                            else
                            {
                                g(7+(q+2)*5, 2); p("    ");
                                g(7+(q+2)*5, 2); p(garage[diff+1]); delay(dtime);
                                g(7+(q+2)*5, 2); p("    ");
                            }
                        }
                    }
                    g(7, 22 - ((top+1) * 2)); p("   ");

                    for (k = chosen; k < top; k++)
                    {
                        sy(garage[k], garage[k + 1]);
                    }
                    top--;
                    break;
                }
            }


            if (found == 0)
            {
                g(30, 15); p("Car not found in the parking garage.\n");
            }

            found = 0;
        }

        else if (cp(ad, "Q") == 0 || cp(ad, "q") == 0)
        {
            break;
        }

        g(55, 10); p("       ");
        g(46, 11); p("       ");
    }
    getch();
}

//for binary tree

void box(i, j)
{
    g(i, j); p("%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 191);
    g(i, j+1); p("%c     %c", 179, 179);
    g(i, j+2); p("%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 217);
}

void tree(level)
{
    int x, x_gap, gap=0, i, j, corner=218;

    if (level > 1)
    {
        for (i=19; i<=59; i++)
        {
            if (i>=36 && i<=42)
            {
                continue;
            }
            else
            {
                g(i, 3); p("%c", 196); delay(20);
            }
        }

        if (level > 2)
        {
            for (i=9; i<=29; i++)
            {
                if (i>=16 && i<=22)
                {
                    continue;
                }
                else
                {
                    g(i, 6); p("%c", 196); delay(20);
                }
            }

            for (i=49; i<=69; i++)
            {
                if (i>=56 && i<=62)
                {
                    continue;
                }
                else
                {
                    g(i, 6); p("%c", 196); delay(20);
                }
            }
        }
    }

    for (i=1; i<=level; i++)
    {
        x = pow(2, i);
        x_gap = pow(2, i-1);

        while (gap<=x_gap-1)
        {
            box((((80/x)-4) + ((80/x_gap)*gap)), (2+((i-1)*3)));
            if (i > 1)
            {
                g((((80/x)-4) + ((80/x_gap)*gap))+3, (2+((i-1)*3))-1); p("%c", 179); delay(20);
                g((((80/x)-4) + ((80/x_gap)*gap))+3, (2+((i-1)*3))-2); p("%c", corner); delay(20);

                if (corner == 218)
                {
                    corner = 191;
                }

                else if (corner == 191)
                {
                    corner = 218;
                }
            }
            delay(20);

            gap++;
        }
        gap=0;
    }
}

void binaryCalculation(char LTR[15][3], char TLR[15][3], char LRT[15][3], int level)
{
    int i, o, k, j, n;

    for (i=0; i<=((pow(2, level))-2); i++)
    {
        o = k = 1;
        if (cp(LTR[i], "_") == 0)
        {
            if (cp(LTR[i+1], "_") == 0)
            {
                for (n=1; n<=15; n++)
                {
                    if (cp(LTR[i+n], "_") == 0)
                    {
                        o++;
                    }

                    else
                    {
                        break;
                    }
                }

                while (k<=o)
                {
                    for(j=i; j<=((pow(2, level))-2); j++)
                    {
                        sy(LTR[j], LTR[j+1]);
                    }
                    k++;
                }
            }

            else
            {
                for(j=i; j<=((pow(2, level))-2); j++)
                {
                    sy(LTR[j], LTR[j+1]);
                }
                k++;
            }
        }
    }


    for (i=0; i<=((pow(2, level))-2); i++)
    {
        o = k = 1;
        if (cp(TLR[i], "_") == 0)
        {
            if (cp(TLR[i+1], "_") == 0)
            {
                for (n=1; n<=15; n++)
                {

                    if (cp(TLR[i+n], "_") == 0)

                    {
                        o++;
                    }

                    else
                    {
                        break;
                    }
                }

                while (k<=o)
                {
                    for(j=i; j<=((pow(2, level))-2); j++)
                    {
                        sy(TLR[j], TLR[j+1]);
                    }
                    k++;
                }
            }

            else
            {
                for(j=i; j<=((pow(2, level))-2); j++)
                {
                    sy(TLR[j], TLR[j+1]);
                }
                k++;
            }
        }
    }

    for (i=0; i<=((pow(2, level))-2); i++)
    {
        o = k = 1;
        if (cp(LRT[i], "_") == 0)
        {
            if (cp(LRT[i+1], "_") == 0)
            {
                for (n=1; n<=15; n++)
                {

                    if (cp(LRT[i+n], "_") == 0)

                    {
                        o++;
                    }

                    else
                    {
                        break;
                    }
                }

                while (k<=o)
                {
                    for(j=i; j<=((pow(2, level))-2); j++)
                    {
                        sy(LRT[j], LRT[j+1]);
                    }
                    k++;
                }
            }

            else
            {
                for(j=i; j<=((pow(2, level))-2); j++)
                {
                    sy(LRT[j], LRT[j+1]);
                }
                k++;
            }
        }

    }
}

void printResults(char LTR[15][3], char TLR[15][3], char LRT[15][3], int level, int blankCount)
{
    int x, y, i, centerPlus = (39 - ((5 + ((pow(2, level))-1)  - blankCount)/2)), valid = 1;

    for (i=0; i<=((pow(2, level))-2)  - blankCount; i++)
    {
        if ((strlen(LTR[i]) > 1) || (strlen(TLR[i]) > 1) || (strlen(LRT[i]) > 1))
        {
            valid = 0;
            break;
        }
    }

    if (valid == 1)
    {
        for (x = centerPlus-2; x <= 80 - centerPlus; x++)
        {
            g(x, 19); p("%c", 205); delay(15);
            g(x, 23); p("%c", 205); delay(15);
        }
        for (y = 20; y <= 22; y++)
        {
            g(centerPlus-3, y); p("%c", 186); delay(15);
            g(80 - centerPlus, y); p("%c", 186); delay(15);
        }

        g(centerPlus-3, 19); p("%c", 201); g(80 - centerPlus, 19); p("%c", 187);
        g(centerPlus-3, 23); p("%c", 200); g(80 - centerPlus, 23); p("%c", 188);

        g(centerPlus, 20); p("LTR: ");
        g(centerPlus, 21); p("TLR: ");
        g(centerPlus, 22); p("LRT: ");

        for (i=0; i<=((pow(2, level))-2)  - blankCount; i++)
        {
            g(centerPlus+i+5, 20); p("%s", LTR[i]); delay(15);
            g(centerPlus+i+5, 21); p("%s", TLR[i]); delay(15);
            g(centerPlus+i+5, 22); p("%s", LRT[i]); delay(15);
        }

        for (i=1; i<= centerPlus-3; i++)
        {
            g(i, 21); p("%c", 205); delay(20);
            g(i+(79 - centerPlus), 21), p("%c", 205); delay(15);

            if (i == centerPlus -3)
            {
                g(i, 21); p("%c", 185); delay(20);
                g(80 - centerPlus, 21); p("%c", 204); delay(15);
            }
        }
    }

    else
    {
        g(2, 18), p("Invalid Input. One Character Only.");
    }


}

void binaryTree()
{
    int level, i, x, y, top, j, k=1, n, o=1, blankCount = 0;

    char a1[1], a2[1], a3[1], a4[1], a5[1], a6[1], a7[1], a8[1], a9[1], a10[1], a11[1], a12[1], a13[1], a14[1], a15[1];

    char LTR[15][3], TLR[15][3], LRT[15][3];

    clrscr();

    g(2, 16); p("Enter Level: "); g(2, 17); p("To input null on the tree, input '_'");

    while(17)
    {
        g(15, 16);
        if(s("%d", &level) != 1)
        {
            g(2, 18), p("Invalid Level Input."); getch(); g(2, 18), p("                    "); g(15, 16);  p("                    ");
            while (getchar() != '\n');
        }

        else
        {
            if (level <= 4 && level >= 1)
            {
                tree(level);

                if (level == 1)
                {

                    g(38, 3); s("%s", a1);

                    if (cp(a1, "_") == 0)
                    {
                        g(2,18); p("Empty Binary Tree. All Null.");
                    }

                    else
                    {
                        sy(LTR[0], a1); sy(TLR[0], a1); sy(LRT[0], a1);
                        binaryCalculation(LTR, TLR, LRT, level);
                        printResults(LTR, TLR, LRT, level, blankCount);
                    }
                }

                else if (level == 2)
                {
                    g(38, 3); s("%s", &a1);

                    if (cp(a1, "_") == 0)
                    {
                        g(2,18); p("Empty Binary Tree. All Null.");
                    }

                    else
                    {
                        g(18, 6); s("%s", &a2); g(58, 6); s("%s", &a3);

                        sy(LTR[0], a2); sy(LTR[1], a1); sy(LTR[2], a3);
                        sy(TLR[0], a1); sy(TLR[1], a2); sy(TLR[2], a3);
                        sy(LRT[0], a2); sy(LRT[1], a3); sy(LRT[2], a1);

                        for (i=0; i<=((pow(2, level))-2); i++)
                        {
                            if ((cp(LTR[i], "_") == 0))
                            {
                                blankCount++;
                            }
                        }

                        binaryCalculation(LTR, TLR, LRT, level);
                        printResults(LTR, TLR, LRT, level, blankCount);
                    }
                }

                else if (level == 3)
                {

                    g(38, 3); s("%s", &a1);

                    if (cp(a1, "_") == 0)
                    {
                        g(2,18); p("Empty Binary Tree. All Null.");
                    }

                    else
                    {
                        g(18, 6); s("%s", &a2); g(58, 6); s("%s", &a3);

                        if ((cp(a2, "_") == 0) && (cp(a3, "_") == 0))
                        {
                            sy(a4, "_"); sy(a5, "_"); sy(a6, "_"); sy(a7, "_");
                        }

                        else if (cp(a2, "_") == 0)
                        {
                            sy(a4, "_"); sy(a5, "_"); g(48, 9); s("%s", &a6); g(68, 9); s("%s", &a7);
                        }

                        else if (cp(a3, "_") == 0)
                        {
                            g(8, 9); s("%s", &a4); g(28, 9); s("%s", &a5); sy(a6, "_"); sy(a7, "_");
                        }

                        else
                        {
                            g(8, 9); s("%s", &a4); g(28, 9); s("%s", &a5); g(48, 9); s("%s", &a6); g(68, 9); s("%s", &a7);
                        }

                        sy(LTR[0], a4); sy(LTR[1], a2); sy(LTR[2], a5); sy(LTR[3], a1); sy(LTR[4], a6); sy(LTR[5], a3); sy(LTR[6], a7);
                        sy(TLR[0], a1); sy(TLR[1], a2); sy(TLR[2], a4); sy(TLR[3], a5); sy(TLR[4], a3); sy(TLR[5], a6); sy(TLR[6], a7);
                        sy(LRT[0], a4); sy(LRT[1], a5); sy(LRT[2], a2); sy(LRT[3], a6); sy(LRT[4], a7); sy(LRT[5], a3); sy(LRT[6], a1);

                        for (i=0; i<=((pow(2, level))-2); i++)
                        {
                            if ((cp(LTR[i], "_") == 0))
                            {
                                blankCount++;
                            }
                        }

                        binaryCalculation(LTR, TLR, LRT, level);

                        printResults(LTR, TLR, LRT, level, blankCount);
                    }
                }

                else if (level == 4)
                {
                    g(38, 3); s("%s", &a1);

                    if (cp(a1, "_") == 0)
                    {
                        g(2,18); p("Empty Binary Tree. All Null.");
                    }

                    else
                    {
                        g(18, 6); s("%s", &a2); g(58, 6); s("%s", &a3);

                        if ((cp(a2, "_") == 0) && (cp(a3, "_") == 0))
                        {
                            sy(a4, "_"); sy(a5, "_"); sy(a6, "_"); sy(a7, "_"); sy(a8, "_"); sy(a9, "_");
                            sy(a10, "_"); sy(a11, "_"); sy(a12, "_"); sy(a13, "_"); sy(a14, "_"); sy(a15, "_");
                        }

                        else if (cp(a2, "_") == 0)
                        {
                            sy(a4, "_"); sy(a5, "_"); sy(a8, "_"); sy(a9, "_"); sy(a10, "_"); sy(a11, "_"); g(48, 9); s("%s", &a6); g(68, 9); s("%s", &a7);

                            if ((cp(a6, "_") == 0) && (cp(a7, "_") == 0))
                            {
                                sy(a12, "_"); sy(a13, "_"); sy(a14, "_"); sy(a15, "_");
                            }

                            else if (cp(a7, "_") == 0)
                            {
                                g(43, 12); s("%s", &a12); g(53, 12); s("%s", &a13); sy(a14, "_"); sy(a15, "_");
                            }

                            else if (cp(a6, "_") == 0)
                            {
                                sy(a12, "_"); sy(a13, "_"); g(63, 12); s("%s", &a14); g(73, 12); s("%s", &a15);
                            }

                            else
                            {
                                g(43, 12); s("%s", &a12); g(53, 12); s("%s", &a13); g(63, 12); s("%s", &a14); g(73, 12); s("%s", &a15);
                            }
                        }

                        else if (cp(a3, "_") == 0)
                        {
                            g(8, 9); s("%s", &a4); g(28, 9); s("%s", &a5); sy(a6, "_"); sy(a7, "_"); sy(a12, "_"); sy(a13, "_"); sy(a14, "_"); sy(a15, "_");

                            if ((cp(a4, "_") == 0) && (cp(a5, "_") == 0))
                            {
                                sy(a8, "_"); sy(a9, "_"); sy(a10, "_"); sy(a11, "_");
                            }

                            else if (cp(a5, "_") == 0)
                            {
                                g(3, 12); s("%s", &a8); g(13, 12); s("%s", &a9); sy(a10, "_"); sy(a11, "_");
                            }

                            else if (cp(a4, "_") == 0)
                            {
                                sy(a8, "_"); sy(a9, "_"); g(23, 12); s("%s", &a10); g(33, 12); s("%s", &a11);
                            }

                            else
                            {
                                g(3, 12); s("%s", &a8); g(13, 12); s("%s", &a9); g(23, 12); s("%s", &a10); g(33, 12); s("%s", &a11);
                            }
                        }

                        else
                        {
                            g(8, 9); s("%s", &a4); g(28, 9); s("%s", &a5); g(48, 9); s("%s", &a6); g(68, 9); s("%s", &a7);

                            if ((cp(a4, "_") == 0) && (cp(a5, "_") == 0))
                            {
                                sy(a8, "_"); sy(a9, "_"); sy(a10, "_"); sy(a11, "_");

                                if ((cp(a6, "_") == 0) && (cp(a7, "_") == 0))
                                {
                                    sy(a12, "_"); sy(a13, "_"); sy(a14, "_"); sy(a15, "_");
                                }

                                else if (cp(a7, "_") == 0)
                                {
                                    g(43, 12); s("%s", &a12); g(53, 12); s("%s", &a13); sy(a14, "_"); sy(a15, "_");
                                }

                                else if (cp(a6, "_") == 0)
                                {
                                    sy(a12, "_"); sy(a13, "_"); g(63, 12); s("%s", &a14); g(73, 12); s("%s", &a15);
                                }

                                else
                                {
                                    g(43, 12); s("%s", &a12); g(53, 12); s("%s", &a13); g(63, 12); s("%s", &a14); g(73, 12); s("%s", &a15);
                                }
                            }

                            else if (cp(a4, "_") == 0)
                            {
                                sy(a8, "_"); sy(a9, "_"); g(23, 12); s("%s", &a10); g(33, 12); s("%s", &a11);

                                if ((cp(a6, "_") == 0) && (cp(a7, "_") == 0))
                                {
                                    sy(a12, "_"); sy(a13, "_"); sy(a14, "_"); sy(a15, "_");
                                }

                                else if (cp(a7, "_") == 0)
                                {
                                    g(43, 12); s("%s", &a12); g(53, 12); s("%s", &a13); sy(a14, "_"); sy(a15, "_");
                                }

                                else if (cp(a6, "_") == 0)
                                {
                                    sy(a12, "_"); sy(a13, "_"); g(63, 12); s("%s", &a14); g(73, 12); s("%s", &a15);
                                }

                                else
                                {
                                    g(43, 12); s("%s", &a12); g(53, 12); s("%s", &a13); g(63, 12); s("%s", &a14); g(73, 12); s("%s", &a15);
                                }
                            }

                            else if (cp(a5, "_") == 0)
                            {

                                if ((cp(a6, "_") == 0) && (cp(a7, "_") == 0))
                                {
                                    sy(a12, "_"); sy(a13, "_"); sy(a14, "_"); sy(a15, "_");
                                }

                                else if (cp(a7, "_") == 0)
                                {
                                    g(43, 12); s("%s", &a12); g(53, 12); s("%s", &a13); sy(a14, "_"); sy(a15, "_");
                                }

                                else if (cp(a6, "_") == 0)
                                {
                                    sy(a12, "_"); sy(a13, "_"); g(63, 12); s("%s", &a14); g(73, 12); s("%s", &a15);
                                }

                                else
                                {
                                    g(43, 12); s("%s", &a12); g(53, 12); s("%s", &a13); g(63, 12); s("%s", &a14); g(73, 12); s("%s", &a15);
                                }

                                g(3, 12); s("%s", &a8); g(13, 12); s("%s", &a9); sy(a10, "_"); sy(a11, "_");
                            }

                            else if ((cp(a6, "_") == 0) && (cp(a7, "_") == 0))
                            {
                                sy(a12, "_"); sy(a13, "_"); sy(a14, "_"); sy(a15, "_");

                                if ((cp(a4, "_") == 0) && (cp(a5, "_") == 0))
                                {
                                    sy(a8, "_"); sy(a9, "_"); sy(a10, "_"); sy(a11, "_");
                                }

                                else if (cp(a5, "_") == 0)
                                {
                                    g(3, 12); s("%s", &a8); g(13, 12); s("%s", &a9); sy(a10, "_"); sy(a11, "_");
                                }

                                else if (cp(a4, "_") == 0)
                                {
                                    sy(a8, "_"); sy(a9, "_"); g(23, 12); s("%s", &a10); g(33, 12); s("%s", &a11);
                                }

                                else
                                {
                                    g(3, 12); s("%s", &a8); g(13, 12); s("%s", &a9); g(23, 12); s("%s", &a10); g(33, 12); s("%s", &a11);
                                }
                            }

                            else if (cp(a6, "_") == 0)
                            {
                                sy(a12, "_"); sy(a13, "_"); g(63, 12); s("%s", &a14); g(73, 12); s("%s", &a15);

                                if ((cp(a4, "_") == 0) && (cp(a5, "_") == 0))
                                {
                                    sy(a8, "_"); sy(a9, "_"); sy(a10, "_"); sy(a11, "_");
                                }

                                else if (cp(a5, "_") == 0)
                                {
                                    g(3, 12); s("%s", &a8); g(13, 12); s("%s", &a9); sy(a10, "_"); sy(a11, "_");
                                }

                                else if (cp(a4, "_") == 0)
                                {
                                    sy(a8, "_"); sy(a9, "_"); g(23, 12); s("%s", &a10); g(33, 12); s("%s", &a11);
                                }

                                else
                                {
                                    g(3, 12); s("%s", &a8); g(13, 12); s("%s", &a9); g(23, 12); s("%s", &a10); g(33, 12); s("%s", &a11);
                                }
                            }

                            else if (cp(a7, "_") == 0)
                            {
                                g(43, 12); s("%s", &a12); g(53, 12); s("%s", &a13); sy(a14, "_"); sy(a15, "_");

                                if ((cp(a4, "_") == 0) && (cp(a5, "_") == 0))
                                {
                                    sy(a8, "_"); sy(a9, "_"); sy(a10, "_"); sy(a11, "_");
                                }

                                else if (cp(a5, "_") == 0)
                                {
                                    g(3, 12); s("%s", &a8); g(13, 12); s("%s", &a9); sy(a10, "_"); sy(a11, "_");
                                }

                                else if (cp(a4, "_") == 0)
                                {
                                    sy(a8, "_"); sy(a9, "_"); g(23, 12); s("%s", &a10); g(33, 12); s("%s", &a11);
                                }

                                else
                                {
                                    g(3, 12); s("%s", &a8); g(13, 12); s("%s", &a9); g(23, 12); s("%s", &a10); g(33, 12); s("%s", &a11);
                                }
                            }

                            else
                            {
                                g(3, 12); s("%s", &a8); g(13, 12); s("%s", &a9); g(23, 12); s("%s", &a10); g(33, 12); s("%s", &a11);
                                g(43, 12); s("%s", &a12); g(53, 12); s("%s", &a13); g(63, 12); s("%s", &a14); g(73, 12); s("%s", &a15);
                            }


                        }

                        sy(LTR[0], a8); sy(LTR[1], a4); sy(LTR[2], a9); sy(LTR[3], a2); sy(LTR[4], a10); sy(LTR[5], a5); sy(LTR[6], a11);
                        sy(LTR[7], a1); sy(LTR[8], a12); sy(LTR[9], a6); sy(LTR[10], a13); sy(LTR[11], a3); sy(LTR[12], a14); sy(LTR[13], a7); sy(LTR[14], a15);

                        sy(TLR[0], a1); sy(TLR[1], a2); sy(TLR[2], a4); sy(TLR[3], a8); sy(TLR[4], a9); sy(TLR[5], a5); sy(TLR[6], a10);
                        sy(TLR[7], a11); sy(TLR[8],a3); sy(TLR[9], a6); sy(TLR[10], a12); sy(TLR[11], a13); sy(TLR[12], a7); sy(TLR[13], a14); sy(TLR[14], a15);

                        sy(LRT[0], a8); sy(LRT[1], a9); sy(LRT[2], a4); sy(LRT[3], a10); sy(LRT[4], a11); sy(LRT[5], a5); sy(LRT[6], a2);
                        sy(LRT[7], a12); sy(LRT[8], a13); sy(LRT[9], a6); sy(LRT[10], a14); sy(LRT[11], a15); sy(LRT[12], a7); sy(LRT[13], a3); sy(LRT[14], a1);

                        for (i=0; i<=((pow(2, level))-2); i++)
                        {
                            if ((cp(LTR[i], "_") == 0))
                            {
                                blankCount++;
                            }
                        }

                        binaryCalculation(LTR, TLR, LRT, level);
                        printResults(LTR, TLR, LRT, level, blankCount);

                    }
                }
                break;
            }

            else
            {
                g(2, 18), p("Level input must only be from 1-4"); getch(); g(2, 18), p("                                                 "); g(15, 16);  p("                    ");
            }
        }
    }
    getch();
}

// digital clock

void numLayout(x, y)
{
    g(x, y); p("%c%c%c%c%c", 178, 178, 178, 178, 178);
    g(x, y+1); p("%c   %c", 178, 178);
    g(x, y+2); p("%c   %c", 178, 178);
    g(x, y+3); p("%c%c%c%c%c", 178, 178, 178, 178, 178);
    g(x, y+4); p("%c   %c", 178, 178);
    g(x, y+5); p("%c   %c", 178, 178);
    g(x, y+6); p("%c%c%c%c%c", 178, 178, 178, 178, 178);
}

void digiNum(num, x, y)
{
    switch(num)
    {
        case 0:
            numLayout(x, y);
            g(x+1, y+3); p("   ");
            break;

        case 1:
            numLayout(x, y);
            g(x, y); p("    ");
            g(x, y+1); p("    ");
            g(x, y+2); p("    ");
            g(x, y+3); p("    ");
            g(x, y+4); p("    ");
            g(x, y+5); p("    ");
            g(x, y+6); p("    ");
            break;

        case 2:
            numLayout(x, y);
            g(x, y+1); p(" ");
            g(x, y+2); p(" ");
            g(x+4, y+4); p(" ");
            g(x+4, y+5); p(" ");
            break;

        case 3:
            numLayout(x, y);
            g(x, y+1); p(" ");
            g(x, y+2); p(" ");
            g(x, y+4); p(" ");
            g(x, y+5); p(" ");
            break;

        case 4:
            numLayout(x, y);
            g(x+1, y); p("   ");
            g(x, y+4); p(" ");
            g(x, y+5); p(" ");
            g(x, y+6); p("    ");
            break;

        case 5:
            numLayout(x, y);
            g(x+4, y+1); p(" ");
            g(x+4, y+2); p(" ");
            g(x, y+4); p(" ");
            g(x, y+5); p(" ");
            break;

        case 6:
            numLayout(x, y);
            g(x+4, y+1); p(" ");
            g(x+4, y+2); p(" ");
            break;

        case 7:
            numLayout(x, y);
            g(x, y+1); p("    ");
            g(x, y+2); p("    ");
            g(x, y+3); p("    ");
            g(x, y+4); p("    ");
            g(x, y+5); p("    ");
            g(x, y+6); p("    ");
            break;

        case 8:
            numLayout(x, y);
            break;

        case 9:
            numLayout(x, y);
            g(x, y+4); p(" ");
            g(x, y+5); p(" ");
            break;


        default:
            p("Error.");
            break;
    }
}

void digiClock(hr, min, sec, x, y)
{
    int hrT, minT, secT, hrO, minO, secO, a;

    for (a = x+1; a <= x+41; a++)
    {
        g(a, y+11); p("%c", 177);
        g(a, y+12); p("%c", 178);
        g(a, y+13); p("%c", 178);
        g(a, y+14); p("%c", 178);
    }

    g(x, y); p("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
    g(x, y+10); p("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);

    for (a=(y+1); a<=(y+9); a++)
    {
        g(x-1, a); p("%c", 186);
    }

    for (a=(y+1); a<=(y+9); a++)
    {
        g(x+43, a); p("%c", 186);
    }

    for (a=(y+11); a<=(y+13); a++)
    {
        g(x-1, a); p("%c", 186);
    }

    for (a=(y+11); a<=(y+13); a++)
    {
        g(x+43, a); p("%c", 186);
    }



    g(x, y+14); p("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);

    g(x-1, y); p("%c", 201); g(x+43, y); p("%c", 187); g(x-1, y+10); p("%c", 204); g(x+43, y+10); p("%c", 185); g(x-1, y+14); p("%c", 200); g(x+43, y+14); p("%c", 188);


    hrT = ((hr-(hr%10))/10); minT = ((min-(min%10))/10); secT = ((sec-(sec%10))/10);
    hrO = hr%10; minO = min%10; secO = sec%10;

    digiNum(hrT, x+2, y+2); digiNum(hrO, x+8, y+2); g(x+14, y+4); p("%c", 254); g(x+14, y+6); p("%c", 254);
    digiNum(minT, x+16, y+2); digiNum(minO, x+22, y+2); g(x+28, y+4); p("%c", 254); g(x+28, y+6); p("%c", 254);
    digiNum(secT, x+30, y+2); digiNum(secO, x+36, y+2); delay(999);

}

void digitalClock()
{
    int hr, min, x, y, sec, hour, minute, second, place;
    char stringHour[1], stringMinute[1], stringSecond[1];

    clrscr();

    pupBorders();

    for (y = 3; y <= 23; y++)
    {
        g(30, y); p("%c", 186);
    }
    for (y = 3; y <= 23; y++)
    {
        g(31, y); p("%c", 186);
    }

    g(31,2); p("%c", 201);
    g(30,2); p("%c", 187);
    g(31,24); p("%c", 200);
    g(30,24); p("%c", 188);

    g(4, 10); p("Enter Time (12-HR FORMAT)");
    g(12, 12); p("HH:MM:SS");
    g(14, 13); p(":");
    g(17, 13); p(":");

    while (17)
    {
        g(12, 13); s("%s", stringHour);
        hour = verifier(3, stringHour, hour);

        if (hour <=12 && hour >= 1)
        {
            while (17)
            {
                g(15, 13);  s("%s", stringMinute);
                minute = verifier(3, stringMinute, minute);

                if (minute <=59 && minute >= 0)
                {
                    while (17)
                    {
                        g(18, 13); s("%s", stringSecond);

                        second = verifier(3, stringSecond, second);

                        if (second <=59 && second >= 0)
                        {
                            break;
                        }

                        else
                        {
                            g(5, 16); p("Invalid Input.   "); getch(); g(5, 16); p("              "); g(18, 13); p("  ");
                        }

                    }
                    break;
                }

                else
                {
                    g(5, 16); p("Invalid Input.   "); getch(); g(5, 16); p("              "); g(15, 13); p("  ");
                }
            }
            break;

        }

        else
        {
            g(5, 16); p("Invalid Input.   "); getch(); g(5, 16); p("              "); g(12, 13); p("  ");
        }
    }

    place = 1;

    while (place > 0)
    {
        for (hr=hour; hr<=12; hr++)
        {
            for (min=minute; min<=59; min++)
            {
                for (sec=second; sec <=59; sec++)
                {
                    digiClock(hr, min, sec, 34, 6);

                    if(kbhit())
                    {
                        place=0;
                        break;
                    }
                }
                if (place == 0) break;
                second = 0;
            }
            if (place == 0) break;
            minute = 0;
        }
        if (place == 0) break;
        hour = 1;
    }
}

// tower of hanoi
void hanoiRods(x, y)
{
    int a;

    g(x, y); p("%c%c%c", 201, 205, 187);

    for (a=y+1; a<=y+15; a++)
    {
        g(x, a); p("%c", 186);
        g(x+2, a); p("%c", 186);
    }
}

void hanoiRings(x, y, level)
{
    int a;

    if (level == 0)
    {
        g(x, y); p("");
    }

    else
    {
        for (a=(x-((level*2))); a<=(x+((level*2)))-2; a++)
        {
            g(a, y); p("%c", 196); g(a, y+1); p("%c", 178); g(a, y+2); p("%c", 196);
        }

        g((x-((level*2))), y); p("%c", 218); g((x+((level*2)))-2, y); p("%c", 191);
        g((x-((level*2))), y+1); p("%c", 179); g((x+((level*2)))-2, y+1); p("%c", 179);
        g((x-((level*2))), y+2); p("%c", 192); g((x+((level*2)))-2, y+2); p("%c", 217);
    }
}

void hanoiErase(x, y, level)
{
    int a;

    if (level == 0)
    {
        for (a=(x-((level*2))); a<=(x+((level*2)))-2; a++)
        {
            g(a, y); p(" "); g(a, y+1); p(" "); g(a, y+2); p(" ");
        }

        g((x-((level*2))), y); p(" "); g((x+((level*2)))-2, y); p(" ");
        g((x-((level*2))), y+1); p(" "); g((x+((level*2)))-2, y+1); p(" ");
        g((x-((level*2))), y+2); p(" "); g((x+((level*2)))-2, y+2); p(" ");
    }

    else
    {
        for (a=(x-((level*2))); a<=(x+((level*2)))-2; a++)
        {
            g(a, y); p(" "); g(a, y+1); p(" "); g(a, y+2); p(" ");
        }

        g((x-((level*2))), y); p(" "); g((x+((level*2)))-2, y); p(" ");
        g((x-((level*2))), y+1); p(" "); g((x+((level*2)))-2, y+1); p(" ");
        g((x-((level*2))), y+2); p(" "); g((x+((level*2)))-2, y+2); p(" ");
    }
}

void hanoiSet(x)
{
    int a, i, j;

    for (a=1; a<=79; a++)
    {
        g(a, 19); p("%c", 205);
    }

    for (i=1; i<=79; i++)
    {
        for (j=20; j<=25; j++)
        {
            if (j>22)
            {
                g(i, j); p("%c", 178);
            }
            else
            {
                g(i, j); p("%c", 176+(j-20));
            }
        }
    }

    g(x, 19); p("%c", 202); g(x+25, 19); p("%c", 202); g(x+50, 19); p("%c", 202);
    g(x+2, 19); p("%c", 202); g(x+27, 19); p("%c", 202); g(x+52, 19); p("%c", 202);
}

void hanoiEraseSet(x)
{
    int a;

    for (a=7; a>=1; a--)
    {
        hanoiErase(x+2, ((a*2)+2), 7);
    }
}

void hanoiRefresh(int* rodA, int* rodB, int* rodC)
{
    int a;

    for (a=0; a<=4; a++)
    {
        hanoiErase(15, 16-(a*2), rodA[a]);
        hanoiErase(40, 16-(a*2), rodB[a]);
        hanoiErase(65, 16-(a*2), rodC[a]);
    }

    hanoiRods(38, 3); hanoiRods(13, 3); hanoiRods(63, 3);
    hanoiSet(13);

    for (a=0; a<=4; a++)
    {
        hanoiRings(15, 16-(a*2), rodA[a]);
        hanoiRings(40, 16-(a*2), rodB[a]);
        hanoiRings(65, 16-(a*2), rodC[a]);
    }

    delay (600);


}

void hanoiRefreshOptional(int* topA, int* topB, int* topC, int* rodA, int* rodB, int* rodC, char exceptList)
{
    int a, decisionA = 4, decisionB = 4, decisionC = 4;

    switch(exceptList)
    {
        case 'A':
            decisionA = atoi(&(*topA)) - 1;
            break;
        case 'B':
            decisionB = atoi(&(*topB)) - 1;
            break;

        case 'C':
            decisionC = atoi(&(*topC)) - 1;
            break;
    }

    for (a=0; a<=decisionA; a++)
    {
        hanoiRings(15, 16-(a*2), rodA[a]);
    }

    for (a=0; a<=decisionB; a++)
    {
        hanoiRings(40, 16-(a*2), rodB[a]);
    }

    for (a=0; a<=decisionC; a++)
    {
        hanoiRings(65, 16-(a*2), rodC[a]);
    }
}

void moveRods(int* source, int* dest, int* topS, int* topD)
{
    (*topD)++;
    dest[*topD] = source[*topS];
    source[*topS] = 0;
    (*topS)--;
}

void moveAnimationLeaving(int* topA, int* topB, int* topC, int* rodA, int* rodB, int* rodC, int rodNum, int* rodPlace, int* rodNeed, char rOptional)
{
    int k;

    for (k=16-((*rodNeed)*2); k>=4; k--)
    {
        hanoiRefreshOptional(topA, topB, topC, rodA, rodB, rodC, rOptional);
        hanoiRings(rodNum, k, rodPlace[(*rodNeed)]); delay(25);
        hanoiErase(rodNum, k, rodPlace[(*rodNeed)]);
        hanoiRods(rodNum-2, 3);
    }
}

void moveAnimation(int* topA, int* topB, int* topC, int* rodA, int* rodB, int* rodC, int rodNum, int* rodPlace, int* rodNeed, char rOptional)
{
    int k;
    for (k=4; k<=16-((*rodNeed)*2); k++)
    {
        hanoiRods(rodNum-2, 3);
        hanoiRefreshOptional(topA, topB, topC, rodA, rodB, rodC, rOptional);
        hanoiRings(rodNum, k, rodPlace[(*rodNeed)]); delay(25);
        hanoiErase(rodNum, k, rodPlace[(*rodNeed)]);
    }
}

void moveDirection(int* topA, int* topB, int* topC, int* rodA, int* rodB, int* rodC, char* rodS, char* direction)
{
    if (sc(rodS, "A") == 0 && sc(direction, "L") == 0)
    {
        moveAnimationLeaving(topA, topB, topC, rodA, rodB, rodC, 15, rodA, &(*topA), 'A');
        moveRods(rodA, rodC, &(*topA), &(*topC));
        moveAnimation(topA, topB, topC, rodA, rodB, rodC, 65, rodC, &(*topC), 'C');
    }

    if (sc(rodS, "A") == 0 && sc(direction, "R") == 0)
    {
        moveAnimationLeaving(topA, topB, topC, rodA, rodB, rodC, 15, rodA, &(*topA), 'A');
        moveRods(rodA, rodB, &(*topA), &(*topB));
        moveAnimation(topA, topB, topC, rodA, rodB, rodC, 40, rodB, &(*topB), 'B');
    }

    if (sc(rodS, "B") == 0 && sc(direction, "L") == 0)
    {
        moveAnimationLeaving(topA, topB, topC, rodA, rodB, rodC, 40, rodB, &(*topB), 'B');
        moveRods(rodB, rodA, &(*topB), &(*topA));
        moveAnimation(topA, topB, topC, rodA, rodB, rodC, 15, rodA, &(*topA), 'A');
    }

    if (sc(rodS, "B") == 0 && sc(direction, "R") == 0)
    {
        moveAnimationLeaving(topA, topB, topC, rodA, rodB, rodC, 40, rodB, &(*topB), 'B');
        moveRods(rodB, rodC, &(*topB), &(*topC));
        moveAnimation(topA, topB, topC, rodA, rodB, rodC, 65, rodC, &(*topC), 'C');
    }

    if (sc(rodS, "C") == 0 && sc(direction, "L") == 0)
    {
        moveAnimationLeaving(topA, topB, topC, rodA, rodB, rodC, 65, rodC, &(*topC), 'C');
        moveRods(rodC, rodB, &(*topC), &(*topB));
        moveAnimation(topA, topB, topC, rodA, rodB, rodC, 40, rodB, &(*topB), 'B');
    }

    if (sc(rodS, "C") == 0 && sc(direction, "R") == 0)
    {
        moveAnimationLeaving(topA, topB, topC, rodA, rodB, rodC, 65, rodC, &(*topC), 'C');
        moveRods(rodC, rodA, &(*topC), &(*topA));
        moveAnimation(topA, topB, topC, rodA, rodB, rodC, 15, rodA, &(*topA), 'A');
    }
}

char* search(int* rodA, int* rodB, int* rodC, int key)
{
    int a;

    for (a=0; a<=6; a++)
    {
        if (rodA[a] == (key))
        {
            return "A";
            break;
        }

        if (rodB[a] == (key))
        {
            return "B";
            break;
        }

        if (rodC[a] == (key))
        {
            return "C";
            break;
        }
    }
}

void moveLegal(int* topA, int* topB, int* topC, int* rodA, int* rodB, int* rodC, int key)
{
    if (sc(search(rodA, rodB, rodC, key), "A")==0)
    {
        if ((rodA[*topA] < rodB[*topB]) || (rodB[*topB] == 0))
        {
            moveDirection(&(*topA), &(*topB), &(*topC), rodA, rodB, rodC, search(rodA, rodB, rodC, key), "R");
        }

        else if ((rodA[*topA] < rodC[*topC]) || (rodC[*topC] == 0))
        {
            moveDirection(&(*topA), &(*topB), &(*topC), rodA, rodB, rodC, search(rodA, rodB, rodC, key), "L");
        }
    }

    else if (sc(search(rodA, rodB, rodC, key), "B")==0)
    {
        if ((rodB[*topB] < rodC[*topC]) || (rodC[*topC] == 0))
        {
            moveDirection(&(*topA), &(*topB), &(*topC), rodA, rodB, rodC, search(rodA, rodB, rodC, key), "R");
        }

        else if ((rodB[*topB] < rodA[*topA]) || (rodA[*topA] == 0))
        {
            moveDirection(&(*topA), &(*topB), &(*topC), rodA, rodB, rodC, search(rodA, rodB, rodC, key), "L");
        }
    }

    else if (sc(search(rodA, rodB, rodC, key), "C")==0)
    {
        if ((rodC[*topC] < rodB[*topB]) || (rodB[*topB] == 0))
        {
            moveDirection(&(*topA), &(*topB), &(*topC), rodA, rodB, rodC, search(rodA, rodB, rodC, key), "L");
        }

        else if ((rodC[*topC] < rodA[*topA]) || (rodA[*topA] == 0))
        {
            moveDirection(&(*topA), &(*topB), &(*topC), rodA, rodB, rodC, search(rodA, rodB, rodC, key), "R");
        }
    }
}

void refresh(int* rodA, int* rodB, int* rodC)
{
    hanoiEraseSet(13); hanoiEraseSet(38); hanoiEraseSet(63);
    hanoiRods(38, 3); hanoiRods(13, 3); hanoiRods(63, 3);
    hanoiRefresh(rodA, rodB, rodC);
}

void firstSeven(int* topA, int* topB, int* topC, int* rodA, int* rodB, int* rodC, int initial)
{
    moveDirection(&(*topA), &(*topB), &(*topC), rodA, rodB, rodC, search(rodA, rodB, rodC, initial), "L"); refresh(rodA, rodB, rodC);
    moveLegal(&(*topA), &(*topB), &(*topC), rodA, rodB, rodC, initial+1); refresh(rodA, rodB, rodC);
    moveDirection(&(*topA), &(*topB), &(*topC), rodA, rodB, rodC, search(rodA, rodB, rodC, initial), "L"); refresh(rodA, rodB, rodC);
    moveLegal(&(*topA), &(*topB), &(*topC), rodA, rodB, rodC, initial+2); refresh(rodA, rodB, rodC);
    moveDirection(&(*topA), &(*topB), &(*topC), rodA, rodB, rodC, search(rodA, rodB, rodC, initial), "L"); refresh(rodA, rodB, rodC);
    moveLegal(&(*topA), &(*topB), &(*topC), rodA, rodB, rodC, initial+1); refresh(rodA, rodB, rodC);
    moveDirection(&(*topA), &(*topB), &(*topC), rodA, rodB, rodC, search(rodA, rodB, rodC, initial), "L"); refresh(rodA, rodB, rodC);
}

void firstSevenRight(int* topA, int* topB, int* topC, int* rodA, int* rodB, int* rodC, int initial)
{
    moveDirection(&(*topA), &(*topB), &(*topC), rodA, rodB, rodC, search(rodA, rodB, rodC, initial), "R"); refresh(rodA, rodB, rodC);
    moveLegal(&(*topA), &(*topB), &(*topC), rodA, rodB, rodC, initial+1); refresh(rodA, rodB, rodC);
    moveDirection(&(*topA), &(*topB), &(*topC), rodA, rodB, rodC, search(rodA, rodB, rodC, initial), "R"); refresh(rodA, rodB, rodC);
    moveLegal(&(*topA), &(*topB), &(*topC), rodA, rodB, rodC, initial+2); refresh(rodA, rodB, rodC);
    moveDirection(&(*topA), &(*topB), &(*topC), rodA, rodB, rodC, search(rodA, rodB, rodC, initial), "R"); refresh(rodA, rodB, rodC);
    moveLegal(&(*topA), &(*topB), &(*topC), rodA, rodB, rodC, initial+1); refresh(rodA, rodB, rodC);
    moveDirection(&(*topA), &(*topB), &(*topC), rodA, rodB, rodC, search(rodA, rodB, rodC, initial), "R"); refresh(rodA, rodB, rodC);
}

void towerHanoi()
{
    int big[3]= {4, 5, 4}, a, b, i, j, k, mode, iterate, choice, randomNumber, topA=4, topB=-1, topC=-1, rodA[5] = {0, 0, 0, 0, 0}, rodB[5] = {0, 0, 0, 0, 0}, rodC[5] = {0, 0, 0, 0, 0};

    clrscr();

    pupBorders();

    g(35, 12); p("Select a mode");
    g(36, 13); p("0 - Random");
    g(36, 14); p("1 - Standard");

    while (17)
    {
        mode = getch();
        if (mode == 48)
        {
            srand(time(NULL));
            randomNumber = (rand() % 5) + 1;
            break;
        }

        else if (mode == 49)
        {
            randomNumber = 1;
            break;
        }
    }

    switch(randomNumber)
    {
        case 1:
            rodA[0] = 5; rodA[1] = 4; rodA[2] = 3; rodA[3] = 2; rodA[4] = 1;
            break;
        case 2:
            rodA[0] = 4; rodA[1] = 3; rodA[2] = 2; rodA[3] = 1; rodA[4] = 5;
            break;
        case 3:
            rodA[0] = 3; rodA[1] = 2; rodA[2] = 1; rodA[3] = 5; rodA[4] = 4;
            break;
        case 4:
            rodA[0] = 2; rodA[1] = 1; rodA[2] = 5; rodA[3] = 4; rodA[4] = 3;
            break;
        case 5:
            rodA[0] = 1; rodA[1] = 5; rodA[2] = 4; rodA[3] = 3; rodA[4] = 2;
            break;

        default:
            break ;
    }

    clrscr();

    for (i=0; i<=4; i++)
    {
        hanoiRods(13, 3); hanoiRods(38, 3); hanoiRods(63, 3);

        hanoiSet(13);

        moveAnimation(&topA, &topB, &topC, rodA, rodB, rodC, 15, rodA, &i, 'A'); hanoiRods(13, 3);

        for (j=0; j<=i; j++)
        {
            hanoiRods(13, 3);
            hanoiRings(15, 16-(j*2), rodA[j]);
        }
    }

    hanoiRefresh(rodA, rodB, rodC); refresh(rodA, rodB, rodC);

    if ((rodA[0] == 5) && (rodA[1] == 4) && (rodA[2] == 3) && (rodA[3] == 2) && (rodA[4] == 1))
    {
        for (a=0; a<=3; a++)
        {
            firstSeven(&topA, &topB, &topC, rodA, rodB, rodC, 1);

            if (a==3)
            {
                break;
            }

            else
            {
                moveLegal(&topA, &topB, &topC, rodA, rodB, rodC, big[a]); refresh(rodA, rodB, rodC);
            }
        }
    }

    else if (rodA[0] == 4 && rodA[1] == 3 && rodA[2] == 2 && rodA[3] == 1 && rodA[4] == 5)
    {
        moveLegal(&topA, &topB, &topC, rodA, rodB, rodC, rodA[4]); refresh(rodA, rodB, rodC);
        moveLegal(&topA, &topB, &topC, rodA, rodB, rodC, rodB[0]); refresh(rodA, rodB, rodC);

        for (a=0; a<=1; a++)
        {
            firstSevenRight(&topA, &topB, &topC, rodA, rodB, rodC, 1);

            if (a==1)
            {
                break;
            }

            else
            {
                moveLegal(&topA, &topB, &topC, rodA, rodB, rodC, big[a]); refresh(rodA, rodB, rodC);
            }
        }
    }

    else if (rodA[0] == 3 && rodA[1] == 2 && rodA[2] == 1 && rodA[3] == 5 && rodA[4] == 4)
    {
        moveLegal(&topA, &topB, &topC, rodA, rodB, rodC, big[0]); refresh(rodA, rodB, rodC);
        moveLegal(&topA, &topB, &topC, rodA, rodB, rodC, big[1]); refresh(rodA, rodB, rodC);
        moveLegal(&topA, &topB, &topC, rodA, rodB, rodC, big[2]); refresh(rodA, rodB, rodC);

        firstSeven(&topA, &topB, &topC, rodA, rodB, rodC, 1);

    }

    else if (rodA[0] == 2 && rodA[1] == 1 && rodA[2] == 5 && rodA[3] == 4 && rodA[4] == 3)
    {

        moveDirection(&(topA), &(topB), &(topC), rodA, rodB, rodC, search(rodA, rodB, rodC, 3), "L"); refresh(rodA, rodB, rodC);
        moveLegal(&(topA), &(topB), &(topC), rodA, rodB, rodC, 4); refresh(rodA, rodB, rodC);
        moveDirection(&(topA), &(topB), &(topC), rodA, rodB, rodC, search(rodA, rodB, rodC, 3), "L"); refresh(rodA, rodB, rodC);
        moveLegal(&(topA), &(topB), &(topC), rodA, rodB, rodC, 5); refresh(rodA, rodB, rodC);
        moveDirection(&(topA), &(topB), &(topC), rodA, rodB, rodC, search(rodA, rodB, rodC, 1), "L"); refresh(rodA, rodB, rodC);
        moveLegal(&topA, &topB, &topC, rodA, rodB, rodC, 2); refresh(rodA, rodB, rodC);
        moveDirection(&(topA), &(topB), &(topC), rodA, rodB, rodC, search(rodA, rodB, rodC, 1), "L"); refresh(rodA, rodB, rodC);
        firstSeven(&topA, &topB, &topC, rodA, rodB, rodC, 1);
        moveLegal(&topA, &topB, &topC, rodA, rodB, rodC, big[0]); refresh(rodA, rodB, rodC);
        firstSeven(&topA, &topB, &topC, rodA, rodB, rodC, 1);

    }

    else if (rodA[0] == 1 && rodA[1] == 5 && rodA[2] == 4 && rodA[3] == 3 && rodA[4] == 2)
    {
        for (a=0; a<=1; a++)
        {

            if (a==1)
            {
                moveLegal(&(topA), &(topB), &(topC), rodA, rodB, rodC, 5); refresh(rodA, rodB, rodC);
                moveDirection(&(topA), &(topB), &(topC), rodA, rodB, rodC, search(rodA, rodB, rodC, 1), "R"); refresh(rodA, rodB, rodC);
                firstSeven(&topA, &topB, &topC, rodA, rodB, rodC, 1);
                moveLegal(&topA, &topB, &topC, rodA, rodB, rodC, big[0]); refresh(rodA, rodB, rodC);
                firstSeven(&topA, &topB, &topC, rodA, rodB, rodC, 1);

                break;
            }

            else
            {
                firstSevenRight(&topA, &topB, &topC, rodA, rodB, rodC, 2);
                continue;
            }
        }
    }
    getch();
}


void queueParkingGarage()
{
    char ad[1], plate[4], garage[12][4], diff;
    int arrivedn=0, departn=0, foundA=0, i, j, k, l=1, m, n, o, q, r, t, u, v, a, count, dtime=100, front=-1, move;

    parkingSpace(19);

    g(30, 8); p("Type 'Q'/'q' to quit the program.");
    g(30, 12); p("NO. OF TIMES ARRIVED: %d", arrivedn);
    g(30, 13); p("NO. OF TIMES DEPART: %d", departn); g(30, 11); p("CAR PLATE NO.: ");

    while (front <= 9)
    {
        l = 1;
        g(30, 12); p("NO. OF TIMES ARRIVED: %d", arrivedn);
        g(30, 13); p("NO. OF TIMES DEPART: %d", departn);
        g(30, 10); p("ARRIVAL/DEPARTURE (A/D): "); g(55, 10); s("%s", &ad);

        if ((front > 9) || (cp(ad, "Q") == 0 || cp(ad, "q") == 0))
        {
            break;
        }

        if (cp(ad, "A") == 0 || cp(ad, "a") == 0)
        {
            foundA=0;
            g(15, 16); p("                                                                 ");


            while (17)
            {
                g(46, 11); s("%s", plate);

                if (strlen(plate)<=3)
                {
                    break;
                }

                else
                {
                    g(46, 11); p("3 CHAR ONLY    "); getch(); g(46, 11); p("                                  ");
                }
            }

            if (front == 9)
            {
                g(30, 16); p("                                    ");
                g(30, 16); p("Sorry, the parking garage is full.\n");
                break;
            }

            for (i = front; i >= 0; i--)
            {
                if (strcmp(garage[i], plate) == 0)
                {
                    g(30, 16); p("                                    ");
                    g(30, 16); p("The car is already in the garage.\n");
                    foundA=1;
                    break;
                }
            }

            if (foundA == 0)
            {
                g(30, 16); p("                                    ");

                if (front > -1)
                {
                    for (i=front; i>=0; i--)
                    {
                        sy(garage[i+1], garage[i]);
                    }
                }
                sy(garage[0], plate);

                arrivedn++;
                front += 1;

                for (i=70; i>=7; i-=5)
                {
                    g(i, 20); p("%s", garage[0]); delay(dtime);
                    g(i, 20); p("   ", garage[0]);
                }

                for (i=front; i>=0; i--)
                {
                    g(7, 22 - ((i+1) * 2)); p("   ");
                    g(7, 22 - ((i+1) * 2)); p("%s", garage[i]);
                }
            }
        }

        else if (cp(ad, "D") == 0 || cp(ad, "d") == 0)
        {
            g(15, 16); p("                                                                 ");
            while (17)
            {
                g(46, 11); s("%s", plate);

                if (strlen(plate)<=3)
                {
                    break;
                }

                else
                {
                    g(46, 11); p("3 CHAR ONLY    "); getch(); g(46, 11); p("                                  ");
                }
            }
            for (i = front; i >= 0; i--)
            {
                if (strcmp(garage[i], plate) == 0)
                {
                    move = front;

                    departn = departn + ((front-i)+1);
                    arrivedn = arrivedn + (front-i);

                    g(30, 16); p("                                    ");
                    while (move >= i)
                    {
                        for (m=front-(front-move); m<=9; m++)
                        {
                            if (m==9)
                            {
                                g(7, 22 - ((m+1) * 2)); p("%s", garage[move]); delay(dtime);
                                g(7, 22 - ((m+1) * 2)); p("   ");

                                for (n=9; n>=0+(front-move); n--)
                                {
                                    if (n==(0+(front-move)))
                                    {
                                        g(14, 22 - ((n+1) * 2)); p("%s", garage[move]); delay(dtime);
                                    }

                                    else
                                    {
                                        g(14, 22 - ((n+1) * 2)); p("%s", garage[move]); delay(dtime);
                                        g(14, 22 - ((n+1) * 2)); p("   ");
                                    }
                                }
                            }

                            else
                            {
                                g(7, 22 - ((m+1) * 2)); p("%s", garage[move]); delay(dtime);
                                g(7, 22 - ((m+1) * 2)); p("   ");
                            }
                        }
                        move-=1;
                    }

                    move = i-1;

                    while (move >= 0)
                    {
                        for (o=(i-1)-((i-1)-move); o<=((i-1)+(((front)-i))-((i-1)-move)); o++)
                        {
                            if (o==((i-1)+((front)-i)-((i-1)-move)))
                            {
                                g(7, 22 - ((o+1) * 2)); p("%s", garage[move]); delay(dtime);
                            }

                            else
                            {
                                g(7, 22 - ((o+1) * 2)); p("%s", garage[move]); delay(dtime);
                                g(7, 22 - ((o+1) * 2)); p("   ");
                            }
                        }
                        move -= 1;
                    }

                    move = front;
                    count=0;

                    while (move > i)
                    {
                        for (r=0+(front-move); r>=0; r--)
                        {
                            if (r==0)
                            {
                                g(14, 22 - ((r+1) * 2)); p("%s", garage[move]); delay(dtime);
                                g(14, 22 - ((r+1) * 2)); p("   ");

                                for (q=0; q<=(move-i)-1; q++)
                                {
                                    if (q==(move-i)-1)
                                    {
                                        g(7, 22 - ((q+1) * 2)); p("%s", garage[move]); delay(dtime);
                                    }

                                    else
                                    {
                                        g(7, 22 - ((q+1) * 2)); p("%s", garage[move]); delay(dtime);
                                        g(7, 22 - ((q+1) * 2)); p("   ");
                                    }

                                }
                                break;
                            }

                            else
                            {
                                g(14, 22 - ((r+1) * 2)); p("%s", garage[move]); delay(dtime);
                                g(14, 22 - ((r+1) * 2)); p("   ");
                            }
                        }
                        move-=1;
                        count+=1;
                    }

                    for (u=front-i; u>=0; u--)
                    {

                        if (u==0)
                        {
                            for (j=14; j<=70; j+=5)
                            {
                                g(j, 20); p("%s", garage[i]); delay(dtime);
                                g(j, 20); p("   ", garage[i]);
                            }

                            break;
                        }

                        else
                        {
                            g(14, 22 - ((u+1) * 2)); p("%s", garage[i]); delay(dtime);
                            g(14, 22 - ((u+1) * 2)); p("   ");
                        }

                    }


                    for (j=i-1; j>=0; j--)
                    {
                        sy(garage[j+1], garage[j]);
                    }

                    sy(garage[0], garage[front]);
                    sy(garage[front], "");

                    while (l<(front-i))
                    {
                        for (v=front; v>=0; v--)
                        {
                            sy(garage[v+1], garage[v]);
                        }

                        sy(garage[0], garage[front]);
                        sy(garage[front], "");
                        l++;
                    }

                    front -= 1;
                    break;
                }

                else if (i==0)
                {
                    g(30, 16); p("                                    ");
                    g(30, 16); p("Car not found in the parking garage.\n");
                }

            }
        }

        g(55, 10); p("       ");
        g(46, 11); p("       ");
    }
    getch();
}
#endif // PROGRAMSTWO_H
