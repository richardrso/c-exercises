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
int isLoggedIn = 0;

void registerUser() {
    printf("Enter your name: ");
    while (scanf("%s", currentUser.name) != 1) {
        printf("Invalid input. Please enter a valid name: ");
        while(getchar() != '\n');
    }
    
    printf("Enter your email: ");
    while (scanf("%s", currentUser.email) != 1) {
        printf("Invalid input. Please enter a valid email: ");
        while(getchar() != '\n');
    }
    
    printf("Enter your password: ");
    while (scanf("%s", currentUser.password) != 1) {
        printf("Invalid input. Please enter a valid password: ");
        while(getchar() != '\n');
    }
    
    currentUser.balance = 0.0;
    printf("Registration Successful!\n");
}

void login() {
    char email[50], password[50];

    printf("Enter your email: ");
    while (scanf("%s", email) != 1) {
        printf("Invalid input. Please enter a valid email: ");
        while(getchar() != '\n');
    }
    
    printf("Enter your password: ");
    while (scanf("%s", password) != 1) {
        printf("Invalid input. Please enter a valid password: ");
        while(getchar() != '\n');
    }

    if (strcmp(email, currentUser.email) == 0 && strcmp(password, currentUser.password) == 0) {
        printf("Login Successful!\n");
        isLoggedIn = 1;
    } else {
        printf("Invalid email or password!\n");
    }
}

void showBalance() {
    if(isLoggedIn) {
        printf("Your balance is: %.2f\n", currentUser.balance);
    } else {
        printf("You need to log in first.\n");
    }
}

void deposit() {
    float amount;
    
    if(isLoggedIn) {
        printf("Enter amount to deposit: ");
        while (scanf("%f", &amount) != 1 || amount < 0) {
            printf("Invalid input. Please enter a positive number: ");
            while(getchar() != '\n');
        }
        
        currentUser.balance += amount;
        printf("Deposit Successful!\n");
        
    } else {
        printf("You need to log in first.\n");
    }
}

void withdraw() {
    float amount;
    
    if(isLoggedIn) {
        printf("Enter amount to withdraw: ");
        while (scanf("%f", &amount) != 1 || amount < 0 || amount > currentUser.balance) {
            if(amount > currentUser.balance){
                printf("Insufficient balance!\n");
            }else{
                printf("Invalid input. Please enter a positive number less than or equal to your balance: ");
            }
            while(getchar() != '\n');
        }
        
        currentUser.balance -= amount;
        printf("Withdrawal Successful!\n");
        
    } else {
        printf("You need to log in first.\n");
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n1. Register\n2. Login\n");
        
        if(isLoggedIn) {
            printf("3. Show Balance\n4. Deposit\n5. Withdraw\n6. Exit\n");
        } else {
            printf("3. Exit\n");
        }
        
        printf("Enter your choice: ");
        
        if(scanf("%d", &choice)!=1){
            printf("Invalid choice!\n");
            while(getchar() != '\n');
            continue;
        }

        switch(choice) {
            case 1:
                registerUser();
                break;
            case 2:
                login();
                break;
            case 3:
                if(isLoggedIn) {
                    showBalance();
                } else {
                    exit(0);
                }
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
                while(getchar() != '\n');
        }
    }

    return 0;
}