// final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Fb.h"


int main()
{
    std::cout << "Hello World!\n";

    FreshUser* user = new FreshUser(
        10, "name10", 10, 10,
        "bong chuyen, bong da",
        vector<uint>({1,2,3}), "");

    Fb fb;
    fb.addUser(*user);
    auto res = fb.getUserByName("name10");
    for (auto r : res) {
        cout << r.getName() << endl;
    }

    cout << "ABC" << endl;
    auto res2 = fb.getFriendList(*user);
    for (auto r : res2) {
        cout << r.getName() << endl;
    }
}
