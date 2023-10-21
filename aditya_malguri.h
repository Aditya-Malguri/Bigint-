
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <gmp.h>


typedef struct Term {
    mpz_t coefficient; 
    int exponent;
    struct Term* next;
} Term;

typedef struct Polynomial {
    Term* head;
} Polynomial;


Polynomial* createPolynomial();
void insertTerm(Polynomial* poly, const mpz_t coefficient, int exponent);
void addPolynomials(Polynomial* result, const Polynomial* poly1, const Polynomial* poly2);
void subtractPolynomials(Polynomial* result, const Polynomial* poly1, const Polynomial* poly2);
void multiplyPolynomials(Polynomial* result, const Polynomial* poly1, const Polynomial* poly2);
void printPolynomial(const Polynomial* poly);
void destroyPolynomial(Polynomial* poly);

#endif 

