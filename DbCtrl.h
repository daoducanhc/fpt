#ifndef  DB_READER_H
#define  DB_READER_H

#include "Utils.h"
#include "BaseUser.h"
#include "CsvParser.h"

using namespace std;

class IDbReader {
public:
    // virtual void read() is not pure virtual function
    // but virtual void read() = 0; is a pure virtual function
    // just add `= 0` to the end to make it a pure virtual function
    virtual void read() = 0;
    virtual vector<BaseUser> getUserList() = 0;
    virtual void write(vector<BaseUser> a) = 0;
};

class CsvReader : public IDbReader {
private:
    string filePath;
    vector<BaseUser> userList;
    CSVParser* row;
public:
    CsvReader(string filePath, char separator);
    static unordered_set<uint> parseFriendList(std::string sv);
    void read();
    vector<BaseUser> getUserList();
    void write(vector<BaseUser> a);
};
#endif
