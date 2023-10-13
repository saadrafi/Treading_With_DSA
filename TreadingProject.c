#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stock Structure
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
float user_balance = 0;
float user_profit = 0;
typedef struct user_stock_node
{
    char name[20];
    float buy_price;
    float *sell_price;
    int quantity;
    struct user_stock_node *next;
} UserStock;

typedef struct transaction_node
{
    char name[20];
    float buy_or_sell_price;
    int quantity;
    float in_out;
    struct transaction_node *next;
} Transaction;

UserStock *user_stock_head = NULL;
Transaction *transaction_head = NULL;
// User Side Function Prototypes

void buy_stock();
void sell_stock();
void view_single_user_stocks(UserStock *user_stock);
void view_user_stocks(UserStock *head);
void view_available_stocks(Stock *head);
UserStock *is_stock_bought(char name[]);
void auto_suggest();
void remove_user_stock(UserStock *user_stock);
void view_transactions();
void add_transaction(char name[], float buy_or_sell_price, int quantity, float in_out);

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
                system("cls");
                printf("***********Welcome to User Side***********\n");
                printf("*\t\t1. Buy Stock\t\t\t*\n");
                printf("*\t\t2. Sell Stock\t\t\t*\n");
                printf("*\t\t3. View Stock\t\t\t*\n");
                printf("*\t\t4. Automated Trading Suggestion\t*\n");
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
                    system("cls");
                    sell_stock();
                    system("pause");
                    break;
                case 3:
                    system("cls");

                    system("pause");
                    break;
                case 4:
                    system("cls");
                    auto_suggest();
                    system("pause");

                    break;
                case 5:

                    system("cls");
                    view_transactions();
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
    if (stock_head == NULL)
    {
        printf("No Stocks Available\n");
        return;
    }
    if (user_balance == 0)
    {
        printf("Enter the amount to add to your account: ");
        enter_float("Enter only positive number.", &user_balance);
    }
    printf("Your Balance: %.2f\n", user_balance);
    view_available_stocks(stock_head);
    printf("\n***************Buy Stock****************\n");
    printf("Enter the name of the stock to buy: ");
    char stock_name[20];
    scanf("%s", stock_name);
    make_upper_case(stock_name);
    Stock *stock = is_stock_available(stock_name);
    if (stock == NULL || stock->quantity == 0)
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
            printf("Available Quantity is %d. Try again.....\n", stock->quantity);
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
                add_transaction(stock->name, -stock->buy_price, quantity, -(stock->buy_price * quantity));
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

// -----------Sell Stock Function Start----------------
void sell_stock()
{
    if (user_stock_head == NULL)
    {
        printf("Please buy stock first\n");
        return;
    }
    printf("Your Balance: %.2f\n", user_balance);
    view_user_stocks(user_stock_head);
    printf("\n***************Sell Stock****************\n");
    printf("Enter the name of the stock to sell: ");
    char stock_name[20];
    scanf("%s", stock_name);
    make_upper_case(stock_name);
    UserStock *user_stock = is_stock_bought(stock_name);
    Stock *stock = is_stock_available(stock_name);
    if (user_stock == NULL)
    {
        printf("Stock Not Available\n");
    }
    else
    {
        // print stock details
        printf("Stock Details\n");
        printf("Name\t\t|\tBuy Price\t|\tSell Price\t|\tQuantity\n");
        view_single_user_stocks(user_stock);
        printf("Enter the quantity to sell: ");
        int quantity;
        enter_int("Enter only positive number.", &quantity);
        if (quantity > user_stock->quantity)
        {
            printf("Stock Not Available\n");
        }
        else
        {
            user_profit += (stock->sell_price * quantity) - (user_stock->buy_price * quantity);
            user_balance += (stock->sell_price * quantity);
            user_stock->quantity -= quantity;
            stock->quantity += quantity;
            add_transaction(stock->name, stock->sell_price, quantity, stock->sell_price * quantity);
            if (user_stock->quantity == 0)
            {
                remove_user_stock(user_stock);
            }

            printf("Stock Sold Successfully\n");
        }
    }
}
// -----------Sell Stock Function End----------------

// -----------Is Stock Bought Function Start----------------

UserStock *is_stock_bought(char name[])
{
    UserStock *temp = user_stock_head;
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

// -----------Is Stock Bought Function End----------------

// -----------Remove User Stock Function Start----------------

void remove_user_stock(UserStock *user_stock)
{
    UserStock *temp = user_stock_head;
    if (temp == user_stock)
    {
        user_stock_head = user_stock_head->next;
        free(user_stock);
    }
    else
    {
        while (temp->next != user_stock)
        {
            temp = temp->next;
        }
        temp->next = user_stock->next;
        free(user_stock);
    }
}

// -----------Remove User Stock Function End----------------

// -----------View User Stock Function Start----------------

void view_single_user_stocks(UserStock *user_stock)
{
    printf("--------------------------------------------------------------------------------------------\n");
    printf("%s\t\t|\t%.2f\t\t|\t%.2f\t\t|\t%d\n", user_stock->name, user_stock->buy_price, *(user_stock->sell_price), user_stock->quantity);
}

void view_user_stocks(UserStock *head)
{
    printf("************************Purchased Stocks**************************\n|\n");
    printf("Name\t\t|\tBuy Price\t|\tSell Price\t|\tQuantity\n");

    UserStock *temp = head;
    if (temp == NULL)
    {
        printf("No Stocks Available\n");
    }
    while (temp != NULL)
    {
        view_single_user_stocks(temp);
        temp = temp->next;
    }
}

// -----------View User Stock Function End----------------

// -----------Add to Transactions Function Start----------------

void add_transaction(char name[], float buy_or_sell_price, int quantity, float in_out)
{
    Transaction *new_transaction = (Transaction *)malloc(sizeof(Transaction));
    strcpy(new_transaction->name, name);
    new_transaction->buy_or_sell_price = buy_or_sell_price;
    new_transaction->quantity = quantity;
    new_transaction->in_out = in_out;
    new_transaction->next = NULL;

    if (transaction_head == NULL)
    {
        transaction_head = new_transaction;
    }
    else
    {
        Transaction *temp = transaction_head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_transaction;
    }
}

// -----------Add to Transactions Function End----------------

// -----------View Transactions Function Start----------------

void view_transactions()
{
    printf("************************Transaction History**************************\n|\n");
    printf("---Balance: %.2f--- \t\t ---Profit: %.2f---\n", user_balance, user_profit);
    printf("Name\t\t|\tBuy\\Sell\t|\tQuantity\t|\tIn\\Out\n");
    Transaction *temp = transaction_head;
    if (temp == NULL)
    {
        printf("No Transactions Available\n");
    }
    while (temp != NULL)
    {
        printf("-------------------------------------------------------------------------------------------\n");
        printf("%s\t\t|\t%.2f\t\t|\t%d\t\t|\t%.2f\n", temp->name, temp->buy_or_sell_price, temp->quantity, temp->in_out);
        temp = temp->next;
    }
}

// -----------View Transactions Function End----------------

// -----------View Available Stocks Function Start----------------

void view_available_stocks(Stock *head)
{
    printf("************************Available Stocks**************************\n|\n");
    printf("Name\t\t|\tBuy Price\t|\tSell Price\t|\tQuantity\n");

    Stock *temp = head;
    if (temp == NULL)
    {
        printf("No Stocks Available\n");
    }
    while (temp != NULL)
    {
        if (temp->quantity > 0)
        {
            view_single_stock(temp);
        }
        temp = temp->next;
    }
}

// -----------View Available Stocks Function End----------------

// -----------Auto Suggest Function Start----------------

void auto_suggest()
{
    printf("***************Auto Suggest****************\n");
    printf("Enter the amount to invest: ");
    float amount;
    enter_float("Enter only positive number.", &amount);

    struct suggestion_node
    {
        char name[20];
        float buy_price;
        float sell_price;
        int quantity;
        float profit;
        float ratio;
        struct suggestion_node *next;
    };
    struct suggestion_node *suggestion_head = NULL;

    Stock *temp = stock_head;
    while (temp != NULL)
    {
        if (temp->buy_price <= amount)
        {
            struct suggestion_node *new_suggestion = (struct suggestion_node *)malloc(sizeof(struct suggestion_node));
            strcpy(new_suggestion->name, temp->name);
            new_suggestion->buy_price = temp->buy_price;
            new_suggestion->sell_price = temp->sell_price;
            new_suggestion->quantity = temp->quantity;
            new_suggestion->profit = temp->sell_price - temp->buy_price;
            new_suggestion->ratio = new_suggestion->profit / temp->buy_price;
            new_suggestion->next = NULL;

            if (suggestion_head == NULL)
            {
                suggestion_head = new_suggestion;
            }
            else
            {
                struct suggestion_node *temp = suggestion_head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = new_suggestion;
            }
        }
        temp = temp->next;
    }

    struct suggestion_node *current = suggestion_head;
    while (current != NULL)
    {
        struct suggestion_node *max = current;
        struct suggestion_node *temp = current->next;

        while (temp != NULL)
        {
            if (temp->ratio > max->ratio)
            {
                max = temp;
            }
            temp = temp->next;
        }

        if (max != current)
        {
            // Swap the data within the nodes for buy_price
            char tempName[20];
            float tempBuyPrice, tempSellPrice;
            int tempQuantity;
            float tempProfit, tempRatio;

            strcpy(tempName, current->name);
            tempBuyPrice = current->buy_price;
            tempSellPrice = current->sell_price;
            tempQuantity = current->quantity;
            tempProfit = current->profit;
            tempRatio = current->ratio;

            strcpy(current->name, max->name);
            current->buy_price = max->buy_price;
            current->sell_price = max->sell_price;
            current->quantity = max->quantity;
            current->profit = max->profit;
            current->ratio = max->ratio;

            strcpy(max->name, tempName);
            max->buy_price = tempBuyPrice;
            max->sell_price = tempSellPrice;
            max->quantity = tempQuantity;
            max->profit = tempProfit;
            max->ratio = tempRatio;
        }

        current = current->next;
    }

    double total_profit = 0;
    struct suggestion_node *temp1 = suggestion_head;
    if (temp1 == NULL)
    {
        printf("No Stocks Available\n");
    }
    printf("------------------------------------------------------------------------------------------------\n");
    printf("Name\t\t|\tBuy\t|\tSell\t|    Quantity   |\tProfit\t|\tRemaining\n");
    while (temp1 != NULL && amount > 0)
    {
        int q;
        double profit = 0;
        if (temp1->buy_price == amount)
        {
            q = 1;
            profit = temp1->profit;
            amount = 0;
            total_profit += profit;
        }
        else
        {
            q = amount / temp1->buy_price;

            if (q > temp1->quantity)
            {
                q = temp1->quantity;
            }
            profit = q * temp1->profit;
            amount -= q * temp1->buy_price;
            total_profit += profit;
        }

        if (q != 0)
        {
            printf("--------------------------------------------------------------------------------------------\n");
            printf("%s\t\t|\t%.2f\t|\t%.2f\t|\t%d\t|\t%.2f\t|\t%.2f\n", temp1->name, temp1->buy_price, temp1->sell_price, q, profit, amount);
        }

        temp1 = temp1->next;
    }

    printf("------------------------------------------------------------------------------------------------\n");
    printf("Remaining amount: %.2f\n", amount);
    printf("Total Profit: %.2f\n", total_profit);

    // Free the memory
    struct suggestion_node *temp2 = suggestion_head;
    while (temp2 != NULL)
    {
        struct suggestion_node *temp3 = temp2;
        temp2 = temp2->next;
        free(temp3);
    }
}
// -----------Auto Suggest Function End----------------