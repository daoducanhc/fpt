#include "BaseUser.h"
#include <string>

using namespace std;

class IDbReader {
public:
    virtual void read();
    virtual vector<BaseUser> getUserList();
    //virtual void write(vector<BaseUser> a);
};

class CsvReader : public IDbReader{
private:
    string filePath;
    vector<BaseUser> userList;
public:
    CsvReader(string filePath);
};
