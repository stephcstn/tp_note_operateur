#include <iostream>
#include <cassert>
#include "VecteurD.hpp"

int main() {
    std::cout << "=== 1. Test des constructeurs et affichage ===" << std::endl;
    VecteurD v1(3, 2.5);
    std::cout << "v1 : " << v1 << std::endl; // Doit afficher [2.5, 2.5, 2.5]
    assert(v1[0] == 2.5 && v1[2] == 2.5);

    std::cout << "\n=== 2. Test copie et affectation ===" << std::endl;
    VecteurD v2 = v1; // Constructeur de copie
    v2[1] = 99.0;     // Ne doit pas modifier v1 (copie profonde)
    assert(v1[1] == 2.5);
    assert(v2[1] == 99.0);

    VecteurD v3;
    v3 = v2;          // Opérateur d'affectation
    assert(v3 == v2);
    assert(v1 != v2);

    std::cout << "\n=== 3. Test arithmétique et chaînage ===" << std::endl;
    VecteurD a(3, 1.0);
    VecteurD b(3, 2.0);
    VecteurD c = a + b;
    std::cout << "a + b = " << c << std::endl; // [3, 3, 3]
    assert(c[0] == 3.0);

    // Test commutativité de la multiplication par un scalaire
    VecteurD d1 = a * 5.0;
    VecteurD d2 = 5.0 * a;
    assert(d1 == d2);
    assert(d1[0] == 5.0);

    // Test produit scalaire
    double prod = a * b; // 1*2 + 1*2 + 1*2 = 6.0
    assert(prod == 6.0);

    std::cout << "\n=== 4. Test unaires et incrémentation ===" << std::endl;
    VecteurD inv = -a;
    assert(inv[0] == -1.0);

    VecteurD testInc(2, 10.0);
    VecteurD post = testInc++;
    assert(post[0] == 10.0);
    assert(testInc[0] == 11.0);

    VecteurD& pre = ++testInc;
    assert(pre[0] == 12.0);
    assert(&pre == &testInc); // Vérifie le renvoi par référence

    std::cout << "\n=== 5. Test de sûreté face aux exceptions ===" << std::endl;
    VecteurD court(2, 1.0);
    VecteurD longVect(4, 1.0);
    try {
        VecteurD fail = court + longVect;
        assert(false); // Ne doit pas arriver
    } catch (const std::invalid_argument& e) {
        std::cout << "Exception bien interceptee : " << e.what() << std::endl;
    }

    std::cout << "\n>>> TOUS LES TESTS SONT PASSES AVEC SUCCES ! <<<" << std::endl;
    return 0;
}