#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

class User{
protected:
    string Name;
    string ID;
    string isRiding;
    string username;
    string password;

public:
    User(string uname, string pass) : username(uname), password(pass) {}
    
    string getusername() const { return username; }
    string getpass() const { return password; }

};

class Cab{
    string CabNumber;
    string type;
    string location;
    bool isAvailable;


};  

class Person: virtual public User{
public:
     Person(string uname, string pass) : User(uname, pass) {}

    void displayPersonInfo() const {
        cout << "Person Username: " << getusername() << endl;
    }
};

class Login{
private:

    
public: 
    void savetofile(User &user){
        ofstream file("userpass.txt", ios::app);
        if(file.is_open()){
            file << "Username: " << user.getusername() << "," << "Password: " << user.getpass() << "\n";
            file.close();
        }else{
            cout << "Unable to open File for writing." << endl;
        }

    }


};


int main(){
     Login loginSystem;
    Person person1("jane_passenger", "pass456");
   

    person1.displayPersonInfo();

    loginSystem.savetofile(person1);
}
