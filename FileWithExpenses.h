#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include "Expense.h"
#include "Markup.h"
#include "AuxiliartMethods.h"
using namespace std;

class FileWithExpenses {

    const string EXPENSES_FILE_NAME;
    Expense  downloadUserData(string dataFromTheFile);

public:
    FileWithExpenses (string expensesFileName): EXPENSES_FILE_NAME(expensesFileName) {};
    bool saveExpenseToFile(Expense expense);
    vector<Expense> loadExpensesFromFile(int userId);



};
#endif
