#pragma once
#include <iostream>

class VecteurD {
private:
    std::size_t m_taille;
    double* m_donnees;

public:
    explicit VecteurD(std::size_t taille = 0, double valInit = 0.0);
    ~VecteurD();
    VecteurD(const VecteurD& autre);
    void print();
    VecteurD& operator=(const VecteurD& rhs);
    double& operator[](std::size_t indice);
    const double& operator[](std::size_t index) const;
    friend std::ostream& operator<<(std::ostream& os, const VecteurD& v);
    bool operator==(const VecteurD& rhs) const;
    bool operator!=(const VecteurD& rhs) const;
    VecteurD& operator+=(const VecteurD& rhs);
    VecteurD& operator-=(const VecteurD& rhs);
    VecteurD& operator*=(double scalaire);
    friend VecteurD operator+(VecteurD a, const VecteurD& b);
    friend VecteurD operator-(VecteurD a, const VecteurD& b);
    friend VecteurD operator*(VecteurD a, double scalaire);
    friend VecteurD operator*(double scalaire, VecteurD v);
    friend double operator*(VecteurD a, const VecteurD& b);
    VecteurD operator-() const;
    VecteurD& operator++();
    VecteurD operator++(int);
};