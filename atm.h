#ifndef ATM_H
#define ATM_H

#define MAX_TRANSACTIONS 20
#define MAX_NAME_LENGTH 50

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int accountNumber;
    int pin;
    double balance;
    double dailyWithdrawn;
} Account;

/* Authentication */
int authenticate(Account *account);

/* ATM operations */
void displayBalance(const Account *account);
void withdrawMoney(Account *account);
void depositMoney(Account *account);
void changePIN(Account *account);

/* Account information */
void displayAccountInfo(const Account *account);

/* Utility */
void clearInputBuffer(void);
void pauseScreen(void);

#endif