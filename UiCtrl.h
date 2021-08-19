#pragma once
#include "Fb.h"

class BaseTask {
protected:
	Fb *fb;
	string name;
public:
	virtual void perform() = 0;
	void setFb(Fb* fb);
	string getName();
};

class AddUserTask : public BaseTask{
public:
	AddUserTask();
	void perform();
};

class DeleteUserTask : public BaseTask {
public:
	DeleteUserTask();
	void perform();
};

class FindUserByNameTask : public BaseTask {
public:
	FindUserByNameTask();
	void perform();
};

class FindUserFriendTask : public BaseTask {
public:
	FindUserFriendTask();
	void perform();
};

class FindSameHobbyTask : public BaseTask {
public:
	FindSameHobbyTask();
	void perform();
};

class AddFriendTask : public BaseTask {
public:
	AddFriendTask();
	void perform();
};

class ShowTask : public BaseTask {
public:
	ShowTask();
	void perform();
};

class UiCtrl {
protected:
	Fb* fb;
	vector<BaseTask*> taskList;
public:
	UiCtrl(Fb *fb);
	void addTask(BaseTask *task);
	void run();
};