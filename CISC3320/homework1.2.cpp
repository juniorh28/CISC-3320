//Junior Hernandez
//CISC 3320
//Homework 1.2 Learning to create Process: 4 child process in 1 parent process array
#include <iostream>
#include <unistd.h>

using std::cout;
using std::endl;

int main()
{

    pid_t childProcessArray[4]; //empty array in parent, that will holds 4 child process


    //The parent will print its id first
    cout << "parent process: " << getpid() << endl;

    //the for loop will then create 4 child process 
    for (int x = 0; x < 4; ++x)
    {
        pid_t process = fork();
        //each child will sleep for 4 sec 
        //then return in order to stop more children from being made
        if (process == 0)
        {
            sleep(4);
            return 0;
        }
        //the parent will add each child to an array so they can be read later
        if (process > 0)
        {
            childProcessArray[x] = process;
        }
    }

    //read all child process
    for (int x = 0; x < 4; x++)
    {
        cout << "child process: " << childProcessArray[x] << endl;
    }

    return 0;
}
