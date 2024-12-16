#pragma once
#include "Library.h"
#include "Reader.h"
// Quản lý sách

#define MAX_BOOKS 100
#define MAX_LOANS 100
#define MAX_ISBN_PER_LOAN 10

struct Book{
    char ISBN[20];
    char Title[50];
    char Author[50];
    char Publisher[50];
    int PublishYear;
    char Category[50];
    float Price;
    int Quantity;
};

//Quản lí sách
void viewBooksList(Book books[MAX_BOOKS], int bookCount);
void addBook(int& n, Book books[MAX_BOOKS], int& bookCount);
void editBook(Book books[MAX_BOOKS], int bookCount);
void deleteBook(Book books[MAX_BOOKS], int& bookCount);
void printBookCatgorry();
void printBookInfo(int i, Book books[MAX_BOOKS]);
int searchBookByISBN(char isbn[], Book books[MAX_BOOKS], int bookCount);
int searchBookByTitle(char title[], Book books[MAX_BOOKS], int bookCount);
int totalBooks(int bookCount, Book books[MAX_BOOKS]);
void booksByCategory(Book books[MAX_BOOKS], int bookCount);
void readBook(const char* fileName, Book books[MAX_BOOKS], int& bookCount);
void writeBook(const char* fileName, Book books[MAX_BOOKS], int bookCount);


struct Loan{
    char ReaderID[20];
    char ReaderName[50];
    char IssueDate[20];
    char DueDate[20];
    char ReturnDate[20];
    char ISBN[MAX_ISBN_PER_LOAN][20];
    char BookName[MAX_ISBN_PER_LOAN][50];
    int BookCount;
};

// Lập phiếu mượn sách
int totalBooksOnLoan(Loan loans[MAX_LOANS], int loanCount);
void viewBooksOnLoan(int readerIndex, Loan loans[MAX_LOANS], int loanCount, Book books[MAX_BOOKS], int bookCount);
void printBookCatgorryOnLoan();
void printBookInfoOnLoan(int bookIndex, int readerIndex, Book books[MAX_BOOKS], Loan loans[MAX_LOANS]);
void createLoanSlip(Reader readers[MAX_READERS], int readerCount, Loan loans[MAX_LOANS], int& loanCount, Book books[MAX_BOOKS], int bookCount);
void createReturnSlip(Reader readers[MAX_READERS], int readerCount, Loan loans[MAX_LOANS], int& loanCount, Book books[MAX_BOOKS], int bookCount);
void printLoanCat();
void printLoanInfo(int i, Loan loans[MAX_LOANS]);
void lateReadersList(Loan loans[MAX_LOANS], int loanCount, Reader readers[MAX_READERS], int readerCount, Book books[MAX_BOOKS], int bookCount);

