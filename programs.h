#ifndef PROGRAMS_H
#define PROGRAMS_H
#include "C:\TURBOC3\Projects\HERE!!!\loading.h"
#define p printf
#define g gotoxy
#define s scanf
#define p printf
#define g gotoxy
#define s scanf
#define sy strcpy
#define cp strcmp

void pupBorders()
{
    int x, y;

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
}


void pupTitle()
{
    g(27,3); p("%c%c%c",218,196,191);                                       g(33,3); p("%c%c%c",218,196,191);
    g(27,4); p("%c %c",179,179);       g(30,4); p("%c %c",179,179);         g(33,4); p("%c %c",179,179);
    g(27,5); p("%c%c%c",195,196,217);  g(30,5); p("%c %c",179,179);         g(33,5); p("%c%c%c",195,196,217);
    g(27,6); p("%c",179);              g(30,6); p("%c %c",179,179);         g(33,6); p("%c",179);
    g(27,7); p("%c",179);              g(30,7); p("%c%c%c",192,196,217);    g(33,7); p("%c",179);

    g(38,3); p("%c%c%c",218,196,191);   g(41,3); p("%c%c%c",196,194,196);   g(44,3); p("%c%c%c",218,196,191);
    g(38,4); p("%c",179);               g(41,4); p(" %c ",179);             g(44,4); p("%c %c",179,179);
    g(38,5); p("%c%c%c",192,196,191);   g(41,5); p(" %c ",179);             g(44,5); p("%c %c",179,179);
    g(38,6); p("  %c",179);             g(41,6); p(" %c ",179);             g(44,6); p("%c %c",179,179);
    g(38,7); p("%c%c%c",192,196,217);   g(41,7); p(" %c ",179);             g(44,7); p("%c%c%c",192,196,217);

    g(47,3); p("%c%c%c",218,196,191);   g(50,3); p("%c%c%c",218,196,196);
    g(47,4); p("%c %c",179,179);        g(50,4); p("%c",179);
    g(47,5); p("%c%c%c",195,194,217);   g(50,5); p("%c%c%c",195,196,196);
    g(47,6); p("%c%c",179,179);         g(50,6); p("%c",179);
    g(47,7); p("%c%c",179,192);         g(50,7); p("%c%c%c",192,196,196);

    g(5,10); p("QUANTITY"); g(64,10); p("AMOUNT"); g(28,10); p("THE ITEM"); g(45,10); p("PRICE PER UNIT"); g(44,19); p("TOTAL AMOUNT:");
}


int pupStore()
{
    int y, i, numQ, validqty = 0, validprice = 0;
    float price, numPrice, amount, totalamount=0;
    char items[10], qty[5];

    clrscr();

    pupBorders();
    pupTitle();

    for(y=1; y<=5; y++)
    {
        validqty=0;
        while (validqty==0)
        {
            g(5,y + 10); s("%s",&qty);
            for (i=0; i<=((strlen(qty))-1); i++)
            {
                if ((isdigit(qty[i]) == 0))
                {
                    g(5,y + 11); p("Invalid     "); getch(); g(5,y + 11); p("          "); g(5,y + 10); p("          ");
                    validqty=0;
                    break;
                }

                else
                {
                    validqty=1;
                    numQ = atoi(qty);
                }
            }
        }

        while (17)
        {
            while ((getchar()) != '\n');
            g(27,y + 10); scanf("%[^\n]", items);

            if (strlen(items)<=15)
            {
                break;
            }

            else
            {
                g(27,y + 10); p("15 CHAR ONLY                "); getch(); g(27,y + 11); p("                                  "); g(27,y + 10); p("                                ");
            }
        }


        do
        {
            g(45,y + 10);

            if (s("%f", &price) != 1)
            {
                g(45,y + 11); p("Invalid     "); getch(); g(45,y + 11); p("          "); g(45,y + 10); p("          ");
                validprice=0;
                while ((getchar()) != '\n');
            }
            else if (price < 0)
            {
                g(45,y + 11); p("Invalid     "); getch(); g(45,y + 11); p("          "); g(45,y + 10); p("          ");
                validprice=0;
            }

            else
            {
                validprice = 1;
                numPrice = price;
            }
        }
        while (validprice == 0);

        amount = numQ*numPrice;
        g(64,y + 10); p("P %.2f", amount);
        totalamount += amount;
        g(58, 19); p("P %.2f", totalamount);

    }

    g(23,17); p("YOU'VE REACHED THE PURCHASE LIMIT!");
    getch();
}


int open()
{
    char uname[30],pwd[30];

    settextstyle(1,0,1);
    outtextxy(170, 140 , "Username: ");
    outtextxy(170, 185 , "Password: ");
    g(36, 10); s("%s", &uname);
    g(36, 13); s("%s", &pwd);


    if ((strlen(uname)>10) && (strlen(pwd)>10))
    {
        outtextxy(170, 280 , "Username Error");
        outtextxy(170, 320 , "Password Error");
        return 0;
    }

    else if (strlen(uname)>10)
    {
        outtextxy(170, 280 , "Username Error");
        return 0;
    }

    else if (strlen(pwd)>10)
    {
        outtextxy(170, 300 , "Password Error");
        return 0;
    }

    else
    {
         return 1;
    }

}

void loading()
{
    int i,y;
    settextstyle(0,0,2);
    rectangle(185,300,475,310);

    for(i=0;i<=320;i++)
    {
        setcolor(13);
        rectangle(205,300,155+i,304);
        setcolor(15);
        rectangle(205,304,155+i,306);
        setcolor(5);
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
    setcolor(0);
    outtextxy(155, 270 , "Loading...");
    setcolor(15);
    outtextxy(155, 270 , "Loading Completed!");
}

void loadingScreen()
{
    int gm,gd=DETECT, openI;
    clrscr();
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    setbkcolor(BLACK);
    bordermenu(5);
    openI = open();

    if (openI == 1)
    {
        loading();
    }

    getch();
    closegraph();
}

void squaresCubes()
{
    int i, square, cube;
    clrscr();
    pupBorders();
    g(25,7); p("NUMBER     SQUARE     CUBE");

    for (i = 1; i <= 10; i++)
    {
        square = i * i;
        cube = i * i * i;
        g(25,i + 8); p("%d", i);
        g(36, i+8); p("%d ^ %d", i, i);
        g(47, i+8); p("%d ^ %d ^ %d", i, i, i);
        delay(500);
        g(36, i+8); p("              ");
        g(47, i+8); p("              ");
        g(25,i + 8); p("%-11d%-11d%d\n", i, square, cube);

        delay(500);
    }
    getch();
}

void spiralMaze()
{
    int x, y, start_x = 1, end_x = 80, start_y = 1, end_y = 24, d = 5;

    clrscr();

    while (start_x < end_x && start_y < end_y)
    {
        for (x = start_x; x <= end_x+1; x++)
        {
            g(x-2, start_y); p("%c", 178); delay (d);
        }
        for (y = start_y; y <= end_y; y++)
        {
            g(end_x, y); p("%c", 178); delay (d);
        }
        for (x = end_x; x >= start_x; x--)
        {
            g(x, end_y); p("%c", 178); delay (d);
        }
        for (y = end_y; y >= start_y + 2; y--)
        {
            g(start_x, y); p("%c", 178); delay (d);
        }

        start_x += 2;
        end_x -= 2;
        start_y += 2;
        end_y -= 2;

    }

    for (x = 11; x <= 67; x++)
    {
        g(x, 13); p("%c", 178); delay(d);
    }



    while (start_x >= 1 && end_x >= 1)
    {
        for (y = start_y+2; y <= end_y; y++)
        {
            g(start_x, y); p(" "); delay(d);
        }
        if (!(start_x == 13))
        {
            for (x = start_x; x <= end_x; x++)
            {
                g(x, end_y); p(" "); delay(d);
            }
        }
        for (y = end_y; y >= start_y; y--)
        {
            g(end_x, y); p(" "); delay(d);
        }
        for (x = end_x+1; x >= start_x; x--)
        {
            g(x-2, start_y); p(" "); delay(d);
        }

        start_x -= 2;
        end_x += 2;
        start_y -= 2;
        end_y += 2;

    }
    getch();
}


void twopageborders()
{
    int x, y;
    clrscr();

    pupBorders();

    for (y = 3; y <= 23; y++)
    {
        g(40, y); p("%c", 186);
    }
    for (y = 3; y <= 23; y++)
    {
        g(41, y); p("%c", 186);
    }
    g(41,2); p("%c", 201);
    g(40,2); p("%c", 187);
    g(41,24); p("%c", 200);
    g(40,24); p("%c", 188);

}

int barGraph()
{
    int x, i, validCPE = 0, validELE = 0, validME = 0, validCE = 0, validECE = 0, validREM = 0, validIE = 0, highest;
    float total, NUMcpe, NUMele, NUMme, NUMce, NUMece, NUMrem, NUMie;
    char cpe[5], ele[5], me[5], ce[5], ece[5], rem[5], ie[5];

    clrscr();
    twopageborders();

    g(6, 4); p("Department");
    g(24, 4); p("No. of Students");
    g(55, 4); p("BAR GRAPH");


    for (x = 54; x <= 65 ; x++)
    {
        g(x, 3); p("%c", 196);
    }
    for (x = 54; x <= 65; x++)
    {
        g(x, 5); p("%c", 196);
    }

    g(65, 3); p("%c", 191);
    g(65, 4); p("%c", 179);
    g(65, 5); p("%c", 217);

    validCPE = 0;

    while (validCPE == 0)
    {
        g(6, 7); p("CPE"); g (25, 7); s("%s", &cpe);
        for (i = 0; i <= ((strlen (cpe)) - 1); i++)
        {
            if ((isdigit (cpe[i]) == 0))
            {
                g (25, 7); p ("INVALID INPUT"); getch();
                g (25, 7); p ("             ");
                validCPE = 0;
                break;
            }
            else
            {
                validCPE = 1;
                NUMcpe = atof(cpe);
                highest = NUMcpe;
            }
        }
    }

    validELE = 0;
    while (validELE == 0)
    {
        g(6, 9); p("ELE"); g (25, 9); s("%s", &ele);
        for (i = 0; i <= ((strlen (ele)) - 1); i++)
        {
            if ((isdigit (ele[i]) == 0))
            {
                g (25, 9); p ("INVALID INPUT"); getch();
                g (25, 9); p ("             ");
                validELE = 0;
                break;
            }
            else
            {
                validELE = 1;
                NUMele = atof(ele);

                if (highest < NUMele)
                {
                    highest = NUMele;
                }
            }
        }
    }

    validME = 0;
    while (validME == 0)
    {
        g(6, 11); p("ME"); g (25, 11); s("%s", &me);
        for (i = 0; i <= ((strlen (me)) - 1); i++)
        {
            if ((isdigit (me[i]) == 0))
            {
                g (25, 11); p ("INVALID INPUT"); getch();
                g (25, 11); p ("             ");
                validME = 0;
                break;
            }
            else
            {
                validME = 1;
                NUMme = atof(me);
                if (highest < NUMme)
                {
                    highest = NUMme;
                }
            }
        }
    }

    validCE = 0;
    while (validCE == 0)
    {
        g(6, 13); p("CE"); g (25, 13); s("%s", &ce);
        for (i = 0; i <= ((strlen (ce)) - 1); i++)
        {
            if ((isdigit (ce[i]) == 0))
            {
                g (25, 13); p ("INVALID INPUT"); getch();
                g (25, 13); p ("             ");
                validCE = 0;
                break;
            }
            else
            {
                validCE = 1;
                NUMce = atof(ce);
                if (highest < NUMce)
                {
                    highest = NUMce;
                }
            }
        }
    }

    validECE = 0;
    while (validECE == 0)
    {
        g(6, 15); p("ECE"); g (25, 15); s("%s", &ece);
        for (i = 0; i <= ((strlen (ece)) - 1); i++)
        {
            if ((isdigit (ece[i]) == 0))
            {
                g (25, 15); p ("INVALID INPUT"); getch();
                g (25, 15); p ("             ");
                validECE = 0;
                break;
            }
            else
            {
                validECE = 1;
                NUMece = atof(ece);
                if (highest < NUMece)
                {
                    highest = NUMece;
                }
            }
        }
    }

    validREM = 0;
    while (validREM == 0)
    {
        g(6, 17); p("REM"); g (25, 17); s("%s", &rem);
        for (i = 0; i <= ((strlen (rem)) - 1); i++)
        {
            if ((isdigit (rem[i]) == 0))
            {
                g (25, 17); p ("INVALID INPUT"); getch();
                g (25, 17); p ("             ");
                validREM = 0;
                break;
            }
            else
            {
                validREM = 1;
                NUMrem = atof(rem);
                if (highest < NUMrem)
                {
                    highest = NUMrem;
                }
            }
        }
    }

    validIE = 0;
    while (validIE == 0)
    {
        g(6, 19); p("IE"); g (25, 19); s("%s", &ie);
        for (i = 0; i <= ((strlen (ie)) - 1); i++)
        {
            if ((isdigit (ie[i]) == 0))
            {
                g (25, 19); p ("INVALID INPUT"); getch();
                g (25, 19); p ("             ");
                validIE = 0;
                break;
            }
            else
            {
                validIE = 1;
                NUMie = atof(ie);
                if (highest < NUMie)
                {
                    highest = NUMie;
                }
            }
        }
    }

    g(43, 7); p("CPE"); g(43, 9); p("ELE"); g(43, 11); p("ME"); g(43, 13); p("CE"); g(43, 15); p("ECE"); g(43, 17); p("REM"); g(43, 19); p("IE");

    for (x = 47; x <= (47+(30*(NUMcpe/highest))); x++)
    {
        if (NUMcpe == 0)
        {
            break;
        }
        else
        {
            g(x, 7); p("%c", 178); delay(20);
        }
    }
    for (x = 47; x <= (47+(30*(NUMele/highest))); x++)
    {
        if (NUMele == 0)
        {
            break;
        }

        else
        {
            g(x, 9); p("%c", 178); delay(20);
        }
    }
    for (x = 47; x <= (47+(30*(NUMme/highest))); x++)
    {
        if (NUMme == 0)
        {
            break;
        }

        else
        {
            g(x, 11); p("%c", 178); delay(20);
        }
    }
    for (x = 47; x <= (47+(30*(NUMce/highest))); x++)
    {
        if (NUMce == 0)
        {
            break;
        }

        else
        {
            g(x, 13); p("%c", 178); delay(20);
        }
    }
    for (x = 47; x <= (47+(30*(NUMece/highest))); x++)
    {
        if (NUMece == 0)
        {
            break;
        }

        else
        {
            g(x, 15); p("%c", 178); delay(20);
        }
    }
    for (x = 47; x <= (47+(30*(NUMrem/highest))); x++)
    {
        if (NUMrem == 0)
        {
            break;
        }

        else
        {
            g(x, 17); p("%c", 178); delay(20);
        }
    }
    for (x = 47; x <= (47+(30*(NUMie/highest))); x++)
    {
        if (NUMie == 0)
        {
            break;
        }

        else
        {
            g(x, 19); p("%c", 178); delay(20);
        }
    }
    getch();
}


void salarytitle()
{
    int x, y;
    g(33,4); p("MID-YEAR BONUS");
    for(x=10; x<=70; x++)
    {
        g(x,6); p("%c",196); g(x,8); p("%c",196); g(x,10); p("%c",196); g(x,12); p("%c",196);
    }

    for(y=7; y<=11; y++)
    {
        g(9,y); p("%c",179); g(39,y); p("%c",179); g(71,y); p("%c",179);
    }

    g(39,6); p("%c",194); g(39,8); p("%c",197); g(39,10); p("%c",197); g(39,12); p("%c",193);
    g(9,6); p("%c",218); g(71,6), p("%c",191);
    g(9,8); p("%c",195); g(71,8); p("%c",180);
    g(9,10); p("%c",195); g(71,10); p("%c",180);
    g(9,12); p("%c",192); g(71,12); p("%c",217);

    g(11,7); p("1 to 5 YEARS OF SERVICE"); g(41,7); p("50% MONTHLY INCOME");
    g(11,9); p("6 to 15 YEARS OF SERVICE"); g(41,9); p("75% MONTHLY INCOME");
    g(11,11); p("16 & ABOVE YEARS OF SERVICE"); g(41,11); p("100% MONTHLY INCOME");
}


void salaryBonus()
{
    int service, validyrs = 0, validSalary = 1, validyrsDecimal = 0, i;
    char serviceSTR[5];
    float salary, bonus;

    clrscr();
    pupBorders();
    salarytitle();

    g(7,15); p("Enter your Monthly Income:");

    while (17)
    {
        g(34,15);

        if (s("%f",&salary) != 1)
        {
            g(34,15); p("Invalid Input."); getch(); g(34,15); p("              ");
            while (getchar() != '\n');
        }

        else if (salary >= 0)
        {
            while(validyrs == 0 || validyrsDecimal == 0)
            {
                g(7,16); p("Enter your Years of Service:"); g(36,16);

                s("%s", &serviceSTR);

                for (i = 0; i <= ((strlen(serviceSTR)) - 1); i++)
                {
                    if ((isdigit(serviceSTR[i]) == 0))
                    {
                        g(36,16); p("Invalid Input."); getch(); g(36,16); p("              ");
                        while (getchar() != '\n');
                        validyrsDecimal = 0;
                        break;
                    }

                    else if (i == ((strlen(serviceSTR)) - 1))
                    {
                        validyrsDecimal = 1;
                        service = atoi(serviceSTR);
                        break;
                    }
                }

                if((service<=0 || service>60) && (validyrsDecimal == 1))
                {
                    g(36,16); p("Invalid Input."); getch(); g(36,16); p("              ");
                    validyrs = 0 ;
                }

                else if ((service>0 && service <=60 ) && (validyrsDecimal == 1))
                {
                    validyrs=1; validyrsDecimal = 1;

                    if(service>=1 && service<=5)
                    {
                        bonus = salary*0.5;
                        g(7,17); p("YOUR BONUS IS P %.2f", bonus);
                        g(7,20); p("FORMULA: Salary x 50% = Bonus");
                    }
                    else if(service>=6 && service<=15)
                    {
                        bonus = salary*0.75;
                        g(7,17); p("YOUR BONUS IS P %.2f", bonus);
                        g(7,20); p("FORMULA: Salary x 75% = Bonus");
                    }
                    else
                    {
                        bonus = salary*1;
                        g(7,17); p("YOUR BONUS IS P %.2f", bonus);
                        g(7,20); p("FORMULA: Salary x 100% = Bonus");
                    }
                    break;
                }
            }



            break;
        }

        else
        {
            g(34,15); p("Invalid Input."); getch(); g(34,15); p("              ");
            while (getchar() != '\n');
        }
    }
    getch();
}
#endif
