// final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Fb.h"


int main()
{
    IDbReader* dbReader = new CsvReader("user.csv");
    Fb fb;
    fb.setDbReader(dbReader);
    fb.init();

    std::cout << "Hello World!\n";

    FreshUser user(
        10, "name10", 10, 10,
        "bong chuyen, bong da",
        unordered_set<uint>({1,2,3}), "");

    fb._showAllInfo();

    fb.addUser(user);
    auto res = fb.getUserByName("name10");
    for (auto r : res) {
        cout << r.getName() << endl;
    }

    cout << "ABC" << endl;
    auto res2 = fb.getFriendList(user);
    for (auto r : res2) {
        cout << r.getName() << endl;
    }

    fb.deleteUser(user);
    res = fb.getUserByName("name10");
    for (auto r : res) {
        cout << r.getName() << endl;
    }
}
