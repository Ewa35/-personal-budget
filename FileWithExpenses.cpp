#include "FileWithExpenses.h"

bool FileWithExpenses::saveExpenseToFile(Expense expense) {
    CMarkup xml;
    bool fileExists = xml.Load( EXPENSES_FILE_NAME );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("expenseId",AuxiliartMethods::conversionIntForString(expense.getId()));
    xml.AddElem("userId",AuxiliartMethods::conversionIntForString(expense.getUserId()));
    xml.AddElem("date",AuxiliartMethods::conversionIntForString (expense.getDate()));
    xml.AddElem("item", expense.getIncomeCategory());
    xml.AddElem("amount",AuxiliartMethods::conversionDoubleForString(expense.getValue()) );

    xml.OutOfElem();
    xml.Save(EXPENSES_FILE_NAME);
    return true;

}

vector<Expense> FileWithExpenses::loadExpensesFromFile(int userId) {
    CMarkup xml;
    vector<Expense> expenses;
    Expense expense;

    bool fileExists = xml.Load(EXPENSES_FILE_NAME);
    xml.FindElem();
    xml.IntoElem();
     while (xml.FindElem("Expense")) {

        xml.IntoElem();
        xml.FindElem("userId");
        if (atoi(xml.GetData().c_str())== userId){
        xml.FindElem("expenseId");
        expense.setId( atoi(xml.GetData().c_str()));
        xml.FindElem("userId");
        expense.setUserId( atoi(xml.GetData().c_str()));
        xml.FindElem("date");
        expense.setDate(atoi(xml.GetData().c_str()));
        xml.FindElem("item");
        expense.setIncomeCategory(xml.GetData());
        xml.FindElem("amount");
        expense.setValue(AuxiliartMethods::conversionStringForDouble(xml.GetData()));
        expenses.push_back(expense);

        }
        xml.OutOfElem();

     }

    xml.OutOfElem();
    return  expenses;
}
Expense FileWithExpenses:: downloadUserData(string dataFromTheFile) {
    Expense expense;
    string singleData = "";
    int numberSingleData = 1;

    for (int markPosition = 0; markPosition < dataFromTheFile.length(); markPosition++) {
        if (dataFromTheFile[markPosition] != '|') {
            singleData += dataFromTheFile[markPosition];
        } else {
            switch(numberSingleData) {
            case 1:
                expense.setUserId( atoi(singleData.c_str()));
                break;
            case 2:
                expense.setId( atoi(singleData.c_str()));
                break;
            case 3:
                expense.setDate(atoi(singleData.c_str()));
                break;
            case 4:
                expense.setIncomeCategory(singleData);
                break;
            case 5:
                expense.setValue(AuxiliartMethods::conversionStringForDouble(singleData));
                break;
            }
            singleData = "";
            numberSingleData++;
        }
    }
    return expense;
}
