#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Member.h"

using namespace std;

int main()
{
    char input;
    UserInfo inputInfo;

    cout << "Welcome to Match-Breaker, a social media network where you can get rid from any relationship..." << endl << endl;

    do
    {
        LoginScreen();
        cin >> input;
        cout << endl;
        if (input == '1' && input != '2' && input != '3')
        {
            inputInfo.signUp();
        }
        else if (input == '2' && input != '3')
        {
            inputInfo.signIn();
        }
        else if(input == '3')
        {
            listUsers();
            cout << endl;
            system("PAUSE");
            cout << endl;
            LoginScreen();
        }
        else if(input == '4'){
            inputInfo.logOut();
        }
        else if(input == '5'){
            inputInfo.displayProfile();
        }
        else if ( input == '6')
        {
            cout << "Thank you for using Match-Breaker." << endl;
        }
        else{
            cout << "Invalid Choice" << endl;
        }
    } while (input != '6');

    return 0;
}
