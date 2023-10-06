#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stock_node
{
    char name[20];
    float buy_price;
    float sell_price;
    int quantity;
    struct stock_node *next;
} Stock;

// Admin Side Variables
Stock *stock_head = NULL;

// Admin Side Function Prototypes
void add_stock(char name[], float buy_price, float sell_price, int quantity);
void view_stocks();
void view_single_stock(Stock *stock);

void main()
{
    int admin_choice, user_choice, choice;
    do
    {
        printf("***********Welcome to Stock Management System************\n");
        printf("*\t\t1. Admin Side\t\t\t\t*\n");
        printf("*\t\t2. User Side\t\t\t\t*\n");
        printf("*\t\t0. Exit\t\t\t\t\t*\n");
        printf("*********************************************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            do
            {
                system("cls");
                printf("**************Welcome to Admin Side**************\n");
                printf("*\t\t1. Add Stock\t\t\t*\n");
                printf("*\t\t2. Update Stock\t\t\t*\n");
                printf("*\t\t3. Delete Stock\t\t\t*\n");
                printf("*\t\t4. View Stock\t\t\t*\n");
                printf("*\t\t0. Exit\t\t\t\t*\n");
                printf("*************************************************\n");
                printf("Enter your choice: ");
                scanf("%d", &admin_choice);
                switch (admin_choice)
                {
                case 1:
                    system("cls");
                    printf("Enter the name of the stock: ");
                    char name[20];
                    scanf("%s", name);
                    printf("Enter the buy price of the stock: ");
                    float buy_price;
                    scanf("%f", &buy_price);
                    printf("Enter the sell price of the stock: ");
                    float sell_price;
                    scanf("%f", &sell_price);
                    printf("Enter the quantity of the stock: ");
                    int quantity;
                    scanf("%d", &quantity);
                    add_stock(name, buy_price, sell_price, quantity);
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    system("cls");
                    view_stocks();
                    system("pause");
                    break;
                case 0:
                    break;
                default:
                    printf("Invalid Choice\n");
                    break;
                }
            } while (admin_choice != 0);
            break;
        case 2:
            do
            {
                printf("***********Welcome to User Side***********\n");
                printf("*\t\t1. Buy Stock\t\t\t*\n");
                printf("*\t\t2. Sell Stock\t\t\t*\n");
                printf("*\t\t3. View Stock\t\t\t*\n");
                printf("*\t\t0. Exit\t\t\t\t*\n");
                printf("*******************************************\n");
                printf("Enter your choice: ");
                scanf("%d", &user_choice);
                switch (user_choice)
                {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 0:
                    break;
                default:
                    printf("Invalid Choice\n");
                    break;
                }
            } while (user_choice != 0);
            break;
        case 0:
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }

    } while (choice != 0);
}

//------------------------------ Admin Side Functions---------------------------------

// -----------Add Stock Function Start----------------
void add_stock(char name[], float buy_price, float sell_price, int quantity)
{
    Stock *new_stock = (Stock *)malloc(sizeof(Stock));
    strcpy(new_stock->name, name);
    new_stock->buy_price = buy_price;
    new_stock->sell_price = sell_price;
    new_stock->quantity = quantity;
    new_stock->next = NULL;

    if (stock_head == NULL)
    {
        stock_head = new_stock;
    }
    else
    {
        Stock *temp = stock_head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_stock;
    }
    printf("Stock Added Successfully\n");
    system("pause");
}
// -----------Add Stock Function End----------------

// -----------View Stock Function Start----------------
void view_single_stock(Stock *stock)
{
    printf("--------------------------------------------------------------------------------------------\n");
    printf("%s\t\t|\t%.2f\t\t|\t%.2f\t\t|\t%d\n", stock->name, stock->buy_price, stock->sell_price, stock->quantity);
}

void view_stocks()
{
    printf("************************Stocks**************************\n|\n");
    printf("Name\t\t|\tBuy Price\t|\tSell Price\t|\tQuantity\n");

    Stock *temp = stock_head;
    if (temp == NULL)
    {
        printf("No Stocks Available\n");
    }
    while (temp != NULL)
    {
        view_single_stock(temp);
        temp = temp->next;
    }
}
// -----------View Stock Function End----------------