#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    srand(time(NULL));
    printf("Name:Irem   Surname:Kavakpinar   Student ID:152120201069   Email Adress:kavakpinarirem1@gmail.com\n");
    printf("Due Date: 19.01.2022    PROBLEM-1");
    printf("\n");

    char array[12] = { '0','1','2','3','4','5','6','7','8','9','X','/' };
    int oyuncu1 = 0;
    char birinciAtis[12];
    char ikinciAtis[12];
    char ucuncuAtis = ' ';
    int score = 0, i, a;
    int b = 0;
    int c = 1;
    if (c == 1) {
        printf("Mary\t");
    }

    while (b < 2) {
        for (i = 0; i < 10; i++)
        {
            int sira = rand() % 11;
            birinciAtis[i] = array[sira];
            if (array[sira] != 'X')
            {
                int sira = rand() % (11 - (int)(birinciAtis[i] - 48));
                ikinciAtis[i] = array[sira];
                int second;
                if (ikinciAtis[i] == 'X')
                {
                    second = 10;
                }
                else
                {
                    second = (int)(ikinciAtis[i] - 48);
                }
                if ((int)(birinciAtis[i] - 48) + second == 10)
                {
                    ikinciAtis[i] = '/';
                }
            }
            else if (i == 9 && array[sira] == 'X')
            {
                int sira = rand() % 11;
                ikinciAtis[i] = array[sira];
            }
            else
            {
                ikinciAtis[i] = ' ';
            }
            if (i == 9 && (int)(birinciAtis[9] - 48) < 10 && (int)(birinciAtis[9] - 48) > -1 && (int)(ikinciAtis[9] - 48) < 10 && (int)(ikinciAtis[9] - 48) > -1) {
                ucuncuAtis = ' ';
            }
            if (i == 9 && (birinciAtis[9] == 'X' || ikinciAtis[9] == '/'))
            {
                if (ikinciAtis[9] == '/')
                {
                    ucuncuAtis = array[rand() % 11];
                }
                else//first X
                {
                    if ((int)(ikinciAtis[i] - 48) < 10)
                    {
                        sira = rand() % (10 - (int)(ikinciAtis[i] - 48));
                        ucuncuAtis = array[sira];
                        if ((int)(ikinciAtis[i] - 48) + (int)(ucuncuAtis - 48) == 10)
                        {
                            ucuncuAtis = '/';
                        }
                    }
                    else//second X
                    {
                        ucuncuAtis = array[rand() % 11];
                    }

                }
            }
        }

        for (int i = 0; i < 10; i++)
        {
            if (i == 9)
            {
                printf("%c%c%c\t", birinciAtis[i], ikinciAtis[i], ucuncuAtis);
            }
            else
            {
                printf("%c%c\t", birinciAtis[i], ikinciAtis[i]);
            }
        }
        printf("\n");
        printf("\t");
        for (int a = 0; a < 10; a++)
        {
            int mevcutScore;
            if (a == 9)
            {
                if ((int)(birinciAtis[a] - 48) < 10 && (int)(ikinciAtis[a] - 48) < 10 && (int)(ikinciAtis[a] - 48) >= 0)
                {
                    mevcutScore = (int)(birinciAtis[a] - 48) + (int)(ikinciAtis[a] - 48);
                    score += mevcutScore;
                }
                else
                {
                    if (birinciAtis[a] == 'X')
                    {
                        score += 10;
                        if (ikinciAtis[a] == 'X')
                        {
                            score += 10;
                            if (ucuncuAtis == 'X')
                            {
                                score += 10;
                            }
                        }
                    }
                    if (((int)(birinciAtis[a] - 48) < 10 && ikinciAtis[a] == '/'))
                    {
                        mevcutScore = ucuncuAtis != 'X' ? (int)(ucuncuAtis - 48) : 10;
                        score += mevcutScore + 10;
                    }
                    if (((int)(ikinciAtis[a] - 48) < 10 && ucuncuAtis == '/'))
                    {
                        score += 10;
                    }
                    if ((int)(ikinciAtis[a] - 48) > -1 && (int)(ikinciAtis[a] - 48) < 10 && (int)(ucuncuAtis - 48) < 10)
                    {
                        score += (int)(ikinciAtis[a] - 48) + (int)(ucuncuAtis - 48);
                    }
                }
            }
            else
            {
                if (birinciAtis[a] == 'X')//9
                {
                    mevcutScore = birinciAtis[a + 1] != 'X' ? (int)(birinciAtis[a + 1] - 48) : 10;
                    if (mevcutScore < 10)
                    {
                        if (ikinciAtis[a + 1] == '/')
                        {
                            mevcutScore = 10;
                        }
                        else
                        {
                            mevcutScore += (int)(ikinciAtis[a + 1] - 48);
                        }
                        mevcutScore += 10;
                    }
                    else//X//10
                    {
                        if (birinciAtis[a + 1] == 'X' && (a != 8))
                        {
                            mevcutScore += (int)(birinciAtis[a + 2] != 'X' ? (int)(birinciAtis[a + 2] - 48) : 10);
                        }
                        else if (ikinciAtis[a + 1] == 'X')
                        {
                            mevcutScore += 10;
                        }
                        else
                        {
                            mevcutScore += (int)(ikinciAtis[a + 1] - 48);
                        }
                        mevcutScore += 10;
                    }
                    score += mevcutScore;

                }
                else
                {
                    if (ikinciAtis[a] == '/')
                    {
                        mevcutScore = birinciAtis[a + 1] != 'X' ? (int)(birinciAtis[a + 1] - 48) : 10;
                        mevcutScore += 10;
                        score += mevcutScore;
                    }
                    else
                    {
                        mevcutScore = (int)(birinciAtis[a] - 48) + (int)(ikinciAtis[a] - 48);
                        score += mevcutScore;
                    }
                }
            }
            printf("%d\t", score);
        }
        if (b == 0) {
            printf("\nScore for player1: %d", score);
        }
        if (b == 1) {
            printf("\nScore for player2: %d", score);
        }
        printf("\n");
        b++;
        c++;
        if (c == 2) {
            printf("Harry\t");
        }
        score = 0;
    }

    return 0;
}