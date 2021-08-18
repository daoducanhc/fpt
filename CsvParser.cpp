#include "CsvParser.h"
#include "Utils.h"

CSVParser::CSVParser(char separator) {
    this->separator = separator;
}

std::string CSVParser::operator[](std::size_t index)
{
    auto res = std::string(&m_line[m_data[index] + 1], m_data[index + 1] - (m_data[index] + 1));
    auto res2 = trim_copy(res);
    return res2;
}

std::size_t CSVParser::size()
{
    return m_data.size() - 1;
}

void CSVParser::readNextRow(std::istream& str)
{
    std::getline(str, m_line);

    m_data.clear();
    m_data.emplace_back(-1);
    std::string::size_type pos = 0;
    while ((pos = m_line.find(separator, pos)) != std::string::npos)
    {
        m_data.emplace_back(pos);
        ++pos;
    }
    // This checks for a trailing comma with no data after it.
    pos = m_line.size();
    m_data.emplace_back(pos);
}

std::istream& operator>>(std::istream& str, CSVParser& data)
{
    data.readNextRow(str);
    return str;
}