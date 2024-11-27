#include <iostream>
#include <algorithm>
#include <cmath>
#include "matrix.h"

istream &operator>>(istream& in, Matrix& mat){
    for (int i = 0; i < mat.N; i++){
        for (int j = 0; j < mat.N; j++){
            in >> mat.matrix[i][j];
        }
    }
    return in;
}

vector<vector<bool>> Matrix::set_borders(vector<vector<bool>> &seen) {
    for (int i = 0; i < N/2; i++){
        seen[N-2-i][i] = true;
    }
    for (int i = N/2 - 1; i < N; i++){
        seen[i][i+1] = true;
    }

    return seen;
}

vector<int> Matrix::snake_traversal(){
    if (N == 2) { return {matrix[0][0], matrix[0][1]};}

    vector<int> result;
    int col_num = 0;

    for (int i = 0; i < N/2; i++){
        for (int j = 0; j <= i; j++){
            result.push_back(matrix[j][col_num]);
        }
        col_num++;

        if (i % 2 == 1){
            reverse(result.end() - i - 1, result.end());
        }
    }


    for (int i = N/2 + 1; i <= N; i++){
        for (int j = 0; j < N - col_num; j++){
            result.push_back(matrix[j][col_num]);
        }
        col_num++;

        if (i % 2 == 0){
            reverse(result.end() - N + col_num - 1, result.end());
        }
    }

    return result;
}

vector<int> Matrix::spiral_traversal(){
    if (N == 2) { return {matrix[1][0], matrix[1][1]};}

    vector<int> result;

    int top = ceil(N/2.0), bottom = N-1;
    int left = 0, right = N-1;

    vector<vector<bool>> seen(N, vector<bool>(N, false));
    this->set_borders(seen);

    int dRow[3] = {0, -1, 1};
    int dCol[3] = {-1, 1, 1};

    int x = N-1, y = N-1, di = 0;

    while(!seen[x][y]){
        result.push_back(matrix[x][y]);

        seen[x][y] = true;

        int newX = x + dRow[di], newY = y + dCol[di];

        if (top - 1 <= newX && newX <= bottom && left <= newY && newY <= right && !seen[newX][newY]){
            x = newX;
            y = newY;
        }
        else {
            di = (di + 1) % 3;
            x += dRow[di];
            y += dCol[di];

            if (di == 0){
                left++;
                right--;
            }
            else if (di == 1){
                bottom--;
            }
            else if (di == 2){
                if (!seen[x-1][y]){x--;}
                top++;
            }
        }
    }

    return result;
}

vector<int> Matrix::modulo_sequence() {
    vector<int> result;

    vector<int> spiral = this->spiral_traversal();
    vector<int> snake = this->snake_traversal();

    for (int i = 0; i < snake.size(); i++){
        if (snake[i] == 0){result.push_back(INT_MAX);} //division by zero -> print INT_MAX
        else{result.push_back(spiral[i] % snake[i]);}
    }
    return result;
}

Matrix::~Matrix(){
    matrix.clear();
}