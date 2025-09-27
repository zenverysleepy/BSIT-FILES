#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int Option;
    
    cout << "Main Menu:" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "Choose Option:" << endl;
    cin >> Option;
    
    if(Option == 1)
    {
        string Username,Password;
        
        cout << "Register:" << endl;
        cout << "Username: " << endl;
        cin >> Username;
        cout << "Password: " << endl;
        cin >> Password;
        cout << "Thank you for Registering " << Username << "!" << endl;
        
    }
    if(Option == 2)
    {
        string Username,Password;
        
        cout << "Login:" << endl;
        cout << "Username:" << endl;
        cin >> Username;
        cout << "Password:" << endl;
        cin >> Password;
        cout << "Welcome Back " << Username << "!" << endl;
    }
    
    return 0;
}