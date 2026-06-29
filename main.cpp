#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <ctime>
#include <iomanip>

// Include other code files to the main code
#include "Apps\CMD\cmd.h"
#include "Apps\SETTINGS\settings.h"

// Include user data file
#include "user.h"

using namespace std;

int main () {
    cout << "Initializing WaraqaOS.." << endl;
    User user; // New user
    // Account setup
    cout << "Enter a username: ";
    getline(cin, user.username);
    if (user.username.empty()) {
        user.username = "Guest"; // Prevent user from not having a username
    }
    while (true) {
        cout << "Enter a password: ";
        getline(cin, user.password);
        if (user.password.empty()) {
            // Check if the user is sure they don't want a password
            cout << "Are you sure you don't want to put a password? (Y/N): "; 
            getline(cin, user.user);
            if (user.user == "Y" || user.user == "y") {
                break;
            }
        } else {
            break;
        }
    } if (user.password.empty()) {
        user.password_hint = "No hint provided"; // Deafult no hint when there isn't a password
    } else {
        cout << "Make password hint? (Y/N): ";
        getline(cin, user.user);
        if (user.user == "Y" || user.user == "y") {
            cout << "Enter a hint: ";
            getline(cin, user.password_hint);
        } else {
            user.password_hint = "No hint provided"; // Deafult no hint instead of empty hint
        }
    }
    while (true){
        // Main menu
        cout << "==================================================================================================" << endl;
        cout << "APPS (Type 'shutdown' to shut down) :" << endl;
        cout << "cmd, settings" << endl;
        getline(cin, user.current_app);
        if (user.current_app == "cmd") {
            cout << "==================================================================================================" << endl;
            start_cmd(user); // In cmd.cpp
        } else if (user.current_app == "settings") {
            cout << "==================================================================================================" << endl;
            settings(user); // In settings.cpp
        } else if (user.current_app == "shutdown") {
            break; // Exit OS
        } else {
            cout << "App doesn't exist" << endl;
        }
    }

    return 0;
}