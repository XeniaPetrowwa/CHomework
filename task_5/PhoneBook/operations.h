#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define FILENAME "phoneBook.txt"

typedef struct {
    char name[50];
    char phone[15];
} PhoneBookEntry;

extern PhoneBookEntry phonebook[MAX_ENTRIES];
extern int countOfEntries;

void loadData(void);
void saveData(void);
void addEntry(void);
void printEntries(void);
void findPhoneByName(void);
void findNameByPhone(void);
void choosingAnAction(void);
