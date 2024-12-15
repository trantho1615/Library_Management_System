#pragma once
#include "Library.h"
#include "Reader.h"
// Quản lý sách

#define MAX_BOOKS 100
#define MAX_LOANS 100
#define MAX_ISBN_PER_LOAN 10

void viewBooksList(char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS], int Quantities[MAX_BOOKS], int bookCount);
void addBook(int n, char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS], int Quantities[MAX_BOOKS], int& bookCount);
void editBook(char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS], int Quantities[MAX_BOOKS], int bookCount);
void deleteBook(char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS], int Quantities[MAX_BOOKS], int& bookCount);
void printBookCatgorry();
void printBookInfo(int i, char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS]);
int searchBookByISBN(char isbn[], char ISBN[MAX_BOOKS][20], int bookCount);
int searchBookByTitle(char title[], char Titles[MAX_BOOKS][50], int bookCount);
int totalBooks(int bookCount, int Quantities[MAX_BOOKS]);
void booksByCategory(char bookCategories[MAX_BOOKS][50], int bookCount);
// void readBook(const char* fileName, char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS], int Quantities[MAX_BOOKS], int& bookCount);
// void writeBook(const char* fileName, char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS], int Quantities[MAX_BOOKS], int bookCount);
// Lập phiếu mượn sách
int totalBooksOnLoan(int loanBookCounts[MAX_LOANS]);
void viewBooksOnLoan(int readerIndex, char loanReaderIDs[MAX_LOANS][20], char loanReaderNames[MAX_LOANS][50], char loanIssueDates[MAX_LOANS][20], char loanDueDates[MAX_LOANS][20], char loanReturnDates[MAX_LOANS][20], char loanISBN[MAX_LOANS][MAX_ISBN_PER_LOAN][20], int loanBookCounts[MAX_LOANS], int loanCount, char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS], int Quantities[MAX_BOOKS], int bookCount);
void printBookCatgorryOnLoan();
void printBookInfoOnLoan(int bookIndex, int readerIndex, char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS], char IssueDates[MAX_BOOKS][20], char ExpiryDates[MAX_BOOKS][20], char ReturnDates[MAX_BOOKS][20]);
void createLoanSlip(char readerNames[MAX_READERS][50], char readerIDs[MAX_READERS][20], char readerCMNDs[MAX_READERS][20], int readerCount, char loanReaderIDs[MAX_LOANS][20], char loanReaderNames[MAX_LOANS][50], char loanIssueDates[MAX_LOANS][20], char loanDueDates[MAX_LOANS][20], char loanReturnDates[MAX_LOANS][20], char loanISBN[MAX_LOANS][MAX_ISBN_PER_LOAN][20], int loanBookCounts[MAX_LOANS], int& loanCount, char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS], int Quantities[MAX_BOOKS], int bookCount);
void createReturnSlip(char readerNames[MAX_READERS][50], char readerCMNDs[MAX_READERS][20], int readerCount, char loanReaderIDs[MAX_LOANS][20], char loanReaderNames[MAX_LOANS][50], char loanIssueDates[MAX_LOANS][20], char loanDueDates[MAX_LOANS][20], char loanReturnDates[MAX_LOANS][20], char loanISBN[MAX_LOANS][MAX_ISBN_PER_LOAN][20], int loanBookCounts[MAX_LOANS], int& loanCount, char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS], int Quantities[MAX_BOOKS], int bookCount);

void printLoanCat();
void printLoanInfo(int i, char loanReaderIDs[MAX_LOANS][20], char loanReaderNames[MAX_LOANS][50], char loanIssueDates[MAX_LOANS][20], char loanDueDates[MAX_LOANS][20], char loanReturnDates[MAX_LOANS][20]);
void lateReadersList(char readerIDs[MAX_READERS][20], char readerNames[MAX_READERS][50], char readerCMNDs[MAX_READERS][20], char readerBirthdays[MAX_READERS][20], char readerGenders[MAX_READERS][10], char readerEmails[MAX_READERS][50], char readerAddresses[MAX_READERS][100], char readerIssueDates[MAX_READERS][20], char readerExpiryDates[MAX_READERS][20], int readerCount, char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS], int Quantities[MAX_BOOKS], int bookCount, char loanReaderIDs[MAX_LOANS][20], char loanReaderNames[MAX_LOANS][50], char loanIssueDates[MAX_LOANS][20], char loanDueDates[MAX_LOANS][20], char loanReturnDates[MAX_LOANS][20], char loanISBN[MAX_LOANS][MAX_ISBN_PER_LOAN][20], char loanBookNames[MAX_LOANS][MAX_ISBN_PER_LOAN][50], int loanBookCounts[MAX_LOANS], int loanCount);

