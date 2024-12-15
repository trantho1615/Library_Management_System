#include "Library.h"
#include "Reader.h"
#include "Book.h"
#include "ultilities.h"

int main() {
    // Quản lý độc giả
    char readerIDs[MAX_READERS][20] = {"23127264", "23127265", "23127266", "23127267", "23127268", "23127269", "23127270", "23127271", "23127272", "23127273"};
    char readerNames[MAX_READERS][50] = {"Tran Tho", "Ngo Thi Nhu Quynh", "Tran Thi B", "Le Van C", "Pham Thi D", "Hoang Van E", "Vu Thi F", "Nguyen Van G", "Tran Thi H", "Le Van I"};
    char readerCMNDs[MAX_READERS][20] = {"058205001180", "058205001181", "058205001182", "058205001183", "058205001184", "058205001185", "058205001186", "058205001187", "058205001188", "058205001189"};
    char readerBirthdays[MAX_READERS][20] = {"16/01/2005", "16/05/2005", "12/12/1998", "01/04/2000", "30/07/1992", "18/03/1999", "10/10/1994", "05/06/2001", "15/11/1990", "29/09/1985"};
    char readerGenders[MAX_READERS][10] = {"Male", "Male", "Female", "Male", "Female", "Male", "Female", "Male", "Female", "Male"};
    char readerEmails[MAX_READERS][50] = {"tholazdo@gmail.com", "ngvanA@gmail.com", "tranthiB@gmail.com", "levanc@gmail.com", "phamthiD@gmail.com", "hoangvanE@gmail.com", "vuthif@gmail.com", "ngvanG@gmail.com", "tranthiH@gmail.com", "levanI@gmail.com"};
    char readerAddresses[MAX_READERS][100] = {"21/21 Tu Lap, P4, Q.Tan Binh, TP.HCM", "12/34 Nguyen Trai, Q.1, TP.HCM", "45/67 Le Lai, Q.3, TP.HCM", "89/10 Tran Hung Dao, Q.5, TP.HCM", "33/12 Le Duan, Q.10, TP.HCM", "21/23 Nguyen Van Cu, Q.7, TP.HCM", "56/78 Truong Chinh, Q.12, TP.HCM", "22/44 Ly Thuong Kiet, Q.4, TP.HCM", "77/88 Hoang Sa, Q.2, TP.HCM", "99/01 Phan Van Tri, Q.9, TP.HCM"};
    char readerIssueDates[MAX_READERS][20] = {"23/06/2019", "10/10/2020", "05/11/2021", "20/02/2022", "15/01/2023", "11/12/2023", "19/05/2022", "08/08/2021", "01/01/2020", "30/12/2019"};
    char readerExpiryDates[MAX_READERS][20] = {""};
    int readerCount = 10;
    for(int i = 0; i < readerCount; i++) {
        addMonthsToDate(readerIssueDates[i], 48, readerExpiryDates[i]);
    }

    //Sách
    char ISBN[MAX_BOOKS][20] = {"12345ABC", "12346DEF", "12347GHI", "12348JKL", "12349MNO", "12350PQR", "12351STU", "12352VWX", "12353YZA", "12354BCD"};
    char Titles[MAX_BOOKS][50] = {"Thay hoa vang tren co xanh", "Co gai den tu hom qua", "Cho toi xin mot ve tuoi tho", "Mot cuoc chia tay trong mua", "Bay troi ve ngang qua pho", "Doi cho em mot mua xuan", "Ngay xua co mot chuyen tinh", "Mot ngay nao do", "Kinh van hoa", "Nhung con meo cua nha van"};
    char Authors[MAX_BOOKS][50] = {"Nguyen Nhat Anh", "Nguyen Nhat Anh", "Nguyen Nhat Anh", "Nguyen Nhat Anh", "Nguyen Nhat Anh", "Nguyen Nhat Anh", "Nguyen Nhat Anh", "Nguyen Nhat Anh", "Nguyen Nhat Anh", "Nguyen Nhat Anh"};
    char Publishers[MAX_BOOKS][50] = {"NXB Kim Dong", "NXB Tre", "NXB Kim Dong", "NXB Tre", "NXB Kim Dong", "NXB Tre", "NXB Kim Dong", "NXB Tre", "NXB Tre", "NXB Kim Dong"};
    int PublishYears[MAX_BOOKS] = {2020, 2000, 2008, 2015, 2017, 2019, 2021, 2013, 1995, 2022};
    char bookCategories[MAX_BOOKS][50] = {"Romantic", "Romance", "Fiction", "Romance", "Adventure", "Romance", "Romance", "Drama", "Fantasy", "Children"};
    float Prices[MAX_BOOKS] = {300, 220, 250, 270, 300, 320, 280, 240, 150, 200};
    int Quantities[MAX_BOOKS] = {100, 85, 90, 95, 105, 100, 110, 95, 80, 90};
    int bookCount = 10;

    // Phiếu mượn/trả sách
    char loanReaderIDs[MAX_LOANS][20];
    char loanReaderNames[MAX_LOANS][50];
    char loanIssueDates[MAX_LOANS][20]; //Ngày mượn
    char loanDueDates[MAX_LOANS][20];   //Ngày trả dự kiến (sau 7 ngày), hay hạn trả
    char loanReturnDates[MAX_LOANS][20] = {""};//Ngày trả thực tế
    char loanISBN[MAX_LOANS][MAX_ISBN_PER_LOAN][20]; //Danh sách ISBN sách của mỗi đọc giả
    char loanBookTitle[MAX_LOANS][MAX_ISBN_PER_LOAN][50]; //Danh sách tên sách mượn của mỗi đọc giả
    int loanBookCounts[MAX_LOANS] = {0}; //Số lượng sách mượn của mỗi đọc giả
    int loanCount = 0;  //Số lượng đọc giả mượn sách

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
        {   viewReadersList(readerIDs, readerNames, readerCMNDs, readerBirthdays, readerGenders, readerEmails, readerAddresses, readerIssueDates, readerExpiryDates, readerCount);
            break;
        }
        case 2:
        {
            //Add Reader from console
            int n;
            addReader(n, readerIDs, readerNames, readerCMNDs, readerBirthdays, readerGenders, readerEmails, readerAddresses, readerIssueDates, readerExpiryDates, readerCount);
            break;
            //Add Reader from file
            // readReader("inputReaders.txt", readerIDs, readerNames, readerCMNDs, readerBirthdays, readerGenders, readerEmails, readerAddresses, readerIssueDates, readerExpiryDates, readerCount);
            // writeReader("outputReaders.txt", readerIDs, readerNames, readerCMNDs, readerBirthdays, readerGenders, readerEmails, readerAddresses, readerIssueDates, readerExpiryDates, readerCount);
            // break;
        }
        case 3:
        {
            editReader(readerIDs, readerNames, readerCMNDs, readerBirthdays, readerGenders, readerEmails, readerAddresses, readerIssueDates, readerExpiryDates, readerCount);
            break;
        }
        case 4:
        {   deleteReader(readerIDs, readerNames, readerCMNDs, readerBirthdays, readerGenders, readerEmails, readerAddresses, readerIssueDates, readerExpiryDates, readerCount);
            break;
        }
        case 5:
        {
            char cmnd[20];
            int readerIndex;
            while(true){
                printf("Enter Reader CMND to search: ");
                scanf("%s", cmnd);
                readerIndex = searchReaderByCMND(cmnd, readerCMNDs, readerCount);
                if(readerIndex == -1) {
                    printf("Reader not found. Please enter another CMND.\n");
                }
                else break;
            }
            printReaderCatgorry();
            printReaderInfo(readerIndex, readerIDs, readerNames, readerCMNDs, readerBirthdays, readerGenders, readerEmails, readerAddresses, readerIssueDates, readerExpiryDates);
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
                readerIndex = searchReaderByName(name, readerNames, readerCount);
                if(readerIndex == -1) {
                    printf("Reader not found. Please enter another Name.\n");
                }
                else break;
            }
            printReaderCatgorry();
            printReaderInfo(readerIndex, readerIDs, readerNames, readerCMNDs, readerBirthdays, readerGenders, readerEmails, readerAddresses, readerIssueDates, readerExpiryDates);
            break;
        }
        case 7:
        {   viewBooksList(ISBN, Titles, Authors, Publishers, PublishYears, bookCategories, Prices, Quantities, bookCount);
            break;
        }
        case 8:
        {
            //Add Book from console
            int n;
            printf("Enter number of books to add: ");
            scanf("%d", &n);
            addBook(n, ISBN, Titles, Authors, Publishers, PublishYears, bookCategories, Prices, Quantities, bookCount);
            break;
            //Add Book from file
            // readBook("inputBooks.txt", ISBN, Titles, Authors, Publishers, PublishYears, bookCategories, Prices, Quantities, bookCount);
            // writeBook("outputBooks.txt", ISBN, Titles, Authors, Publishers, PublishYears, bookCategories, Prices, Quantities, bookCount);
            // break;
        }
        case 9:
        {   editBook(ISBN, Titles, Authors, Publishers, PublishYears, bookCategories, Prices, Quantities, bookCount);
            break;
        }
        case 10:
        {   deleteBook(ISBN, Titles, Authors, Publishers, PublishYears, bookCategories, Prices, Quantities, bookCount);
            break;
        }
        case 11:
        {
            char isbn[20];
            printf("Enter Book ISBN to search: ");
            scanf("%s", isbn);
            int bookIndex = searchBookByISBN(isbn, ISBN, bookCount);
            if(bookIndex == -1) {
                printf("Book not found.\n");
            }
            else {
                printBookCatgorry();
                printBookInfo(bookIndex, ISBN, Titles, Authors, Publishers, PublishYears, bookCategories, Prices);
            }
            break;
        }
        case 12:
        {
            char title[50];
            printf("Enter Book Title to search: ");
            cin.ignore();
            cin.getline(title, 50);
            int bookIndex = searchBookByTitle(title, Titles, bookCount);
            if(bookIndex == -1) {
                printf("Book not found.\n");
            }
            else {
                printBookCatgorry();
                printBookInfo(bookIndex, ISBN, Titles, Authors, Publishers, PublishYears, bookCategories, Prices);
            }
            break;
        }
        case 13:
        {
            createLoanSlip(readerNames, readerIDs, readerCMNDs, readerCount, loanReaderIDs, loanReaderNames, loanIssueDates, loanDueDates, loanReturnDates, loanISBN, loanBookCounts, loanCount, ISBN, Titles, Authors, Publishers, PublishYears, bookCategories, Prices, Quantities, bookCount);
            break;
        }
        case 14:
        {
            createReturnSlip(readerNames, readerCMNDs, readerCount, loanReaderIDs, loanReaderNames, loanIssueDates, loanDueDates, loanReturnDates, loanISBN, loanBookCounts, loanCount, ISBN, Titles, Authors, Publishers, PublishYears, bookCategories, Prices, Quantities, bookCount);
            break;
        }
        case 15:
        {
            cout << "Total Books: " << totalBooks(bookCount, Quantities) << endl;
            break;
        }
        case 16:
        {
            booksByCategory(bookCategories, bookCount);
            break;
        }
        case 17:
        {
            cout << "Total Readers: " << totalReaders(readerCount) << endl;
            break;
        }
        case 18:
        {
            readersByGender(readerGenders, readerCount);
            break;
        }
        case 19:
        {
            cout << "Total books on loan: " << totalBooksOnLoan(loanBookCounts) << endl;
            break;
        }
        case 20:
        {
            lateReadersList(readerIDs, readerNames, readerCMNDs, readerBirthdays, readerGenders, readerEmails, readerAddresses, readerIssueDates, readerExpiryDates, readerCount, ISBN, Titles, Authors, Publishers, PublishYears, bookCategories, Prices, Quantities, bookCount, loanReaderIDs, loanReaderNames, loanIssueDates, loanDueDates, loanReturnDates, loanISBN, loanBookTitle, loanBookCounts, loanCount);
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
