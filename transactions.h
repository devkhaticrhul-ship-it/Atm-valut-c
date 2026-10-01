#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#define MAX_TRANSACTIONS 20

typedef struct
{
    char type[20];
    double amount;
    double balanceAfter;
} Transaction;

/* Transaction operations */
void addTransaction(Transaction transactions[], int *count,
                    const char *type, double amount, double balanceAfter);

void displayTransactions(const Transaction transactions[], int count);

#endif