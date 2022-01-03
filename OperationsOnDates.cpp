#include "OperationsOnDates.h"

string OperationsOnDates::todaysDate() {
    time_t currentTime;
    tm *date;
    char todaysDate [11];
    time( & currentTime );
    date = localtime( & currentTime );
    strftime( todaysDate, 11, "%Y-%m-%d", date );
    return todaysDate;
}
bool OperationsOnDates::checkTheCorrectnessOfTheDate(string date) {
    int day=0, month=0, year=0;
    int currentDay=0, currentMonth=0, currentYear=0;
    int daysInAMonth=0;
    string currentDate="";
    currentDate=todaysDate();
    conversionCharONInt( date,   day,   month,  year);
    conversionCharONInt(  currentDate,  currentDay,  currentMonth,  currentYear);
    if (year>=2000 && year<=currentYear) {
        if (month>=1 && month<=currentMonth|| currentYear>year) {
            daysInAMonth=numberDaysOfTheMonth( month,  year);
            if (day>=1 && day<= daysInAMonth) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void OperationsOnDates::conversionCharONInt(string date, int &day, int &month, int &year) {

    string dayBuffer, monthBuffer, yearBuffer;
    for (int i=0; i<10; i++) {
        if (i==0 || i<=3) {
            yearBuffer+=date[i];
        }
        if (i==5 || i==6) {
            monthBuffer+=date[i];
        }
        if (i==8 || i==9) {
            dayBuffer+=date[i];
        }
    }
    day = atoi(dayBuffer.c_str());
    month = atoi(monthBuffer.c_str());
    year = atoi(yearBuffer.c_str());
}

int OperationsOnDates::numberDaysOfTheMonth (int monthNumber, int year) {
    int numberDaysInAMonth=0;
    switch(monthNumber) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        numberDaysInAMonth=31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        numberDaysInAMonth=30;
        break;

    case 2: {

        if (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0))
            numberDaysInAMonth=29;
        else
            numberDaysInAMonth=28;
    }
    break;
    default:
        cout<<"Niepoprawny numer miesiaca!";

    }
    return numberDaysInAMonth;
}
string OperationsOnDates::changeTheDateFormat(int date) {
    string buffor;
    string correctDateFormat;
    buffor=AuxiliartMethods::conversionIntForString(date);

    for(int i=0; i<buffor.length(); i++) {
        correctDateFormat+=buffor[i];
        if (i==3 || i==5 ) {
            correctDateFormat+="-";
        }
    }
    return correctDateFormat;
}

string OperationsOnDates::getNumberDaysOfTheMonth (string date) {
    string  monthBuffer, yearBuffer;
    int month, year;
    string numberDays;
    for (int i=0; i<10; i++) {
        if (i==0 || i<=3) {
            yearBuffer+=date[i];
        }
        if (i==5 || i==6) {
            monthBuffer+=date[i];
        }

    }
    month = atoi(monthBuffer.c_str());
    year = atoi(yearBuffer.c_str());
    numberDays = AuxiliartMethods::conversionIntForString(numberDaysOfTheMonth ( month,  year));
    return numberDays;
}
string OperationsOnDates::downloadFirstDayOfTheMonth(string currentDate) {
    string firstDayOfTheMonth;
    for (int i=0; i<=currentDate.length(); i++) {
        if (i==8) {
            firstDayOfTheMonth+="0";
        } else if (i==9) {
            firstDayOfTheMonth+="1";
        } else
            firstDayOfTheMonth+=currentDate[i];
    }
    return firstDayOfTheMonth;
}
string OperationsOnDates::downloadLastDayOfTheMonth(string currentDate) {
    string lastDayOfTheMonth;
    for (int i=0; i<=currentDate.length()-3; i++) {

        lastDayOfTheMonth+=currentDate[i];
    }
    lastDayOfTheMonth+=OperationsOnDates::getNumberDaysOfTheMonth(currentDate);
    return lastDayOfTheMonth;
}
string OperationsOnDates::SetTheDateBackOneMonth(string date) {
    string month="";
    int monthNumber=0;
    month[0]=date[5];
    month[1]=date[6];
    monthNumber=atoi(month.c_str());
    if (monthNumber==1) {
        monthNumber=12;
        date=SetTheDateBackOneYear(date);
    } else {
        monthNumber-=1;
    }
    month=AuxiliartMethods::conversionIntForString(monthNumber);
    if (monthNumber<10) {
        date[5]='0';
        date[6]=month[0];
    } else {
        date[5]=month[0];
        date[6]=month[1];
    }
    return date;
}
string OperationsOnDates::SetTheDateBackOneYear(string date) {
    string year="";
    int numberYear=0;
    for (int i=0; i<=3; i++) {
        year+=date[i];
    }
    numberYear=atoi(year.c_str());
    numberYear--;
    year=AuxiliartMethods::conversionIntForString(numberYear);
    for (int i=0; i<=3; i++) {
        date[i]=year[i];
    }
    return date;
}
