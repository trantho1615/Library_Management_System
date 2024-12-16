#pragma once

// Quản lý độc giả
#define MAX_READERS 100

struct Reader{
    char ID[20];
    char Name[50];
    char CMND[20];
    char Birthday[20];
    char Gender[10];
    char Email[50];
    char Address[100];
    char IssueDate[20];
    char ExpiryDate[20];
};

void viewReadersList(Reader readers[MAX_READERS], int readerCount);
void addReader(int& n, Reader readers[MAX_READERS], int& readerCount);
void editReader(Reader readers[MAX_READERS], int readerCount);
void deleteReader(Reader readers[MAX_READERS], int& readerCount);
void printReaderCategory();
void printReaderInfo(int i, Reader readers[MAX_READERS]);
int searchReaderByCMND(char cmnd[], Reader readers[MAX_READERS], int readerCount);
int searchReaderByID(char id[], Reader readers[MAX_READERS], int readerCount);
int searchReaderByName(char name[], Reader readers[MAX_READERS], int readerCount);
int searchReaderByEmail(char email[], Reader readers[MAX_READERS], int readerCount);
int totalReaders(int readerCount);
void readersByGender(Reader readers[MAX_READERS], int readerCount);


void viewReadersList(Reader readers[MAX_READERS], int readerCount);
void addReader(int& n, Reader readers[MAX_READERS], int& readerCount);
void editReader(Reader readers[MAX_READERS], int readerCount);
void deleteReader(Reader readers[MAX_READERS], int& readerCount);
void printReaderCatgorry();
void printReaderInfo(int i, Reader readers[MAX_READERS]);
int searchReaderByCMND(char cmnd[], Reader readers[MAX_READERS], int readerCount);
int searchReaderByID(char id[], Reader readers[MAX_READERS], int readerCount);
int searchReaderByName(char name[], Reader readers[MAX_READERS], int readerCount);
int searchReaderByEmail(char email[], Reader readers[MAX_READERS], int readerCount);
int totalReaders(int readerCount);
void readersByGender(Reader readers[MAX_READERS], int readerCount);

void readReader(const char* fileName, Reader readers[MAX_READERS], int& readerCount);
void writeReader(const char* fileName, Reader readers[MAX_READERS], int readerCount);
