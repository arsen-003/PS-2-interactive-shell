#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    std::string input;

    while (true) {
        std::cout << ">> ";
        std::getline(std::cin, input);

        if (input == "exit") {
            std::cout << "Exiting shell..." << std::endl;
            break;
        }

        if (input.empty()) continue;

        bool silent = false;
        if (input.substr(0, 6) == "silent") {
            silent = true;
            input = input.substr(7); // Remove "silent " prefix
        }

        pid_t pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            continue;
        }

        if (pid == 0) { // Child process
            if (silent) {
                std::string logFile = std::to_string(getpid()) + ".log";
                int log_fd = open(logFile.c_str(), O_CREAT | O_WRONLY | O_TRUNC, 0644);
                if (log_fd == -1) {
                    perror("Log file error");
                    _exit(1);
                }
                dup2(log_fd, STDOUT_FILENO);
                dup2(log_fd, STDERR_FILENO);
                close(log_fd);
            }

            char* args[] = {(char*)"/bin/sh", (char*)"-c", (char*)input.c_str(), nullptr};
            execv("/bin/sh", args); // Execute the command
            perror("Execution failed");
            _exit(1);
        } else { // Parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
