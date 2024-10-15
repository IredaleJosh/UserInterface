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
    
    float value;
    //input >> value == reads a single numerica value into "value"
    //repeats until fail e.g. end of the file
    while (input >> value){
        //puts the value into the data vector
        data.push_back(value);
    }
}

//const == being used for efficiency rather than to change it
//makes function more efficient
float mean_value(const vector<float>& average){

    float average_value = 0;
    for(int i=0; i<=average.size();i++){
        average_value += average[i];
    }
    return average_value/average.size();
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
    float mean;
    read_data(infile, data);
    mean = mean_value(data);
    //.size() gets the size of the vector
        //find more in lecture 1 slides
    cout << data.size() << " read from the file" << endl;
    cout << "Mean value = " << mean << endl;
    return 0;    
}