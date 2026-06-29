#include "settings.h"

// Include user data file
#include "../../user.h"
#include <iostream>
using namespace std;

void settings(User &user) {
    while (true) {
        cout << "ENTER A NUMBER ('exit' to exit program):\n";
        cout << "(1) Change password\n";
        cout << "(2) Change password hint\n";
        cout << "(3) Reset account\n";
        getline(cin, user.user);
        if (user.user == "1"){
            if (user.password != "") { 
                cout << "\033[2J\033[1;1H"; // Clear screen
                cout << "SCREEN CLEARED FOR PRIVACY\n";
            }
            while (true) {
                if (user.password == "") { 
                    user.user = "";
                } else {
                    cout << "Enter old password (c to cancel): ";
                    getline(cin, user.user);
                }
                if (user.user == user.password) {
                    while (true) {
                        cout << "Enter a password: ";
                        getline(cin, user.password);
                        if (user.password == ""){
                            cout << "Are you sure you want to leave your password empty? (Y/N): ";
                            getline(cin, user.user);
                            if (user.user == "Y" || user.user == "y") {
                                break;
                            }
                        } else {
                            break;
                        }
                    }
                    break;
                } else if (user.user == "c") {
                    break;
                } else {
                    cout << "Password incorrect!\n";
                }
            }
        } else if (user.user == "2"){
            cout << "New password hint: ";
            getline(cin, user.password_hint);
        } else if (user.user == "3") {
            cout << "Are you sure you want to reset your account? (Y/N): ";
            getline(cin, user.user);
            if (user.user == "Y" || user.user == "y") {
                user.username = "Guest";
                user.password = "";
                user.password_hint = "No hint provided";
                cout << "Account reset successfully\n";
            }
        } else if (user.user == "exit") {
            break; // Exit settings app
        } else {
            cout << "Command doesn't exist\n";
        } 
    }
}