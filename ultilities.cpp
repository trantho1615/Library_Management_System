#include "Library.h"
#include "ultilities.h"

//Kiểm tra chuỗi ngày tháng năm
bool isValidDate(const char* dateStr, int day, int month, int year) {
    stringToDate(dateStr, day, month, year);
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (month == 2) {
        if (isLeap && day > 29) {
            return false;
        } else if (!isLeap && day > 28) {
            return false;
        }
    }
    return true;
}
void inputDateValid(char* dateStr) {
    int day, month, year;
    while(true){
        cin.getline(dateStr, 11);
        stringToDate(dateStr, day, month, year);
        if(isValidDate(dateStr, day, month, year)) {
            break;
        }
        else {
            printf("Invalid date. Please enter again: ");
        }
    }
    snprintf(dateStr, 11, "%02d/%02d/%04d", day, month, year);
}

//Trả về days ngày sau, để tính hạn trả sách
void addDaysToDate(const char* dateStr, int days, char* newDateStr) {
    int day, month, year;
    char tempStr[11];
    strcpy(tempStr, dateStr);

    char* token = strtok(tempStr, "/");
    day = atoi(token);
    token = strtok(NULL, "/");
    month = atoi(token);
    token = strtok(NULL, "/");
    year = atoi(token);

    // Days in each month
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Check for leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[1] = 29;
    }

    day += days;

    while (day > daysInMonth[month - 1]) {
        day -= daysInMonth[month - 1];
        month++;
        if (month > 12) {
            month = 1;
            year++;
            // Check for leap year again
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                daysInMonth[1] = 29;
            }
            else {
                daysInMonth[1] = 28;
            }
        }
    }
    snprintf(newDateStr, 11, "%02d/%02d/%04d", day, month, year);
}

//Trả về chuỗi mới sau months tháng, để tính hạn thẻ
void addMonthsToDate(const char* dateStr, int months, char* newDateStr) 
{
    int day, month, year;
    char tempStr[11];
    strcpy(tempStr, dateStr);

    char* token = strtok(tempStr, "/");
    day = atoi(token);
    token = strtok(NULL, "/");
    month = atoi(token);
    token = strtok(NULL, "/");
    year = atoi(token);

    month += months;
    while (month > 12) {
        month -= 12;
        year++;
    }
    snprintf(newDateStr, 11, "%02d/%02d/%04d", day, month, year);
}

//Các hàm hỗ trợ trả sách
// Check leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Convert string to date
void stringToDate(const char* dateStr, int& day, int& month, int& year) {
    char tempStr[11];
    strcpy(tempStr, dateStr);

    char* token = strtok(tempStr, "/");
    day = atoi(token);
    token = strtok(NULL, "/");
    month = atoi(token);
    token = strtok(NULL, "/");
    year = atoi(token);
}

// Calculate the number of days in a month
int daysInMonth(int month, int year) {
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysInMonth[month - 1];
}

// Calculate the number of days from the start of the year
int daysFromStartOfYear(int day, int month, int year) {
    int days = 0;
    for (int i = 1; i < month; i++) {
        days += daysInMonth(i, year);
    }
    days += day;
    return days;
}

// Function to calculate the number of days between two dates
int daysBetweenDates(const char* dateStr1, const char* dateStr2) {
    int day1, month1, year1;
    int day2, month2, year2;

    stringToDate(dateStr1, day1, month1, year1);
    stringToDate(dateStr2, day2, month2, year2);

    int days1 = daysFromStartOfYear(day1, month1, year1);
    int days2 = daysFromStartOfYear(day2, month2, year2);

    for (int year = year1; year < year2; year++) {
        days2 += isLeapYear(year) ? 366 : 365;
    }

    return days2 - days1;
}

// Hàm kiểm tra mảng có rỗng hay không
bool isArrayEmpty(char strings[][20], int n) {
    for (int i = 0; i < n; i++) {
        if (strings[i][0] != '\0') { 
            return false;
        }
    }
    return true;

}
//Xử lí xóa kí tự xuống dòng
void endlineHandler(char* str) {
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}