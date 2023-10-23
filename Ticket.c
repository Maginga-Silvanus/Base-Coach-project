#include <stdio.h>

// Function to get customer details
void getCustomerDetails(char *name, int *age, char *gender, char *destination, char *date, int *ticketNumber) {
    printf("Enter Customer Details:\n");
    printf("Name: ");
    scanf("%s", name);
    printf("Age: ");
    scanf("%d", age);
    printf("Gender: ");
    scanf("%s", gender);
    printf("Destination: ");
    scanf("%s", destination);
    printf("Date of Travel: ");
    scanf("%s", date);
    printf("Ticket Number: ");
    scanf("%d", ticketNumber);
}

// Function to print the bus ticket
void printBusTicket(char *name, int age, char *gender, char *destination, char *date, int ticketNumber) {
    printf("Here is your ticket for Base Coach\n");
	printf("\n");
    printf("------------------------------\n");
    printf("|      Base Coach Ticket      |\n");
    printf("------------------------------\n");
    printf("| Name: %20s  |\n", name);
    printf("| Age: %21d  |\n", age);
    printf("| Gender: %18s  |\n", gender);
    printf("| Destination: %13s  |\n", destination);
    printf("| Date of Travel: %10s  |\n", date);
    printf("| Ticket Number: %12d  |\n", ticketNumber);
    printf("------------------------------\n");
}

int main_ticket() {
    char name[50], gender[10], destination[50], date[20];
    int age, ticketNumber;

    getCustomerDetails(name, &age, gender, destination, date, &ticketNumber);
    printBusTicket(name, age, gender, destination, date, ticketNumber);

    return 0;
}

