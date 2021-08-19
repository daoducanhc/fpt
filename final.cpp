// final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Fb.h"
#include "UiCtrl.h"

int main()
{
    IDbReader* dbReader = new CsvReader("user.csv", '|');
    Fb fb;
    fb.setDbReader(dbReader);
    fb.init();

    UiCtrl uiCtrl(&fb);
    ShowTask showTask;
    uiCtrl.addTask(&showTask);
    AddUserTask addUserTask;
    uiCtrl.addTask(&addUserTask);
    DeleteUserTask deleteUserTask;
    uiCtrl.addTask(&deleteUserTask);
    FindUserByNameTask findByNameTask;
    uiCtrl.addTask(&findByNameTask);
    FindUserFriendTask findFriendTask;
    uiCtrl.addTask(&findFriendTask);
    FindSameHobbyTask findHobbyTask;
    uiCtrl.addTask(&findHobbyTask);
    AddFriendTask addFriendTask;
    uiCtrl.addTask(&addFriendTask);
    uiCtrl.run();
}
