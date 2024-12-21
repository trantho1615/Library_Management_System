#include "Library.h"
#include "Book.h"
#include "Reader.h"
#include "ultilities.h"

//Hiển thị danh sách sách
void viewBooksList(Book books[MAX_BOOKS], int bookCount) {
    if(bookCount == 0) {cout << "Empty book list\n"; return;}
    printf("List of Books:\n");
    printf("%-5s %-10s %-28s %-18s %-18s %-8s %-10s %-10s %-10s\n",
        "STT", "ISBN", "Title", "Author", "Publisher", "Year", "Category", "Price", "Quantity");
    for (int i = 0; i < bookCount; i++) {
        printf("%-5d %-10s %-28s %-18s %-18s %-8d %-10s %-10.2f %-10d\n",
            i+1, books[i].ISBN, books[i].Title, books[i].Author, books[i].Publisher, books[i].PublishYear, books[i].Category, books[i].Price, books[i].Quantity);
    }
}

void addBook(int& n, Book books[MAX_BOOKS], int& bookCount) {
//Thêm sách mới, có thể chọn số lượng muốn thêm
    if (bookCount >= MAX_BOOKS) {
        printf("Book list is full.\n");
        return;
    }
    for(int i = 0; i < n; i++){
        printf("Enter Book ISBN: ");
        cin.ignore();
        cin.getline(books[bookCount].ISBN, 20);
        printf("Enter Book Title: ");
        cin.getline(books[bookCount].Title, 50);
        printf("Enter Book Author: ");
        cin.getline(books[bookCount].Author, 50);
        printf("Enter Book Publisher: ");
        cin.getline(books[bookCount].Publisher, 50);
        printf("Enter Book Publish Year: ");
        scanf("%d", &books[bookCount].PublishYear);
        printf("Enter Book Category: ");
        cin.ignore();
        cin.getline(books[bookCount].Category, 50);
        printf("Enter Book Price: ");
        scanf("%f", &books[bookCount].Price);
        printf("Enter Book Quantity: ");
        scanf("%d", &books[bookCount].Quantity);
        bookCount++;
        printf("Book added successfully.\n");
    }
}

//Chỉnh sửa thông tin sách
void editBook(Book books[MAX_BOOKS], int bookCount) {
    viewBooksList(books, bookCount);
    int index;
    while(true){
        char isbn[20];
        printf("Enter Book's ISBN to edit: ");
        scanf("%s", isbn);
        index = searchBookByISBN(isbn, books, bookCount);
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
        {
            while(true){
                char isbn[20];
                printf("Enter new Book ISBN: ");
                scanf("%s", isbn);
                if(searchBookByISBN(isbn, books, bookCount) != -1) {
                    printf("Book's ISBN already exists. Please enter another one.\n");
                }
                else {
                    strcpy(books[index].ISBN, isbn);
                    break;
                }
            }
            break;
        }
        case 2: 
        {
            printf("Enter new Book Title: ");
            cin.ignore();
            cin.getline(books[index].Title, 50);
            break;
        }
        case 3: 
        {
            printf("Enter new Book Author: ");
            cin.ignore();
            cin.getline(books[index].Author, 50);
            break;
        }
        case 4: 
        {
            printf("Enter new Book Publisher: ");
            cin.ignore();
            cin.getline(books[index].Publisher, 50);
            break;
        }
        case 5: 
        {
            printf("Enter new Book Publish Year: ");
            scanf("%d", &books[index].PublishYear);
            break;
        }
        case 6: 
        {
            printf("Enter new Book Category: ");
            cin.ignore();
            cin.getline(books[index].Category, 50);
            break;
        }
        case 7: 
        {
            printf("Enter new Book Price: ");
            scanf("%f", &books[index].Price);
            break;
        }
        case 8: 
        {
            printf("Enter new Book Quantity: ");
            scanf("%d", &books[index].Quantity);
            break;
        }
        case 0: 
            return;
        }
    }
}

//Xóa sách
void deleteBook(Book books[MAX_BOOKS], int& bookCount) {
    char isbn[20];
    int index;
    viewBooksList(books, bookCount);
    while(true){
        printf("Enter Book ISBN to delete: ");
        scanf("%s", isbn);
        index = searchBookByISBN(isbn, books, bookCount);
        if(index == -1) {
            printf("Book not found. Please enter another ISBN.\n");
        }
        else break;
    }
    for(int i = index; i < bookCount - 1; i++){
        strcpy(books[i].ISBN, books[i + 1].ISBN);
        strcpy(books[i].Title, books[i + 1].Title);
        strcpy(books[i].Author, books[i + 1].Author);
        strcpy(books[i].Publisher, books[i + 1].Publisher);
        books[i].PublishYear = books[i + 1].PublishYear;
        strcpy(books[i].Category, books[i + 1].Category);
        books[i].Price = books[i + 1].Price;
        books[i].Quantity = books[i + 1].Quantity;
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
void printBookInfo(int i, Book books[MAX_BOOKS]) {
    printf("%-5d %-10s %-28s %-18s %-18s %-8d %-10s %-10.2f\n",
        i+1, books[i].ISBN, books[i].Title, books[i].Author, books[i].Publisher, books[i].PublishYear, books[i].Category, books[i].Price);
}

//Tìm kiếm sách theo ISBN
int searchBookByISBN(char isbn[], Book books[MAX_BOOKS], int bookCount) {
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].ISBN, isbn) == 0) {
            return i;
        }
    }
    return -1;
}

//Tìm kiếm sách theo tiêu đề
int searchBookByTitle(char title[], Book books[MAX_BOOKS], int bookCount) {

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].Title, title) == 0) {
			return i;
        }
    }
    return -1;
}

//In ra danh sách sách mà người đọc cụ thể đang mượn
void viewBooksOnLoan(int readerIndex, Loan loans[MAX_LOANS], int loanCount, Book books[MAX_BOOKS], int bookCount) {
    printf("List of Books on Loan:\n");
    printBookCatgorryOnLoan();
    for (int i = 0; i < loans[readerIndex].BookCount; i++) {
        int bookIndex = searchBookByISBN(loans[readerIndex].ISBN[i], books, bookCount);
        printBookInfoOnLoan(bookIndex, readerIndex, books, loans);    
    }
}

// Lập phiếu mượn sách
void createLoanSlip(Reader readers[MAX_READERS], int readerCount, Loan loans[MAX_LOANS], int& loanCount, Book books[MAX_BOOKS], int bookCount) {
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
    if(searchReaderByName(readerName, readers, readerCount) == -1 || searchReaderByID(readerID, readers, readerCount) == -1) {
        printf("Reader not found.\n");
        return;
    }
    else{
        strcpy(loans[loanCount].ReaderID, readerID);
        strcpy(loans[loanCount].ReaderName, readerName);
    }
	printf("Enter Issue Date (dd/mm/yy): ");
	inputDateValid(loans[loanCount].IssueDate);
    addDaysToDate(loans[loanCount].IssueDate, 7, loans[loanCount].DueDate);
    printf("Enter number of books to loan: ");
    scanf("%d", &loans[loanCount].BookCount);
    viewBooksList(books, bookCount);
    for (int i = 0; i < loans[loanCount].BookCount; i++) {
        char isbn[20];
        while(true){
            printf("Enter Book ISBN %d: ", i + 1);
            scanf("%s", isbn);
            if(searchBookByISBN(isbn, books, bookCount) == -1) {
                printf("Book not found.\n");
            }
            else break;
        }
        strcpy(loans[loanCount].ISBN[i], isbn);
        books[searchBookByISBN(isbn, books, bookCount)].Quantity--;
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
void printBookInfoOnLoan(int bookIndex, int readerIndex, Book books[MAX_BOOKS], Loan loans[MAX_LOANS]) {
    printf("%-5d %-10s %-28s %-18s %-18s %-8d %-10s %-10.2f %-12s %-12s %-12s\n",
        bookIndex+1, books[bookIndex].ISBN, books[bookIndex].Title, books[bookIndex].Author, books[bookIndex].Publisher, books[bookIndex].PublishYear, books[bookIndex].Category, books[bookIndex].Price, loans[readerIndex].IssueDate, loans[readerIndex].DueDate, loans[readerIndex].ReturnDate);
}

// Lập phiếu trả sách
void createReturnSlip(Reader readers[MAX_READERS], int readerCount, Loan loans[MAX_LOANS], int& loanCount, Book books[MAX_BOOKS], int bookCount) {
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
		if (strcmp(loans[i].ReaderName, readerName) == 0) {
			check = true;
			readerIndex = i;
            if(strcmp(loans[i].ReturnDate, "") == 0) {
                break;
            }
		}
    }
    if (check == false) {
        printf("Reader not found.\n");
        return;
    }

	//Nhap thong tin tra sach
    int returnCount = loans[readerIndex].BookCount;
    char isbn[MAX_ISBN_PER_LOAN][20] = {""};
    viewBooksOnLoan(readerIndex, loans, loanCount, books, bookCount);
    for(int i = 0; i < returnCount; i++) {
        strcpy(isbn[i], loans[readerIndex].ISBN[i]);
    }

    printf("Enter Return Date (dd/mm/yy): ");
    inputDateValid(loans[readerIndex].ReturnDate);
    int fineDaysPerBook = daysBetweenDates(loans[readerIndex].DueDate, loans[readerIndex].ReturnDate);
    int fineDays = 0;
    double fine = 0.0;
    for (int i = 0; i < returnCount; i++) {
        //Kiem tra sach da muon co mat khong
        int lostBook = 0;
        int bookIndex = searchBookByISBN(isbn[i], books, bookCount);
		printf("Is the book \"%s\" lost? (1: Yes, 0: No): ", books[bookIndex].Title);
		scanf("%d", &lostBook);
        if(lostBook == 1) {
            fine += (double)books[bookIndex].Price * 2;
        }
        else if(lostBook == 0)
        {
            if (fineDaysPerBook > 0) {
                fineDays += fineDaysPerBook;
            }
            books[searchBookByISBN(isbn[i], books, bookCount)].Quantity++;
        }
    }
    fine += (double)fineDays * 5000;
    printf("Fine: %.2lf\n", fine);
}

//Tổng số sách trong thư viện
int totalBooks(int bookCount, Book books[MAX_BOOKS]) {
    int total = 0;
    for (int i = 0; i < bookCount; i++) {
        total += books[i].Quantity;
    }
    return total;
}

//Thống kê số lượng sách theo từng thể loại
void booksByCategory(Book books[MAX_BOOKS], int bookCount) {
    char categories[MAX_BOOKS][50];
    int categoryCounts[MAX_BOOKS] = { 0 };
    int categoryCount = 0;
    for (int i = 0; i < bookCount; i++) {
        int found = 0;
        for (int j = 0; j < categoryCount; j++) {
            if (strcmp(categories[j], books[i].Category) == 0) {
                categoryCounts[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(categories[categoryCount], books[i].Category);
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
int totalBooksOnLoan(Loan loans[MAX_LOANS], int loanCount) {
    int total = 0;
    for(int i = 0; i < loanCount; i++) {
        total += loans[i].BookCount;
    }
    return total;
}

//In ra thông tin người mượn sách
void printLoanCat()
{
    printf("%-10s %-20s %-12s %-12s %-12s\n",
        "ID", "Name", "Issue Date", "Expiry Date", "Return Date");
}
void printLoanInfo(int i, Loan loans[MAX_LOANS]) {
    printf("%-10s %-20s %-12s %-12s %-12s\n",
        loans[i].ReaderID, loans[i].ReaderName, loans[i].IssueDate, loans[i].DueDate, loans[i].ReturnDate);
}


//Danh sách đọc giả trả sách trễ hạn
void lateReadersList(Loan loans[MAX_LOANS], int loanCount, Reader readers[MAX_READERS], int readerCount, Book books[MAX_BOOKS], int bookCount) 
{
    char loanReturnDates[MAX_LOANS][20];   
    for (int i = 0; i < loanCount; i++)
    {
        strcpy(loanReturnDates[i], loans[i].ReturnDate);
    }
    if(isArrayEmpty(loanReturnDates, MAX_LOANS)) {
        printf("No books returned\n");
        return;
    }
    printf("Late Readers List:\n");
    printLoanCat();
    int printed[MAX_LOANS] = {0};
    for (int i = 0; i < loanCount; i++) {
        int fineDays = daysBetweenDates(loans[i].DueDate, loans[i].ReturnDate);
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
            printLoanInfo(i, loans);
            printf("\tOverdue books list:\n");
            printf("\t"); printBookCatgorryOnLoan();    
            for (int j = 0; j < loans[i].BookCount; j++) {
                int bookIndex = searchBookByISBN(loans[i].ISBN[j], books, bookCount);
                printf("\t"); printBookInfoOnLoan(bookIndex, i, books, loans);
                printed[i] = 1;
            }
        }
    }
}

void readBook(const char *fileName, Book books[MAX_BOOKS], int& bookCount)
{
   FILE* f = fopen(fileName, "r");
   if (f == NULL) {
       printf("Cannot open file %s\n", fileName);
       return;
   }
   int n;
   fscanf(f, "%d\n", &n);

   for (int i = 0; i < n; i++)
   {
       endlineHandler(fgets(books[bookCount].ISBN, sizeof(books[bookCount].ISBN), f));
       endlineHandler(fgets(books[bookCount].Title, sizeof(books[bookCount].Title), f));
       endlineHandler(fgets(books[bookCount].Author, sizeof(books[bookCount].Author), f));
       endlineHandler(fgets(books[bookCount].Publisher, sizeof(books[bookCount].Publisher), f));
       fscanf(f, "%d\n", &books[bookCount].PublishYear);
       endlineHandler(fgets(books[bookCount].Category, sizeof(books[bookCount].Category), f));
       fscanf(f, "%f\n", &books[bookCount].Price);
       fscanf(f, "%d\n", &books[bookCount].Quantity);
       bookCount++;
   }
   printf("Book added successfully.\n");
   fclose(f);
}
void writeBook(const char* fileName, Book books[MAX_BOOKS], int bookCount)
{
   FILE* f = fopen(fileName, "a");
   if (f == NULL) {
       printf("Cannot open file %s\n", fileName);
       return;
   }

   fprintf(f, "%d\n", bookCount);
   for (int i = 0; i < bookCount; i++) {
       fprintf(f, "%d\n", i + 1);
       fprintf(f, "%s\n", books[i].ISBN);
       fprintf(f, "%s\n", books[i].Title);
       fprintf(f, "%s\n", books[i].Author);
       fprintf(f, "%s\n", books[i].Publisher);
       fprintf(f, "%d\n", books[i].PublishYear);
       fprintf(f, "%s\n", books[i].Category);
       fprintf(f, "%.2f\n", books[i].Price);
       fprintf(f, "%d\n", books[i].Quantity);
   }

   fclose(f);
}
