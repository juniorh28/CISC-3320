//Junior Hernandez
//CISC 3320
//Homework 1.1 Learning to create Process: Date and day
#include <iostream>
#include <unistd.h> 
#include <ctime> //Get current date

using std::cout;
using std::endl;

int main()
{
    // fork will create a seperate but duplicate process
    pid_t c_pid = fork();

    // current date and time on the current system
    // How to get current date - https://www.cplusplus.com/reference/ctime/strftime/
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    if (c_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (c_pid > 0)
    {
        cout << "printed from parent process " << getpid() << endl;
        strftime(buffer, 80, "Date: %D.", timeinfo);
        puts(buffer);

        wait(nullptr);
    }
    else
    {
        cout << "printed from child process " << getpid() << endl;
        strftime(buffer, 80, "Today is %A.", timeinfo);
        puts(buffer);

        exit(EXIT_SUCCESS);
    }

    return EXIT_SUCCESS;
}
