#include "Library.h"
#include "Book.h"
#include "Reader.h"
#include "ultilities.h"

//Hiển thị danh sách sách
void viewBooksList(char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS], int Quantities[MAX_BOOKS], int bookCount) {
    printf("List of Books:\n");
    printf("%-5s %-10s %-28s %-18s %-18s %-8s %-10s %-10s %-10s\n",
        "STT", "ISBN", "Title", "Author", "Publisher", "Year", "Category", "Price", "Quantity");
    for (int i = 0; i < bookCount; i++) {
        printf("%-5d %-10s %-28s %-18s %-18s %-8d %-10s %-10.2f %-10d\n",
            i+1, ISBN[i], Titles[i], Authors[i], Publishers[i], PublishYears[i], bookCategories[i], Prices[i], Quantities[i]);
    }
}

//Thêm sách mới, có thể chọn số lượng muốn thêm
void addBook(int n, char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS], int Quantities[MAX_BOOKS], int& bookCount) {
    if (bookCount >= MAX_BOOKS) {
        printf("Book list is full.\n");
        return;
    }
    for(int i = 0; i < n; i++){
        printf("Enter Book ISBN: ");
        cin.ignore();
        cin.getline(ISBN[bookCount], 20);
        printf("Enter Book Title: ");
        cin.getline(Titles[bookCount], 50);
        printf("Enter Book Author: ");
        cin.getline(Authors[bookCount], 50);
        printf("Enter Book Publisher: ");
        cin.getline(Publishers[bookCount], 50);
        printf("Enter Book Publish Year: ");
        scanf("%d", &PublishYears[bookCount]);
        printf("Enter Book Category: ");
        cin.ignore();
        cin.getline(bookCategories[bookCount], 50);
        printf("Enter Book Price: ");
        scanf("%f", &Prices[bookCount]);
        printf("Enter Book Quantity: ");
        scanf("%d", &Quantities[bookCount]);
        bookCount++;
        printf("Book added successfully.\n");
    }
}

//Chỉnh sửa thông tin sách
void editBook(char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS], int Quantities[MAX_BOOKS], int bookCount) {
    viewBooksList(ISBN, Titles, Authors, Publishers, PublishYears, bookCategories, Prices, Quantities, bookCount);
    int index;
    while(true){
        char isbn[20];
        printf("Enter Book's ISBN to edit: ");
        scanf("%s", isbn);
        index = searchBookByISBN(isbn, ISBN, bookCount);
        if(index == -1) {
            printf("Book not found. Please enter another ISBN.\n");
        }
        else break;
    }
    int choice;
    while (true) {
        printf("Choose information to edit: \n");
        printf("1. ISBN\n");
        printf("2. Title\n");
        printf("3. Author\n");
        printf("4. Publisher\n");
        printf("5. Publish Year\n");
        printf("6. Category\n");
        printf("7. Price\n");
        printf("8. Quantity\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: 
            while(true){
                char isbn[20];
                printf("Enter new Book ISBN: ");
                scanf("%s", isbn);
                if(searchBookByISBN(isbn, ISBN, bookCount) != -1) {
                    printf("Book's ISBN already exists. Please enter another one.\n");
                }
                else {
                    strcpy(ISBN[index], isbn);
                    break;
                }
            }
        {
    
            break;
        }
        case 2: 
        {
            printf("Enter new Book Title: ");
            cin.ignore();
            cin.getline(Titles[index], 50);
            break;
        }
        case 3: 
        {
            printf("Enter new Book Author: ");
            cin.ignore();
            cin.getline(Authors[index], 50);
            break;
        }
        case 4: 
        {
            printf("Enter new Book Publisher: ");
            cin.ignore();
            cin.getline(Publishers[index], 50);
            break;
        }
        case 5: 
        {
            printf("Enter new Book Publish Year: ");
            scanf("%d", &PublishYears[index]);
            break;
        }
        case 6: 
        {
            printf("Enter new Book Category: ");
            cin.ignore();
            cin.getline(bookCategories[index], 50);
            break;
        }
        case 7: 
        {
            printf("Enter new Book Price: ");
            scanf("%f", &Prices[index]);
            break;
        }
        case 8: 
        {
            printf("Enter new Book Quantity: ");
            scanf("%d", &Quantities[index]);
            break;
        }
        case 0: 
            return;
        }
    }
}

//Xóa sách
void deleteBook(char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS], int Quantities[MAX_BOOKS], int& bookCount) {
    char isbn[20];
    int index;
    viewBooksList(ISBN, Titles, Authors, Publishers, PublishYears, bookCategories, Prices, Quantities, bookCount);
    while(true){
        printf("Enter Book ISBN to delete: ");
        scanf("%s", isbn);
        index = searchBookByISBN(isbn, ISBN, bookCount);
        if(index == -1) {
            printf("Book not found. Please enter another ISBN.\n");
        }
        else break;
    }
    for(int i = index; i < bookCount - 1; i++){
        strcpy(ISBN[i], ISBN[i + 1]);
        strcpy(Titles[i], Titles[i + 1]);
        strcpy(Authors[i], Authors[i + 1]);
        strcpy(Publishers[i], Publishers[i + 1]);
        PublishYears[i] = PublishYears[i + 1];
        strcpy(bookCategories[i], bookCategories[i + 1]);
        Prices[i] = Prices[i + 1];
        Quantities[i] = Quantities[i + 1];
    }
    bookCount--;
    printf("Book deleted successfully.\n");
}

//In ra thông tin sách
void printBookCatgorry()
{
    printf("%-5s %-10s %-28s %-18s %-18s %-8s %-10s %-10s\n",
        "STT", "ISBN", "Title", "Author", "Publisher", "Year", "Category", "Price");   
}
void printBookInfo(int i, char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS]) {
    printf("%-5d %-10s %-28s %-18s %-18s %-8d %-10s %-10.2f\n",
        i+1, ISBN[i], Titles[i], Authors[i], Publishers[i], PublishYears[i], bookCategories[i], Prices[i]);
}

//Tìm kiếm sách theo ISBN
int searchBookByISBN(char isbn[], char ISBN[MAX_BOOKS][20], int bookCount) 
{
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(ISBN[i], isbn) == 0) {
            return i;
        }
    }
    return -1;
}

//Tìm kiếm sách theo tiêu đề
int searchBookByTitle(char title[], char Titles[MAX_BOOKS][50], int bookCount) {

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(Titles[i], title) == 0) {
			return i;
        }
    }
    return -1;
}

//In ra danh sách sách mà người đọc cụ thể đang mượn
void viewBooksOnLoan(int readerIndex, char loanReaderIDs[MAX_LOANS][20], char loanReaderNames[MAX_LOANS][50], char loanIssueDates[MAX_LOANS][20], char loanDueDates[MAX_LOANS][20], char loanReturnDates[MAX_LOANS][20], char loanISBN[MAX_LOANS][MAX_ISBN_PER_LOAN][20], int loanBookCounts[MAX_LOANS], int loanCount, char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS], int Quantities[MAX_BOOKS], int bookCount) {
    printf("List of Books on Loan:\n");
    printBookCatgorryOnLoan();
    for (int i = 0; i < loanBookCounts[readerIndex]; i++) {
        int bookIndex = searchBookByISBN(loanISBN[readerIndex][i], ISBN, bookCount);
        printBookInfoOnLoan(bookIndex, readerIndex, ISBN, Titles, Authors, Publishers, PublishYears, bookCategories, Prices, loanIssueDates, loanDueDates, loanReturnDates);    
    }
}

// Lập phiếu mượn sách
void createLoanSlip(char readerNames[MAX_READERS][50], char readerIDs[MAX_READERS][20], char readerCMNDs[MAX_READERS][20], int readerCount, char loanReaderIDs[MAX_LOANS][20], char loanReaderNames[MAX_LOANS][50], char loanIssueDates[MAX_LOANS][20], char loanDueDates[MAX_LOANS][20], char loanReturnDates[MAX_LOANS][20], char loanISBN[MAX_LOANS][MAX_ISBN_PER_LOAN][20], int loanBookCounts[MAX_LOANS], int& loanCount, char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS], int Quantities[MAX_BOOKS], int bookCount) {
    if (loanCount >= MAX_LOANS) {
        printf("Loan list is full.\n");
        return;
    }
    char readerID[20];
    char readerName[50];
    printf("Enter Reader ID: ");
    scanf("%s", readerID);
    printf("Enter Reader Name: ");  
    cin.ignore();
    cin.getline(readerName, 50);
    if(searchReaderByName(readerName, readerNames, readerCount) == -1 || searchReaderByID(readerID, readerIDs, readerCount) == -1) {
        printf("Reader not found.\n");
        return;
    }
    else{
        strcpy(loanReaderIDs[loanCount], readerID);
        strcpy(loanReaderNames[loanCount], readerName);
    }
	printf("Enter Issue Date (dd/mm/yy): ");
	inputDateValid(loanIssueDates[loanCount]);
    addDaysToDate(loanIssueDates[loanCount], 7, loanDueDates[loanCount]);
    printf("Enter number of books to loan: ");
    scanf("%d", &loanBookCounts[loanCount]);
    viewBooksList(ISBN, Titles, Authors, Publishers, PublishYears, bookCategories, Prices, Quantities, bookCount);
    for (int i = 0; i < loanBookCounts[loanCount]; i++) {
        char isbn[20];
        while(true){
            printf("Enter Book ISBN %d: ", i + 1);
            scanf("%s", isbn);
            if(searchBookByISBN(isbn, ISBN, bookCount) == -1) {
                printf("Book not found.\n");
            }
            else break;
        }
        strcpy(loanISBN[loanCount][i], isbn);
        Quantities[searchBookByISBN(isbn, ISBN, bookCount)]--;
    }
    loanCount++;
    printf("Loan slip created successfully.\n");
}

// Lập phiếu trả sách
void printBookCatgorryOnLoan()
{
    printf("%-5s %-10s %-28s %-18s %-18s %-8s %-10s %-10s %-12s %-12s %-12s\n",
        "STT", "ISBN", "Title", "Author", "Publisher", "Year", "Category", "Price", "Issue Date", "Expiry Date", "Return Date");   
}

//In ra thông tin sách mà người đọc cụ thể đang mượn
void printBookInfoOnLoan(int bookIndex, int readerIndex, char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS], char IssueDates[MAX_BOOKS][20], char ExpiryDates[MAX_BOOKS][20], char ReturnDates[MAX_BOOKS][20]) {
    printf("%-5d %-10s %-28s %-18s %-18s %-8d %-10s %-10.2f %-12s %-12s %-12s\n",
        bookIndex+1, ISBN[bookIndex], Titles[bookIndex], Authors[bookIndex], Publishers[bookIndex], PublishYears[bookIndex], bookCategories[bookIndex], Prices[bookIndex], IssueDates[readerIndex], ExpiryDates[readerIndex], ReturnDates[readerIndex]);
}

// Lập phiếu trả sách
void createReturnSlip(char readerNames[MAX_READERS][50], char readerCMNDs[MAX_READERS][20], int readerCount, char loanReaderIDs[MAX_LOANS][20], char loanReaderNames[MAX_LOANS][50], char loanIssueDates[MAX_LOANS][20], char loanDueDates[MAX_LOANS][20], char loanReturnDates[MAX_LOANS][20], char loanISBN[MAX_LOANS][MAX_ISBN_PER_LOAN][20], int loanBookCounts[MAX_LOANS], int& loanCount, char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS], int Quantities[MAX_BOOKS], int bookCount) {
    if (loanCount == 0) {
        printf("No loan slip found.\n");
        return;
    }
	//Nhap thong tin nguoi tra sach
    char readerName[50];
    printf("Enter Reader Name: ");
    cin.ignore();
    cin.getline(readerName, 50);

    //Xac dinh index cua nguoi tra sach
    int readerIndex;
    bool check = false;
    for (int i = 0; i < loanCount; i++) {
		if (strcmp(loanReaderNames[i], readerName) == 0) {
			check = true;
			readerIndex = i;
            if(strcmp(loanReturnDates[i], "") == 0) {
                break;
            }
		}
    }
    if (check == false) {
        printf("Reader not found.\n");
        return;
    }

	//Nhap thong tin tra sach
    int returnCount = loanBookCounts[readerIndex];
    char isbn[MAX_ISBN_PER_LOAN][20] = {""};
    viewBooksOnLoan(readerIndex, loanReaderIDs, loanReaderNames, loanIssueDates, loanDueDates, loanReturnDates, loanISBN, loanBookCounts, loanCount, ISBN, Titles, Authors, Publishers, PublishYears, bookCategories, Prices, Quantities, bookCount);
    for(int i = 0; i < loanBookCounts[readerIndex]; i++){
        strcpy(isbn[i], loanISBN[readerIndex][i]);
    }

    printf("Enter Return Date (dd/mm/yy): ");
    inputDateValid(loanReturnDates[readerIndex]);
    int fineDaysPerBook = daysBetweenDates(loanDueDates[readerIndex], loanReturnDates[readerIndex]);
    int fineDays = 0;
    double fine = 0.0;
    for (int i = 0; i < returnCount; i++) {
        //Kiem tra sach da muon co mat khong
        int lostBook = 0;
        int bookIndex = searchBookByISBN(isbn[i], ISBN, bookCount);
		printf("Is the book \"%s\" lost? (1: Yes, 0: No): ", Titles[bookIndex]);
		scanf("%d", &lostBook);
        if(lostBook == 1) {
            fine += (double)Prices[bookIndex] * 2;
        }
        else if(lostBook == 0)
        {
            if (fineDaysPerBook > 0) {
                fineDays += fineDaysPerBook;
            }
            Quantities[searchBookByISBN(isbn[i], ISBN, bookCount)]++;
        }
    }
    fine += (double)fineDays * 5000;
    printf("Fine: %.2lf\n", fine);
}

//Tổng số sách trong thư viện
int totalBooks(int bookCount, int Quantities[MAX_BOOKS]) {
    int total = 0;
    for (int i = 0; i < bookCount; i++) {
        total += Quantities[i];
    }
    return total;
}

//Thống kê số lượng sách theo từng thể loại
void booksByCategory(char bookCategories[MAX_BOOKS][50], int bookCount) {
    char categories[MAX_BOOKS][50];
    int categoryCounts[MAX_BOOKS] = { 0 };
    int categoryCount = 0;
    for (int i = 0; i < bookCount; i++) {
        int found = 0;
        for (int j = 0; j < categoryCount; j++) {
            if (strcmp(categories[j], bookCategories[i]) == 0) {
                categoryCounts[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(categories[categoryCount], bookCategories[i]);
            categoryCounts[categoryCount]++;
            categoryCount++;
        }
    }
    printf("Books by Category:\n");
    for (int i = 0; i < categoryCount; i++) {
        printf("Category: %s, Count: %d\n", categories[i], categoryCounts[i]);
    }
}

//Tổng số sách đang được mượn
int totalBooksOnLoan(int loanBookCounts[MAX_LOANS]) {
    int total = 0;
    for(int i = 0; i < MAX_LOANS; i++) {
        total += loanBookCounts[i];
    }
    return total;
}

//In ra thông tin người mượn sách
void printLoanCat()
{
    printf("%-10s %-20s %-12s %-12s %-12s\n",
        "ID", "Name", "Issue Date", "Expiry Date", "Return Date");
}
void printLoanInfo(int i, char loanReaderIDs[MAX_LOANS][20], char loanReaderNames[MAX_LOANS][50], char loanIssueDates[MAX_LOANS][20], char loanDueDates[MAX_LOANS][20], char loanReturnDates[MAX_LOANS][20]) {
    printf("%-10s %-20s %-12s %-12s %-12s\n",
        loanReaderIDs[i], loanReaderNames[i], loanIssueDates[i], loanDueDates[i], loanReturnDates[i]);
}


//Danh sách đọc giả trả sách trễ hạn
void lateReadersList(char readerIDs[MAX_READERS][20],
    char readerNames[MAX_READERS][50],
    char readerCMNDs[MAX_READERS][20],
    char readerBirthdays[MAX_READERS][20],
    char readerGenders[MAX_READERS][10],
    char readerEmails[MAX_READERS][50],
    char readerAddresses[MAX_READERS][100],
    char readerIssueDates[MAX_READERS][20],
    char readerExpiryDates[MAX_READERS][20],
    int readerCount,
    char ISBN[MAX_BOOKS][20],
    char Titles[MAX_BOOKS][50],
    char Authors[MAX_BOOKS][50],
    char Publishers[MAX_BOOKS][50],
    int PublishYears[MAX_BOOKS],
    char bookCategories[MAX_BOOKS][50],
    float Prices[MAX_BOOKS],
    int Quantities[MAX_BOOKS],
    int bookCount,
    char loanReaderIDs[MAX_LOANS][20],
    char loanReaderNames[MAX_LOANS][50],
    char loanIssueDates[MAX_LOANS][20],
    char loanDueDates[MAX_LOANS][20],
    char loanReturnDates[MAX_LOANS][20],
    char loanISBN[MAX_LOANS][MAX_ISBN_PER_LOAN][20],
    char loanBookNames[MAX_LOANS][MAX_ISBN_PER_LOAN][50],
    int loanBookCounts[MAX_LOANS],
    int loanCount) {
        if(isArrayEmpty(loanReturnDates, MAX_LOANS)) {
            printf("No books returned\n");
            return;
        }
        printf("Late Readers List:\n");
        printLoanCat();
        int printed[MAX_LOANS] = {0};
        for (int i = 0; i < loanCount; i++) {
            int fineDays = daysBetweenDates(loanDueDates[i], loanReturnDates[i]);
            // int readerIndex = searchReaderByName(loanReaderNames[i], readerNames, readerCount);
            // // if(printed[readerIndex] == 1) {
            // //     continue;
            // // }
            // if(readerIndex == -1) {
            //     printf("Reader not found.\n");
            //     return;
            // } 
            if (fineDays > 0 && printed[i] == 0) {
                printf("----------------------------------------------------------------------\n");
                printLoanInfo(i, loanReaderIDs, loanReaderNames, loanIssueDates, loanDueDates, loanReturnDates);
                printf("\tOverdue books list:\n");
                printf("\t"); printBookCatgorryOnLoan();    
                for (int j = 0; j < loanBookCounts[i]; j++) {
                    int bookIndex = searchBookByISBN(loanISBN[i][j], ISBN, bookCount);
                    printf("\t"); printBookInfoOnLoan(bookIndex, i, ISBN, Titles, Authors, Publishers, PublishYears, bookCategories, Prices, loanIssueDates, loanDueDates, loanReturnDates);
                    printed[i] = 1;
                }
            }
        }
}

//void readBook(const char* fileName, char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS], int Quantities[MAX_BOOKS], int& bookCount)
//{
//    FILE* f = fopen(fileName, "r");
//    if (f == NULL) {
//        printf("Cannot open file %s\n", fileName);
//        return;
//    }
//    int n;
//    fscanf(f, "%d\n", &n);
//
//    for (int i = 0; i < n; i++)
//    {
//        endlineHandler(fgets(ISBN[bookCount], sizeof(ISBN[bookCount]), f));
//        endlineHandler(fgets(Titles[bookCount], sizeof(Titles[bookCount]), f));
//        endlineHandler(fgets(Authors[bookCount], sizeof(Authors[bookCount]), f));
//        endlineHandler(fgets(Publishers[bookCount], sizeof(Publishers[bookCount]), f));
//        fscanf(f, "%d\n", &PublishYears[bookCount]);
//        endlineHandler(fgets(bookCategories[bookCount], sizeof(bookCategories[bookCount]), f));
//        fscanf(f, "%f\n", &Prices[bookCount]);
//        fscanf(f, "%d\n", &Quantities[bookCount]);
//        bookCount++;
//    }
//    printf("Read books successfully.\n");
//    fclose(f);
//}
//void writeBook(const char* fileName, char ISBN[MAX_BOOKS][20], char Titles[MAX_BOOKS][50], char Authors[MAX_BOOKS][50], char Publishers[MAX_BOOKS][50], int PublishYears[MAX_BOOKS], char bookCategories[MAX_BOOKS][50], float Prices[MAX_BOOKS], int Quantities[MAX_BOOKS], int bookCount)
//{
//    FILE* f = fopen(fileName, "w");
//    if (f == NULL) {
//        printf("Cannot open file %s\n", fileName);
//        return;
//    }
//
//    fprintf(f, "%d\n", bookCount);
//    for (int i = 0; i < bookCount; i++) {
//        fprintf(f, "%d\n", i + 1);
//        fprintf(f, "%s\n", ISBN[i]);
//        fprintf(f, "%s\n", Titles[i]);
//        fprintf(f, "%s\n", Authors[i]);
//        fprintf(f, "%s\n", Publishers[i]);
//        fprintf(f, "%d\n", PublishYears[i]);
//        fprintf(f, "%s\n", bookCategories[i]);
//        fprintf(f, "%.2f\n", Prices[i]);
//        fprintf(f, "%d\n", Quantities[i]);
//    }
//
//    fclose(f);
//}
