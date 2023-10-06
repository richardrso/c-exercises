#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char email[50];
    char password[50];
    float balance;
} User;

User currentUser;

void registerUser() {
    printf("Enter your name: ");
    scanf("%s", currentUser.name);
    printf("Enter your email: ");
    scanf("%s", currentUser.email);
    printf("Enter your password: ");
    scanf("%s", currentUser.password);
    currentUser.balance = 0.0;
    printf("Registration Successful!\n");
}

void login() {
    char email[50], password[50];

    printf("Enter your email: ");
    scanf("%s", email);
    printf("Enter your password: ");
    scanf("%s", password);

    if (strcmp(email, currentUser.email) == 0 && strcmp(password, currentUser.password) == 0) {
        printf("Login Successful!\n");
    } else {
        printf("Invalid email or password!\n");
    }
}

void showBalance() {
    printf("Your balance is: %.2f\n", currentUser.balance);
}

void deposit() {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    currentUser.balance += amount;
    printf("Deposit Successful!\n");
}

void withdraw() {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= currentUser.balance) {
        currentUser.balance -= amount;
        printf("Withdrawal Successful!\n");
    } else {
        printf("Insufficient balance!\n");
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n1. Register\n2. Login\n3. Show Balance\n4. Deposit\n5. Withdraw\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                registerUser();
                break;
            case 2:
                login();
                break;
            case 3:
                showBalance();
                break;
            case 4:
                deposit();
                break;
            case 5:
                withdraw();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}