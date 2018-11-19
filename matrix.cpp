#include <iostream>
#include <string>
#include <stdlib.h>

#include "matrix.hpp"

using std::istream;
using std::string;
using std::getline;
using std::ostream;
using std::atoi;

Matrix::Matrix(const unsigned int row, const unsigned int col) {
    contents.resize(row);
    
    for (auto & r : contents)
        r.resize(col);
}

Matrix::Matrix(istream & in, const unsigned int row, const unsigned int col) : Matrix(row, col) {
    
    for (int r = 0; r < row; r++) {
        string row;
        getline(in, row);
        for (int c = 0; c < col; c++)
            contents[r][c] = row[c] - 48;
    }
        
}

ostream& operator<<(ostream& os, const Matrix& mat) {
    for (const auto & row : mat.contents) {
        for (const auto val : row)
            os << val << ' ';
        os << '\n';
    }
    return os;
}

Matrix Matrix::operator*(Matrix b) {
    
    Matrix out(1, (unsigned int) colCount());
    
    for (auto c = 0; c < colCount(); c++) {
        bool sum = false;
        for (auto r = 0; r < rowCount(); r++) {
            sum = sum xor (b[0][r] bitand contents[r][c]);
        }
        out[0][c] = sum;
    }
    
    return out;
    
}
