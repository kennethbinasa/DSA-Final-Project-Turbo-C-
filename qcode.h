#ifndef QCODE_H
#define QCODE_H
#define p printf
#define g gotoxy
#define s scanf
#define p printf
#define g gotoxy
#define s scanf
#define sy strcpy
#define cp strcmp
#define sc strcmp

char months[13][30] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
char stone[13][30] = {"Garnet", "Amethyst", "Aquamarine", "Diamond", "Emerald", "Pearl", "Ruby", "Peridot", "Sapphire", "Opal", "Topaz", "Turquoise"};
char flower[13][30] = {"Carnation", "Violet", "Jonquil", "Sweet Pea", "Lily of the Valley", "Rose", "Larkspur", "Gladiola", "Aster", "Aster", "Calendula", "Chrysantemum", "Narcissus"};
char astrosign[13][30] = {"Sagittarius", "Capricorn", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio"};
char chinesesign[13][30] = {"Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Sheep", "Monkey", "Rooster", "Dog", "Pig", "Rat", "Ox"};
int leapyear[] = {1964, 1968, 1972, 1976, 1980, 1984, 1988, 1992, 1996, 2000, 2004, 2008, 2012, 2016, 2020}, length = 15, day, year;

void displayall(int month, int day, int year)
{
    int x, y;

    for (x=23; x>=15; x--)
    {
        g(x,19); p("%c",205); delay(30);
    }
    g(15,19); p("%c",200);

    for (y=18; y>=13; y--)
    {
        g(15,y); p("%c",186); delay(50);
    }
    g(15,13); p("%c",201);

    for (x=16; x<=23; x++)
    {
        g(x,13); p("%c",205); delay(30);
    }

    switch(month)
    {
        case 1: g(33,12); p("%s",months[0]); delay(500); break;
        case 2: g(33,12); p("%s",months[1]); delay(500); break;
        case 3: g(33,12); p("%s",months[2]); delay(500); break;
        case 4: g(33,12); p("%s",months[3]); delay(500); break;
        case 5: g(33,12); p("%s",months[4]); delay(500); break;
        case 6: g(33,12); p("%s",months[5]); delay(500); break;
        case 7: g(33,12); p("%s",months[6]); delay(500); break;
        case 8: g(33,12); p("%s",months[7]); delay(500); break;
        case 9: g(33,12); p("%s",months[8]); delay(500); break;
        case 10: g(33,12); p("%s",months[9]); delay(500); break;
        case 11: g(33,12); p("%s",months[10]); delay(500); break;
        case 12: g(33,12); p("%s",months[11]); delay(500); break;
    }
    g(31,13); p("%d",day); delay(500); g(32,14); p("%d",year); delay(500);
}

void borderoutput()
{
    int x, y, i, j;

    for (x = 24; x <= 56; x++)
    {
        g(x, 17); p("%c", 205);
        g(x, 22); p("%c", 205);
    }
    for (y = 17; y <= 22; y++)
    {
        g(24, y); p("%c", 186);
        g(56, y); p("%c", 186);
    }
    g(24,19); p("%c",185); g(24, 17); p("%c", 201); g(56, 17); p("%c", 187); g(24, 22); p("%c", 200); g(56, 22); p("%c", 188);

    for (i = 24; i <= 46; i++)
    {
        g(i, 11); p("%c", 205);
        g(i, 15); p("%c", 205);
    }
    for (j = 11; j <= 15; j++)
    {
        g(24, j); p("%c", 186);
        g(46, j); p("%c", 186);
    }
    g(24,13); p("%c",185); g(24, 11); p("%c", 201); g(46, 11); p("%c", 187); g(24, 15); p("%c", 200); g(46, 15); p("%c", 188);
}


void monthtable()
{
    int x, y;

    for(x=47; x<=75; x++)
    {
        g(x,4); p("%c", 196);
        g(61,4); p("%c",194);
        g(x,16); p("%c",196);
        g(61,16); p("%c",193);
        g(x,6); p("%c", 196); g(x,8); p("%c", 196); g(x,10); p("%c", 196); g(x,12); p("%c", 196); g(x,14); p("%c", 196);
    }
    for (y = 4; y <= 16; y++)
    {
        g(47, y); p("%c", 179);
        g(61, y); p("%c", 179);
        g(75, y); p("%c", 179);
    }

    g(47, 4); p("%c", 218); g(75, 4); p("%c", 191);
    g(47, 16); p("%c", 192); g(75, 16); p("%c", 217);
    g(61,4); p("%c",194); g(61,6); p("%c",197); g(61,8); p("%c",197); g(61,10); p("%c",197); g(61,12); p("%c",197); g(61,14); p("%c",197); g(61,16); p("%c",193);

    g(48,5); p("1. JAN"); g(48,7); p("2. FEB"); g(48,9); p("3. MAR"); g(48,11); p("4. APR"); g(48,13); p("5. MAY"); g(48,15); p("6. JUN");
    g(62,5); p("7. JUL"); g(62,7); p("8. AUG"); g(62,9); p("9. SEPT"); g(62,11); p("10. OCT"); g(62,13); p("11. NOV"); g(62,15); p("12. DEC");
}


int leapcheck(int array[], int length, int value)
{
    int i;
    for(i = 0; i < length; i++)
    {
        if (array[i] == value)
        {
            return 1;
        }
    }
    return 0;
}

void ssfResults(char astrosign[13][30], char stone[13][30], char flower[13][30], int listNum, int astroNum)
{
    g(26,18); p("ASTROLOGICAL SIGN: %s",astrosign[astroNum]); delay(500);
    g(26,19); p("BIRTH STONE: %s",stone[listNum]); delay(500);
    g(26,20); p("BIRTH FLOWER: %s",flower[listNum]); delay(500);
}

int zodiacSigns()
{
    int x, month, validyear = 0, validmonth = 0, validday = 0;
    char stringYear[4], stringMonth[2], stringDay[2];

    clrscr();

    pupBorders();
    borderoutput();
    g(26,12); p("MONTH: "); g(26,13); p("DAY: "); g(26,14); p("YEAR: ");

    while (validyear == 0)
    {
        g(3,3); p("Enter Birth Year (1962 - 2023): "); g(3,4); p(">> "); s("%s", stringYear);

        year = verifier(3, stringYear, year);

        if (year<1962 || year >2023)
        {
            g(3,4); p("Invalid        \n"); getch(); g(3,4); p("                ");
        }

        else if (leapcheck(leapyear, length, year))
        {
            g(53,3); p("IT IS A LEAPYEAR!");
            validyear == 1;
            break;
        }
        else
        {
            validyear == 1;
            break;
        }
    }

    monthtable();

    while (validmonth == 0)
    {
        g(3,5); p("Enter Birth Month (1 - 12): "); g(3,6); p(">> ");

        s("%s", stringMonth);
        month = verifier(3, stringMonth, month);

        if (month<1 || month>12)
        {
            g(3,6); p("Invalid        \n"); getch(); g(3,6); p("                ");
            while(getchar() != '\n');
            continue;
        }

        else if (month == 2)
        {
            for (x=48; x<=60; x++)
            {
                g(x,5); p("%c",178); g(x,9); p("%c",178); g(x,11); p("%c",178); g(x,13); p("%c",178); g(x,15); p("%c",178);
                delay(50);
            }
            for (x=62; x<=74; x++)
            {
                g(x,5); p("%c",178); g(x,7); p("%c",178); g(x,9); p("%c",178); g(x,11); p("%c",178); g(x,13); p("%c",178); g(x,15); p("%c",178);
                delay(50);
            }


            if (leapcheck(leapyear, length, year))
            {
                while (validday == 0)
                {
                    g(3,7); p("Enter Birth Day (1 - 29): "); g(3,8); p(">> "); s("%s", stringDay);

                    day = verifier(3, stringDay, day);

                    if (day>=1 && day<=19)
                    {
                        ssfResults(astrosign, stone, flower, 1, 2);
                        validday = 1;
                        break;
                    }
                    else if (day>=20 && day<=29)
                    {
                        ssfResults(astrosign, stone, flower, 1, 3);
                        validday = 1;
                        break;
                    }
                    else
                    {
                        g(3,8); p("Invalid        \n"); getch(); g(3,8); p("           ");
                    }

                }
            }

            else
            {
                while (validday ==0)
                {
                    g(3,7); p("Enter Birth Day (1 - 28): "); g(3,8); p(">> ");

                    s("%s", stringDay);
                    day = verifier(3, stringDay, day);

                    if (day>=1 && day<=19)
                    {
                        ssfResults(astrosign, stone, flower, 1, 2);
                        validday = 1;
                        break;
                    }
                    else if (day>=20 && day<=28)
                    {
                        ssfResults(astrosign, stone, flower, 1, 3);
                        validday = 1;
                        break;
                    }
                    else
                    {
                        g(3,8); p("Invalid        \n"); getch(); g(3,8); p("           ");
                    }

                }
            }
            validmonth = 1;
        }

        switch(month)
        {
            case 1:
                for (x=48; x<=60; x++)
                {
                    g(x,7); p("%c",178); g(x,9); p("%c",178); g(x,11); p("%c",178); g(x,13); p("%c",178); g(x,15); p("%c",178);
                    delay(50);
                }
                for (x=62; x<=74; x++)
                {
                    g(x,5); p("%c",178); g(x,7); p("%c",178); g(x,9); p("%c",178); g(x,11); p("%c",178); g(x,13); p("%c",178); g(x,15); p("%c",178);
                    delay(50);
                }


                while (validday == 0)
                {
                    g(3,7); p("Enter Birth Day (1 - 31): "); g(3,8); p(">> "); s("%s", stringDay);

                    day = verifier(3, stringDay, day);

                    if (day>=1 && day<=20)
                    {
                        ssfResults(astrosign, stone, flower, 0, 1);
                        validday = 1;
                        break;
                    }
                    else if (day>=21 && day<=31)
                    {
                        ssfResults(astrosign, stone, flower, 0, 2);
                        validday = 1;
                        break;
                    }
                    else
                    {
                        g(3,8); p("Invalid        \n"); getch(); g(3,8); p("           ");
                    }
                }
                break;

            case 3:
                for (x=48; x<=60; x++)
                {
                    g(x,5); p("%c",178); g(x,7); p("%c",178); g(x,11); p("%c",178); g(x,13); p("%c",178); g(x,15); p("%c",178);
                    delay(50);
                }
                for (x=62; x<=74; x++)
                {
                    g(x,5); p("%c",178); g(x,7); p("%c",178); g(x,9); p("%c",178); g(x,11); p("%c",178); g(x,13); p("%c",178); g(x,15); p("%c",178);
                    delay(50);
                }

                while (validday == 0)
                {
                    g(3,7); p("Enter Birth Day (1 - 31): "); g(3,8); p(">> ");s("%s", stringDay);

                    day = verifier(3, stringDay, day);

                    if (day>=1 && day<=20)
                    {
                        ssfResults(astrosign, stone, flower, 2, 3);
                        validday = 1;
                        break;
                    }
                    else if (day>=21 && day<=31)
                    {
                        ssfResults(astrosign, stone, flower, 2, 4);
                        validday = 1;
                        break;
                    }
                    else
                    {
                        g(3,8); p("Invalid        \n"); getch(); g(3,8); p("           ");
                    }
                }
                break;

            case 4:
                for (x=48; x<=60; x++)
                {
                    g(x,5); p("%c",178); g(x,7); p("%c",178); g(x,9); p("%c",178); g(x,13); p("%c",178); g(x,15); p("%c",178);
                    delay(50);
                }
                for (x=62; x<=74; x++)
                {
                    g(x,5); p("%c",178); g(x,7); p("%c",178); g(x,9); p("%c",178); g(x,11); p("%c",178); g(x,13); p("%c",178); g(x,15); p("%c",178);
                    delay(50);
                }

                while (validday == 0)
                {
                    g(3,7); p("Enter Birth Day (1 - 30): "); g(3,8); p(">> ");s("%s", stringDay);

                    day = verifier(3, stringDay, day);

                    if (day>=1 && day<=19)
                    {
                        ssfResults(astrosign, stone, flower, 3, 4);
                        validday = 1;
                        break;
                    }
                    else if (day>=20 && day<=30)
                    {
                        ssfResults(astrosign, stone, flower, 3, 5);
                        validday = 1;
                        break;
                    }
                    else
                    {
                        g(3,8); p("Invalid        \n"); getch(); g(3,8); p("           ");
                    }
                }
                break;

            case 5:
                for (x=48; x<=60; x++)
                {
                    g(x,5); p("%c",178); g(x,7); p("%c",178); g(x,9); p("%c",178); g(x,11); p("%c",178); g(x,15); p("%c",178);
                    delay(50);
                }
                for (x=62; x<=74; x++)
                {
                    g(x,5); p("%c",178); g(x,7); p("%c",178); g(x,9); p("%c",178); g(x,11); p("%c",178); g(x,13); p("%c",178); g(x,15); p("%c",178);
                    delay(50);
                }

                while (validday == 0)
                {
                    g(3,7); p("Enter Birth Day (1 - 31): "); g(3,8); p(">> ");s("%s", stringDay);

                    day = verifier(3, stringDay, day);
                    if (day>=1 && day<=20)
                    {
                        ssfResults(astrosign, stone, flower, 4, 5);
                        validday = 1;
                        break;
                    }
                    else if (day>=21 && day<=31)
                    {
                        ssfResults(astrosign, stone, flower, 4, 6);
                        validday = 1;
                        break;
                    }
                    else
                    {
                        g(3,8); p("Invalid        \n"); getch(); g(3,8); p("           ");
                    }
                }
                break;

            case 6:
                for (x=48; x<=60; x++)
                {
                    g(x,5); p("%c",178); g(x,7); p("%c",178); g(x,9); p("%c",178); g(x,11); p("%c",178); g(x,13); p("%c",178);
                    delay(50);
                }
                for (x=62; x<=74; x++)
                {
                    g(x,5); p("%c",178); g(x,7); p("%c",178); g(x,9); p("%c",178); g(x,11); p("%c",178); g(x,13); p("%c",178); g(x,15); p("%c",178);
                    delay(50);
                }

                while (validday == 0)
                {
                    g(3,7); p("Enter Birth Day (1 - 30): "); g(3,8); p(">> ");s("%s", stringDay);

                    day = verifier(3, stringDay, day);

                    if (day>=1 && day<=21)
                    {
                        ssfResults(astrosign, stone, flower, 5, 6);
                        validday = 1;
                        break;
                    }
                    else if (day>=22 && day<=30)
                    {
                        ssfResults(astrosign, stone, flower, 5, 7);
                        validday = 1;
                        break;
                    }
                    else
                    {
                        g(3,8); p("Invalid        \n"); getch(); g(3,8); p("           ");
                    }
                }
                break;

            case 7:
                for (x=74; x>=62; x--)
                {
                    g(x,7); p("%c",178); g(x,9); p("%c",178); g(x,11); p("%c",178); g(x,13); p("%c",178); g(x,15); p("%c",178);
                    delay(50);
                }
                for (x=60; x>=48; x--)
                {
                    g(x,5); p("%c",178); g(x,7); p("%c",178); g(x,9); p("%c",178); g(x,11); p("%c",178); g(x,13); p("%c",178); g(x,15); p("%c",178);
                    delay(50);
                }

                while (validday == 0)
                {
                    g(3,7); p("Enter Birth Day (1 - 31): "); g(3,8); p(">> ");s("%s", stringDay);

                    day = verifier(3, stringDay, day);

                    if (day>=1 && day<=21)
                    {
                        ssfResults(astrosign, stone, flower, 6, 7);
                        validday = 1;
                        break;
                    }
                    else if (day>=22 && day<=31)
                    {
                        ssfResults(astrosign, stone, flower, 6, 8);
                        validday = 1;
                        break;
                    }
                    else
                    {
                        g(3,8); p("Invalid        \n"); getch(); g(3,8); p("           ");
                    }
                }
                break;

            case 8:
                for (x=74; x>=62; x--)
                {
                    g(x,5); p("%c",178); g(x,9); p("%c",178); g(x,11); p("%c",178); g(x,13); p("%c",178); g(x,15); p("%c",178);
                    delay(50);
                }
                for (x=60; x>=48; x--)
                {
                    g(x,5); p("%c",178); g(x,7); p("%c",178); g(x,9); p("%c",178); g(x,11); p("%c",178); g(x,13); p("%c",178); g(x,15); p("%c",178);
                    delay(50);
                }

                while (validday == 0)
                {
                    g(3,7); p("Enter Birth Day (1 - 31): "); g(3,8); p(">> ");s("%s", stringDay);

                    day = verifier(3, stringDay, day);

                    if (day>=1 && day<=21)
                    {
                        ssfResults(astrosign, stone, flower, 7, 8);
                        validday = 1;
                        break;
                    }
                    else if (day>=22 && day<=31)
                    {
                        ssfResults(astrosign, stone, flower, 7, 9);
                        validday = 1;
                        break;
                    }
                    else
                    {
                        g(3,8); p("Invalid        \n"); getch(); g(3,8); p("           ");
                    }
                }
                break;

            case 9:
                for (x=74; x>=62; x--)
                {
                    g(x,5); p("%c",178); g(x,7); p("%c",178); g(x,11); p("%c",178); g(x,13); p("%c",178); g(x,15); p("%c",178);
                    delay(50);
                }
                for (x=60; x>=48; x--)
                {
                    g(x,5); p("%c",178); g(x,7); p("%c",178); g(x,9); p("%c",178); g(x,11); p("%c",178); g(x,13); p("%c",178); g(x,15); p("%c",178);
                    delay(50);
                }

                while (validday == 0)
                {
                    g(3,7); p("Enter Birth Day (1 - 30): "); g(3,8); p(">> ");s("%s", stringDay);

                    day = verifier(3, stringDay, day);

                    if (day>=1 && day<=22)
                    {
                        ssfResults(astrosign, stone, flower, 8, 9);
                        validday = 1;
                        break;
                    }
                    else if (day>=23 && day<=30)
                    {
                        ssfResults(astrosign, stone, flower, 8, 10);
                        validday = 1;
                        break;
                    }
                    else
                    {
                        g(3,8); p("Invalid        \n"); getch(); g(3,8); p("           ");
                    }
                }
                break;

            case 10:
                for (x=74; x>=62; x--)
                {
                    g(x,5); p("%c",178); g(x,7); p("%c",178); g(x,9); p("%c",178); g(x,13); p("%c",178); g(x,15); p("%c",178);
                    delay(50);
                }
                for (x=60; x>=48; x--)
                {
                    g(x,5); p("%c",178); g(x,7); p("%c",178); g(x,9); p("%c",178); g(x,11); p("%c",178); g(x,13); p("%c",178); g(x,15); p("%c",178);
                    delay(50);
                }

                while (validday == 0)
                {
                    g(3,7); p("Enter Birth Day (1 - 31): "); g(3,8); p(">> "); s("%s", stringDay);

                    day = verifier(3, stringDay, day);

                    if (day>=1 && day<=22)
                    {
                        ssfResults(astrosign, stone, flower, 9, 10);
                        validday = 1;
                        break;
                    }
                    else if (day>=23 && day<=31)
                    {
                        ssfResults(astrosign, stone, flower, 9, 11);
                        validday = 1;
                        break;
                    }
                    else
                    {
                        g(3,8); p("Invalid        \n"); getch(); g(3,8); p("           ");
                    }
                }
                break;

            case 11:
                for (x=74; x>=62; x--)
                {
                    g(x,5); p("%c",178); g(x,7); p("%c",178); g(x,9); p("%c",178); g(x,11); p("%c",178); g(x,15); p("%c",178);
                    delay(50);
                }
                for (x=60; x>=48; x--)
                {
                    g(x,5); p("%c",178); g(x,7); p("%c",178); g(x,9); p("%c",178); g(x,11); p("%c",178); g(x,13); p("%c",178); g(x,15); p("%c",178);
                    delay(50);
                }

                while (validday == 0)
                {
                    g(3,7); p("Enter Birth Day (1 - 30): "); g(3,8); p(">> ");s("%s", stringDay);

                    day = verifier(3, stringDay, day);

                    if (day>=1 && day<=21)
                    {

                        ssfResults(astrosign, stone, flower, 10, 11);
                        validday = 1;
                        break;
                    }
                    else if (day>=22 && day<=30)
                    {
                        ssfResults(astrosign, stone, flower, 10, 0);
                        validday = 1;
                        break;
                    }
                    else
                    {
                        g(3,8); p("Invalid        \n"); getch(); g(3,8); p("           ");
                    }
                }
                break;

            case 12:
                for (x=74; x>=62; x--)
                {
                    g(x,5); p("%c",178); g(x,7); p("%c",178); g(x,9); p("%c",178); g(x,11); p("%c",178); g(x,13); p("%c",178);
                    delay(50);
                }
                for (x=60; x>=48; x--)
                {
                    g(x,5); p("%c",178); g(x,7); p("%c",178); g(x,9); p("%c",178); g(x,11); p("%c",178); g(x,13); p("%c",178); g(x,15); p("%c",178);
                    delay(50);
                }

                while (validday == 0)
                {
                    g(3,7); p("Enter Birth Day (1 - 31): "); g(3,8); p(">> ");s("%s", stringDay);

                    day = verifier(3, stringDay, day);

                    if (day>=1 && day<=21)
                    {
                        ssfResults(astrosign, stone, flower, 11, 0);
                        validday = 1;
                        break;
                    }
                    else if (day>=22 && day<=31)
                    {
                        ssfResults(astrosign, stone, flower, 11, 1);
                        validday = 1;
                        break;
                    }
                    else
                    {
                        g(3,8); p("Invalid        \n"); getch(); g(3,8); p("           ");
                    }
                }
                break;
        }
        validmonth = 1;
    }

    switch(year)
    {
        case 1962: case 1974: case 1986: case 1998: case 2010: case 2022:
            g(26,21); p("CHINESE ZODIAC SIGN: %s",chinesesign[0]); break;
        case 1963: case 1975: case 1987: case 1999: case 2011: case 2023:
            g(26,21); p("CHINESE ZODIAC SIGN: %s",chinesesign[1]); break;
        case 1964: case 1976: case 1988: case 2000: case 2012:
            g(26,21); p("CHINESE ZODIAC SIGN: %s",chinesesign[2]); break;
        case 1965: case 1977: case 1989: case 2001: case 2013:
            g(26,21); p("CHINESE ZODIAC SIGN: %s",chinesesign[3]); break;
        case 1966: case 1978: case 1990: case 2002: case 2014:
            g(26,21); p("CHINESE ZODIAC SIGN: %s",chinesesign[4]); break;
        case 1967: case 1979: case 1991: case 2003: case 2015:
            g(26,21); p("CHINESE ZODIAC SIGN: %s",chinesesign[5]); break;
        case 1968: case 1980: case 1992: case 2004: case 2016:
            g(26,21); p("CHINESE ZODIAC SIGN: %s",chinesesign[6]); break;
        case 1969: case 1981: case 1993: case 2005: case 2017:
            g(26,21); p("CHINESE ZODIAC SIGN: %s",chinesesign[7]); break;
        case 1970: case 1982: case 1994: case 2006: case 2018:
            g(26,21); p("CHINESE ZODIAC SIGN: %s",chinesesign[8]); break;
        case 1971: case 1983: case 1995: case 2007: case 2019:
            g(26,21); p("CHINESE ZODIAC SIGN: %s",chinesesign[9]); break;
        case 1972: case 1984: case 1996: case 2008: case 2020:
            g(26,21); p("CHINESE ZODIAC SIGN: %s",chinesesign[10]); break;
        case 1973: case 1985: case 1997: case 2009: case 2021:
            g(26,21); p("CHINESE ZODIAC SIGN: %s",chinesesign[11]); break;
    }

    displayall(month, day, year);

    getch();
}



// for ticTacToe
void playingBoard()
{
    int x, y;

    clrscr();

    for (y = 2; y <= 16; y++)
    {
        g(11, y); p("%c", 186);
        g(21, y); p("%c", 186);
    }

    for (x = 2; x <= 31; x++)
    {
        g(x, 6); p("%c", 205);
        g(x, 11); p("%c", 205);
    }



    g(11, 6); p("%c", 206);
    g(11, 11); p("%c", 206);
    g(21, 6); p("%c", 206);
    g(21,11); p("%c", 206);


}

void logBox()
{
    int x, y;

    g(39, 2); p("%c", 201); g(79, 2); p("%c", 187);
    g(39, 19); p("%c", 200); g(79, 19); p("%c", 188);

    for (x = 40; x <= 78; x++)
    {
        g(x, 2); p("%c", 205);
        g(x, 19); p("%c", 205);
    }
    for (y = 3; y <= 19; y++)
    {
        g(39, y); p("%c", 186);
        g(79, y); p("%c", 186);
    }

    g(58, 4); p("LOGS");
}

int verifier(int x, char stringPlayer[1], int player)
{
    int i;

    for (i=0; i<=((strlen(stringPlayer))-1); i++)
    {
        if ((isdigit(stringPlayer[i]) == 0))
        {
            return 100;
            break;
        }

        else if (i == (strlen(stringPlayer))-1)
        {
            player = atoi(stringPlayer);
            return player;
        }
    }

}
void ticTacToe()
{
    int x, player1, player2, pl = 1, a = 1, player1Log = 0, player2Log = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0, a8 = 0, a9 = 0, win = 0;
    char stringPlayer1[1], stringPlayer2[1];

    playingBoard();
    logBox();

    while (a <= 9)
    {
        if (pl == 1)
        {
            g(2, 18); p("Player 1 (X)");
            g(2, 19); p("Enter bet: ");
            g(13, 19); s("%s", stringPlayer1);
            player1 = verifier(3, stringPlayer1, player1);

            if ((player1 >= 1 && player1 <= 9) &&
                ((player1 == 1 && a1 == 0) || (player1 == 2 && a2 == 0) || (player1 == 3 && a3 == 0) ||
                 (player1 == 4 && a4 == 0) || (player1 == 5 && a5 == 0) || (player1 == 6 && a6 == 0) ||
                 (player1 == 7 && a7 == 0) || (player1 == 8 && a8 == 0) || (player1 == 9 && a9 == 0)))
            {

                g(13, 19); p(" ");

                for (x = 1; x <= 76; x++)
                {
                    g(x, 20); p(" ");
                }

                player1Log++;
                g(45, 7+player1Log); p("%d. X to %d", player1Log, player1);

                switch (player1)
                {
                    case 1:
                        a1 = 1;
                        g(6, 4); p("X");
                        break;
                    case 2:
                        a2 = 1;
                        g(16, 4); p("X");
                        break;
                    case 3:
                        a3 = 1;
                        g(26, 4); p("X");
                        break;
                    case 4:
                        a4 = 1;
                        g(6, 9); p("X");
                        break;
                    case 5:
                        a5 = 1;
                        g(16, 9); p("X");
                        break;
                    case 6:
                        a6 = 1;
                        g(26, 9); p("X");
                        break;
                    case 7:
                        a7 = 1;
                        g(6, 14); p("X");
                        break;
                    case 8:
                        a8 = 1;
                        g(16, 14); p("X");
                        break;
                    case 9:
                        a9 = 1;
                        g(26, 14); p("X");
                        break;
                    default:
                        break;
                }
                pl = 2;
                a++;

                if ((a1 == 1 && a2 == 1 && a3 == 1) ||
                    (a4 == 1 && a5 == 1 && a6 == 1) ||
                    (a7 == 1 && a8 == 1 && a9 == 1) ||
                    (a1 == 1 && a4 == 1 && a7 == 1) ||
                    (a2 == 1 && a5 == 1 && a8 == 1) ||
                    (a3 == 1 && a6 == 1 && a9 == 1) ||
                    (a1 == 1 && a5 == 1 && a9 == 1) ||
                    (a3 == 1 && a5 == 1 && a7 == 1))
                {

                        for (x = 1; x <= 38; x++)
                        {
                            g(x, 20); p(" ");
                        }

                        g(42, 9+player1Log); p("Player 1 Wins!!");

                        g(2, 20); p("Player 1 Wins!!"); win = 1;
                        break;
                }
            }
            else
            {
                g(2, 18); p("Player 1 (X)");
                g(3, 20); p("Invalid position or already taken!");
                getch(); g(13, 19); p("    "); g(3, 20); p("                                  ");
            }
        }


        else if (pl == 2)
        {
            g(19, 18); p("Player 2 (O)");
            g(19, 19); p("Enter bet: ");
            g(30, 19); s("%s", stringPlayer2);

            player2 = verifier(19, stringPlayer2, player2);

            if ((player2 >= 1 && player2 <= 9) &&
                ((player2 == 1 && a1 == 0) || (player2 == 2 && a2 == 0) || (player2 == 3 && a3 == 0) ||
                 (player2 == 4 && a4 == 0) || (player2 == 5 && a5 == 0) || (player2 == 6 && a6 == 0) ||
                 (player2 == 7 && a7 == 0) || (player2 == 8 && a8 == 0) || (player2 == 9 && a9 == 0)))
            {

                g(30, 19); p(" ");

                for (x = 1; x <= 65; x++)
                {
                    g(x, 20); p(" ");
                }

                player2Log++;
                g(64, 7+player2Log); p("%d. O to %d", player2Log, player2);

                switch (player2)
                {
                    case 1:
                        a1 = 2;
                        g(6, 4); p("O");
                        break;
                    case 2:
                        a2 = 2;
                        g(16, 4); p("O");
                        break;
                    case 3:
                        a3 = 2;
                        g(26, 4); p("O");
                        break;
                    case 4:
                        a4 = 2;
                        g(6, 9); p("O");
                        break;
                    case 5:
                        a5 = 2;
                        g(16, 9); p("O");
                        break;
                    case 6:
                        a6 = 2;
                        g(26, 9); p("O");
                        break;
                    case 7:
                        a7 = 2;
                        g(6, 14); p("O");
                        break;
                    case 8:
                        a8 = 2;
                        g(16, 14); p("O");
                        break;
                    case 9:
                        a9 = 2;
                        g(26, 14); p("O");
                        break;
                    default:
                        break;
                }
                pl = 1;
                a++;

                if ((a1 == 2 && a2 == 2 && a3 == 2) ||
                    (a4 == 2 && a5 == 2 && a6 == 2) ||
                    (a7 == 2 && a8 == 2 && a9 == 2) ||
                    (a1 == 2 && a4 == 2 && a7 == 2) ||
                    (a2 == 2 && a5 == 2 && a8 == 2) ||
                    (a3 == 2 && a6 == 2 && a9 == 2) ||
                    (a1 == 2 && a5 == 2 && a9 == 2) ||
                    (a3 == 2 && a5 == 2 && a7 == 2))
                {

                    for (x = 1; x <= 38; x++)
                    {
                        g(x, 20); p(" ");
                    }

                    g(19, 20); p("Player 2 Wins!!");
                    g(64, 9+player1Log); p("Player 2 Wins!!"); win = 1;
                    break;
                }
            }

            else
            {
                g(19, 18); p("Player 2 (O)");
                g(19, 20); p("Invalid position or already taken!");
                getch(); g(30, 19); p("    "); g(19, 20); p("                                   ");
            }
        }
    }

    if (win == 0)
    {
        g(15, 20); p("Draw!");
        g(58, 14); p("Draw!");
    }
    getch();
}
#endif  //QCODE_H
