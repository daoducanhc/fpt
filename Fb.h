#include "BaseUser.h"
#include "DbCtrl.h"
#include <string>

using namespace std;

class Fb{
public:
    DbCtrl dbCtrl;
    vector<BaseUser> UserList;
    void addUser(BaseUser a);
    void deleteUser(BaseUser a);
    vector<BaseUser> getUserByName(string name);
    vector<BaseUser> getFriendList(BaseUser a);
    vector<BaseUser> getUserListByHobbyList(string hobbyList);
    void addFriend(BaseUser a, vector<uint> idList);

    BaseUser* _getUserById(uint id);
};
