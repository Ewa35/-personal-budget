#include"BudgetManager.h"


void BudgetManager::addIncome() {
    system ("cls");

    incomeManager.addIncome(LOGGED_USER_ID);

}
void BudgetManager::addExpense() {
    system ("cls");

    expenseManager.addExpense(LOGGED_USER_ID);
}
void BudgetManager::balanceCurrentMonths() {
    system ("cls");

    string currentDate="", firstDayOfTheMonth="", lastDayOfTheMonth="";
    int integerFirstDayOfTheMonth=0, integerLastDayOfTheMonth=0;
    double sumExpenses=0, sumInocmes=0, differenceBetweenIncomeAndExpenses=0;
    currentDate=OperationsOnDates::todaysDate();
    firstDayOfTheMonth=OperationsOnDates::downloadFirstDayOfTheMonth(currentDate);
    lastDayOfTheMonth=OperationsOnDates::downloadLastDayOfTheMonth(currentDate);
    integerFirstDayOfTheMonth=AuxiliartMethods::conversionStringForInt(firstDayOfTheMonth);
    integerLastDayOfTheMonth=AuxiliartMethods::conversionStringForInt(lastDayOfTheMonth);

    cout<<endl<<"DOCHODY BIERZACEGO MIESIACA: "<<endl;
    sumInocmes=incomeManager.balanceForTheCurrentMonth(integerFirstDayOfTheMonth, integerLastDayOfTheMonth);
    cout<<endl<<endl<<" WYDATKI BIERZACEGO MIESIACA: "<<endl;
    sumExpenses=expenseManager.balanceForTheCurrentMonth(integerFirstDayOfTheMonth, integerLastDayOfTheMonth);
    differenceBetweenIncomeAndExpenses=sumInocmes-sumExpenses;
    cout<<endl<<endl<<"SALDO KONTA W BIERZACYM MIESIACU WYNOSI: "<<differenceBetweenIncomeAndExpenses<<endl;
    system ("pause");
}
void  BudgetManager::balanceOfThePreviousMonth() {
    system ("cls");

    string currentDate="", dateOfThePreviousMonth="", firstDayOfTheMonth="", lastDayOfTheMonth="";
    int integerFirstDayOfTheMonth=0, integerLastDayOfTheMonth=0;
    double sumExpenses=0, sumInocmes=0, differenceBetweenIncomeAndExpenses=0;
    currentDate=OperationsOnDates::todaysDate();
    dateOfThePreviousMonth=OperationsOnDates::SetTheDateBackOneMonth(currentDate);
    firstDayOfTheMonth=OperationsOnDates::downloadFirstDayOfTheMonth(dateOfThePreviousMonth);
    lastDayOfTheMonth=OperationsOnDates::downloadLastDayOfTheMonth(dateOfThePreviousMonth);
    integerFirstDayOfTheMonth=AuxiliartMethods::conversionStringForInt(firstDayOfTheMonth);
    integerLastDayOfTheMonth=AuxiliartMethods::conversionStringForInt(lastDayOfTheMonth);
    cout<<endl<<"DOCHODY POPRZEDNIEGO MIESIACA: "<<endl;
    sumInocmes=incomeManager.balanceForThePreviousMonth(integerFirstDayOfTheMonth, integerLastDayOfTheMonth);
    cout<<endl<<"WYDATKI POPRZEDNIEGO MIESIACA: "<<endl;
    sumExpenses=expenseManager.balanceForThePreviousMonth(integerFirstDayOfTheMonth, integerLastDayOfTheMonth);
     differenceBetweenIncomeAndExpenses=sumInocmes-sumExpenses;
    cout<<endl<<endl<<"SALDO KONTA W POPRZEDNIM MIESIACU WYNOSI: "<<differenceBetweenIncomeAndExpenses<<endl;
     system ("pause");

}
void  BudgetManager::balanceSelectedPeriodOfTime() {
    system ("cls");

    string startingDateOfTheBalance="", endDateOfTheBalance="";
    int startingDate=0, endDate=0;
    double sumExpenses=0, sumInocmes=0, differenceBetweenIncomeAndExpenses=0;

    cout<<"Podaj date, od ktorej chcesz wyswietlic bilans w formacie rrrr-mm-dd"<<endl;
    cin>>startingDateOfTheBalance;
    if (OperationsOnDates::checkTheCorrectnessOfTheDate(startingDateOfTheBalance)) {
        cout<<"Podaj date, do ktorej chcesz wyswietlic bilans w formacie rrrr-mm-dd"<<endl;
        cin>>endDateOfTheBalance;

        if (OperationsOnDates::checkTheCorrectnessOfTheDate(endDateOfTheBalance)) {
            system ("cls");
            startingDate=AuxiliartMethods::conversionStringForInt(startingDateOfTheBalance);
            endDate=AuxiliartMethods::conversionStringForInt(endDateOfTheBalance);
            if (startingDate<endDate)
            {
            cout<<endl<<"PRZYCHODY DLA PRZEDZIALU CZASU OD "<< startingDateOfTheBalance<< " DO "<< endDateOfTheBalance<<endl;
            sumInocmes=incomeManager.incomeBalanceForTheSelectedPeriod(startingDate, endDate);
            cout<<endl<<endl<<"WYDATKI DLA PRZEDZIALU CZASU OD "<< startingDateOfTheBalance<< " DO "<< endDateOfTheBalance<<endl;
            sumExpenses=expenseManager.expenseBalanceForTheSelectedPeriod(startingDate, endDate);
            differenceBetweenIncomeAndExpenses=sumInocmes-sumExpenses;
    cout<<endl<<endl<<"SALDO KONTA W WYBRANYM PRZEDZIALE CZASU WYNOSI: "<<differenceBetweenIncomeAndExpenses<<endl;
            }
            else
            {
                cout<<" Wybrano bledny zakres dat"<<endl;
            }

        }
    } else {
        cout<<"Podana data jest bledna. "<<endl;
    }
        system ("pause");
        return ;
}
