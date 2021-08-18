#include "BaseUser.h"
#include <string>
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class IDbReader {
public:
    virtual void read() = 0;
    virtual vector<BaseUser> getUserList() = 0;
    virtual void write(vector<BaseUser> a) = 0;
};

class CsvReader : public IDbReader{
private:
    string filePath;
    vector<BaseUser> userList;
public:
    CsvReader(string filePath);
    void read();
    vector<BaseUser> getUserList();
    void write(vector<BaseUser> a);
};
