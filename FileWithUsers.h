#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include "User.h"
#include "Markup.h"
#include "AuxiliartMethods.h"


using namespace std;
class FileWithUsers {
    const string USER_FILE_NAME;
public:
    FileWithUsers (string userFileName):USER_FILE_NAME(userFileName) {};
    void addUsersToFile(User user);
    vector<User> loadUsersFromFile();
    void saveTheNewPasswordInAFile(string oldPassword, string newPassword);


};
#endif
