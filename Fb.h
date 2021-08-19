#ifndef  FB_H
#define  FB_H

#include "BaseUser.h"
#include "DbCtrl.h"
#include <string>
#include <unordered_map>
#include "Utils.h"

using namespace std;

class Fb{
private:
    IDbReader* dbReader;
    void _initHobbyMap();
    unordered_set<string> _parseHoobyList(string hobby);
    unordered_map<string, unordered_set<uint>> HobbyMap;
    vector<BaseUser> userList;
    
public:
    Fb();
    void init();
    vector<BaseUser> getUserList();
    void setDbReader(IDbReader*);
    void addUser(BaseUser a);
    void deleteUser(BaseUser a);
    vector<BaseUser> getUserByName(string name);
    vector<BaseUser> getFriendList(BaseUser a);
    unordered_set<uint> getUserListByHobbyList(string hobbyList);
    void addFriend(BaseUser *a, unordered_set<uint> idList);
    void showAllInfo();
    BaseUser* getUserById(uint id);
    void showInfoByGroup(vector<BaseUser> a);
    void showInfo(BaseUser a);
};
#endif