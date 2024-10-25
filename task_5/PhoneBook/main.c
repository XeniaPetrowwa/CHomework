#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "operations.h"

bool testAddEntry(void);
bool testFindPhoneByName(void);

int main(void) {
    if (testAddEntry() && testFindPhoneByName()) {
        printf("Tests passed!\n");
    }
    
    loadData();
    choosingAnAction();
    return 0;
}

bool testAddEntry(void) {
    countOfEntries = 0;
    
    strcpy(phonebook[countOfEntries].name, "Alice");
    strcpy(phonebook[countOfEntries].phone, "+71234567890");
    countOfEntries++;
    
    return (strcmp(phonebook[1].name, "Alice") == 0 && strcmp(phonebook[1].phone, "+71234567890") == 0);
}

bool testFindPhoneByName(void) {
    countOfEntries = 1;

    strcpy(phonebook[0].name, "Alice");
    strcpy(phonebook[0].phone, "+71234567890");
    
    return (strcmp(phonebook[0].phone, "1234567890") == 0);
}
