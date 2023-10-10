#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
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
void make_upper_case(char *str);

// Admin Side Variables
Stock *stock_head = NULL;

// Admin Side Function Prototypes

void add_stock(char name[], float buy_price, float sell_price, int quantity);
void view_stocks(Stock *head);
void view_single_stock(Stock *stock);
void delete_stock();
Stock *is_stock_available(char name[]);
void update_stock();

// User Side Variables
double user_balance = 0;
typedef struct user_stock_node
{
    char name[20];
    float buy_price;
    float *sell_price;
    int quantity;
    struct user_stock_node *next;
} UserStock;

UserStock *user_stock_head = NULL;
// User Side Function Prototypes

void buy_stock();

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
                    make_upper_case(name);
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

                    update_stock();
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    delete_stock();
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    view_stocks(stock_head);
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
                printf("*\t\t4. Automated Suggestion\t\t*\n");
                printf("*\t\t5. View Transaction History\t*\n");
                printf("*\t\t0. Exit\t\t\t\t*\n");
                printf("*******************************************\n");
                printf("Enter your choice: ");
                scanf("%d", &user_choice);
                switch (user_choice)
                {
                case 1:

                    system("cls");
                    buy_stock();
                    system("pause");

                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:

                    system("cls");
                    printf("************************Transaction History**************************\n|\n");
                    printf("Name\t\t|\tBuy Price\t|\tSell Price\t|\tQuantity\n");

                    UserStock *temp = user_stock_head;
                    if (temp == NULL)
                    {
                        printf("No Transactions Available\n");
                    }
                    while (temp != NULL)
                    {

                        printf("%s\t\t|\t%.2f\t\t|\t%.2f\t\t|\t%d\n", temp->name, temp->buy_price, *(temp->sell_price), temp->quantity);
                        temp = temp->next;
                    }
                    system("pause");

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

void view_stocks(Stock *head)
{
    printf("************************Stocks**************************\n|\n");
    printf("Name\t\t|\tBuy Price\t|\tSell Price\t|\tQuantity\n");

    Stock *temp = head;
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

    if (stock_head == NULL)
    {
        printf("\n***************Update Stock****************\n");
        printf("No Stocks Available\n");
        return;
    }
    view_stocks(stock_head);
    printf("\n***************Update Stock****************\n");
    printf("Enter the name of the stock to update: ");
    char stock_name[20];
    scanf("%s", stock_name);
    make_upper_case(stock_name);
    Stock *stock = is_stock_available(stock_name);
    if (stock == NULL)
    {
        printf("Stock Not Available\n");
    }
    else
    {
        system("cls");
        // print stock details
        printf("Stock Details\n");
        printf("Name\t\t|\tBuy Price\t|\tSell Price\t|\tQuantity\n");
        view_single_stock(stock);
        printf("Enter the new buy price to update or enter any character to skip: ");
        float buy_price;
        if (scanf("%f", &buy_price) == 1)
        {
            stock->buy_price = buy_price;
        }
        else
        {
            // Consume the newline character from the previous input
            scanf("%*c");
        }

        printf("Enter the new sell price to update or enter any character to skip: ");
        float sell_price;
        if (scanf("%f", &sell_price) == 1)
        {
            stock->sell_price = sell_price;
        }
        else
        {
            // Consume the newline character from the previous input
            scanf("%*c");
        }

        printf("Enter the new quantity to update or enter any character to skip: ");
        int quantity;
        if (scanf("%d", &quantity) == 1)
        {
            stock->quantity = quantity;
        }
        else
        {
            // Consume the newline character from the previous input
            scanf("%*c");
        }

        printf("\nStock Updated Successfully\n");
        view_single_stock(stock);
    }
}
// -----------Update Stock Function End----------------

// -----------Delete Stock Function Start----------------
void delete_stock()
{
    if (stock_head == NULL)
    {
        printf("\n***************Delete Stock****************\n");
        printf("No Stocks Available\n");
        return;
    }
    view_stocks(stock_head);
    printf("\n***************Delete Stock****************\n");
    printf("Enter the name of the stock to delete: ");
    char stock_name[20];
    scanf("%s", stock_name);
    make_upper_case(stock_name);
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
        printf("Are you sure you want to delete this stock? (y/n): ");
        char ch;
        scanf(" %c", &ch);
        if (ch == 'y' || ch == 'Y')
        {
            Stock *temp = stock_head;
            if (temp == stock)
            {
                stock_head = stock_head->next;
                free(stock);
            }
            else
            {
                while (temp->next != stock)
                {
                    temp = temp->next;
                }
                temp->next = stock->next;
                free(stock);
            }
            printf("Stock Deleted Successfully\n");
        }
    }
}

// -----------Delete Stock Function End----------------

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

void make_upper_case(char *str)
{
    while (*str != '\0')
    {
        if (*str >= 'a' && *str <= 'z')
        {
            *str = *str - 32;
        }
        str++;
    }
}

//------------------------------ User Side Functions---------------------------------

// -----------Buy Stock Function Start----------------
void buy_stock()
{
    if (user_balance == 0)
    {
        printf("Enter the amount to add to your account: ");
        enter_float("Enter only positive number.", &user_balance);
    }
    view_stocks(stock_head);
    printf("\n***************Buy Stock****************\n");
    printf("Enter the name of the stock to buy: ");
    char stock_name[20];
    scanf("%s", stock_name);
    make_upper_case(stock_name);
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
        printf("Enter the quantity to buy: ");
        int quantity;
        enter_int("Enter only positive number.", &quantity);
        if (quantity > stock->quantity)
        {
            printf("Stock Not Available\n");
        }
        else
        {
            if (user_balance < (stock->buy_price * quantity))
            {
                printf("Insufficient Balance\n");
            }
            else
            {
                UserStock *new_user_stock = (UserStock *)malloc(sizeof(UserStock));
                strcpy(new_user_stock->name, stock->name);
                new_user_stock->buy_price = stock->buy_price;
                new_user_stock->sell_price = &(stock->sell_price);
                new_user_stock->quantity = quantity;
                new_user_stock->next = NULL;

                if (user_stock_head == NULL)
                {
                    user_stock_head = new_user_stock;
                }
                else
                {
                    UserStock *temp = user_stock_head;
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->next = new_user_stock;
                }
                user_balance -= (stock->buy_price * quantity);
                stock->quantity -= quantity;
                printf("Stock Bought Successfully\n");
            }
        }
    }
}
// -----------Buy Stock Function End----------------