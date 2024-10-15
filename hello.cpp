#include <iostream> //the c++ I/O library

using namespace std; //allows for cout instead of std::cout

int main(){
    cout << "Hello World!" << endl;
    //cout == output stream object representing console output
    //<< == stream insertion operator, inserts value into stream
    return 0;
}

//run with g++ hello.cpp -o hello
//g++ == invokes C++ compiler
//-c == makes file of object code
//-o == makes an executable project