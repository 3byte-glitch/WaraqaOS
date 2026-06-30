#include "cmd.h"
#include "../../user.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cctype>
#include <algorithm>
#include <iomanip>

vector<string> history; // Command history

using namespace std;
void echo(string input, string username);
void start_cmd(User &user) {
    cout << "CMD LINE loaded.. type 'help' to show commands\n";
    while (true) {
        // Command loop

        // Time update
        time_t now = time(nullptr);
        tm* local_time = localtime(&now);

        cout << "Waraqa@" << user.username << "> ";
        getline(cin, user.cmd);
        history.push_back(user.cmd); // Add user's command to history

        if (user.cmd == "help") {
            cout << "Available commands: help, info, clear, echo, lock, exit\n";
        } else if (user.cmd == "info") {
            cout << "WaraqaOS v1.0.0, made by Omar (c) 2026\n";
        } else if (user.cmd == "clear") {
            cout << "\033[2J\033[1;1H"; // Clear screen
        } else if (user.cmd.find("echo ") == 0) {
            echo(user.cmd, user.username);
        } else if (user.cmd == "lock") {
            if (user.password == "") {
                cout << "Cannot lock system without a password\n";
            } else {
                cout << "\033[2J\033[1;1H"; // Clear screen
                cout << "SYSTEM LOCKED\n";
                cout << "SCREEN CLEARED FOR PRIVACY\n";
                cout << "Password hint: " << user.password_hint << '\n';
                while (true) {
                    cout << "Enter password to unlock: ";
                    getline(cin, user.user);
                    if (user.user == user.password) {
                        cout << "Password correct! Unlocked successfully\n";
                        break;
                    } else {
                        cout << "Password incorrect!\n";
                    }
                }
            }
        } else if (user.cmd == "exit") {
            break; // Exit app
        } else {
            cout << "Unavailable command\n";
        }
    }
}
void echo(string input, string username) {
    time_t now = time(nullptr);
    tm* local_time = localtime(&now);
    string text;
    if (input == "echo $USER") {
        cout << username;
    } else if (input == "echo $HISTORY") {
        for (const string& h : history) {
            cout << h << '\n';
        }
    } else if (input == "echo $TIME") {
        cout << put_time(local_time, "%H:%M") << '\n';
    } else if (input == "echo $DATE") {
        cout << put_time(local_time, "%d/%m/%Y") << '\n';
    } else if (input.substr(5, 7) == "$UPPER ") {
        text = input.substr(12);
        transform(text.begin(), text.end(), text.begin(), [](unsigned char c) {
            return toupper(c);
        });
        cout << text << '\n';
    } else if (input.substr(5, 7) == "$LOWER ") {
        text = input.substr(12);
        transform(text.begin(), text.end(), text.begin(), [](unsigned char c) {
            return tolower(c);
        });
        cout << text << '\n';
    } else if (input.substr(5, 7) == "$COUNT ") {
        text = input.substr(12);
        cout << text.length() << '\n';
    } else if (input.substr(5, 9) == "$REVERSE ") {
        text = input.substr(14);
        reverse(text.begin(), text.end());
        cout << text << '\n';
    } else  {
        cout << input.substr(5) << '\n';
    }
}
