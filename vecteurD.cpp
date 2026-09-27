#include "vecteurD.hpp"

VecteurD::VecteurD(std::size_t taille, double valInit){
    if (taille == 0){
        m_donnees = nullptr;
        m_taille = 0;
    }else{
        m_donnees = new double[taille];

        for (std::size_t i = 0; i < taille; i++){
            m_donnees[i] = valInit;
        }

        m_taille = taille;
    }
    
}

VecteurD::~VecteurD(){
        delete[] m_donnees;
        m_donnees = nullptr;
        m_taille = 0;
}

VecteurD::VecteurD(const VecteurD& autre){
    m_donnees    = new (std::nothrow) double[autre.m_taille];

    if (m_donnees == nullptr) {
        std::cerr << "Echec de l'allocation memoire (pointeur nul)." << std::endl;
        return;
    }

    for (std::size_t i = 0; i < autre.m_taille; i++){
        m_donnees[i] = autre.m_donnees[i];
    }

    m_taille = autre.m_taille;
}

void VecteurD::print(){
    if (m_taille == 0){
        std::cout << "tableau vide" << std::endl;
        return;
    }
    std::cout << "[ ";

    for (std::size_t i = 0; i < m_taille-1 ; i++){
        std::cout << m_donnees[i] << " , ";
    }
    std::cout << m_donnees[m_taille-1] << " ]" << std::endl;

    std::cout << "La taille du tableau est :" << m_taille << std::endl;
}


VecteurD& VecteurD::operator=(const VecteurD& rhs){
    if (this == &rhs){
        return *this;
    }
    double* m_donnees_tmp = nullptr;

    if (rhs.m_taille > 0) {
        m_donnees_tmp = new (std::nothrow) double[rhs.m_taille];

        for (std::size_t i = 0; i < rhs.m_taille; i++){
            m_donnees_tmp[i] = rhs.m_donnees[i];
        }
    }

    delete[] m_donnees;
    m_donnees = m_donnees_tmp;
    m_taille = rhs.m_taille;

    return *this;
}

double& VecteurD::operator[](std::size_t index) {
    return m_donnees[index];
}

const double& VecteurD::operator[](std::size_t index) const {
    return m_donnees[index];
}

std::ostream& operator<<(std::ostream& os, const VecteurD& v){
    if (v.m_taille == 0){
        os << "[]\n";
        return os;
    }
    os << "[ ";

    for (std::size_t i = 0; i < v.m_taille-1 ; i++){
        os << v.m_donnees[i] << " , ";
    }
    os << v.m_donnees[v.m_taille-1] << " ]";

    return os;
}

bool VecteurD::operator==(const VecteurD& rhs) const{
    if (m_taille != rhs.m_taille){
        return false;
    }else {
        for (std::size_t i = 0; i < m_taille ; i++){
            if (m_donnees[i] != rhs.m_donnees[i]){
                return false;
            }
        }
    }
    return true;
}

bool VecteurD::operator!=(const VecteurD& rhs) const{
    return !(this->operator==(rhs));
}

VecteurD& VecteurD::operator+=(const VecteurD& rhs){
    if (m_taille != rhs.m_taille){
        throw std::invalid_argument("Tailles incompatibles.");
    }

    for (std::size_t i = 0 ; i < m_taille ; i++){
        m_donnees[i] = m_donnees[i] + rhs.m_donnees[i];
    }

    return *this;
}

VecteurD& VecteurD::operator-=(const VecteurD& rhs){
    if (m_taille != rhs.m_taille){
        throw std::invalid_argument("Tailles incompatibles.");
    }

    for (std::size_t i = 0 ; i < m_taille ; i++){
        m_donnees[i] = m_donnees[i] - rhs.m_donnees[i];
    }

    return *this;
}

VecteurD& VecteurD::operator*=(double scalaire){

    for (std::size_t i = 0 ; i < m_taille ; i++){
        m_donnees[i] = m_donnees[i] * scalaire;
    }

    return *this;
}

VecteurD operator+(VecteurD a, const VecteurD& b){
    a += b;   // On applique += sur notre copie locale
    return a;
}

VecteurD operator-(VecteurD a, const VecteurD& b){
    a -= b;   // On applique += sur notre copie locale
    return a;
}

VecteurD operator*(VecteurD a, double scalaire){
    a *= scalaire;
    return a;
}

VecteurD operator*(double scalaire, VecteurD v){
    v *= scalaire;
    return v;
}

double operator*(VecteurD a, const VecteurD& b) {
    if (a.m_taille != b.m_taille) {
        throw std::invalid_argument("Tailles incompatibles pour le produit scalaire.");
    }
    double somme = 0.0;
    for (std::size_t i = 0; i < a.m_taille; ++i) {
        somme += a.m_donnees[i] * b.m_donnees[i];
    }
    return somme;
}

VecteurD VecteurD::operator-() const {
    VecteurD copie(*this);    
    for (std::size_t i = 0; i < copie.m_taille; ++i) {
        copie.m_donnees[i] = -copie.m_donnees[i];
    }
    return copie;
}

VecteurD& VecteurD::operator++(){
    for (std::size_t i = 0 ; i < m_taille ; i++){
        ++m_donnees[i];
    }
    return *this;
}

VecteurD VecteurD::operator++(int){
    VecteurD copie(*this);    
    ++(*this);
    return copie;
}