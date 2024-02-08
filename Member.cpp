#include <iostream>
#include <fstream>

#include <istream>
#include <ostream>

#include <string>
#include <cstdlib>

#include "Member.h"
#include <bits/stdc++.h>

using namespace std;

ofstream fout;
ifstream fin;


/// LoginScreen
void LoginScreen()
{
    cout << "Please select from the following options by entering the corresponding number:" << endl << endl;
    cout << "1. Sign up" << endl;
    cout << "2. Log in" << endl;
    cout << "3. User list" << endl;
    cout << "4. Log Out" << endl;
    cout << "5. User Detail" << endl;
    cout << "6. Exit" << endl << endl;
    cout << "Please make your selection: ";
}


/// User Sign Up
void UserInfo::signUp()
{
    int offset;
    string line;
    bool isTaken;

    string fName;
    string lName;
    string bYear;
    string screenName;

    cout << "Enter your first name: ";
    cin >> fName;
    setFirstName(fName);

    cout << "Enter your last name: ";
    cin >> lName;
    setLastName(lName);

    cout << "Enter your birth year: ";
    cin >> bYear;
    setBirthYear(bYear);

    cout << "Create your screen name (no special characters or spaces): ";
    do
    {
        cin >> screenName;
        isTaken = false;

        /// check if userName has already been taken
        fin.open("RegisteredUsers.txt");
        while (!fin.eof())
        {
            getline(fin, line);
            if ((offset = line.find(screenName, 0)) != string::npos)
            {
                isTaken = true;
                cout << "The username " << screenName << " is already taken, please choose a different username: ";
            }
        }
        fin.close();
    } while (isTaken = true && isTaken != false);

    setScreenName(screenName);

    cout << endl;
    cout << "Registered with the following information:" << endl;
    cout << endl;
    cout << "Full name: " << getFirstName() << " " << getLastName() << endl;
    cout << "Birth year: " << getBirthYear() << endl;
    cout << "Screen name: " << getScreenName() << endl;
    cout << "You may now log in to your newly created account." << endl;
    cout << endl;

    string infoFileName = screenName + "_info.txt";
    string followerFileName = screenName + "_follow.txt";
    string activityFileName = screenName + "_activity.txt";

    registerUser(fout, screenName);

    fout.open(infoFileName.c_str());
    writeUserInfo(fout, fName, lName, bYear, screenName);
    fout.close();
}


/// Write User Information
void writeUserInfo(ofstream & fout, string & first, string & last, string & year, string & screen)
{
    fout << first + " " + last + " " + year + " ";
}

/// Register User
void registerUser(ofstream & fout, string screen)
{
    fout.open("RegisteredUsers.txt", ios::app);
    fout << " " + screen;
    fout.close();
}

/// Log out
void UserInfo::logOut(){

    if(isLogOut == true){
        cout << "No user login, sorry...\n\n";
        return;
    }

    isLogOut = true;
    cout << "Logged Out Successfully\n" << endl;
}

/// List of all users
void listUsers()
{
    ifstream fin;
    string screen;
    cout << "\n===============================================\n";
    cout << "The following users are registered: " << endl << endl;
    fin.open("RegisteredUsers.txt");
    while(!fin.eof())
    {
        fin >> screen;
        cout << screen << endl;
    }
    cout << "=============================================\n\n";
    fin.close();
}

/// User Sign in
void UserInfo::signIn()
{
    int offset;
    string line;
    bool exists;
    string screenName;

    cout << "Please enter your screen name to sign in: ";
    do
    {
        if(isLogOut == false){
            cout << "Log out first then try to log in\n";
            return;
        }
        cin >> screenName;
        exists = true;
            fin.open("RegisteredUsers.txt");
            while (!fin.eof())
            {
                getline(fin, line);
                if ((offset = line.find(screenName, 0)) == string::npos)
                {
                    exists = false;
                    cout << endl;
                    cout << "User " << screenName << " does not exist!" << endl << endl;
                    cout << "Please enter an existing username to sign in: ";
                }
            }
            fin.close();
    } while (exists = false || exists != true or isLogOut == false);
    cout << "You are now logged in as " + screenName << endl;
    isLogOut = false;

}




/// Display User Profile
void UserInfo::displayProfile()
{
    cout << "Enter screen name\n";
    string screen_name;   cin >> screen_name;

    ifstream fin;
    fin.open(screen_name+"_info.txt", ios::in);
    string screen;

    cout << "\n=======================================\n";
    cout << "Details are:\n\n";
    fin >> screen;
    cout << "First Name: " << screen << " \n";
    fin >> screen;
    cout << "Last Name: " << screen << " \n";
    fin >> screen;
    cout  << "Date of Birth: " << screen << " \n";
    fin >> screen;
    cout << "userName: " << screen << endl;

    cout << "\n======================================\n\n";
    //fin.read((char*)this, sizeof(*this));
}













/// Constructor
UserInfo::UserInfo(){
    _firstName = "";
    _lastName = "";
    _birthYear = "";
    _screenName = "";
}


/// Set first Name
void UserInfo::setFirstName(string fName)
{
    _firstName = fName;
}

/// Get First Name
string UserInfo::getFirstName()
{
    return _firstName;
}

/// Set Last Name
void UserInfo::setLastName(string lName)
{
    _lastName = lName;
}

/// Get Last Name
string UserInfo::getLastName()
{
    return _lastName;
}

/// Set Date of Birth
void UserInfo::setBirthYear(string bYear)
{
    _birthYear = bYear;
}

/// Get Date of Birth
string UserInfo::getBirthYear()
{
    return _birthYear;
}

/// Set Screen Name
void UserInfo::setScreenName(string screenName)
{
    _screenName = screenName;
}

/// Get Screen Name
string UserInfo::getScreenName()
{
    return _screenName;
}
