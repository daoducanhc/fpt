//#include "UiCtrl.h"

//void BaseTask::setFb(Fb* fb)
//{
//	this->fb = fb;
//}

//void AddUserTask::perform()
//{
//	uint id, type, age, height;
//	string name, workPlaceName, hobby, friendList;
//	cout << "\nNhap id: ";
//	cin >> id;
//	cout << "\nNhap ten: ";
//	getline(cin, name);
//	cout << "\nNhap tuoi: ";
//	cin >> age;
//	cout << "\nNhap chieu cao(cm): ";
//	cin >> height;
//	cout << "\nNhap so thich: ";
//	getline(cin, hobby);
//	cout << "\nNhap danh sach ket ban: ";
//	getline(cin, friendList);
//	cout << "\nNhap loai nhan vien (0:Fresher, 1:Permanent): ";
//	cin >> type;
//	auto _type = static_cast<UserType>(type);
//	auto _friendList = parseFriendList(friendList);
//	if (type == UserType::Fresh) {
//		cout << "\nNhap lop hoc: ";
//		getline(cin, workPlaceName);
//		FreshUser user(id, name, age, height, hobby, _friendList, workPlaceName);
//		fb->addUser(user);
//	}
//	else if (type == UserType::Permanent) {
//		cout << "\nNhap noi lam viec: ";
//		getline(cin, workPlaceName);
//		PermanentUser user(id, name, age, height, hobby, _friendList, workPlaceName);
//		fb->addUser(user);
//	}
//	
//}

//UiCtrl::UiCtrl(Fb* fb)
//{
//	this->fb = fb;
//}

//void UiCtrl::addTask(BaseTask *task)
//{
//	task->setFb(fb);
//	taskList.push_back(task);
//}

//void UiCtrl::run()
//{
//	while (1) {
//		// Print menu
//		for (int i = 0; i < taskList.size(); i++) {
//			auto task = taskList[i];
//			cout << i + 1 << ": " << taskList[i]->Name << endl;
//		}
//		cout << "Chon tac vu: ";
//		int i;
//		cin >> i;
//		taskList[i]->perform();
//	}
//}
