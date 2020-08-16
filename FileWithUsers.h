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
class FileWithUsers
{

    public:
    void addUsersToFile(User user);
   vector<User> loadUsersFromFile();
    User downloadUserData(string dataFromTheFile);
   void saveTheNewPasswordInAFile(string newPassword, int loggedUserId);
   string replaceUserDataForDataLinesSeparatedByVerticalLines(User user);//do pomocniczych??

};
#endif
