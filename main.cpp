#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int MAX_USER = 100;

class User{
protected:
    string Name;
    bool isRiding;
    string Contact;
    string Location;

public:  
    User(string name="", string contact="", string location="",bool riding=false) : Name(name), Contact(contact), Location(location), isRiding(riding){}

    string getName() const {return Name;}
    string getContact() const {return Contact;}
    string getLocation() const {return Location;}
    bool getRidingStatus() const {return isRiding;}
};

class RegisteredUser: public User{
private:
    string username;
    string password;
public:

    RegisteredUser(string name= "", string contact="", string uname="", string pass="", string location="", bool riding=false) : User(name, contact, location, riding), username(uname), password(pass) {}

    string getusername(){return username;}
    string getpassword(){return password;}
};  

class Login{    
private:
    RegisteredUser* user;
    int usercount;

    void loaduser(){
        ifstream file("user.txt");
        string uname,pass,name,contact;

        while(file >> name >> contact >> uname >> pass){
            if(usercount < MAX_USER){
                user[usercount++] = RegisteredUser(name,contact,uname,pass);
            }else{
                cout << "System User limit reached.\nCannot Register Your Account\t!!ERROR!!" << endl; 
            }
        }
        file.close();
    }

    void savetofile(){
        ofstream file("user.txt",ios::app);
    
    for(int i=0;i < usercount;i++){
        file << user[i].getName() << " " << user[i].getContact() << " " << user[i].getusername() << " " << user[i].getpassword() << endl;
    }

    file.close();

}
    int searchUser(const string &uname,const string &pass){
        for(int i=0; i<usercount;i++){
            if(user[i].getusername() == uname && user[i].getpassword() == pass){
                return 1;
            }
        }
        return -1;
    }

public:

    Login(){
        user =  new RegisteredUser[MAX_USER];
        usercount = 0;
    }

    bool SignUp(){
        string name,contact,uname,pass;

         cout << "Enter your full name: ";
        cin >> ws; 
        getline(cin, name);

        cout << "Enter your contact number: ";
        cin >> contact;

        cout << "Enter a new username: ";
        cin >> uname;

        cout << "Enter a new password: ";
        cin >> pass;

        if(searchUser(uname,pass) != -1){
            cout << "This combination already exists try logging in.." << endl;
        }
        
        user[usercount++] = RegisteredUser(name, contact, uname, pass);
        savetofile();

        cout << "Sign Up Succesfull!!\n" << "Login again to Sign In" << endl; 
        return true;
    }

    bool SignIn(){
        string uname,pass;

        cout << "Enter your username: ";
        cin >> uname;

        cout << "Enter your password: ";
        cin >> pass;

        if(searchUser(uname,pass)==1){
            cout << "Login Sucessful";
            return true;
        }
        cout << "Invalid username or password. Please try again or sign up." << endl;
        return false;
    
    }

    ~Login(){
        delete[] user;
    }

};


int main(){
    Login loginvar;

    int choice;
        string uname;

        do {
            cout << "\n--- LOGIN SYSTEM ---" << endl;
            cout << "1. Sign In" << endl;
            cout << "2. Sign Up" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    if (loginvar.SignIn()) {
                        cout << "This should be cab booking screen...!!!";
                    }
                    break;
                case 2:
                    loginvar.SignUp();
                    break;
                case 3:
                    cout << "Exiting... Thank you!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 4);
    

}
