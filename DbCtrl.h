#include "BaseUser.h"
#include <string>

using namespace std;

class DbCtrl{
private:
    string filePath;
public:
    DbCtrl(string filePath);
    vector<BaseUser> read();
    void write(vector<BaseUser> a);
};
