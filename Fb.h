#ifndef  FB_H
#define  FB_H

#include "BaseUser.h"
#include "DbCtrl.h"
#include <string>
#include <unordered_map>

using namespace std;

class Fb{
private:
    IDbReader* dbReader;
    
public:
    vector<BaseUser> UserList;
    unordered_map<string, vector<uint>> HobbyMap;
    Fb();
    void init();
    void setDbReader(IDbReader*);
    void addUser(BaseUser a);
    void deleteUser(BaseUser a);
    vector<BaseUser> getUserByName(string name);
    vector<BaseUser> getFriendList(BaseUser a);
    vector<BaseUser> getUserListByHobbyList(string hobbyList);
    void addFriend(BaseUser a, unordered_set<uint> idList);

    BaseUser* _getUserById(uint id);
    void _showAllInfo();
    void _initHobbyMap();
    unordered_set<string> _parseHoobyList(string hobby);
};
#endif