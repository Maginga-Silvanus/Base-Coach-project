#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to store user information
typedef struct user {
    char username[20];
    char password[20];
} user;

// A function to check if a username already exists in the file
int check_username(char *username) {
    FILE *fp = fopen("users.txt", "r"); // Open the file in read mode
    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }
    user u; // A temporary variable to store user information
    while (fread(&u, sizeof(user), 1, fp) == 1) { // Read the file until the end
        if (strcmp(u.username, username) == 0) { // Compare the usernames
            fclose(fp); // Close the file
            return 1; // Return 1 if the username exists
        }
    }
    fclose(fp); // Close the file
    return 0; // Return 0 if the username does not exist
}

// A function to register a new user
void register_user() {
    user u; // A variable to store user information
    printf("Enter a username: ");
    scanf("%s", u.username); // Read the username from the user
    while (check_username(u.username) == 1) { // Check if the username already exists
        printf("This username Already Exists. Please Try another one.\n");
        printf("Enter a username: ");
        scanf("%s", u.username); // Read another username from the user
    }
    printf("Enter a password: ");
    scanf("%s", u.password); // Read the password from the user
    FILE *fp = fopen("users.txt", "a"); // Open the file in append mode
    fwrite(&u, sizeof(user), 1, fp); // Write the user information to the file
    fclose(fp); // Close the file
    printf("Registration successful.\n");
}

// A function to login a user
void login_user() {
    char username[20]; // A variable to store the username
    char password[20]; // A variable to store the password
    printf("Enter your username: ");
    scanf("%s", username); // Read the username from the user
    printf("Enter your password: ");
    scanf("%s", password); // Read the password from the user
    FILE *fp = fopen("users.txt", "r"); // Open the file in read mode
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    user u; // A temporary variable to store user information
    int flag = 0; // A flag to indicate if the login is successful or not
    while (fread(&u, sizeof(user), 1, fp) == 1) { // Read the file until the end
        if (strcmp(u.username, username) == 0 && strcmp(u.password, password) == 0) { // Compare the usernames and passwords
            flag = 1; // Set the flag to 1 if they match
            break; // Break out of the loop
        }
    }
    fclose(fp); // Close the file
    if (flag == 1) { // If the flag is 1, login is successful
        printf("Login successful.\n");
        printf("Welcome %s!\n", username);
        // Do something after login here ...
		// Function to execute bus_details.c
 	} else { // If the flag is 0, login is unsuccessful
        printf("Invalid username or password.\n");
        printf("Please try again.\n");
 	}
}

// The main function of the program
int main() {
	   int choice; // A variable to store the user's choice
    do {
        printf("Welcome to Base Coach Booking system. \n");
        printf("Please How do we help you! \n");
        printf("-----------------------------\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("-----------------------------\n");
        printf("Select option >>");
        scanf("%d", &choice); // Read the choice from the user

        switch (choice) { // Execute different functions based on the choice
            case 1:
                register_user(); // Call the register_user function
                break;
            case 2:
                login_user(); // Call the login_user function
                break;

            case 3:
                printf("Thank you for Visiting Silva Cab system. Welcome again!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
  		    }

    } while (choice != 3); // Repeat until the user chooses to exit

    return 0;
}

