#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

#include "matrix.hpp"

using std::cin;
using std::cout;
using std::string;

bool isInKernel(Matrix &, Matrix &);

int main(int argc, const char * argv[]) {
    
    if (!freopen("/Users/greg/Library/Mobile Documents/com~apple~CloudDocs/School/MATH 214/math214 proj/math214 proj/input.txt", "r", stdin)) {
        std::cerr << "freopen() failed, file not found\n";
        exit(1);
    }
    
    Matrix parity(cin, 4, 9);
    
    cout << "Parity Check Matrix:\n" << parity;
    
    std::vector<Matrix> codes;
    
    const unsigned int codeLength = 50;
    
    for (int i = 0; i < codeLength; i++)
        codes.push_back(Matrix(cin, 1, 9));
    
    cout << "Code: \n";
    
    for (int i = 0; i < codeLength; i++) {
        if (not isInKernel(parity, codes[i])) {
            for (int c = 0; c < codes[i].colCount(); c++) {
                codes[i][0][c] = codes[i][0][c] xor 1;
                if (isInKernel(parity, codes[i])) break;
                codes[i][0][c] = codes[i][0][c] xor 1;
            }
        }
        string binaryString = "";
        for (int j = 0; j < 5; j++)
            binaryString += codes[i][0][j] ? '1' : '0';
        char val = std::stoi(binaryString, nullptr, 2) + 64;
        cout << (val == '@' ? ' ' : val);
    }
    
    cout << std::endl;
    
    return 0;
}

bool isInKernel(Matrix & a, Matrix & b) {
    
    Matrix res((unsigned int) a.rowCount(), 1);
    
    for (int r = 0; r < a.rowCount(); r++) {
        int sum = false;
        for (int c = 0; c < a.colCount(); c++)
            sum = sum xor (a[r][c] bitand b[0][c]);
        res[r][0] = sum;
    }
    
    unsigned int sum = 0;
    
    for (int r = 0; r < res.rowCount(); r++)
        sum += res[r][0];
    
    return sum == 0;
}
