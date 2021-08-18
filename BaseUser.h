#ifndef  BASE_USER_H 
#define  BASE_USER_H

#pragma once
#include <string>
#include <vector>
#include <unordered_set>
#include "Utils.h"
using namespace std;
enum UserType {
	Fresh,
	Permanent,
};

class BaseUser {
protected:
	uint id;
	UserType type;
	string name;
	uint age;
	uint heightCm;
	string hobbyList;
	unordered_set<uint> friendList;
public:
	BaseUser(uint id, UserType type, string name, uint age = 0, uint heightCm = 0,
		string hobbyList = "", unordered_set<uint> friendList = {});
	uint getId();
	UserType getType();
	string getName();
	uint getAge();
	uint getHeightCm();
	string getHobbyList();
	unordered_set<uint> getFriendList();

	void setId(uint a);
	void setType(UserType a);
	void setName(string a);
	void setAge(uint a);
	void setHeightCm(uint a);
	void setHobbyList(string a);
	void setFriendList(unordered_set<uint> a);
};

class FreshUser : public BaseUser {
private:
	string className;
public:
	FreshUser(uint id, string name, uint age = 0, uint heightCm = 0,
		string hobbyList = "", unordered_set<uint> friendList = {}, string className="");
	string getClassName();
	void setClassName(string a);
};

class PermanentUser : public BaseUser {
private:
	string departmentName;
public:
	PermanentUser(uint id, string name, uint age = 0, uint heightCm = 0,
		string hobbyList = "", unordered_set<uint> friendList = {}, string departmentName = "");
	string getDepartmentName();
	void setDepartmentName(string a);
};
#endif