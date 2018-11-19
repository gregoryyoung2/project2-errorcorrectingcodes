#ifndef matrix_hpp
#define matrix_hpp

#include <iostream>
#include <vector>

class Matrix {
  
public:
    
    Matrix(std::istream&, const unsigned int, const unsigned int);
    Matrix(const unsigned int, const unsigned int);

    
    std::vector<bool> & operator[](unsigned int i) { return contents[i]; }
    
    friend std::ostream& operator<<(std::ostream&, const Matrix&);
    
    size_t rowCount() const { return contents.size(); };
    size_t colCount() const {return contents.empty() ? 0 : contents[0].size(); };
    
    Matrix operator*(Matrix);
    
private:
    
    std::vector<std::vector<bool>> contents;
    
};



#endif /* matrix_hpp */
