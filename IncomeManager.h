#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
#include "Income.h"
#include "OperationsOnDates.h"
#include "AuxiliartMethods.h"
#include "FileWithIncomes.h"


using namespace std;

class IncomeManager {

    FileWithIncomes fileWithIncomes;

    vector<Income> incomes;
    Income addIncomeData(int userId, string date);

    int  getIncomeId();
    void displayIncomeData (Income income);
    string selectDate();

public:
    IncomeManager (string incomesFileName): fileWithIncomes(incomesFileName) {

    };
    void addIncome(int userId);
    void loadIncomesFromFile(int userId);
    double balanceForTheCurrentMonth(int integerFirstDayOfTheMonth, int integerLastDayOfTheMonth);
    double  balanceForThePreviousMonth(int integerFirstDayOfTheMonth, int integerLastDayOfTheMonth);
    double incomeBalanceForTheSelectedPeriod(int startingDate, int endDate);


    struct before {
        inline bool operator() ( Income& struct1,  Income& struct2) {
            return (struct1.getDate() < struct2.getDate());
        }
    };



};
#endif
