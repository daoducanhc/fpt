#include "Fb.h"

Fb::Fb()
{
	
}

void Fb::addUser(BaseUser a)
{
	unordered_set<uint> temp = a.getFriendList();
	auto it = temp.begin();
	while (it != temp.end()) {
		if (_getUserById(*it) == NULL) {
			it = temp.erase(it);
		}
		else {
			// Update list friend of other
			BaseUser* temp = _getUserById(*it);
			unordered_set<uint> s = temp->getFriendList();
			s.insert(a.getId());
			temp->setFriendList(s);

			++it;
		}
	}
	a.setFriendList(temp);
	UserList.push_back(a);
}

void Fb::deleteUser(BaseUser a)
{
	// Update list friend of other
	for (uint id : a.getFriendList()) {
		BaseUser* temp = _getUserById(id);
		if (temp != NULL) {
			unordered_set<uint> s = temp->getFriendList();
			s.erase(a.getId());
			temp->setFriendList(s);
		}
	}

	UserList.erase(remove_if(UserList.begin(), UserList.end(), 
		[&a](BaseUser i) { 
			return i.getId() == a.getId(); 
		}
	));
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

void Fb::setDbReader(IDbReader* a)
{
	dbReader = a;
}

void Fb::init()
{
	dbReader->read();
	UserList = dbReader->getUserList();
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
