# WaraqaOS Guide

Welcome to the documentation for WaraqaOS. Use this guide to learn how to navigate the apps and use CLI and other apps.

## CLI

### Core commands

| Command | Arguments | Description | Example |
| :--- | :--- | :--- | :--- |
| `help` | None | Displays available system commands. | `help` |
| `info` | None | Provides general information about the OS. | `info` |
| `echo` | `[text]` | Prints the provided text directly to the screen. | `echo hello` |
| `lock` | None | Clears the terminal and locks it with the user's password. | `lock` |
| `clear` | None | Clears the terminal screen. | `clear` |
| `exit` | None | Exits the CLI. | `exit` |

## Echo function

Special flags can be used immediately after the `echo` command for modifying output or to output a system variable

### Modifiers
#### 1. $UPPER
Make following text fully uppercase
#### 2. $LOWER
Make following text fully lowercase
#### 3. $REVERSE
Make following text reversed
#### 4. $COUNT
Print number of letters in the text

### System variable (NO ARGUMENTS)
#### 1. $USER
Prints the user's username
#### 2. $HISTORY
Prints the user's command history
#### 3. $TIME
Print the current time
#### 4. $DATE
Print the current date
