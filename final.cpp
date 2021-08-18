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

    UiCtrl uiCtrl(fb);
    AddUserTask add;
    uiCtrl.addTask(&add);
    uiCtrl.run();
    /*std::cout << "Hello World!\n";

    FreshUser user(
        10, "name10", 10, 10,
        "bong chuyen, bong da",
        unordered_set<uint>({1,2,3}), "");


    fb.addUser(user);
    fb._showAllInfo();
    auto res = fb.getUserByName("name10");
    for (auto r : res) {
        cout << r.getName() << endl;
    }
    fb._showInfoByGroup(fb.getUserListByHobbyList("bong chuyen, cau long"));
    cout << "ABC" << endl;
    auto res2 = fb.getFriendList(user);
    for (auto r : res2) {
        cout << r.getName() << endl;
    }

    fb.deleteUser(user);
    res = fb.getUserByName("name10");
    for (auto r : res) {
        cout << r.getName() << endl;
    }*/
}
