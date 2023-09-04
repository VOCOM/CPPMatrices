/**
 * @file matrix.cpp
 * @author Muhammad Syamim (Syazam33@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../inc/matrix.hpp"

MATRIX::MATRIX() : MATRIX(1, 1) {}

MATRIX::MATRIX(const int rows,const int cols) : m_rows(rows), m_cols(cols)
{
    Resize();
    Clear();
}

MATRIX::~MATRIX()
{
}

size_t MATRIX::Rows() const { return m_rows; }

size_t MATRIX::Cols() const { return m_cols; }

void MATRIX::Resize()
{
    m_data.resize(m_rows);
    for(auto& row : m_data) row.resize(m_cols);
}

void MATRIX::Clear()
{
    for(size_t i{}; i < m_rows; i++)
    {
        for(size_t j{}; j < m_cols; j++){
            m_data[i][j] = 0.0f;
        }
    }
}

void MATRIX::Reset()
{
    m_rows = 1;
    m_cols = 1;
    Resize();
    Clear();
}

bool MATRIX::isSquare() const { return m_rows == m_cols ? true : false; }

/**
 * @brief Calculates the determinant of the underlying matrix
 * 
 * @return double The determinant | -1 if non-square
 */
double MATRIX::Determinant() const
{
    if(!isSquare()) return -1;
    if(m_rows == 2) return Determinant2(m_data[0][0], m_data[0][1], m_data[1][0], m_data[1][1]);
    if(m_rows == 3) return Determinant3();
    /* To Do: Implement Co Factor for NxN matrix */
    return -1;
}

double MATRIX::Determinant2(const int a, const int b, const int c, const int d) const { return ( a * d ) - ( b * c ); }

double MATRIX::Determinant3() const
{
    double d1 = Determinant2(m_data[1][1], m_data[1][2], m_data[2][1], m_data[2][2]);
    double d2 = Determinant2(m_data[1][0], m_data[1][2], m_data[2][0], m_data[2][2]);
    double d3 = Determinant2(m_data[1][0], m_data[1][1], m_data[2][0], m_data[2][1]);
    return ( m_data[0][0] * d1 ) - ( m_data[0][1] * d2 ) + ( m_data[0][2] * d3 );
}

std::vector<double>& MATRIX::operator[](const size_t index) { return m_data[index]; }

std::vector<double> MATRIX::operator[](const size_t index) const { return m_data[index]; }

MATRIX& MATRIX::operator=(std::initializer_list<double> list)
{
    m_rows = 1;
    if(list.size() == 0){
        m_cols = 1;
        Resize();
    }else{
        m_cols = list.size();
        m_data.insert(m_data.begin(), list);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const MATRIX& rhs)
{
    os << rhs.Rows() << "x" << rhs.Cols() << " matrix\n";
    for(size_t i{}; i < rhs.Rows(); i++){
        os << "[ ";
        for(size_t j{}; j < rhs.Cols(); j++){
            os << rhs[i][j] << " ";
        }
        os << "]\n";
    }

    return os;
}

/* Arithmetic */
MATRIX MATRIX::operator+(const MATRIX rhs) const
{
    if((m_rows != rhs.Rows()) && (m_cols != rhs.Cols())){
        /* To Do: Add Exceptions */
        throw;
    }

    MATRIX m(m_rows, m_cols);

    for(size_t i{}; i < m_rows; i++){
        for(size_t j{}; j < m_cols; j++){
            m[i][j] = m_data[i][j] + rhs[i][j];
        }
    }
    return m;
}
