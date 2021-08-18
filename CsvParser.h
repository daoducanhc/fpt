#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <vector>

class CSVParser {
private:
    char                separator;
    std::string         m_line;
    std::vector<int>    m_data;

public:
    CSVParser(char separator);
    std::string operator[](std::size_t index);
    std::size_t size();
    void readNextRow(std::istream& str);
};

// operator overloading is not a class member
// operator overloading signature should be declared in header file
// then it will be implemented in cpp file
std::istream& operator>>(std::istream& str, CSVParser& data);
