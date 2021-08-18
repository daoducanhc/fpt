#pragma once
#include "Fb.h"

class BaseTask {
protected:
	Fb *fb;
public:
	const string Name;
	virtual void perform() = 0;
	void setFb(Fb* fb);
};

class AddUserTask : public BaseTask{
public:
	const string Name = "Add User";
	void perform();
};

class UiCtrl {
protected:
	Fb* fb;
	vector<BaseTask*> taskList;
public:
	UiCtrl(Fb fb);
	void addTask(BaseTask *task);
	void run();
};