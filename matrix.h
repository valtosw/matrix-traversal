#pragma once
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Matrix{
    int N;
    vector<vector<int>> matrix;
public:
    Matrix(int N) : N(N), matrix(N, vector<int>(N)){};
    Matrix(const Matrix&) = delete;
    Matrix(Matrix&&) = delete;
    Matrix &operator=(Matrix&&) = delete;
    Matrix &operator=(const Matrix&) = delete;
    ~Matrix();

    friend istream &operator>>(istream& in, Matrix& mat);

    vector<vector<bool>> set_borders(vector<vector<bool>> &seen);
    vector<int> snake_traversal();
    vector<int> spiral_traversal();
    vector<int> modulo_sequence();
};