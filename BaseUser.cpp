#include "BaseUser.h"

FreshUser::FreshUser(uint id, string name, uint age, uint heightCm, string hobbyList, unordered_set<uint> friendList, string className)
	: BaseUser(id, UserType::Fresh, name, age, heightCm, hobbyList, friendList)
{
	this->className = className;
}

string FreshUser::getClassName()
{
	return this->className;
}

void FreshUser::setClassName(string a)
{
	this->className = a;
}

BaseUser::BaseUser(uint id, UserType type, string name, uint age, uint heightCm, string hobbyList, unordered_set<uint> friendList)
{
	this->id = id;
	this->type = type;
	this->name = name;
	this->age = age;
	this->heightCm = heightCm;
	this->hobbyList = hobbyList;
	this->friendList = friendList;
}

uint BaseUser::getId()
{
	return this->id;
}

UserType BaseUser::getType()
{
	return this->type;
}

string BaseUser::getName()
{
	return this->name;
}

uint BaseUser::getAge()
{
	return this->age;
}

uint BaseUser::getHeightCm()
{
	return this->heightCm;
}

string BaseUser::getHobbyList()
{
	return this->hobbyList;
}

unordered_set<uint> BaseUser::getFriendList()
{
	return this->friendList;
}

void BaseUser::setId(uint a)
{
	this->id = a;
}

void BaseUser::setType(UserType a)
{
	this->type = a;
}

void BaseUser::setName(string a)
{
	this->name = a;
}

void BaseUser::setAge(uint a)
{
	this->age = a;
}

void BaseUser::setHeightCm(uint a)
{
	this->heightCm = a;
}

void BaseUser::setHobbyList(string a)
{
	this->hobbyList = a;
}

void BaseUser::setFriendList(unordered_set<uint> a)
{
	this->friendList = a;
}

PermanentUser::PermanentUser(uint id, string name, uint age, uint heightCm, string hobbyList, unordered_set<uint> friendList, string departmentName)
	: BaseUser(id, UserType::Permanent, name, age, heightCm, hobbyList, friendList)
{
	this->departmentName = departmentName;
}

string PermanentUser::getDepartmentName()
{
	return this->departmentName;
}

void PermanentUser::setDepartmentName(string a)
{
	this->departmentName = a;
}
