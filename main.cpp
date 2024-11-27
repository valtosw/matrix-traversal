#include <iostream>
#include <fstream>
#include "print.h"
#include "matrix.h"
#include "handle_errors.h"

int main(int argc, char* argv[]){
    valid_number_of_arguments(argc);

    ifstream inputFile(argv[1]);
    ofstream outputFile(argv[2]);

    handle_input_files(inputFile, outputFile);

    int N; handle_size(N, inputFile);

    inputFile.clear(); inputFile.seekg(to_string(N).length(), ios::beg);

    Matrix matrix(N); inputFile >> matrix;

    printInfo();
    printSequences(matrix);
    printResult(matrix, outputFile);
    printEnd();

    inputFile.close();
    outputFile.close();

    return 0;
}
