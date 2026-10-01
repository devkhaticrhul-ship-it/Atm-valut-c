#include <stdio.h>
#include "atm.h"
#include "transactions.h"

void displayWelcome(void);
void displayMenu(void);

int main(void)
{
    Account account = {
        "Rahul Kumar",
        10010001,
        1234,
        25000.00,
        0.00
    };

    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount = 0;
    int choice;

    displayWelcome();

    if (!authenticate(&account))
    {
        printf("\nThank you for using ATM//VAULT.\n");
        return 0;
    }

    do
    {
        displayMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice)
        {
            case 1:
                displayBalance(&account);
                pauseScreen();
                break;

            case 2:
            {
                double oldBalance = account.balance;

                withdrawMoney(&account);

                if (account.balance != oldBalance)
                {
                    addTransaction(
                        transactions,
                        &transactionCount,
                        "WITHDRAWAL",
                        oldBalance - account.balance,
                        account.balance
                    );
                }

                pauseScreen();
                break;
            }

            case 3:
            {
                double oldBalance = account.balance;

                depositMoney(&account);

                if (account.balance != oldBalance)
                {
                    addTransaction(
                        transactions,
                        &transactionCount,
                        "DEPOSIT",
                        account.balance - oldBalance,
                        account.balance
                    );
                }

                pauseScreen();
                break;
            }

            case 4:
                displayTransactions(
                    transactions,
                    transactionCount
                );
                pauseScreen();
                break;

            case 5:
                changePIN(&account);
                pauseScreen();
                break;

            case 6:
                displayAccountInfo(&account);
                pauseScreen();
                break;

            case 7:
                printf("\n========================================\n");
                printf("          SESSION TERMINATED\n");
                printf("========================================\n");
                printf("Please collect your card.\n");
                printf("Thank you for using ATM//VAULT.\n");
                printf("Have a great day!\n");
                printf("========================================\n");
                break;

            default:
                printf("\nInvalid choice.\n");
                printf("Please select an option from 1 to 7.\n");
                pauseScreen();
        }

    } while (choice != 7);

    return 0;
}

void displayWelcome(void)
{
    printf("\n");
    printf("========================================\n");
    printf("              ATM//VAULT\n");
    printf("       SECURE BANKING SIMULATOR\n");
    printf("========================================\n");
    printf("          Welcome to the ATM\n");
    printf("========================================\n");
}

void displayMenu(void)
{
    printf("\n========================================\n");
    printf("              ATM MAIN MENU\n");
    printf("========================================\n");
    printf("1. Check Balance\n");
    printf("2. Withdraw Money\n");
    printf("3. Deposit Money\n");
    printf("4. Mini Statement\n");
    printf("5. Change PIN\n");
    printf("6. Account Profile\n");
    printf("7. Exit\n");
    printf("========================================\n");
}