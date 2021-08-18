#include "DbCtrl.h"

using namespace std;

CsvReader::CsvReader(string filePath, char separator)
{
	this->filePath = filePath;
    row = new CSVParser(separator);
}

unordered_set<uint> CsvReader::parseFriendList(std::string sv) {
    stringstream ss(sv);
    unordered_set<uint> result;
    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        result.insert(stoi(substr));
    }
    return result;
}

void CsvReader::read()
{
    userList.clear();
    std::ifstream file(filePath);
    while (file >> *row)
    {
        auto type = static_cast<UserType>(stoi((*row)[1]));
        auto friendList = parseFriendList((*row)[6]);
        if (type == UserType::Fresh) {
            FreshUser user(
                stoi((*row)[0]), (*row)[2], stoi((*row)[3]), stoi((*row)[4]),
                (*row)[5], friendList, (*row)[7]);
            userList.push_back(user);
        }
        else if (type == UserType::Permanent) {
            PermanentUser user(
                stoi((*row)[0]), (*row)[2], stoi((*row)[3]), stoi((*row)[4]),
                (*row)[5], friendList, (*row)[7]);
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

