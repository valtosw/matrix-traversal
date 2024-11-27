#include <iostream>
#include <fstream>
#include <vector>
#include "handle_errors.h"
using namespace std;

void valid_number_of_arguments(const int& argc){
    if (argc != 3){
        cout << "Wrong number of command-line arguments" << endl;
        exit(1);
    }
}

void handle_input_files(ifstream& inputFile,ofstream& outputFile){
    if (!inputFile.is_open() || !outputFile.is_open()){
        cout << "Error opening files" << endl;
        exit(1);
    }
}

void handle_size(int& N, ifstream& inputFile){
    inputFile >> N;
    if (N < 2){
        cout << "Invalid size" << endl;
        exit(1);
    }

    vector<int> elements;
    int el;

    while(inputFile >> el){
        elements.push_back(el);
    }
    if (elements.size() != N*N){
        cout << "Invalid number of integers in a matrix" << endl;
        exit(1);
    }
}