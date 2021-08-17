#include "DbCtrl.h"
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class CSVRow
{
public:
    std::string operator[](std::size_t index) const
    {
        return std::string(&m_line[m_data[index] + 1], m_data[index + 1] - (m_data[index] + 1));
    }
    std::size_t size() const
    {
        return m_data.size() - 1;
    }
    void readNextRow(std::istream& str)
    {
        std::getline(str, m_line);

        m_data.clear();
        m_data.emplace_back(-1);
        std::string::size_type pos = 0;
        while ((pos = m_line.find(';', pos)) != std::string::npos)
        {
            m_data.emplace_back(pos);
            ++pos;
        }
        // This checks for a trailing comma with no data after it.
        pos = m_line.size();
        m_data.emplace_back(pos);
    }
private:
    std::string         m_line;
    std::vector<int>    m_data;
};

std::istream& operator>>(std::istream& str, CSVRow& data)
{
    data.readNextRow(str);
    return str;
}

DbCtrl::DbCtrl(string filePath)
{
	this->filePath = filePath;
    read();
}

vector<uint> parseFriendList(std::string sv) {
    stringstream ss(sv);
    vector<uint> result;
    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        result.push_back(stoi(substr));
    }
    return result;
}

void DbCtrl::read()
{
    userList.clear();
    std::ifstream file(filePath);
    CSVRow row;
    while (file >> row)
    {
        auto type = static_cast<UserType>(stoi(row[1]));
        auto friendList = parseFriendList(row[6]);
        if (type == UserType::Fresh) {
            FreshUser user(
                stoi(row[0]), row[2], stoi(row[3]), stoi(row[4]),
                row[5], friendList, row[7]);
            userList.push_back(user);
        }
        else if (type == UserType::Permanent) {
            PermanentUser user(
                stoi(row[0]), row[2], stoi(row[3]), stoi(row[4]),
                row[5], friendList, row[7]);
            userList.push_back(user);
        }
    }
}

vector<BaseUser> DbCtrl::getUserList()
{
    return userList;
}


void DbCtrl::write(vector<BaseUser> user)
{

}