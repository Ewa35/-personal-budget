#include "FileWithIncomes.h"

bool FileWithIncomes::saveIncomeToFile(Income income) {

    CMarkup xml;
    bool fileExists = xml.Load( INCOMES_FILE_NAME );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("incomeId",AuxiliartMethods::conversionIntForString(income.getId()));
    xml.AddElem("userId",AuxiliartMethods::conversionIntForString(income.getUserId()));
    xml.AddElem("date",AuxiliartMethods::conversionIntForString (income.getDate()));
    xml.AddElem("item", income.getIncomeCategory());
    xml.AddElem("amount",AuxiliartMethods::conversionDoubleForString(income.getValue()) );

    xml.OutOfElem();
    xml.Save(INCOMES_FILE_NAME);
    return true;
}

vector<Income> FileWithIncomes::loadIncomesFromFile(int userId) {
    CMarkup xml;
    vector<Income> incomes;
    Income income;

    bool fileExists = xml.Load( INCOMES_FILE_NAME );
    xml.FindElem();
    xml.IntoElem();
     while (xml.FindElem("Income")) {

        xml.IntoElem();
        xml.FindElem("userId");
        if (atoi(xml.GetData().c_str())== userId){
        xml.FindElem("IncomeId");
        income.setId( atoi(xml.GetData().c_str()));
        xml.FindElem("userId");
        income.setUserId( atoi(xml.GetData().c_str()));
        xml.FindElem("date");
        income.setDate(atoi(xml.GetData().c_str()));
        xml.FindElem("item");
        income.setIncomeCategory(xml.GetData());
        xml.FindElem("amount");
        income.setValue(AuxiliartMethods::conversionStringForDouble(xml.GetData()));
        incomes.push_back(income);

        }
        xml.OutOfElem();

     }

    xml.OutOfElem();
    return  incomes;
}
Income FileWithIncomes:: downloadUserData(string dataFromTheFile) {
    Income income;
    string singleData = "";
    int numberSingleData = 1;

    for (int markPosition = 0; markPosition < dataFromTheFile.length(); markPosition++) {
        if (dataFromTheFile[markPosition] != '|') {
            singleData += dataFromTheFile[markPosition];
        } else {
            switch(numberSingleData) {
            case 1:
                income.setUserId( atoi(singleData.c_str()));
                break;
            case 2:
                income.setId( atoi(singleData.c_str()));
                break;
            case 3:
                income.setDate(atoi(singleData.c_str()));
                break;
            case 4:
                income.setIncomeCategory(singleData);
                break;
            case 5:
                income.setValue(AuxiliartMethods::conversionStringForDouble(singleData));
                break;
            }
            singleData = "";
            numberSingleData++;
        }
    }
    return income;
}
