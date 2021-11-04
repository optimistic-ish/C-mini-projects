//0=draw, 1=win, 2=in progress;
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int score1 = 0, score2 = 0;
int control[10] = {'d', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char play1[15];
char play2[15];
int status()
{
    if (control[1] == control[2] && control[2] == control[3] && control[1] != ' ' && control[2] != ' ' && control[3] != ' ')
        return 1;
    else if (control[4] == control[5] && control[5] == control[6] && control[4] != ' ' && control[5] != ' ' && control[6] != ' ')
        return 1;
    else if (control[7] == control[8] && control[8] == control[9] && control[7] != ' ' && control[8] != ' ' && control[9] != ' ')
        return 1;
    else if (control[1] == control[5] && control[5] == control[9] && control[1] != ' ' && control[5] != ' ' && control[9] != ' ')
        return 1;
    else if (control[3] == control[5] && control[5] == control[7] && control[3] != ' ' && control[5] != ' ' && control[7] != ' ')
        return 1;
    else if (control[1] == control[4] && control[4] == control[7] && control[1] != ' ' && control[4] != ' ' && control[7] != ' ')
        return 1;
    else if (control[2] == control[5] && control[5] == control[8] && control[2] != ' ' && control[5] != ' ' && control[8] != ' ')
        return 1;
    else if (control[3] == control[6] && control[6] == control[9] && control[9] != ' ' && control[3] != ' ' && control[6] != ' ')
        return 1;

    else if (control[1] != ' ' && control[9] != ' ' && control[2] != ' ' && control[3] != ' ' && control[4] != ' ' && control[5] != ' ' && control[6] != ' ' && control[7] != ' ' && control[8] != ' ')
        return 0;

    else
        return 2;
};
void AI(){

};

void ScoreBoard(int x, char c[15], char d[15])
{
    if (x == 1)
    {
        score1++;
    }
    else if (x == 2)
    {
        score2++;
    }
    printf("%s \t\t %s\n", c, d);
    //printf("_________|_________\n");
    // printf("    %d    |    %d    \n", score1, score2);
    //printf("         |         \n");
    printf("%d \t\t %d\n", score1, score2);
};
void Reference()
{
    printf("  %d |  %d  |  %d \n", 1, 2, 3);
    printf("____|_____|____\n");
    printf("  %d |  %d  |  %d \n", 4, 5, 6);
    printf("____|_____|____\n");
    printf("  %d |  %d  |  %d \n", 7, 8, 9);
    printf("    |     |    \n");
    printf("\n");
};

void drawboard()
{
    printf("  %c |  %c  |  %c \t\t\t", control[1], control[2], control[3]);
    printf("  %d |  %d  |  %d \n", 1, 2, 3);
    printf("____|_____|____\t\t\t");
    printf("____|_____|____\n");
    printf("  %c |  %c  |  %c \t\t\t", control[4], control[5], control[6]);
    printf("  %d |  %d  |  %d \n", 4, 5, 6);
    printf("____|_____|____\t\t\t");
    printf("____|_____|____\n");
    printf("  %c |  %c  |  %c \t\t\t", control[7], control[8], control[9]);
    printf("  %d |  %d  |  %d \n", 7, 8, 9);
    printf("    |     |    \t\t\t");
    printf("    |     |    \n");
    printf("\n");
};

int main()
{
    int choice, player = 1, para = 2, mark, a = 5;
    char n;
    printf("Player 1, Enter your name:\n");
    scanf("%s", &play1);
    printf("Player 2, Enter your name:\n");
    scanf("%s", &play2);
    while (a == 5)
    {
        for (int i = 1; i < 10; i++)
        {
            control[i] = ' ';
            player = 1;
            para = 2;
        }
        while (para == 2)
        {
            if (player == 1)
                mark = 'X';
            else if (player == 2)
                mark = 'O';
            drawboard();
            if (player == 1)
            {
                printf("%s, Enter your choice:", play1);
            }
            else if (player == 2)
            {
                printf("%s, Enter your choice:", play2);
            }
            scanf("%d", &choice);

            if (choice == 1 && control[1] == ' ')
            {
                control[1] = mark;
            }
            else if (choice == 2 && control[2] == ' ')
            {
                control[2] = mark;
            }
            else if (choice == 3 && control[3] == ' ')
            {
                control[3] = mark;
            }
            else if (choice == 4 && control[4] == ' ')
            {
                control[4] = mark;
            }
            else if (choice == 5 && control[5] == ' ')
            {
                control[5] = mark;
            }
            else if (choice == 6 && control[6] == ' ')
            {
                control[6] = mark;
            }
            else if (choice == 7 && control[7] == ' ')
            {
                control[7] = mark;
            }
            else if (choice == 8 && control[8] == ' ')
            {
                control[8] = mark;
            }
            else if (choice == 9 && control[9] == ' ')
            {
                control[9] = mark;
            }
            else
            {
                printf("Invalid choice!Try again!!!\n");
                player--;
            }

            player++;
            if (player % 2 == 0)
            {
                player = 2;
            }
            else if (player % 2 == 1)
            {
                player = 1;
            }

            para = status();
            if (para == 1 || para == 0)
                break;
        }
        if (para == 1)
        {
            drawboard();
            if (player == 1)
            {
                player = 2;
            }
            else if (player == 2)
            {
                player = 1;
            }
            printf("Player %d wins:\n\n", player);
            ScoreBoard(player, play1, play2);
        }

        if (para == 0)
        {
            drawboard();
            printf("The game is drawn!\n");
            ScoreBoard(10, play1, play2);
        }

        printf("Do you want to play again? Enter 'y' for yes and 'n' for no:\n");
        scanf(" %c", &n);
        if (n == 'y' || n == 'Y')
        {
            a = 5;
        }
        else
        {
            break;
        }
    }
}
