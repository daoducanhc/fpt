#pragma once
#include <string>
#include <vector>
using namespace std;
using uint = unsigned int;

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
	vector<uint> friendList;
public:
	BaseUser(uint id, UserType type, string name, uint age = 0, uint heightCm = 0,
		string hobbyList = "", vector<uint> friendList = {});
	uint getId();
	UserType getType();
	string getName();
	uint getAge();
	uint getHeightCm();
	string getHobbyList();
	vector<uint> getFriendList();

	void setId(uint a);
	void setType(UserType a);
	void setName(string a);
	void setAge(uint a);
	void setHeightCm(uint a);
	void setHobbyList(string a);
	void setFriendList(vector<uint> a);
};

class FreshUser : public BaseUser {
private:
	string className;
public:
	FreshUser(uint id, string name, uint age = 0, uint heightCm = 0, 
		string hobbyList = "", vector<uint> friendList = {}, string className="");
	string getClassName();
	void setClassName(string a);
};

class PermanentUser : public BaseUser {
private:
	string departmentName;
public:
	PermanentUser(uint id, string name, uint age = 0, uint heightCm = 0,
		string hobbyList = "", vector<uint> friendList = {}, string departmentName = "");
	string getDepartmentName();
	void setDepartmentName(string a);
};
