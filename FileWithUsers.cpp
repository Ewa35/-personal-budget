#include "FileWithUsers.h"

void FileWithUsers:: addUsersToFile(User user) {
    CMarkup xml;

    bool fileExists = xml.Load( USER_FILE_NAME );
    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();

    xml.AddElem("USER");

    xml.IntoElem();
    xml.AddElem("USERID",AuxiliartMethods::conversionIntForString(user.getId()));

    xml.AddElem("LOGIN", user.getLogin());

    xml.AddElem("PASSWORD", user.getPassword());

    xml.AddElem("NAME", user.getName());

    xml.AddElem("SURNAME", user.getLastName());

    xml.OutOfElem();

    xml.Save(USER_FILE_NAME);

}


vector<User> FileWithUsers::loadUsersFromFile() {
    CMarkup xml;
    vector<User> users;
    User user;
    bool fileExists = xml.Load( USER_FILE_NAME );
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("USER")) {

        xml.IntoElem();
        xml.FindElem("USERID");
        MCD_STR dataFromTheFile = xml.GetData();
        user.setId(atoi(dataFromTheFile.c_str()));
        xml.FindElem("LOGIN");
        dataFromTheFile = xml.GetData();
        user.setLogin(dataFromTheFile);
        xml.FindElem("PASSWORD");
        dataFromTheFile = xml.GetData();
        user.setPassword(dataFromTheFile);
        xml.FindElem("NAME");
        dataFromTheFile = xml.GetData();
        user.setName(dataFromTheFile);
        xml.FindElem("SURNAME");
        dataFromTheFile = xml.GetData();
        user.setLastName(dataFromTheFile);
        users.push_back(user);

        xml.OutOfElem();
    }
    xml.OutOfElem();

    return users;

}



void FileWithUsers::saveTheNewPasswordInAFile(string oldPassword, string newPassword) {
   CMarkup xml;
    bool fileExists = xml.Load( USER_FILE_NAME );
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("USER")){
    xml.IntoElem();
    xml.FindElem( "PASSWORD");
    if (xml.GetData()==oldPassword){
    xml.SetData(newPassword);

    }
    xml.OutOfElem();
    }
    xml.Save(USER_FILE_NAME);
}


