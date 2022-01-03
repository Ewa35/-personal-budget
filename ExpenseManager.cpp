#include "ExpenseManager.h"

void ExpenseManager::addExpense(int userId) {
    Expense expense;
    string date="";
    system("cls");
    cout << " >>> DODAJ KOSZT <<<" << endl << endl;
    date=selectDate();
    if (date!="") {
        if (OperationsOnDates::checkTheCorrectnessOfTheDate(date)) {
            expense=addExpenseData(userId, date);
            expenses.push_back(expense);
            if(fileWithExpenses.saveExpenseToFile(expense)) {
                cout<<"Wydatek zostal dodany."<<endl;
            } else {
                cout<<"Blad. Nie udalo sie dodac nowego wydatku do pliku." <<endl;
            }

        } else
            cout<<"data jest niepoprawna"<<endl;
    }
    system("pause");
}

string ExpenseManager::selectDate() {
    string date="";
    char choice;
    cout<<"Czy chcesz dodac wydatek z data dnia dzisiejszego?"<<endl;
    cout<<" 1. TAK"<<endl;
    cout<<" 2. NIE"<<endl;
    cin>>choice;
    switch (choice) {
    case '1':

        date=OperationsOnDates::todaysDate();
        break;
    case '2':
        cout<<"Podaj date w formacie: rrrr-mm-dd"<<endl;//mo¿e mo¿na wymusiæ wpisanie daty w odpowiednim formacie
        date=AuxiliartMethods:: loadLine();
        break;

    default:
        cout<<"Brak wybranej opcji"<<endl;
        break;
    }
    return date;
}
Expense ExpenseManager::addExpenseData(int userId, string date) {
    Expense expense;
    string expenseCategory="", value="";
    int dateOfExpense=0;
    double expenseValue=0;
    int expenseId=0;
    expenseId=getExpenseId();

    dateOfExpense=AuxiliartMethods::conversionStringForInt(date);

    cout<<"Podaj kategorie wydatku"<<endl;
    expenseCategory=AuxiliartMethods:: loadLine();
    cout<<"Podaj wartosc wydatku"<<endl;
    cin>>value;
    expenseValue=AuxiliartMethods::conversionStringForDouble(value);

    expense.setUserId(userId);
    expense.setId(expenseId);
    expense.setDate(dateOfExpense);
    expense.setIncomeCategory (expenseCategory);
    expense.setValue(expenseValue);

    return expense;

}
int ExpenseManager :: getExpenseId() {
    if (expenses.empty())
        return 1;
    else
        return expenses.back().getId() + 1;
}
void ExpenseManager :: wypisz() {

    for (int i=0; i<expenses.size(); i++) {
        cout<<expenses[i].getUserId()<<"  ";
        cout<<expenses[i].getId()<<"  ";
        cout<<expenses[i].getIncomeCategory()<<"  ";
        cout<<OperationsOnDates::changeTheDateFormat(expenses[i].getDate())<<"  ";
        cout<<expenses[i].getValue()<<endl;
    }
}
void ExpenseManager ::loadExpensesFromFile(int userId) {
    expenses.clear();
    expenses=fileWithExpenses.loadExpensesFromFile(userId);
    sort( expenses.begin(), expenses.end(), before() );
}
double ExpenseManager  :: balanceForTheCurrentMonth(int integerFirstDayOfTheMonth, int integerLastDayOfTheMonth) {


    double totalExpense=0;
    int numberOfHits=0;

    for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); ++itr) {
        if (itr->getDate() >=integerFirstDayOfTheMonth && itr->getDate()<=integerLastDayOfTheMonth) {
            displayExpenseData(*itr);
            totalExpense+=itr->getValue();
            numberOfHits++;
        }
    }
    if (numberOfHits==0)
        cout<<" Brak wydatkow w bierzacym miesiacu"<<endl;
    else {
        cout<<endl<<"Calkowita watrosc wydatkow w bierzacym miesiacu:   "<< totalExpense<<endl;
    }
    return totalExpense;
}
void ExpenseManager ::displayExpenseData (Expense expense) {
    cout<<endl<<"  kategoria wydatku:  "<< expense.getIncomeCategory()<<"  data:  "<< OperationsOnDates::changeTheDateFormat(expense.getDate())<<"  watrosc wydatku:  "<< expense.getValue();
}
double ExpenseManager  :: balanceForThePreviousMonth(int integerFirstDayOfTheMonth, int integerLastDayOfTheMonth) {

     double totalExpense=0;
    int numberOfHits=0;

    for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); ++itr) {
        if (itr->getDate() >=integerFirstDayOfTheMonth && itr->getDate()<=integerLastDayOfTheMonth) {
            displayExpenseData(*itr);
            totalExpense+=itr->getValue();
            numberOfHits++;
        }
    }
    if (numberOfHits==0)
        cout<<" Brak wydatkow w poprzednim miesiacu"<<endl;
    else {
        cout<<endl<<"Calkowita watrosc wydatkow w poprzednim miesiacu:   "<< totalExpense<<endl;
    }


    return totalExpense;
}
double ExpenseManager  ::expenseBalanceForTheSelectedPeriod(int startingDate, int endDate) {

     int  numberOfHits=0;
    double totalExpense=0;

    for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); ++itr) {
        if (itr->getDate() >=startingDate && itr->getDate()<=endDate) {
            displayExpenseData(*itr);
            totalExpense+=itr->getValue();
            numberOfHits++;
        }
    }

    if (numberOfHits==0) {
        cout<<" Brak wydatkow w wybranym przedziale czasu"<<endl;
    } else {
        cout<<endl<<"Calkowita watrosc wydatkow: "<< totalExpense<<endl;
    }


    return totalExpense;
}

