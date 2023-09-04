/**
 * @file matrix.hpp
 * @author Muhammad Syamim (Syazam33@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <initializer_list>
#include <vector>
#include <iostream>

class MATRIX
{
public:
    /* Construtors & Destructors */
    MATRIX();
    MATRIX(const int, const int);
    ~MATRIX();
    /* Information Function */
    size_t Rows() const;
    size_t Cols() const;
    bool isSquare() const;
    double Determinant() const;
    /* Manipulation Function */
    void Resize();
    void Reset();
    void Clear();
    /* Operators */
    std::vector<double>& operator[](const size_t);
    std::vector<double> operator[](const size_t) const;
    MATRIX& operator=(std::initializer_list<double>);
    /* Arithmetic */
    MATRIX operator+(const MATRIX) const;
private:
    size_t m_rows, m_cols;
    std::vector<std::vector<double>> m_data;
private:
    double Determinant2(const int a, const int b, const int c, const int d) const;
    double Determinant3() const;
};

/* Global Operators */
std::ostream& operator<<(std::ostream&, const MATRIX&);

#endif