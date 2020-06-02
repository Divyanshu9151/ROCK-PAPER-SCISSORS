#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generaterandomnumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}
int greater(char c1, char c2)
{
    if (c1 == c2)
    {
        return -1;
    }
    if ((c1 == 'R') && (c2 == 'S'))
    {
        return 1;
    }
    else if ((c2 == 'R') && (c1 == 'S'))
    {
        return 0;
    }
    if ((c1 == 'P') && (c2 == 'R'))
    {
        return 1;
    }
    else if ((c2 == 'P') && (c1 == 'R'))
    {
        return 0;
    }
    if ((c1 == 'S') && (c2 == 'P'))
    {
        return 1;
    }
    else if ((c2 == 'P') && (c1 == 'S'))
    {
        return 0;
    }
}
int main()
{
    int playerscore = 0, compscore = 0, temp;
    char playerchar, compchar;
    char dict[] = {'R', 'P', 'S'};
    printf("WELCOME TO THE ROCK PAPER SCISSOR.\n");
    for (int i = 0; i < 3; i++)
    {
        printf("YOUR TURN:\n");
        printf("CHOOSE 1 FOR ROCK, 2 FOR PAPER, 3 FOR SCISSOR\n");
        scanf("%d", &temp);
        playerchar = dict[temp - 1];
        printf("YOU CHOOSE %c\n\n\n", playerchar);

        printf("COMPUTER TURN:\n");
        printf("CHOOSE 1 FOR ROCK, 2 FOR PAPER, 3 FOR SCISSOR\n");
        temp = generaterandomnumber(3) + 1;
        compchar = dict[temp - 1];
        printf("COMPUTER CHOOSE %c\n\n\n", compchar);
        if (greater(compchar, playerchar) == 1)
        {
            compscore += 1;
            printf("COMPUTER GOT IT:%d\n", compscore);
        }
        else if (greater(compchar, playerchar) == -1)
        {
            compscore += 1;
            playerscore += 1;
        }
        else
        {
            playerscore += 1;
            printf("YOU GOT IT:%d\n", playerscore);
        }
        printf("YOU:%d\nCOMPUTER: %d\n\n", playerscore, compscore);
    }
    if (playerscore > compscore)
    {
        printf("CONGRATULATIONS !!! \n YOU WIN THE GAME\n");
    }
    else if (playerscore < compscore)
    {
        printf("COMPUTER WIN THE GAME\n BETTER LUCK NEXT TIME\n");
    }
    else
    {
        printf("THE GAME IS DRAW\n");
    }

    return 0;
}