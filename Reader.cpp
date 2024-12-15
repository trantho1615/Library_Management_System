#include "Library.h"
#include "Reader.h"
#include "ultilities.h"


//Xem danh sách độc giả, chú ý maximize màn hình console để được aligment đẹp
void viewReadersList(char readerIDs[MAX_READERS][20], char readerNames[MAX_READERS][50], char readerCMNDs[MAX_READERS][20], char readerBirthdays[MAX_READERS][20], char readerGenders[MAX_READERS][10], char readerEmails[MAX_READERS][50], char readerAddresses[MAX_READERS][100], char readerIssueDates[MAX_READERS][20], char readerExpiryDates[MAX_READERS][20], int readerCount) {
    printReaderCatgorry();
    for (int i = 0; i < readerCount; i++) {
        printf("%-5d %-10s %-20s %-15s %-12s %-10s %-12s %-12s %-20s %-20s\n",
            i + 1, readerIDs[i], readerNames[i], readerCMNDs[i], readerBirthdays[i], readerGenders[i],
            readerIssueDates[i], readerExpiryDates[i], readerEmails[i], readerAddresses[i]);
    }
}


//Thêm độc giả mới, có thể chọn số lượng muốn thêm 
void addReader(int& n, char readerIDs[MAX_READERS][20], char readerNames[MAX_READERS][50], char readerCMNDs[MAX_READERS][20], char readerBirthdays[MAX_READERS][20], char readerGenders[MAX_READERS][10], char readerEmails[MAX_READERS][50], char readerAddresses[MAX_READERS][100], char readerIssueDates[MAX_READERS][20], char readerExpiryDates[MAX_READERS][20], int& readerCount) {
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
            if(searchReaderByID(id, readerIDs, readerCount) != -1) {
                printf("Reader ID already exists. Please enter another one.\n");
            }
            else {
                strcpy(readerIDs[readerCount], id);
                break;
            }
        }
        printf("Enter Reader Name: ");
        cin.getline(readerNames[readerCount], 50); 
        while(true){
            printf("Enter Reader CMND: ");
            char cmnd[20];
            cin.getline(cmnd, 20);
            if(searchReaderByCMND(cmnd, readerCMNDs, readerCount) != -1) {
                printf("Reader ID already exists. Please enter another one.\n");
            }
            else {
                strcpy(readerCMNDs[readerCount], cmnd);
                break;
            }
        }
        printf("Enter Reader Birthday (dd/mm/yyyy): ");
        inputDateValid(readerBirthdays[readerCount]);
        printf("Enter Reader Gender: ");
        cin.getline(readerGenders[readerCount], 10);
        printf("Enter Reader Email: ");
        cin.getline(readerEmails[readerCount], 50);
        printf("Enter Reader Address: ");
        cin.getline(readerAddresses[readerCount], 100);
        printf("Enter Reader Issue Date (dd/mm/yyyy): ");
        inputDateValid(readerIssueDates[readerCount]);
        strcpy(readerExpiryDates[readerCount], readerIssueDates[readerCount]);
        addMonthsToDate(readerIssueDates[readerCount], 48, readerExpiryDates[readerCount]);
        readerCount++;
        printf("Reader added successfully.\n");
    }
}

//Chỉnh sửa thông tin độc giả
void editReader(char readerIDs[MAX_READERS][20], char readerNames[MAX_READERS][50], char readerCMNDs[MAX_READERS][20], char readerBirthdays[MAX_READERS][20], char readerGenders[MAX_READERS][10], char readerEmails[MAX_READERS][50], char readerAddresses[MAX_READERS][100], char readerIssueDates[MAX_READERS][20], char readerExpiryDates[MAX_READERS][20], int readerCount) {
    int index;
    while(true){
        char id[20];
        printf("Enter Reader ID: ");
        scanf("%s", id);
        index = searchReaderByID(id, readerIDs, readerCount);
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
            if(searchReaderByID(id, readerIDs, readerCount) != -1) {
                printf("Reader's ID already exists. Please enter another one.\n");
            }
            else {
                strcpy(readerIDs[index], id);
                break;
            }
            }
            break;
        }
        case 2:
        {   
            printf("Enter new Reader Name: ");
            cin.ignore();
            cin.getline(readerNames[index], 50);
            break;
        }
        case 3:
        {   
            cin.ignore();
            while(true){
            printf("Enter New Reader's CMND: ");
            char cmnd[20];
            cin.getline(cmnd, 20);
            if(searchReaderByCMND(cmnd, readerCMNDs, readerCount) != -1) {
                printf("Reader's CMND already exists. Please enter another one.\n");
            }
            else {
                strcpy(readerCMNDs[index], cmnd);
                break;
            }
            }
            break;
        }
        case 4:
        {   printf("Enter new Reader Birthday (dd/mm/yyyy): ");
            cin.ignore();
            cin.getline(readerBirthdays[index], 20);
            break;
            }
        case 5:
        {   
            printf("Enter new Gender: ");
            cin.ignore();
            cin.getline(readerGenders[index], 10);
            break;
            }
        case 6:
        {   
            cin.ignore();
            while(true){
            printf("Enter New Reader's Email: ");
            char email[50];
            cin.getline(email, 50);
            if(searchReaderByEmail(email, readerEmails, readerCount) != -1) {
                printf("Reader's Email already exists. Please enter another one.\n");
            }
            else {
                strcpy(readerEmails[index], email);
                break;
            }
            }
            break;
        }
        case 7:
        {   
            printf("Enter new Address: ");
            cin.ignore();
            cin.getline(readerAddresses[index], 100);
            break;
        }
        case 8:
        {   
            printf("Enter new Issue Date (dd/mm/yyyy): ");
            cin.ignore();
            cin.getline(readerIssueDates[index], 20);
            strcpy(readerExpiryDates[index], readerIssueDates[index]);
            addMonthsToDate(readerIssueDates[index], 48, readerExpiryDates[index]);
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
void deleteReader(char readerIDs[MAX_READERS][20], char readerNames[MAX_READERS][50], char readerCMNDs[MAX_READERS][20], char readerBirthdays[MAX_READERS][20], char readerGenders[MAX_READERS][10], char readerEmails[MAX_READERS][50], char readerAddresses[MAX_READERS][100], char readerIssueDates[MAX_READERS][20], char readerExpiryDates[MAX_READERS][20], int& readerCount) {
    char id[20];
    int idx;
    viewReadersList(readerIDs, readerNames, readerCMNDs, readerBirthdays, readerGenders, readerEmails, readerAddresses, readerIssueDates, readerExpiryDates, readerCount);
    while(true){
        printf("Enter Reader ID to delete: ");
        scanf("%s", id);
        idx = searchReaderByID(id, readerIDs, readerCount);
        if(idx == -1) {
            printf("Reader not found. Please enter another ID.\n");
        }
        else break;
    }
    for(int i = idx; i < readerCount - 1; i++){
        strcpy(readerIDs[i], readerIDs[i + 1]);
        strcpy(readerNames[i], readerNames[i + 1]);
        strcpy(readerCMNDs[i], readerCMNDs[i + 1]);
        strcpy(readerBirthdays[i], readerBirthdays[i + 1]);
        strcpy(readerGenders[i], readerGenders[i + 1]);
        strcpy(readerEmails[i], readerEmails[i + 1]);
        strcpy(readerAddresses[i], readerAddresses[i + 1]);
        strcpy(readerIssueDates[i], readerIssueDates[i + 1]);
        strcpy(readerExpiryDates[i], readerExpiryDates[i + 1]);
    }
    readerCount--;
    printf("Reader deleted successfully.\n");            
}

//In ra thông tin của 1 đọc giả cụ thể
void printReaderCatgorry() {
    printf("%-5s %-10s %-20s %-15s %-12s %-10s %-12s %-12s %-20s %-20s\n",
        "STT", "ID", "Name", "CMND", "Birthday", "Gender", "Issue Date", "Expiry Date", "Email", "Address");
}
void printReaderInfo(int i, char readerIDs[MAX_READERS][20], char readerNames[MAX_READERS][50], char readerCMNDs[MAX_READERS][20], char readerBirthdays[MAX_READERS][20], char readerGenders[MAX_READERS][10], char readerEmails[MAX_READERS][50], char readerAddresses[MAX_READERS][100], char readerIssueDates[MAX_READERS][20], char readerExpiryDates[MAX_READERS][20])
{
    printf("%-5d %-10s %-20s %-15s %-12s %-10s %-12s %-12s %-20s %-20s\n",
        i + 1, readerIDs[i], readerNames[i], readerCMNDs[i], readerBirthdays[i], readerGenders[i],
        readerIssueDates[i], readerExpiryDates[i], readerEmails[i], readerAddresses[i]);
}


//Tìm kiếm đọc giả theo CMND
int searchReaderByCMND(char cmnd[], char readerCMNDs[MAX_READERS][20], int readerCount) {
    for (int i = 0; i < readerCount; i++) {
        if (strcmp(readerCMNDs[i], cmnd) == 0) {
			return i;
        }
    }
    return -1;
}

//Tìm kiếm đọc giả theo ID
int searchReaderByID(char id[], char readerIDs[MAX_READERS][20], int readerCount) {
    for (int i = 0; i < readerCount; i++) {
        if (strcmp(readerIDs[i], id) == 0) {
            return i;
        }
    }
    return -1;
}

//Tìm kiếm đọc giả theo tên
int searchReaderByName(char name[], char readerNames[MAX_READERS][50], int readerCount) {
    for (int i = 0; i < readerCount; i++) {
        if (strcmp(readerNames[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

//Tìm kiếm đọc giả theo email
int searchReaderByEmail(char email[], char readerEmails[MAX_READERS][50], int readerCount) {
    for (int i = 0; i < readerCount; i++) {
        if (strcmp(readerEmails[i], email) == 0) {
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
void readersByGender(char readerGenders[MAX_READERS][10], int readerCount) {
    int maleCount = 0, femaleCount = 0;
    for (int i = 0; i < readerCount; i++) {
        if (strcmp(readerGenders[i], "Male") == 0) {
            maleCount++;
        }
        else if (strcmp(readerGenders[i], "Female") == 0) {
            femaleCount++;
        }
    }   
    printf("Readers by Gender:\n");
    printf("Male: %d\n", maleCount);
    printf("Female: %d\n", femaleCount);
}

//void readReader(const char* fileName, char readerIDs[MAX_READERS][20], char readerNames[MAX_READERS][50], char readerCMNDs[MAX_READERS][20], char readerBirthdays[MAX_READERS][20], char readerGenders[MAX_READERS][10], char readerEmails[MAX_READERS][50], char readerAddresses[MAX_READERS][100], char readerIssueDates[MAX_READERS][20], char readerExpiryDates[MAX_READERS][20], int& readerCount)
//{
//    FILE* f = fopen(fileName, "r");
//    if (f == NULL) {
//        printf("Cannot open file %s\n", fileName);
//        return;
//    }
//    int n;
//    fscanf(f, "%d\n", &n);
//
//    for(int i = 0; i < n; i++){
//        endlineHandler(fgets(readerIDs[readerCount], sizeof(readerIDs[readerCount]), f));
//        endlineHandler(fgets(readerNames[readerCount], sizeof(readerNames[readerCount]), f));
//        endlineHandler(fgets(readerCMNDs[readerCount], sizeof(readerCMNDs[readerCount]), f));
//        endlineHandler(fgets(readerBirthdays[readerCount], sizeof(readerBirthdays[readerCount]), f));
//        endlineHandler(fgets(readerGenders[readerCount], sizeof(readerGenders[readerCount]), f));
//        endlineHandler(fgets(readerEmails[readerCount], sizeof(readerEmails[readerCount]), f));
//        endlineHandler(fgets(readerAddresses[readerCount], sizeof(readerAddresses[readerCount]), f));
//        endlineHandler(fgets(readerIssueDates[readerCount], sizeof(readerIssueDates[readerCount]), f));
//        strcpy(readerExpiryDates[readerCount], readerIssueDates[readerCount]);
//        addMonthsToDate(readerIssueDates[readerCount], 48, readerExpiryDates[readerCount]);
//        readerCount++;
//    }
//    printf("Readers added successfully.\n");
//    fclose(f);
//}
//
//void writeReader(const char* fileName, char readerIDs[MAX_READERS][20], char readerNames[MAX_READERS][50], char readerCMNDs[MAX_READERS][20], char readerBirthdays[MAX_READERS][20], char readerGenders[MAX_READERS][10], char readerEmails[MAX_READERS][50], char readerAddresses[MAX_READERS][100], char readerIssueDates[MAX_READERS][20], char readerExpiryDates[MAX_READERS][20], int readerCount)
//{
//    FILE* f = fopen(fileName, "w");
//    if (f == NULL) {
//        printf("Cannot open file %s\n", fileName);
//        return;
//    }
//    fprintf(f, "%d\n", readerCount);
//    for (int i = 0; i < readerCount; i++) {
//        fprintf(f, "%d\n", i + 1);
//        fprintf(f, "%s\n", readerIDs[i]);
//        fprintf(f, "%s\n", readerNames[i]);
//        fprintf(f, "%s\n", readerCMNDs[i]);
//        fprintf(f, "%s\n", readerBirthdays[i]);
//        fprintf(f, "%s\n", readerGenders[i]);
//        fprintf(f, "%s\n", readerIssueDates[i]);
//        fprintf(f, "%s\n", readerExpiryDates[i]);
//        fprintf(f, "%s\n", readerEmails[i]);
//        fprintf(f, "%s\n", readerAddresses[i]);
//    }
//    fclose(f);
//}
