/** 
    Coding Assignment 4: Compression
    compress.cpp
    November 5, 2019

    @author <your name>
    @collaboration
*/

#include <iostream>
#include <string>

using namespace std;

/**
    compress text from a given input file to a given
    output file

    @param argc the number of command-line arguments
    @param argv an array of command-line-arguments
    @return an error code
*/
int main(int argc, char **argv) {
    if (argc != 3) {
        cout << "usage: " << argv[0] << "<input file> <output file>" << endl;
        return 1;
    }

    string input_file_name(argv[1]);
    string output_file_name(argv[2]);
    cout << "Compressing " << input_file_name << " and writing to ";
    cout << output_file_name << endl;

    //TODO: Compress

    return 0;
}
