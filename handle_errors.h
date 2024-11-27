#pragma once
#include <fstream>

void valid_number_of_arguments(const int& argc);
void handle_input_files(std::ifstream& inputFile, std::ofstream& outputFile);
void handle_size(int& N, std::ifstream& inputFile);