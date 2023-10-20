#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    
    
    
};
struct UserData{
    int flag;
    
};
union Users{
    struct  UserData data;  
};
union Users user;
struct User users[MAX_USERS];
int numUsers = 0;
int flagValue;
void registerUser() {
    if (numUsers >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    struct User newUser;
    
    

    printf("Enter username: ");
    scanf("%s", newUser.username);

    printf("Enter password: ");
    scanf("%s", newUser.password);
    printf("Enter The Flag value(0 or 1): ");
    scanf("%d",&flagValue);
    
    user.data.flag=flagValue;
   
    users[numUsers] = newUser;
    numUsers++;

    printf("Registration successful.\n");
}

void loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0 &&user.data.flag==1) {
            printf("Login successful.\n");
            return;
        }else if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0 && user.data.flag==0 )
        {
            printf("Login failed.\n");
        }
        
    }

   printf("Invalid username or password or user not active.\n");
}

int main() {
   int choice;

   do {
       printf("\n1. Register\n");
       printf("2. Login\n");
       printf("3. Exit\n");

       printf("\nEnter your choice: ");
       scanf("%d", &choice);

       switch(choice) {
           case 1:
               registerUser();
               break;
           case 2:
               loginUser();
               break;
           case 3:
               printf("Exiting...\n");
               break;
           default:
               printf("Invalid choice. Please try again.\n");
       }
   } while(choice != 3);

   return 0;
}
