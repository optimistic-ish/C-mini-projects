#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int total = 33;
int bill_number;

typedef struct food
{
    char code[6];
    char list[19];
    int price;
} item;

//item *menu;
item menu[33];
typedef struct ordering
{
    int SN;
    int quantity;
} orders;

//cheque *bills_;

void menu_card()
{
    //menu=malloc(total*sizeof(item));
    FILE *ptr;
    ptr = fopen("menu.txt", "r+");
    for (int i = 0; i < 50; i++)
    {
        fscanf(ptr, "%s %18c %d", &menu[i].code, &menu[i].list, &menu[i].price);
    }
    printf("\t\t\tMENU\n\n");
    printf("%5s %-17s %-5s\n", "S.N", "Food item", "Price");
    for (int i = 0; i < total; i++)
    {
        printf("%5d %s %d \n", i + 1, menu[i].list, menu[i].price);
    }    
}
void sort()
{
    printf("\nPlease select the following options:\n");

}

void order()
{
    FILE *number = fopen("system_.bin", "rb+");
        fread(&bill_number, sizeof(int), 1, number);
        fclose(number);
    orders day[50];
    int index = 0, sum = 0, correct;
    printf("\n\nWelcome to the food ordering section.\nPlease enter the Serial Numbers(S.N.) of the food you want to order along with its quantity.\nEnter 0 after you have completed entering the food you want:\n");
    while (1)
    {
        scanf("%d", &day[index].SN);
        if (day[index].SN == 0)
        {
            day[index].quantity == 0;
            break;
        }
        scanf("%d", &day[index].quantity);
        index++;
    }

    // bills_=malloc(index*sizeof(cheque));

    printf("\nPlease confirm your order:\n%-5s %-14s %-8s %-8s\n", "S.N.", "Food item", "Quantity", "Price");
    for (int i = 0; i < index; i++)
    {
        printf("%2d    %18s %-6d %d\n", i + 1, menu[day[i].SN - 1].list, day[i].quantity, menu[day[i].SN - 1].price * day[i].quantity);
        sum += menu[day[i].SN - 1].price * day[i].quantity;
    }
    printf("%29s %5d\n", "TOTAL", sum);
    fflush(stdin);
    printf("\nEnter 1 to confirm and 0 to go back:");
    scanf("%d", &correct);
    if (correct == 1)
    {
        FILE *ptr2 = fopen("bill.txt", "w+");        
        fprintf(ptr2, "\n\
                XYZ CANTEEN \n\
                Location \n\
                \n\
                Bill number=%d \n\n\
%s %-14s %-8s %s\n",
                bill_number, "S.N.", "Food item", "Quantity", "Price");
        for (int i = 0; i < index; i++)
        {
            fprintf(ptr2, "%2d   %18s %-4d %d\n", i + 1, menu[day[i].SN - 1].list, day[i].quantity, menu[day[i].SN - 1].price * day[i].quantity);
            sum += menu[day[i].SN - 1].price * day[i].quantity;
        }
        fprintf(ptr2, "%27s  %-5d\n", "TOTAL", sum);
        fclose(ptr2);
        bill_number++;
        FILE *number = fopen("system_.bin", "wb+");        
        fwrite(&bill_number, sizeof(int), 1, number);
        fclose(number);
        printf("\nYour order has been placed and your bill has been generated.\nPlease wait while the kitchen prepares your order!!");
    }
    else
        order();
}

void customer()
{
    system("Cls");
    int choice;
    printf("\t\t\tWELCOME CUSTOMER!!\n\n");
    menu_card();
    printf("\tPlease select one of the following options:\n");
    printf("1. Student login\n2. Order\n3. See your bill\n");
    scanf("%d", &choice);
    if(choice==1)
        printf("No database available.\nPlease contact your school's administration.\n");
    if (choice == 2)
        order();
    if(choice==3)
        {printf("You haven't ordered anything.\n");
        getch();
        customer();}
}
void staff()
{
}
void admin()
{
}

void entry()
{   
    int choice;
    printf("\t\t\tWELCOME TO THE CANTEEN!!!\n\n");
    printf("\tPlease select one of the options below:\n");
    printf("1. Customer\n2. Staff\n3. Admin\n");
    scanf("%d", &choice);

    if (choice == 1)
        customer();
    if (choice == 2)
        staff();
    if (choice == 3)
        admin();
}

void main()
{    
    //entry();
    customer();  
    
}
