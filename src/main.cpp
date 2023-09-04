/**
 * @file main.cpp
 * @author Muhammad Syamim (Syazam33@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../inc/matrix.hpp"

int main(){
    /* Initialize Test */
    MATRIX m1;
    std::cout << "Initialize Test: \n" << m1;
    /* Assignment Test */
    m1 = {0, 1, 2};
    std::cout << "\nAssignment Test: \n" << m1;
    MATRIX m2;
    m2 = {3, 4, 5};
    /* Addition Test */
    std::cout << "\nAddition Test: m1 + m2\n" << m1 + m2;
    /* Subtraction Test */
    /* Dot Product */
    /* Cross Product */
    /* Transpose Test */
    /* Inverse Test */
    /* Determinant Test */
    std::cout << "\nDeterminant Test:\n" << m2;
    std::cout << "Determinant: " << m2.Determinant() << '\n';
}