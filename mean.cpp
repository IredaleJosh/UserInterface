#include <iostream>
#include <fstream> //library to rea from/ write to files
#include <vector> //library to create vectors
                    //vector is a dynamic array of any type of data we chose

using namespace std;

//parameters
//input --> takes an input stream
//data --> a vector capable of holding float values
//& == means both are references, as function will change them

void read_data(istream& input, vector<float>& data){
    //
    float value;
    while (input >> value){
        data.push_back(value);
    }
}

//argc == arguement count --> n0. of arguements
//argv == arguement values --> what the arguements are

int main(int argc, char* argv[]){
    if(argc != 2){
        cerr << "Usage: ./mean <filename>" << endl;
        return 1;
    }

    //this reads a file, nd uses ifstream object
    //te first line gets the value of the first arguement
    //2nd line uses an if to check the status of the object -> False means no file
    ifstream infile(argv[1]);
    if (not infile){
        cerr << "Error: cannot access " << argv[1] << endl;
        return 2;
    }
    vector<float> data;
    read_data(infile, data);
    return 0;    
}