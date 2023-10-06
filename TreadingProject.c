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

// Common Functions
void enter_float(char message[], float *value);
void enter_int(char message[], int *value);

// Admin Side Variables
Stock *stock_head = NULL;

// Admin Side Function Prototypes

void add_stock(char name[], float buy_price, float sell_price, int quantity);
void view_stocks();
void view_single_stock(Stock *stock);
Stock *is_stock_available(char name[]);
void update_stock();

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
                    enter_float("Enter only positive number.", &buy_price);
                    printf("Enter the sell price of the stock: ");
                    float sell_price;
                    enter_float("Enter only positive number.", &sell_price);
                    printf("Enter the quantity of the stock: ");
                    int quantity;
                    enter_int("Enter only positive number.", &quantity);
                    add_stock(name, buy_price, sell_price, quantity);
                    break;
                case 2:
                    system("cls");
                    view_stocks();
                    update_stock();
                    system("pause");
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

// -----------Update Stock Function Start----------------
Stock *is_stock_available(char name[])
{
    Stock *temp = stock_head;
    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void update_stock()
{
    printf("\n***************Update Stock****************\n");
    printf("Enter the name of the stock to update: ");
    char stock_name[20];
    scanf("%s", stock_name);
    Stock *stock = is_stock_available(stock_name);
    if (stock == NULL)
    {
        printf("Stock Not Available\n");
    }
    else
    {
        // print stock details
        printf("Stock Details\n");
        printf("Name\t\t|\tBuy Price\t|\tSell Price\t|\tQuantity\n");
        view_single_stock(stock);
        printf("Enter the new buy price to update or enter n: ");
        float buy_price;
        int ch;
        ch = scanf("%f", &buy_price);
        if (ch == 1)
        {
            stock->buy_price = buy_price;
        }
        printf("Enter the new sell price to update or enter n: ");
        float sell_price;
        ch = scanf("%f", &sell_price);
        if (ch == 1)
        {
            stock->sell_price = sell_price;
        }
        printf("Enter the new quantity to update or enter n: ");
        int quantity;
        ch = scanf("%d", &quantity);
        if (ch == 1)
        {
            stock->quantity = quantity;
        }

        printf("\nStock Updated Successfully\n");
        view_single_stock(stock);
    }
}
// Common Functions
void enter_float(char message[], float *value)
{

    int ret;
    do
    {
        ret = scanf("%f", value);
        if (ret == 0 || *value < 0)
        {
            printf("Invalid Input\n");
            printf("%s\n", message);
            fflush(stdin);
        }

    } while (ret != 1 || *value < 0);
}

void enter_int(char message[], int *value)
{

    int ret;
    do
    {
        ret = scanf("%d", value);
        if (ret == 0 || *value < 0)
        {
            printf("Invalid Input\n");
            printf("%s\n", message);
            fflush(stdin);
        }
        fflush(stdin);
    } while (ret != 1 || *value < 0);
}