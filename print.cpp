#include <iostream>
#include "print.h"

void printInfo(){
    std::cout << "The lab consists of implementing a matrix traversal and finding some values during this traversal.\n" << std::endl;
}

void printSequences(Matrix& matrix){
    std::cout << "Spiral traversal: ";
    for (int& i : matrix.spiral_traversal()){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Snake traversal: ";
    for (int& i : matrix.snake_traversal()){
        std::cout << i << " ";
    }
    std::cout << std::endl;

}

void printResult(Matrix& matrix, std::ofstream& outputFile){
    std::cout << "Modulo sequence: ";
    for (int& i : matrix.modulo_sequence()){
        std::cout << i << " ";
        outputFile << i << " ";
    }
    std::cout << std::endl;
}

void printEnd(){
    std::cout << "\nFINISHED" << std::endl;
}