#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int coefficient;
    int exponent;
} Term;

typedef struct {
    Term *terms;
    int count;
} Polynomial;

Polynomial createPolynomial(int n);

Polynomial differentiatePolynomial(Polynomial poly);

void printPolynomial(Polynomial poly);

int main() {
    Polynomial poly, derivative;
    int n;

    scanf("%d", &n);
    poly = createPolynomial(n);

    derivative = differentiatePolynomial(poly);
    printPolynomial(derivative);

    free(poly.terms);
    free(derivative.terms);

    return 0;
}

Polynomial createPolynomial(int n) {
    Polynomial poly;
    poly.terms = (Term *) malloc(n * sizeof(Term));
    poly.count = n;

    for (int i = 0; i < n; i++) {
        scanf(" (%d,%d)", &(poly.terms[i].coefficient), &(poly.terms[i].exponent));
    }

    return poly;
}

Polynomial differentiatePolynomial(Polynomial poly) {
    Polynomial derivative;
    int n = poly.count;
    derivative.terms = (Term *) malloc(n * sizeof(Term));
    derivative.count = 0;

    for (int i = 0; i < n; i++) {
        int coefficient = poly.terms[i].coefficient;
        int exponent = poly.terms[i].exponent;

        if (exponent > 0) {
            derivative.terms[i].coefficient = coefficient * exponent;
            derivative.terms[i].exponent = exponent - 1;
            derivative.count++;
        }
    }

    return derivative;
}

void printPolynomial(Polynomial poly) {
    int n = poly.count;

    for (int i = 0; i < n; i++) {
        int coefficient = poly.terms[i].coefficient;
        int exponent = poly.terms[i].exponent;

        if (coefficient > 0) {
            if (i != 0) {
                printf("+");
            }
        } else if (coefficient < 0) {
            printf("-");
        } else {
            continue;
        }

        if (exponent == 0) {
            printf("%d", abs(coefficient));
        } else if (exponent == 1) {
            printf("%dX", abs(coefficient));
        } else {
            printf("%dX^%d", abs(coefficient), exponent);
        }
    }

    printf("\n");
}