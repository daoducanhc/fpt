#include "DbCtrl.h"

using namespace std;

CsvReader::CsvReader(string filePath, char separator)
{
	this->filePath = filePath;
    row = new CSVParser(separator);
}

void CsvReader::read()
{
    userList.clear();
    std::ifstream file(filePath);
    while (file >> *row)
    {
        auto type = static_cast<UserType>(stoi((*row)[3]));
        auto friendList = parseFriendList((*row)[8]);
        if (type == UserType::Fresh) {
            FreshUser user(
                stoi((*row)[1]), (*row)[2], stoi((*row)[5]), stoi((*row)[6]),
                (*row)[7], friendList, (*row)[4]);
            userList.push_back(user);
        }
        else if (type == UserType::Permanent) {
            PermanentUser user(
                stoi((*row)[1]), (*row)[2], stoi((*row)[5]), stoi((*row)[6]),
                (*row)[7], friendList, (*row)[4]);
            userList.push_back(user);
        }
    }
}

vector<BaseUser> CsvReader::getUserList()
{
    return userList;
}


void CsvReader::write(vector<BaseUser> user)
{

}
