#include "DbCtrl.h"
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <string_view>


class CSVRow
{
public:
    std::string_view operator[](std::size_t index) const
    {
        return std::string_view(&m_line[m_data[index] + 1], m_data[index + 1] - (m_data[index] + 1));
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

void DbCtrl::read()
{
    std::ifstream file(filePath);
    CSVRow row;
    while (file >> row)
    {
        std::cout << "4th Element(" << row[3] << ")\n";
    }
}

vector<BaseUser> DbCtrl::getUserList()
{
    return userList;
}


void DbCtrl::write(vector<BaseUser> a)
{
}
