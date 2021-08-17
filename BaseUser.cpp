#include "BaseUser.h"

FreshUser::FreshUser(uint id, string name, uint age, uint heightCm, string hobbyList, vector<uint> friendList, string className)
{
}

string FreshUser::getClassName()
{
	return string();
}

void FreshUser::setClassName(string a)
{
}


BaseUser::BaseUser(uint id, string name, uint age, uint heightCm, string hobbyList, vector<uint> friendList)
{
}

BaseUser::BaseUser(uint id, UserType type, string name, uint age, uint heightCm, string hobbyList, vector<uint> friendList)
{
}

uint BaseUser::getId()
{
	return uint();
}

UserType BaseUser::getType()
{
	return UserType();
}

string BaseUser::getName()
{
	return string();
}

uint BaseUser::getAge()
{
	return uint();
}

uint BaseUser::getHeightCm()
{
	return uint();
}

string BaseUser::getHobbyList()
{
	return string();
}

vector<uint> BaseUser::getFriendList()
{
	return vector<uint>();
}

void BaseUser::setId(uint a)
{
}

void BaseUser::setType(UserType a)
{
}

void BaseUser::setName(string a)
{
}

void BaseUser::setAge(uint a)
{
}

void BaseUser::setHeightCm(uint a)
{
}

void BaseUser::setHobbyList(string a)
{
}

void BaseUser::setFriendList(vector<uint> a)
{
}

PermanentUser::PermanentUser(uint id, string name, uint age, uint heightCm, string hobbyList, vector<uint> friendList, string departmentName)
{
}

string PermanentUser::getDepartmentName()
{
	return string();
}

void PermanentUser::setDepartmentName(string a)
{
}
