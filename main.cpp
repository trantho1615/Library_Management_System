#include "Library.h"
#include "Reader.h"
#include "Book.h"
#include "ultilities.h"

int main() {
    // Quản lý độc giả
    Reader readers[MAX_READERS] = {
        {"23127264", "Tran Tho", "058205001180", "16/01/2005", "Male", "tholazdo@gmail.com", "21/21 Tu Lap, P4, Q.Tan Binh, TP.HCM", "23/06/2019", ""},
        {"23127265", "Ngo Thi Nhu Quynh", "058205001181", "16/05/2005", "Male", "ngvanA@gmail.com", "12/34 Nguyen Trai, Q.1, TP.HCM", "10/10/2020", ""},
        {"23127266", "Tran Thi B", "058205001182", "12/12/1998", "Female", "tranthiB@gmail.com", "45/67 Le Lai, Q.3, TP.HCM", "05/11/2021", ""},
        {"23127267", "Le Van C", "058205001183", "01/04/2000", "Male", "levanc@gmail.com", "89/10 Tran Hung Dao, Q.5, TP.HCM", "20/02/2022", ""},
        {"23127268", "Pham Thi D", "058205001184", "30/07/1992", "Female", "phamthiD@gmail.com", "33/12 Le Duan, Q.10, TP.HCM", "15/01/2023", ""},
        {"23127269", "Hoang Van E", "058205001185", "18/03/1999", "Male", "hoangvanE@gmail.com", "21/23 Nguyen Van Cu, Q.7, TP.HCM", "11/12/2023", ""},
        {"23127270", "Vu Thi F", "058205001186", "10/10/1994", "Female", "vuthif@gmail.com", "56/78 Truong Chinh, Q.12, TP.HCM", "19/05/2022", ""},
        {"23127271", "Nguyen Van G", "058205001187", "05/06/2001", "Male", "ngvanG@gmail.com", "22/44 Ly Thuong Kiet, Q.4, TP.HCM", "08/08/2021", ""},
        {"23127272", "Tran Thi H", "058205001188", "15/11/1990", "Female", "tranthiH@gmail.com", "77/88 Hoang Sa, Q.2, TP.HCM", "01/01/2020", ""},
        {"23127273", "Le Van I", "058205001189", "29/09/1985", "Male", "levanI@gmail.com", "99/01 Phan Van Tri, Q.9, TP.HCM", "30/12/2019", ""}
    };
    int readerCount = 10;
    for(int i = 0; i < readerCount; i++) {
        addMonthsToDate(readers[i].IssueDate, 48, readers[i].ExpiryDate);
    }

    //Quản lí sách
    Book books[MAX_BOOKS] = {
        {"12345ABC", "Thay hoa vang tren co xanh", "Nguyen Nhat Anh", "NXB Kim Dong", 2020, "Romantic", 300, 100},
        {"12346DEF", "Co gai den tu hom qua", "Nguyen Nhat Anh", "NXB Tre", 2000, "Romance", 220, 85},
        {"12347GHI", "Cho toi xin mot ve tuoi tho", "Nguyen Nhat Anh", "NXB Kim Dong", 2008, "Fiction", 250, 90},
        {"12348JKL", "Mot cuoc chia tay trong mua", "Nguyen Nhat Anh", "NXB Tre", 2015, "Romance", 270, 95},
        {"12349MNO", "Bay troi ve ngang qua pho", "Nguyen Nhat Anh", "NXB Kim Dong", 2017, "Adventure", 300, 105},
        {"12350PQR", "Doi cho em mot mua xuan", "Nguyen Nhat Anh", "NXB Tre", 2019, "Romance", 320, 100},
        {"12351STU", "Ngay xua co mot chuyen tinh", "Nguyen Nhat Anh", "NXB Kim Dong", 2021, "Romance", 280, 110},
        {"12352VWX", "Mot ngay nao do", "Nguyen Nhat Anh", "NXB Tre", 2013, "Drama", 240, 95},
        {"12353YZA", "Kinh van hoa", "Nguyen Nhat Anh", "NXB Tre", 1995, "Fantasy", 150, 80},
        {"12354BCD", "Nhung con meo cua nha van", "Nguyen Nhat Anh", "NXB Kim Dong", 2022, "Children", 200, 90}
    };
    int bookCount = 10;

    // Phiếu mượn/trả sách
    Loan loans[MAX_LOANS];
    for (int i = 0; i < MAX_LOANS; i++) {
        strcpy(loans[i].ReturnDate, "");
    }
    for (int i = 0; i < MAX_LOANS; i++) {
        loans[i].BookCount = 0;
    }
    int loanCount = 0;


    //Menu
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. View Readers List\n");
        printf("2. Add Reader\n");
        printf("3. Edit Reader\n");
        printf("4. Delete Reader\n");
        printf("5. Search Reader by CMND\n");
        printf("6. Search Reader by Name\n");
        printf("7. View Books List\n");
        printf("8. Add Book\n");
        printf("9. Edit Book\n");
        printf("10. Delete Book\n");
        printf("11. Search Book by ISBN\n");
        printf("12. Search Book by Title\n");
        printf("13. Create Loan Slip\n");
        printf("14. Create Return Slip\n");
        printf("15. Total Books\n");
        printf("16. Books by Category\n");
        printf("17. Total Readers\n");
        printf("18. Readers by Gender\n");
        printf("19. Total Books on Loan\n");
        printf("20. Late Readers List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
        {   viewReadersList(readers, readerCount);
            break;
        }
        case 2:
        {
            printf("1. Add Reader from console\n");
            printf("2. Add Reader from file\n");
            printf("Your choice: ");
            int choice;
            scanf("%d", &choice);
            switch(choice)
            {
                case 1:
                {
                    //Add Reader from console
                    int n;
                    addReader(n, readers, readerCount);
                    break;
                }
                case 2:
                {
                    //Add Reader from file
                    readReader("inputReaders.txt", readers, readerCount);
                    writeReader("outputReaders.txt", readers, readerCount);
                    break;
                }
                default:
                {
                    printf("Invalid choice.\n");
                    break;
                }
            }
            break;
        }
        case 3:
        {
            editReader(readers, readerCount);
            break;
        }
        case 4:
        {   deleteReader(readers, readerCount);
            break;
        }
        case 5:
        {
            char cmnd[20];
            int readerIndex;
            while(true){
                printf("Enter Reader CMND to search: ");
                scanf("%s", cmnd);
                readerIndex = searchReaderByCMND(cmnd, readers, readerCount);
                if(readerIndex == -1) {
                    printf("Reader not found. Please enter another CMND.\n");
                }
                else break;
            }
            printReaderCatgorry();
            printReaderInfo(readerIndex, readers);
            break;
        }
        case 6:
        {
            char name[50];
            int readerIndex;
            cin.ignore();
            while(true){
                printf("Enter Reader Name to search: ");
                cin.getline(name, 50);
                readerIndex = searchReaderByName(name, readers, readerCount);
                if(readerIndex == -1) {
                    printf("Reader not found. Please enter another Name.\n");
                }
                else break;
            }
            printReaderCatgorry();
            printReaderInfo(readerIndex, readers);
            break;
        }
        case 7:
        {   viewBooksList(books, bookCount);
            break;
        }
        case 8:
        {
            printf("1. Add Book from console\n");
            printf("2. Add Book from file\n");
            printf("Your choice: ");
            int choice;
            scanf("%d", &choice);
            switch(choice)
            {
                case 1:
                {
                    //Add Book from console
                    int n;
                    printf("Enter number of books to add: ");
                    scanf("%d", &n);
                    addBook(n, books, bookCount);
                    break;
                }
                case 2:
                {
                    //Add Book from file
                    readBook("inputBooks.txt", books, bookCount);
                    writeBook("outputBooks.txt", books, bookCount);
                    break;
                }
                default:
                {
                    printf("Invalid choice.\n");
                    break;
                }
            }
            break;
        }
        case 9:
        {   editBook(books, bookCount);
            break;
        }
        case 10:
        {   deleteBook(books, bookCount);
            break;
        }
        case 11:
        {
            char isbn[20];
            printf("Enter Book ISBN to search: ");
            scanf("%s", isbn);
            int bookIndex = searchBookByISBN(isbn, books, bookCount);
            if(bookIndex == -1) {
                printf("Book not found.\n");
            }
            else {
                printBookCatgorry();
                printBookInfo(bookIndex, books);
            }
            break;
        }
        case 12:
        {
            char title[50];
            printf("Enter Book Title to search: ");
            cin.ignore();
            cin.getline(title, 50);
            int bookIndex = searchBookByTitle(title, books, bookCount);
            if(bookIndex == -1) {
                printf("Book not found.\n");
            }
            else {
                printBookCatgorry();
                printBookInfo(bookIndex, books);
            }
            break;
        }
        case 13:
        {
            createLoanSlip(readers, readerCount, loans, loanCount, books, bookCount);
            break;
        }
        case 14:
        {
            createReturnSlip(readers, readerCount, loans, loanCount, books, bookCount);
            break;
        }
        case 15:
        {
            cout << "Total Books: " << totalBooks(bookCount, books) << endl;
            break;
        }
        case 16:
        {
            booksByCategory(books, bookCount);
            break;
        }
        case 17:
        {
            cout << "Total Readers: " << totalReaders(readerCount) << endl;
            break;
        }
        case 18:
        {
            readersByGender(readers, readerCount);
            break;
        }
        case 19:
        {
            cout << "Total books on loan: " << totalBooksOnLoan(loans, loanCount) << endl;
            break;
        }
        case 20:
        {
            lateReadersList(loans, loanCount, readers, readerCount, books, bookCount);
            break;
        }
        case 0:
        {
            printf("See you again!\n");
            exit(0);
        }
        default:
        {
            printf("Invalid choice. Please try again.\n");
            break;
        }
        }

    }
    return 0;
}