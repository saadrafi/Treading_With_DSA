# Stock Management System

This is a simple Stock (Treading) Management System implemented in C. The system provides functionalities for both administrators and users to manage and track stocks, buy and sell stocks, view transaction history, and get automated trading suggestions.

## Features

### Admin Side

1. **Add Stock:** Allows the administrator to add new stocks to the system, providing details such as name, buy price, sell price, and quantity.

2. **Update Stock:** Enables the administrator to update the details of existing stocks, including buy price, sell price, and quantity.

3. **Delete Stock:** Allows the administrator to remove a stock from the system.

4. **View Stock:** Displays a list of all available stocks with their details.

### User Side

1. **Buy Stock:** Users can buy stocks by specifying the stock name and quantity. The system checks for sufficient balance and updates the user's portfolio.

2. **Sell Stock:** Users can sell stocks from their portfolio, and the system updates their balance and transaction history accordingly.

3. **View Stock By:** Users can view available stocks sorted by either buying price or selling price.

4. **Automated Trading Suggestion:** Provides an automated suggestion for stock purchases based on the available budget, maximizing potential profit.

5. **View Transaction History:** Users can view a history of their transactions, including buy/sell actions, quantity, and financial impact.

## How to Run
```bash
  git clone https://github.com/saadrafi/Treading_With_DSA.git
```
```bash
  gcc TreadingProject.c -o TreadingProject
```

```bash
  ./TreadingProject
```
   
