#include "UiCtrl.h"

void BaseTask::setFb(Fb* fb)
{
	this->fb = fb;
}

UiCtrl::UiCtrl(Fb *fb)
{
	this->fb = fb;
}

void UiCtrl::addTask(BaseTask *task)
{
	task->setFb(fb);
	taskList.push_back(task);
}

void UiCtrl::run()
{
	while (1) {
		// Print menu
		for (int i = 0; i < taskList.size(); i++) {
			auto task = taskList[i];
			cout << i << ": " << taskList[i]->Name << endl;
		}
		cout << "Chon tac vu: ";
		int i;
		cin >> i;
		taskList[i]->perform();
	}
}

AddUserTask::AddUserTask() {
	Name = "Add User";
}

void AddUserTask::perform()
{
	uint id, type, age, height;
	string name, workPlaceName, hobby, friendList, temp;

	cout << "\nNhap id: ";
	cin >> id;

	cout << "\nNhap ten: ";
	cin.ignore(1024, '\n');
	getline(cin, name);

	cout << "\nNhap tuoi: ";
	getline(cin, temp);
	if (temp.length() != 0) age = stoi(temp);
	else age = 0;

	cout << "\nNhap chieu cao(cm): ";
	getline(cin, temp);
	if (temp.length() != 0) height = stoi(temp);
	else height = 0;

	cout << "\nNhap so thich: ";
	getline(cin, hobby);
	if (temp.length() != 0) hobby = temp;
	else hobby = "";

	cout << "\nNhap danh sach ket ban: ";
	getline(cin, friendList);
	if (temp.length() != 0) friendList = temp;
	else friendList = "";

	cout << "\nNhap loai nhan vien (0:Fresher, 1:Permanent): ";
	cin >> type;
	auto _type = static_cast<UserType>(type);
	auto _friendList = parseFriendList(friendList);
	if (type == UserType::Fresh) {
		cout << "\nNhap lop hoc: ";
		cin.ignore(1024, '\n');
		getline(cin, workPlaceName);
		FreshUser user(id, name, age, height, hobby, _friendList, workPlaceName);
		fb->addUser(user);
	}
	else if (type == UserType::Permanent) {
		cout << "\nNhap noi lam viec: ";
		cin.ignore(1024, '\n');
		getline(cin, workPlaceName);
		PermanentUser user(id, name, age, height, hobby, _friendList, workPlaceName);
		fb->addUser(user);
	}

}


DeleteUserTask::DeleteUserTask()
{
	this->Name = "Delete User";
}

void DeleteUserTask::perform()
{
	uint id;
	cout << "\nNhap id: ";
	cin >> id;
	BaseUser *temp = fb->_getUserById(id);
	fb->deleteUser(*temp);
}

FindUserByNameTask::FindUserByNameTask()
{
	Name = "Find User By Name";
}

void FindUserByNameTask::perform()
{
	string name;
	cout << "Nhap ten: ";
	cin.ignore(1024, '\n');
	getline(cin, name);
	vector<BaseUser> temp = fb->getUserByName(name);
	fb->_showInfoByGroup(temp);
	cout << "\n\n";
}

FindUserFriendTask::FindUserFriendTask()
{
	Name = "Find Friend of User";
}

void FindUserFriendTask::perform()
{
	uint id;
	cout << "\nNhap id: ";
	cin >> id;
	BaseUser* temp = fb->_getUserById(id);
	vector<BaseUser> a = fb->getFriendList(*temp);
	fb->_showInfoByGroup(a);
	cout << "\n\n";
}

FindSameHobbyTask::FindSameHobbyTask()
{
	Name = "Find User has same hobby";
}

void FindSameHobbyTask::perform()
{
	string hobby;
	cout << "\nNhap cac so thich, cach nhau boi dau phay (,): ";
	cin.ignore(1024, '\n');
	getline(cin, hobby);
	unordered_set<uint> userId = fb->getUserListByHobbyList(hobby);
	for (uint id : userId) {
		cout << id << " ";
	}
	cout << "\n\n";
}

AddFriendTask::AddFriendTask()
{
	Name = "Add Friend";
}

void AddFriendTask::perform()
{
	uint id;
	cout << "\nNhap id: ";
	cin >> id;
	string friendList;
	cout << "\nNhap danh sach id nhung nguoi muon kb, cach nhau boi dau phay (,): ";
	cin.ignore(1024, '\n');
	getline(cin, friendList);
	auto _friendList = parseFriendList(friendList);
	BaseUser* temp = fb->_getUserById(id);
	fb->addFriend(temp, _friendList);
	cout << "\n";
}

ShowTask::ShowTask()
{
	Name = "Show user";
}

void ShowTask::perform()
{
	uint n;
	cout << "\nNhap so nguoi muon show: ";
	cin >> n;
	if (n > fb->UserList.size()) n = fb->UserList.size();
	for (int i = 0; i < n; i++) {
		fb->_showInfo(fb->UserList[i]);
	}

	cout << "\n\n";
}
