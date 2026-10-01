#include <stdio.h>
#include "atm.h"

#define DAILY_WITHDRAW_LIMIT 20000.0
#define MIN_BALANCE 500.0

int authenticate(Account *account)
{
    int enteredPIN;
    int attempts = 0;

    printf("\n========================================\n");
    printf("             ATM//VAULT\n");
    printf("          SECURE LOGIN\n");
    printf("========================================\n");

    while (attempts < 3)
    {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &enteredPIN);
        clearInputBuffer();

        if (enteredPIN == account->pin)
        {
            printf("\nAuthentication successful.\n");
            printf("Welcome, %s!\n", account->name);
            return 1;
        }

        attempts++;

        if (attempts < 3)
        {
            printf("Incorrect PIN. Attempts remaining: %d\n",
                   3 - attempts);
        }
    }

    printf("\nToo many incorrect attempts.\n");
    printf("Your account has been locked for this session.\n");

    return 0;
}

void displayBalance(const Account *account)
{
    printf("\n========================================\n");
    printf("           ACCOUNT BALANCE\n");
    printf("========================================\n");
    printf("Account Number : %d\n", account->accountNumber);
    printf("Available Balance : Rs. %.2f\n", account->balance);
    printf("========================================\n");
}

void withdrawMoney(Account *account)
{
    double amount;

    printf("\n========================================\n");
    printf("            CASH WITHDRAWAL\n");
    printf("========================================\n");

    printf("Enter amount to withdraw: Rs. ");
    scanf("%lf", &amount);
    clearInputBuffer();

    if (amount <= 0)
    {
        printf("\nInvalid amount.\n");
        return;
    }

    if (amount > DAILY_WITHDRAW_LIMIT - account->dailyWithdrawn)
    {
        printf("\nDaily withdrawal limit exceeded.\n");
        printf("Remaining limit: Rs. %.2f\n",
               DAILY_WITHDRAW_LIMIT - account->dailyWithdrawn);
        return;
    }

    if (amount > account->balance - MIN_BALANCE)
    {
        printf("\nInsufficient balance.\n");
        printf("Minimum balance of Rs. %.2f must be maintained.\n",
               MIN_BALANCE);
        return;
    }

    account->balance -= amount;
    account->dailyWithdrawn += amount;

    printf("\nWithdrawal successful.\n");
    printf("Amount withdrawn : Rs. %.2f\n", amount);
    printf("Remaining balance: Rs. %.2f\n", account->balance);
}

void depositMoney(Account *account)
{
    double amount;

    printf("\n========================================\n");
    printf("             CASH DEPOSIT\n");
    printf("========================================\n");

    printf("Enter amount to deposit: Rs. ");
    scanf("%lf", &amount);
    clearInputBuffer();

    if (amount <= 0)
    {
        printf("\nInvalid amount.\n");
        return;
    }

    account->balance += amount;

    printf("\nDeposit successful.\n");
    printf("Amount deposited : Rs. %.2f\n", amount);
    printf("New balance      : Rs. %.2f\n", account->balance);
}

void changePIN(Account *account)
{
    int oldPIN;
    int newPIN;
    int confirmPIN;

    printf("\n========================================\n");
    printf("              CHANGE PIN\n");
    printf("========================================\n");

    printf("Enter current PIN: ");
    scanf("%d", &oldPIN);
    clearInputBuffer();

    if (oldPIN != account->pin)
    {
        printf("\nIncorrect current PIN.\n");
        return;
    }

    printf("Enter new 4-digit PIN: ");
    scanf("%d", &newPIN);
    clearInputBuffer();

    if (newPIN < 1000 || newPIN > 9999)
    {
        printf("\nPIN must contain exactly 4 digits.\n");
        return;
    }

    printf("Confirm new PIN: ");
    scanf("%d", &confirmPIN);
    clearInputBuffer();

    if (newPIN != confirmPIN)
    {
        printf("\nPIN confirmation does not match.\n");
        return;
    }

    account->pin = newPIN;

    printf("\nPIN changed successfully.\n");
}

void displayAccountInfo(const Account *account)
{
    printf("\n========================================\n");
    printf("           ACCOUNT PROFILE\n");
    printf("========================================\n");
    printf("Account Holder : %s\n", account->name);
    printf("Account Number : %d\n", account->accountNumber);
    printf("Balance        : Rs. %.2f\n", account->balance);
    printf("Daily Withdraw : Rs. %.2f / Rs. %.2f\n",
           account->dailyWithdrawn,
           DAILY_WITHDRAW_LIMIT);
    printf("========================================\n");
}

void clearInputBuffer(void)
{
    int character;

    while ((character = getchar()) != '\n' && character != EOF)
    {
        /* Clear invalid input */
    }
}

void pauseScreen(void)
{
    printf("\nPress ENTER to continue...");
    getchar();
}