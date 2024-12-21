#include "Library.h"
#include "Reader.h"
#include "ultilities.h"


//Xem danh sách độc giả, chú ý maximize màn hình console để được aligment đẹp
void viewReadersList(Reader readers[MAX_READERS], int readerCount) {
    if(readerCount == 0){cout << "Empy reader list\n"; return;}
    printReaderCatgorry();
    for (int i = 0; i < readerCount; i++) {
        printf("%-5d %-10s %-20s %-15s %-12s %-10s %-12s %-12s %-20s %-20s\n",
            i + 1, readers[i].ID, readers[i].Name, readers[i].CMND, readers[i].Birthday, readers[i].Gender, readers[i].IssueDate, readers[i].ExpiryDate, readers[i].Email, readers[i].Address);
    }
}


//Thêm độc giả mới, có thể chọn số lượng muốn thêm 
void addReader(int& n, Reader readers[MAX_READERS], int& readerCount) {
    printf("Enter number of readers to add: ");
    scanf("%d", &n);
    if (readerCount >= MAX_READERS) {
        printf("Reader list is full.\n");
        return;
    }
    cin.ignore();
    for(int i = 0; i < n; i++){
        while(true){
            printf("Enter Reader ID: ");
            char id[20];
            cin.getline(id, 20);
            if(searchReaderByID(id, readers, readerCount) != -1) {
                printf("Reader ID already exists. Please enter another one.\n");
            }
            else {
                strcpy(readers[readerCount].ID, id);
                break;
            }
        }
        printf("Enter Reader Name: ");
        cin.getline(readers[readerCount].Name, 50);
        while(true){
            printf("Enter Reader CMND: ");
            char cmnd[20];
            cin.getline(cmnd, 20);
            if(searchReaderByCMND(cmnd, readers, readerCount) != -1) {
                printf("Reader ID already exists. Please enter another one.\n");
            }
            else {
                strcpy(readers[readerCount].CMND, cmnd);
                break;
            }
        }
        printf("Enter Reader Birthday (dd/mm/yyyy): ");
        inputDateValid(readers[readerCount].Birthday);
        printf("Enter Reader Gender: ");
        cin.getline(readers[readerCount].Gender, 10);
        printf("Enter Reader Email: ");
        cin.getline(readers[readerCount].Email, 50);
        printf("Enter Reader Address: ");
        cin.getline(readers[readerCount].Address, 100);
        printf("Enter Reader Issue Date (dd/mm/yyyy): ");
        inputDateValid(readers[readerCount].IssueDate);
        strcpy(readers[readerCount].ExpiryDate, readers[readerCount].IssueDate);
        addMonthsToDate(readers[readerCount].IssueDate, 48, readers[readerCount].ExpiryDate);
        readerCount++;
        printf("Reader added successfully.\n");
    }
}

//Chỉnh sửa thông tin độc giả
void editReader(Reader readers[MAX_READERS], int readerCount) {
    int index;
    while(true){
        char id[20];
        printf("Enter Reader ID: ");
        scanf("%s", id);
        index = searchReaderByID(id, readers, readerCount);
        if(index == -1) {
            printf("Reader not found. Please enter another ID.\n");
        }
        else break;
    }
    int choice;
    while (true) {
        printf("Choose information to edit: \n");
        printf("1. ID\n");
        printf("2. Name\n");
        printf("3. CMND\n");
        printf("4. Birthday\n");
        printf("5. Gender\n");
        printf("6. Email\n");
        printf("7. Address\n");
        printf("8. Issue Date\n");
        printf("0. Back to MENU\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
        {   
            cin.ignore();
            while(true){
            printf("Enter New Reader's ID: ");
            char id[20];
            cin.getline(id, 20);
            if(searchReaderByID(id, readers, readerCount) != -1) {
                printf("Reader's ID already exists. Please enter another one.\n");
            }
            else {
                strcpy(readers[index].ID, id);
                break;
            }
            }
            break;
        }
        case 2:
        {   
            printf("Enter new Reader Name: ");
            cin.ignore();
            cin.getline(readers[index].Name, 50);
            break;
        }
        case 3:
        {   
            cin.ignore();
            while(true){
            printf("Enter New Reader's CMND: ");
            char cmnd[20];
            cin.getline(cmnd, 20);
            if(searchReaderByCMND(cmnd, readers, readerCount) != -1) {
                printf("Reader's CMND already exists. Please enter another one.\n");
            }
            else {
                strcpy(readers[index].CMND, cmnd);
                break;
            }
            }
            break;
        }
        case 4:
        {   printf("Enter new Reader Birthday (dd/mm/yyyy): ");
            cin.ignore();
            cin.getline(readers[index].Birthday, 20);
            break;
            }
        case 5:
        {   
            printf("Enter new Gender: ");
            cin.ignore();
            cin.getline(readers[index].Gender, 10);
            break;
            }
        case 6:
        {   
            cin.ignore();
            while(true){
            printf("Enter New Reader's Email: ");
            char email[50];
            cin.getline(email, 50);
            if(searchReaderByEmail(email, readers, readerCount) != -1) {
                printf("Reader's Email already exists. Please enter another one.\n");
            }
            else {
                strcpy(readers[index].Email, email);
                break;
            }
            }
            break;
        }
        case 7:
        {   
            printf("Enter new Address: ");
            cin.ignore();
            cin.getline(readers[index].Address, 100);
            break;
        }
        case 8:
        {   
            printf("Enter new Issue Date (dd/mm/yyyy): ");
            cin.ignore();
            cin.getline(readers[index].IssueDate, 20);
            strcpy(readers[index].ExpiryDate, readers[index].IssueDate);
            addMonthsToDate(readers[index].IssueDate, 48, readers[index].ExpiryDate);
            break;
        }
        case 0:
            return;
        default:
        {   
            printf("Invalid choice. Please enter again.\n");
            break;
        }
        }
    }
}

//Xóa đọc giả
void deleteReader(Reader readers[MAX_READERS], int& readerCount) {  
    char id[20];
    int idx;
    viewReadersList(readers, readerCount);
    while(true){
        printf("Enter Reader ID to delete: ");
        scanf("%s", id);
        idx = searchReaderByID(id, readers, readerCount);
        if(idx == -1) {
            printf("Reader not found. Please enter another ID.\n");
        }
        else break;
    }
    for(int i = idx; i < readerCount - 1; i++){
        strcpy(readers[i].ID, readers[i + 1].ID);
        strcpy(readers[i].Name, readers[i + 1].Name);
        strcpy(readers[i].CMND, readers[i + 1].CMND);
        strcpy(readers[i].Birthday, readers[i + 1].Birthday);
        strcpy(readers[i].Gender, readers[i+1].Gender);
        strcpy(readers[i].Email, readers[i + 1].Email);
        strcpy(readers[i].Address, readers[i + 1].Address);
        strcpy(readers[i].IssueDate, readers[i + 1].IssueDate);
        strcpy(readers[i].ExpiryDate, readers[i + 1].ExpiryDate);
    }
    readerCount--;
    printf("Reader deleted successfully.\n");            
}

//In ra thông tin của 1 đọc giả cụ thể
void printReaderCatgorry() {
    printf("%-5s %-10s %-20s %-15s %-12s %-10s %-12s %-12s %-20s %-20s\n",
        "STT", "ID", "Name", "CMND", "Birthday", "Gender", "Issue Date", "Expiry Date", "Email", "Address");
}
void printReaderInfo(int i, Reader readers[MAX_READERS])
{
    printf("%-5d %-10s %-20s %-15s %-12s %-10s %-12s %-12s %-20s %-20s\n",
        i + 1, readers[i].ID, readers[i].Name, readers[i].CMND, readers[i].Birthday, readers[i].Gender, readers[i].IssueDate, readers[i].ExpiryDate, readers[i].Email, readers[i].Address);
}


//Tìm kiếm đọc giả theo CMND
int searchReaderByCMND(char cmnd[], Reader readers[MAX_READERS], int readerCount) 
{
    for (int i = 0; i < readerCount; i++) {
        if (strcmp(readers[i].CMND, cmnd) == 0) {
			return i;
        }
    }
    return -1;
}

//Tìm kiếm đọc giả theo ID
int searchReaderByID(char id[], Reader readers[MAX_READERS], int readerCount) {
    for (int i = 0; i < readerCount; i++) {
        if (strcmp(readers[i].ID, id) == 0) {
            return i;
        }
    }
    return -1;
}

//Tìm kiếm đọc giả theo tên
int searchReaderByName(char name[], Reader readers[MAX_READERS], int readerCount) {
    for (int i = 0; i < readerCount; i++) {
        if (strcmp(readers[i].Name, name) == 0) {
            return i;
        }
    }
    return -1;
}

//Tìm kiếm đọc giả theo email
int searchReaderByEmail(char email[], Reader readers[MAX_READERS], int readerCount) {
    for (int i = 0; i < readerCount; i++) {
        if (strcmp(readers[i].Email, email) == 0) {
            return i;
        }
    }
    return -1;
}
    
//Tổng số đọc giả
int totalReaders(int readerCount)
{
    return readerCount;
}

//Thống kê số lượng đọc giả theo giới tính
void readersByGender(Reader readers[MAX_READERS], int readerCount) {
    int maleCount = 0, femaleCount = 0;
    for (int i = 0; i < readerCount; i++) {
        if (strcmp(readers[i].Gender, "Male") == 0) {
            maleCount++;
        }
        else if (strcmp(readers[i].Gender, "Female") == 0) {
            femaleCount++;
        }
    }   
    printf("Readers by Gender:\n");
    printf("Male: %d\n", maleCount);
    printf("Female: %d\n", femaleCount);
}

void readReader(const char* fileName, Reader readers[MAX_READERS], int& readerCount)
{
   FILE* f = fopen(fileName, "r");
   if (f == NULL) {
       printf("Cannot open file %s\n", fileName);
       return;
   }
   int n;
   fscanf(f, "%d\n", &n);

   for(int i = 0; i < n; i++){
       endlineHandler(fgets(readers[readerCount].ID, sizeof(readers[readerCount].ID), f));
       endlineHandler(fgets(readers[readerCount].Name, sizeof(readers[readerCount].Name), f));
       endlineHandler(fgets(readers[readerCount].CMND, sizeof(readers[readerCount].CMND), f));
       endlineHandler(fgets(readers[readerCount].Birthday, sizeof(readers[readerCount].Birthday), f));
       endlineHandler(fgets(readers[readerCount].Gender, sizeof(readers[readerCount].Gender), f));
       endlineHandler(fgets(readers[readerCount].Email, sizeof(readers[readerCount].Email), f));
       endlineHandler(fgets(readers[readerCount].Address, sizeof(readers[readerCount].Address), f));
       endlineHandler(fgets(readers[readerCount].IssueDate, sizeof(readers[readerCount].IssueDate), f));
       strcpy(readers[readerCount].ExpiryDate, readers[readerCount].IssueDate);
       addMonthsToDate(readers[readerCount].IssueDate, 48, readers[readerCount].ExpiryDate);
       readerCount++;
   }
   printf("Readers added successfully.\n");
   fclose(f);
}

void writeReader(const char* fileName, Reader readers[MAX_READERS], int readerCount)
{
   FILE* f = fopen(fileName, "a");
   if (f == NULL) {
       printf("Cannot open file %s\n", fileName);
       return;
   }
   fprintf(f, "%d\n", readerCount);
   for (int i = 0; i < readerCount; i++) {
       fprintf(f, "%d\n", i + 1);
       fprintf(f, "%s\n", readers[i].ID);   
       fprintf(f, "%s\n", readers[i].Name);
       fprintf(f, "%s\n", readers[i].CMND);
       fprintf(f, "%s\n", readers[i].Birthday);
       fprintf(f, "%s\n", readers[i].Gender);
       fprintf(f, "%s\n", readers[i].IssueDate);
       fprintf(f, "%s\n", readers[i].ExpiryDate);
       fprintf(f, "%s\n", readers[i].Email);
       fprintf(f, "%s\n", readers[i].Address);
   }
   fclose(f);
}
