#include <stdio.h>
#include <string.h>
#include "transactions.h"

void addTransaction(Transaction transactions[], int *count,
                    const char *type, double amount, double balanceAfter)
{
    if (*count >= MAX_TRANSACTIONS)
    {
        /* Remove the oldest transaction */
        for (int i = 1; i < MAX_TRANSACTIONS; i++)
        {
            transactions[i - 1] = transactions[i];
        }

        *count = MAX_TRANSACTIONS - 1;
    }

    strcpy(transactions[*count].type, type);
    transactions[*count].amount = amount;
    transactions[*count].balanceAfter = balanceAfter;

    (*count)++;
}

void displayTransactions(const Transaction transactions[], int count)
{
    printf("\n========================================\n");
    printf("           MINI STATEMENT\n");
    printf("========================================\n");

    if (count == 0)
    {
        printf("No transactions available.\n");
        printf("========================================\n");
        return;
    }

    printf("%-15s %-12s %-15s\n", "TYPE", "AMOUNT", "BALANCE");
    printf("----------------------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("%-15s Rs.%-9.2f Rs.%-10.2f\n",
               transactions[i].type,
               transactions[i].amount,
               transactions[i].balanceAfter);
    }

    printf("========================================\n");
}