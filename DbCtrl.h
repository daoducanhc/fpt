#include "BaseUser.h"
#include <string>

using namespace std;

class DbCtrl{
private:
    string filePath;
    vector<BaseUser> userList;
protected:
    void read();
public:
    DbCtrl(string filePath);
    vector<BaseUser> getUserList();
    void write(vector<BaseUser> a);
};
