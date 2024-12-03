# Interactive Shell

This is a simple interactive shell program written in C++. It allows you to execute commands and redirect output to log files when running commands in "silent" mode.

## Features

- Execute standard system commands (e.g., `ls`, `/bin/ls`, `./program`).
- Redirect output to a log file when using "silent" mode (e.g., `silent ls`).
- Exit the shell gracefully using the `exit` command.

## Requirements

- **C++ compiler**: Make sure `g++` is installed.
- **Make utility**: Ensure `make` is available on your system.

## Build Instructions

1. Clone or download the project:
   ```bash
   git clone https://github.com/arsen-003/interactive-shell.git
   cd interactive-shell
   make
   ./interactive-shell
