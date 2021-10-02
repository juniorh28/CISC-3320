//Junior Hernandez
//CISC 3320
//Homework 1.3 Learning to create Process: children with children, showing parent's grandchild
#include <iostream>
#include <unistd.h>

using std::cout;
using std::endl;

int main()
{

    pid_t process = fork();

    //since fork returns twice, a child and a parent, when its the parent, 
    //we know it must be the grandparent process since its the first ever process
    if (process > 0)
    {
        cout << "I am the grandparent process " << process << endl;
    }
    //so the only thing left is the child of the grandparent
    else if (process == 0)
    {
        //but since the child process is also a parent, 
        //we need to check if which process is the parent and which is the grandchild
        pid_t c_process = fork();
        //following same logic, we can tell if the id is >0, its the parent
        if (c_process > 0)
        {
            cout << "I am the parent process " << process << endl;
        }
        //so the only thing left is the grandchild since its the child of the parent
        //who is in turn child of the grandparent
        else
        {
            cout << "I am a grandchild process " << process << endl;
        }
    }
    //wait so that the grandchild can be ran in the grandparent process
    wait(NULL);

    return 0;
}
