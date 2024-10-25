#include "operations.h"

PhoneBookEntry phonebook[MAX_ENTRIES];
int countOfEntries = 0;

void choosingAnAction(void) {
    int choice = 0;
    do {
        printf("Select an action:\n");
        printf("0 - Exit\n");
        printf("1 - Add an entry\n");
        printf("2 - Printing all records\n");
        printf("3 - Find a phone by name\n");
        printf("4 - Find a name by phone\n");
        printf("5 - Save data to a file\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 0:
                printf("Exit...\n");
                break;
            case 1:
                addEntry();
                break;
            case 2:
                printEntries();
                break;
            case 3:
                findPhoneByName();
                break;
            case 4:
                findNameByPhone();
                break;
            case 5:
                saveData();
                printf("The data is saved!\n");
                break;
            default:
                printf("There is no such action\n");
        }
    } while (choice != 0);
}

void loadData(void) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("File not found!\n");
        return;
    }
    
    while (countOfEntries < MAX_ENTRIES && fscanf(file, "%49s %14s",
            phonebook[countOfEntries].name, phonebook[countOfEntries].phone) == 2) {
            countOfEntries++;
    }
    fclose(file);
}

void saveData(void) {
    FILE *file = fopen(FILENAME, "a");
    for (int i = 0; i < countOfEntries; i++) {
        fprintf(file, "%s %s\n", phonebook[i].name, phonebook[i].phone);
    }
    fclose(file);
}

void addEntry(void) {
    if (countOfEntries >= MAX_ENTRIES) {
        printf("The directory is full. You cannot add a new entry.\n");
        return;
    }
    printf("Enter a name: ");
    scanf("%49s", phonebook[countOfEntries].name);
    
    printf("Enter the phone number: ");
    scanf("%14s", phonebook[countOfEntries].phone);
    
    countOfEntries++;
    printf("An entry has been added!\n");
}

void printEntries(void) {
    if (countOfEntries == 0) {
        printf("The directory is empty\n");
        return;
    }
    printf("List of entries:\n");
    for (int i = 0; i < countOfEntries; i++) {
        printf("%s - %s\n", phonebook[i].name, phonebook[i].phone);
    }
}

void findPhoneByName(void) {
    char name[50];
    printf("Enter a name: ");
    scanf("%49s", name);
    for (int i = 0; i < countOfEntries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Phone number for %s: %s\n", name, phonebook[i].phone);
            return;
        }
    }
    printf("The name was not found\n");
}

void findNameByPhone(void) {
    char phone[15];
    printf("Enter the phone number: ");
    scanf("%14s", phone);
    for (int i = 0; i < countOfEntries; i++) {
        if (strcmp(phonebook[i].phone, phone) == 0) {
            printf("Name for %s: %s\n", phone, phonebook[i].name);
            return;
        }
    }
    printf("The number was not found\n");
}
