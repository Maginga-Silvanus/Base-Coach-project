#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUSES 10
#define MAX_SEATS 40

typedef struct Bus {
    char name[20];
    char route[30];
    char time[10];
    int seats[MAX_SEATS];
} Bus;

void initializeBus(Bus *bus, const char *name, const char *route, const char *time) {
    strcpy(bus->name, name);
    strcpy(bus->route, route);
    strcpy(bus->time, time);
    for (int i = 0; i < MAX_SEATS; i++) {
        bus->seats[i] = 0; // 0 indicates an empty seat
    }
}

void displaySeatArrangement(const Bus *bus) {
    printf("Seat Arrangement for Bus: %s\n", bus->name);
    printf("Route: %s\n", bus->route);
    printf("Time: %s\n", bus->time);
    for (int i = 0; i < MAX_SEATS; i++) {
        if (i % 4 == 0) {
            printf("\n");
        }
        if (bus->seats[i] == 0) {
            printf("O ");
        } else {
            printf("X ");
        }
    }
    printf("\n");
}

void bookSeat(Bus *bus, int seatNumber) {
    if (seatNumber >= 1 && seatNumber <= MAX_SEATS) {
        if (bus->seats[seatNumber - 1] == 0) {
            bus->seats[seatNumber - 1] = 1; // Mark the seat as booked (1)
            printf("Seat %d has been booked.\n", seatNumber);
        } else {
            printf("Seat %d is already booked.\n", seatNumber);
        }
    } else {
        printf("Invalid seat number.\n");
    }
}

int main_bus() {
    Bus buses[MAX_BUSES];
    int busCount = 0;

    int choice;
    do {
        printf("Base Coach Booking System\n");
        printf("--------------------------------\n");
        printf("1. Add a Bus\n");
        printf("2. View Available Buses\n");
        printf("3. View Bus Seat Arrangement\n");
        printf("4. Book a Seat\n");
        printf("5. Exit\n");
         printf("--------------------------------\n");
        printf("Select option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (busCount < MAX_BUSES) {
                    char name[20];
                    char route[30];
                    char time[10];
                    printf("Enter Bus Name: ");
                    scanf("%s", name);
                    printf("Enter Bus Route: ");
                    scanf("%s", route);
                    printf("Enter Departure Time: ");
                    scanf("%s", time);
                    initializeBus(&buses[busCount], name, route, time);
                    busCount++;
                    printf("Bus added successfully!\n");
                } else {
                    printf("Maximum number of buses reached.\n");
                }
                break;
            case 2:
                if (busCount > 0) {
                    printf("Available Buses:\n");
                    for (int i = 0; i < busCount; i++) {
                        printf("%d. %s (Route: %s, Time: %s)\n", i + 1, buses[i].name, buses[i].route, buses[i].time);
                    }
                } else {
                    printf("No buses added yet.\n");
                }
                break;
            case 3:
                if (busCount > 0) {
                    int busIndex;
                    printf("Select a Bus (1-%d): ", busCount);
                    scanf("%d", &busIndex);
                    if (busIndex >= 1 && busIndex <= busCount) {
                        displaySeatArrangement(&buses[busIndex - 1]);
                    } else {
                        printf("Invalid bus selection.\n");
                    }
                } else {
                    printf("No buses added yet.\n");
                }
                break;
            case 4:
                if (busCount > 0) {
                    int busIndex;
                    printf("Select a Bus (1-%d): ", busCount);
                    scanf("%d", &busIndex);
                    if (busIndex >= 1 && busIndex <= busCount) {
                        int seatNumber;
                        printf("Enter the seat number to book: ");
                        scanf("%d", &seatNumber);
                        bookSeat(&buses[busIndex - 1], seatNumber);
                    } else {
                        printf("Invalid bus selection.\n");
                    }
                } else {
                    printf("No buses added yet.\n");
                }
                break;
            case 5:
                printf("Thank you for using the Base Coach Booking System. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

