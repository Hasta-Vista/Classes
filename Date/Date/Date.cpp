#include <iostream> 
using namespace std;
class Date {
private:
    int year;
    int month;
    int day;
    int DaysInFeb(int year) const {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    int DaysInMonth(int month, int year) const {
        switch (month) {
        case 2:
            return DaysInFeb(year);
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        default:
            return 30;
        }
    }
    bool CorrectDate() {
        if (year < 1 || month < 1 || month > 12 ||
            day > DaysInMonth(month, year) || day < 1) {
            return false;
        }
        return true;
    }
    int DaysInYear(int year) const {
        return (DaysInFeb(year) == 29) ? 366 : 365;
    }
    int DateToDays() const {
        int days = day;
        for (int i = 1; i != month; ++i) {
            days += DaysInMonth(i, year);
        }
        for (int i = 1; i != year; ++i) {
            days += DaysInYear(i);
        }
        return days;
    }
    void DaysToDate(int days) {
        year = 1;
        month = 1;
        day = 1;
        while (true) {
            if (days <= DaysInMonth(month, year)) {
                break;
            }
            days -= DaysInMonth(month, year);
            month++;
            if (month > 12) {
                year++;
                month = 1;
            }
        }
        day = days;
    }
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {
        if (CorrectDate() == false) {
            year = 1970;
            month = 1;
            day = 1;
        }
    }
    int GetDay() const {
        return day;
    }

    int GetMonth() const {
        return month;
    }

    int GetYear() const {
        return year;
    }
    Date operator + (const int days) {
        Date newDate(*this);
        newDate.DaysToDate(newDate.DateToDays() + days);
        return newDate;
    }
    Date operator - (const int days) {
        Date newDate(*this);
        newDate.DaysToDate(newDate.DateToDays() - days);
        return newDate;
    }
    int operator - (const Date& other) {
        return DateToDays() - other.DateToDays();
    }
    friend ostream& operator << (ostream& os, const Date& date) {
        os << "Year - " << date.GetYear() << endl << "Month - " << date.GetMonth() << endl << "Day - " << date.GetDay() << endl;
        return os;
    }
};
int main() {
    int year, month, day, days;
    cin >> year >> month >> day;
    Date date(year, month, day);
    cin >> days;
    cout << endl;
    Date DatePlus = date - days;
    cout << "Subtraction:" << endl;
    cout << DatePlus << endl;
    Date DateMinus = date + days;
    cout << "Addition:" << endl;
    cout << DateMinus << endl;
    cin >> year >> month >> day;
    cout << endl;
    Date otherDate(year, month, day);
    int difference = date - otherDate;
    cout << "Difference between two dates - " << difference << " days";
    return 0;
}
