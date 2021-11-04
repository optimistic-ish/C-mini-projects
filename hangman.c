#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
//show one letter for one live but dont count it in score==feature
//show the letters tried on top==feature
const char data[][55] = {
    "variation",
    "minimize",
    "distortion",
    "accountant",
    "prejudice",
    "satisfied",
    "earthquake",
    "conductor",
    "penetrate",
    "integrity",
    "skeleton",
    "consumption",
    "astonishing",
    "admiration",
    "audience",
    "approval",
    "consultation",
    "telephone",
    "suspicion",
    "medieval",
    "expectation",
    "personal",
    "landowner",
    "offensive",
    "battlefield",
    "transparent",
    "familiar",
    "strikebreaker",
    "producer",
    "analysis",
    "innovation",
    "artificial",
    "standard",
    "preference",
    "revolutionary",
    "extraterrestrial",
    "migration",
    "amputate",
    "positive",
    "suffering",
    "tradition",
    "hemisphere",
    "conception",
    "inflation",
    "sympathetic",
    "authorise",
    "dedicate",
    "agriculture",
    "mainstream",
    "sensitive"};
//shape[2]='O';shape[6]='|';shape[1]=shape[3]='_';shape[9]='/';shape[11]=92;
char hints[][55]={
    "Change or slight difference in condition",
    "Reduce",
    "Out of shape",
    "A profession",
    "Not based on reason",


};
char shape[12];
int gameover = 0, counter = 0, length, list[50], ran, score = 0, correction,life=3;
char word[20], temp, entered[20];
int i = 0; //game tracker

int wordChecker(int x)
{
    for (int i = 0; i < 50; i++)
    {
        if (list[i] == x)
        {
            x++;
            if (x > 50)
                x % 50;
            wordChecker(x);
        }
        else
            return x;
    }
};
void hint(){
if(life>0){
    for(int i=0;i<length;i++){
        if((word[i])==' '){
            word[i]=data[ran][i];
            life--;         
            break;
        }
    }
}
if(life<1){
    printf("Sorry no life lines remaining!\n");
    getch();
}
};
void hangman()
{
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tLevel:%d", i);
    printf("\n___\n%c  %c", 179, 179);
    printf("\t\tEntered letters:");
    for (int i = 0; i < 20; i++)
        printf("%c ", entered[i]);
    printf("\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%c", 179);
        for (int j = 0; j < 4; j++)
            printf("%c", shape[4 * i + j]);
        printf("\n");
    }
};
void setup()
{
    printf("\t\t\t\t\t\t\t\t\tScore:%d\n\n\n\t", score);
    for (int i = 0; i < length; i++)
        printf(" %c   ", word[i]);

    printf("\n\t");
    for (int i = 0; i < length; i++)
        printf("___  ");
    printf("\n\n");
};

void input()
{
    int index1 = 0;
    scanf(" %c", &temp);
    if(temp>64 && temp<123){
    for (int i = 0; i < length; i++)
    {
        if (temp == data[ran][i] || temp - 32 == data[ran][i])
        {
            word[i] = data[ran][i];
            index1 = 1;
        }
    }}
    if(temp=='/'){
        hint();
    }
    if (index1 == 0)
    {
        counter++;
        if (counter == 1)
            shape[2] = 'O';
        if (counter == 2)
            shape[6] = '|';
        if (counter == 3)
            shape[1] = '_';
        if (counter == 4)
            shape[3] = '_';
        if (counter == 5)
            shape[9] = '/';
        if (counter == 6)
            shape[11] = 92;
        if (counter > 6)
            gameover = 1; //loss
    }
};
void tester()
{
    int index2 = 0;
    for (int i = 0; i < length; i++)
    {
        if (word[i] != data[ran][i])
        {
            index2 = 1;
            break;
        }
    }
    if (index2 == 0)
    {
        gameover = 2; //win
    }
};
void Scoreboard(int a)
{
    if (a == 2)
    {
        int counter = 0;
        for (int i = 0; i < length; i++)
        {
            int index = 0;
            for (int j = i + 1; j < length; j++)
            {
                if (data[ran][i] == data[ran][j])
                {
                    index = 1;
                    break;
                }
            }
            if (index == 0)
                counter++;
        }
        counter -= 2; //correction
        score += counter;
    }
    printf("Your score is %d", score);
};
void decider()
{
    if (gameover == 1)
    {
        printf("SORRY!!!YOU LOST\n");
        printf("The word was %s.\n", data[ran]);
        Scoreboard(1);
        getch();
    }
    if (gameover == 2)
    {
        printf("You win!\n");
        Scoreboard(2);
        getch();
    }
};

void main()
{
    while (1)
    {
        int wordtracker = 0;
        gameover = 0;counter=0;
        srand(time(NULL));
        ran = rand() % 51;
        list[i] = ran;
        ran = wordChecker(ran);
        length = strlen(data[ran]);
        for (int i = 0; i < 12; i++)
            shape[i] = ' ';
        for (int i = 0; i < 20; i++)
        {
            word[i] = ' ';
            entered[i] = ' ';
        }
        i++;
        {
            int temp = rand() % 7, c1 = 0, c2 = 0;
            word[temp] = data[ran][temp];
            for (int i = 0; i < length; i++)
            {
                if (data[ran][i] == word[temp])
                {
                    word[i] = data[ran][i];
                    c1++;
                }
            }
            temp = rand() % 7;
            word[temp] = data[ran][temp];
            for (int i = 0; i < length; i++)
            {
                if (data[ran][i] == word[temp])
                {
                    word[i] = data[ran][i];
                    c2++;
                }
            }
            correction = c1 + c2;
        }
        while (1)
        {

            system("cls");
            //printf("\033[2J\033[1;1H");
            hangman();
            setup();
            tester();
            decider();
            if (gameover == 1 || gameover == 2)
                break;
            input();
            entered[wordtracker] = temp;
            wordtracker++;
        }
        if (gameover == 1)
        {

            break;
        }
    }
};