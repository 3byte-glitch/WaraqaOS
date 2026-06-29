#ifndef USER_H
#define USER_H

// User data file

#include <iostream>
using namespace std;

// All variables associated with the user
struct User { 
    string cmd;
    string user;
    string username;
    string password;
    string password_hint;
    string current_app;
};

#endif