#include<iostream>

using namespace std;
struct Location{
    double lattitude;
    double longitude;
};

class Cabs{
    private:
    string cabId;
    string driverName;
    Location cab_loc;
    bool available;
    public:
    Cabs(string id,string name,Location loc,bool available):cabId(id) ,driverName(name) ,cab_loc(loc) ,available(available){}


};

class User{
    private:
    string userId;
    String userName;
    Location  user_loc;
    bool isactive;
    public:
    User(string id,string user,Location loc,bool act)
    {
        userId=id;
        userName=user;
        user_loc=loc;
        active=act;
    }

};


int main()
{
    cout<<"XXXX"<<endl;
    return 0;
}
