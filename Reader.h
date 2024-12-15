#pragma once

// Quản lý độc giả
#define MAX_READERS 100

void viewReadersList(char readerIDs[MAX_READERS][20], char readerNames[MAX_READERS][50], char readerCMNDs[MAX_READERS][20], char readerBirthdays[MAX_READERS][20], char readerGenders[MAX_READERS][10], char readerEmails[MAX_READERS][50], char readerAddresses[MAX_READERS][100], char readerIssueDates[MAX_READERS][20], char readerExpiryDates[MAX_READERS][20], int readerCount);
void addReader(int& n, char readerIDs[MAX_READERS][20], char readerNames[MAX_READERS][50], char readerCMNDs[MAX_READERS][20], char readerBirthdays[MAX_READERS][20], char readerGenders[MAX_READERS][10], char readerEmails[MAX_READERS][50], char readerAddresses[MAX_READERS][100], char readerIssueDates[MAX_READERS][20], char readerExpiryDates[MAX_READERS][20], int& readerCount);
void editReader(char readerIDs[MAX_READERS][20], char readerNames[MAX_READERS][50], char readerCMNDs[MAX_READERS][20], char readerBirthdays[MAX_READERS][20], char readerGenders[MAX_READERS][10], char readerEmails[MAX_READERS][50], char readerAddresses[MAX_READERS][100], char readerIssueDates[MAX_READERS][20], char readerExpiryDates[MAX_READERS][20], int readerCount);
void deleteReader(char readerIDs[MAX_READERS][20], char readerNames[MAX_READERS][50], char readerCMNDs[MAX_READERS][20], char readerBirthdays[MAX_READERS][20], char readerGenders[MAX_READERS][10], char readerEmails[MAX_READERS][50], char readerAddresses[MAX_READERS][100], char readerIssueDates[MAX_READERS][20], char readerExpiryDates[MAX_READERS][20], int& readerCount);
void printReaderCatgorry();
void printReaderInfo(int i, char readerIDs[MAX_READERS][20], char readerNames[MAX_READERS][50], char readerCMNDs[MAX_READERS][20], char readerBirthdays[MAX_READERS][20], char readerGenders[MAX_READERS][10], char readerEmails[MAX_READERS][50], char readerAddresses[MAX_READERS][100], char readerIssueDates[MAX_READERS][20], char readerExpiryDates[MAX_READERS][20]);
int searchReaderByCMND(char cmnd[], char readerCMNDs[MAX_READERS][20], int readerCount);
int searchReaderByID(char id[], char readerIDs[MAX_READERS][20], int readerCount);
int searchReaderByName(char name[], char readerNames[MAX_READERS][50], int readerCount);
int searchReaderByEmail(char email[], char readerEmails[MAX_READERS][50], int readerCount);
int totalReaders(int readerCount);
void readersByGender(char readerGenders[MAX_READERS][10], int readerCount);

// void readReader(const char* fileName, char readerIDs[MAX_READERS][20], char readerNames[MAX_READERS][50], char readerCMNDs[MAX_READERS][20], char readerBirthdays[MAX_READERS][20], char readerGenders[MAX_READERS][10], char readerEmails[MAX_READERS][50], char readerAddresses[MAX_READERS][100], char readerIssueDates[MAX_READERS][20], char readerExpiryDates[MAX_READERS][20], int& readerCount);
// void writeReader(const char* fileName, char readerIDs[MAX_READERS][20], char readerNames[MAX_READERS][50], char readerCMNDs[MAX_READERS][20], char readerBirthdays[MAX_READERS][20], char readerGenders[MAX_READERS][10], char readerEmails[MAX_READERS][50], char readerAddresses[MAX_READERS][100], char readerIssueDates[MAX_READERS][20], char readerExpiryDates[MAX_READERS][20], int readerCount);
