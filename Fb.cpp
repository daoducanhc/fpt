#include "Fb.h"

Fb::Fb()
{
	dbCtrl = new DbCtrl("user.csv");
	UserList = dbCtrl->getUserList();
}

void Fb::addUser(BaseUser a)
{
	vector<uint> temp = a.getFriendList();
	auto it = temp.begin();
	while (it != temp.end()) {
		if (_getUserById(*it) == NULL) {
			it = temp.erase(it);
		}
		else {
			++it;
		}
	}
	a.setFriendList(temp);
	UserList.push_back(a);
}

void Fb::deleteUser(BaseUser a)
{
}



vector<BaseUser> Fb::getUserByName(string name)
{
	vector<BaseUser> result;
	for (BaseUser user : UserList) {
		if (user.getName() == name) {
			result.push_back(user);
		}
	}
	return result;
}

vector<BaseUser> Fb::getFriendList(BaseUser a)
{
	vector<BaseUser> result;
	BaseUser* user;
	for (uint id : a.getFriendList()) {
		user = _getUserById(id);
		if (user != NULL) {
			result.push_back(*user);
		}
	}
	return result;
}

vector<BaseUser> Fb::getUserListByHobbyList(string hobbyList)
{
	return vector<BaseUser>();
}

void Fb::addFriend(BaseUser a, vector<uint> idList)
{
}


BaseUser* Fb::_getUserById(uint id)
{
	for (int i = 0; i < UserList.size(); ++i) {
		if (UserList[i].getId() == id) {
			return &UserList[i];
		}
	}
	/*for (BaseUser& user : UserList) {
		if (user.getId() == id) {
			return &user;
		}
	}*/
	return NULL;
}
