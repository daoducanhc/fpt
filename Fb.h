#include "BaseUser.h"
#include "DbCtrl.h"
#include <string>

using namespace std;

class Fb{
public:
    void addUser(BaseUser a);
    void deleteUser(BaseUser a);
    BaseUser getUserByName(string name);
    vector<BaseUser> getFriendList(BaseUser a);
    vector<BaseUser> getUserListByHobbyList(string hobbyList);
    void addFriend(BaseUser a, vector<uint> idList);
};
