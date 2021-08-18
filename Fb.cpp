#include <iostream>
#include "Fb.h"

using namespace std;

Fb::Fb()
{

}

void Fb::setDbReader(IDbReader* a)
{
	dbReader = a;
}

void Fb::init()
{
	dbReader->read();
	UserList = dbReader->getUserList();
	_initHobbyMap();
}

void Fb::addUser(BaseUser a)
{
	unordered_set<uint> list = a.getFriendList();
	auto it = list.begin();
	while (it != list.end()) {
		if (_getUserById(*it) == NULL) {
			it = list.erase(it);
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
	a.setFriendList(list);

	// Update HobbyMap
	unordered_set<string> hobbies = _parseHoobyList(a.getHobbyList());
	unordered_set<string>::iterator it2 = hobbies.begin();
	while (it2 != hobbies.end()) {
		HobbyMap[*it2].insert(a.getId());
		it2++;
	}

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

	// Update HobbyMap
	unordered_set<string> hobbies = _parseHoobyList(a.getHobbyList());
	unordered_set<string>::iterator it2 = hobbies.begin();
	while (it2 != hobbies.end()) {
		HobbyMap[*it2].erase(a.getId());
		it2++;
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

vector<BaseUser> Fb::getUserListByHobbyList(string hobbyList)
{
	vector<BaseUser> result;
	unordered_set<string> hobbies = _parseHoobyList(hobbyList);
	unordered_set<string>::iterator it = hobbies.begin();
	unordered_set<uint> userId;
	while (it != hobbies.end()) {
		userId.insert(HobbyMap[*it].begin(), HobbyMap[*it].end());
		it++;
	}
	for (uint id : userId) {
		BaseUser* temp = _getUserById(id);
		if (temp != NULL) {
			result.push_back(*temp);
		}
	}
	return result;
}

void Fb::addFriend(BaseUser a, unordered_set<uint> idList)
{
	BaseUser* user;
	for (uint id : idList) {
		user = _getUserById(id);
		if (_getUserById(id) != NULL) {
			// Update list friend of a
			unordered_set<uint> s = a.getFriendList();
			s.insert(id);
			a.setFriendList(s);

			// Update list friend of other
			s = user->getFriendList();
			s.insert(a.getId());
			user->setFriendList(s);
		}
	}
}

void Fb::_showAllInfo()
{
	_showInfoByGroup(UserList);
}

void Fb::_showInfoByGroup(vector<BaseUser> a)
{
	for (int i = 0; i < a.size(); i++) {
		cout << "\nId: " << a[i].getId() << "\tName: " << a[i].getName();
	}
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

void Fb::_initHobbyMap() {
	for (int i = 0; i < UserList.size(); i++) {
		unordered_set<string> hobbies = _parseHoobyList(UserList[i].getHobbyList());
		unordered_set<string>::iterator it = hobbies.begin();
		while (it != hobbies.end()) {
			HobbyMap[*it].insert(UserList[i].getId());
			it++;
		}
	}
}

unordered_set<string> Fb::_parseHoobyList(string hobby) {
	unordered_set<string> result;
	stringstream ss(hobby);
	while (ss.good())
	{
		string substr;
		getline(ss, substr, ',');
		trim(substr);
		result.insert(substr);
	}
	return result;
}
