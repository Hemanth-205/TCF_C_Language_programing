#include <stdio.h>

#define MAX_TRANSACTIONS 100

// Structure for transaction
typedef struct {
    int type; // 1 for deposit, 2 for withdrawal
    float amount;
    float balance;
} Transaction;

// Global variables
float balance = 1000.0; // Initial balance
Transaction transactions[MAX_TRANSACTIONS];
int transactionCount = 0;

// Function prototypes
void displayMenu();
void deposit();
void withdraw();
void checkBalance();
void displayTransactions();
void addTransaction(int type, float amount);

int main() {
    int choice;
    
    printf("=== SIMPLE BANKING SYSTEM ===\n");
    printf("Initial balance: $%.2f\n", balance);
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                deposit();
                break;
            case 2:
                withdraw();
                break;
            case 3:
                checkBalance();
                break;
            case 4:
                displayTransactions();
                break;
            case 5:
                printf("Thank you for using our banking system!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);
    
    return 0;
}

void displayMenu() {
    printf("\n1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Transaction History\n");
    printf("5. Exit\n");
    printf("============================\n");
}

void deposit() {
    float amount;
    
    printf("Enter amount to deposit: $");
    scanf("%f", &amount);
    
    if (amount > 0) {
        balance += amount;
        addTransaction(1, amount);
        printf("Deposit successful! New balance: $%.2f\n", balance);
    } else {
        printf("Invalid amount! Please enter a positive value.\n");
    }
}

void withdraw() {
    float amount;
    
    printf("Enter amount to withdraw: $");
    scanf("%f", &amount);
    
    if (amount > 0) {
        if (amount <= balance) {
            balance -= amount;
            addTransaction(2, amount);
            printf("Withdrawal successful! New balance: $%.2f\n", balance);
        } else {
            printf("Insufficient funds! Current balance: $%.2f\n", balance);
        }
    } else {
        printf("Invalid amount! Please enter a positive value.\n");
    }
}

void checkBalance() {
    printf("Current balance: $%.2f\n", balance);
}

void addTransaction(int type, float amount) {
    if (transactionCount < MAX_TRANSACTIONS) {
        transactions[transactionCount].type = type;
        transactions[transactionCount].amount = amount;
        transactions[transactionCount].balance = balance;
        transactionCount++;
    }
}

void displayTransactions() {
    if (transactionCount == 0) {
        printf("No transactions found!\n");
        return;
    }
    
    printf("\n=== TRANSACTION HISTORY ===\n");
    printf("Type\t\tAmount\t\tBalance\n");
    printf("----\t\t------\t\t-------\n");
    
    for (int i = 0; i < transactionCount; i++) {
        if (transactions[i].type == 1) {
            printf("Deposit\t\t$%.2f\t\t$%.2f\n", 
                   transactions[i].amount, transactions[i].balance);
        } else {
            printf("Withdrawal\t$%.2f\t\t$%.2f\n", 
                   transactions[i].amount, transactions[i].balance);
        }
    }
    
    printf("\nTotal transactions: %d\n", transactionCount);
} 