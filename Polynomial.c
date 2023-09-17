//
// Created by 86138 on 2023/9/17.
//
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int coef;
    int expo;
} Term;

typedef struct {
    Term *terms;
    int count;
} Polynomial;

Polynomial createPolynomial(int n);

void sortPolynomial(Polynomial *poly);

void printPolynomial(Polynomial poly);

Polynomial addPolynomials(Polynomial poly1, Polynomial poly2);

Polynomial subtractPolynomials(Polynomial poly1, Polynomial poly2);

Polynomial multiplyPolynomials(Polynomial poly1, Polynomial poly2);

int evaluatePolynomial(Polynomial poly, int x);

Polynomial differentiatePolynomial(Polynomial poly);

int main() {
    int n1, n2;
    Polynomial poly, poly1, poly2, sum, diff, product, derivative;
//    scanf("%d", &n1);
//    poly1 = createPolynomial(n1);
//    sortPolynomial(&poly1);
//    scanf("%d", &n2);
//    poly2 = createPolynomial(n2);
//    sortPolynomial(&poly2);
//    //sum = addPolynomials(poly1, poly2);
//    //diff = subtractPolynomials(poly1, poly2);
//    product = multiplyPolynomials(poly1, poly2);
    int n, x;
    scanf("%d", &n);
    poly = createPolynomial(n);
    sortPolynomial(&poly);
//    scanf("%d", &x);
//    int result = evaluatePolynomial(poly, x);
//    printf("result: %d\n", result);
//    free(poly.terms);
    //printPolynomial(product);
    //free(poly1.terms);
    //free(poly2.terms);
    //free(sum.terms);
    //free(diff.terms);
    //free(product.terms);
    derivative = differentiatePolynomial(poly);
    printPolynomial(derivative);
    free(poly.terms);
    free(derivative.terms);
    return 0;
}

Polynomial createPolynomial(int n) {
    Polynomial poly;
    poly.terms = malloc(sizeof(Term) * n);
    poly.count = n;
    for (int i = 0; i < n; i++) {
        scanf(" (%d,%d)", &(poly.terms[i].coef), &(poly.terms[i].expo));
    }
    return poly;
}

void sortPolynomial(Polynomial *poly) {
    int n = poly->count;
    Term temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (poly->terms[j].expo > poly->terms[j + 1].expo) {
                temp = poly->terms[j];
                poly->terms[j] = poly->terms[j + 1];
                poly->terms[j + 1] = temp;
            }
        }
    }
}

Polynomial addPolynomials(Polynomial poly1, Polynomial poly2) {
    Polynomial sum;
    int n1 = poly1.count;
    int n2 = poly2.count;
    int maxSize = n1 + n2;
    sum.terms = malloc(sizeof(Term) * maxSize);
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (poly1.terms[i].expo < poly2.terms[j].expo) {
            sum.terms[k] = poly1.terms[i];
            i++;
        } else if (poly1.terms[i].expo > poly2.terms[j].expo) {
            sum.terms[k] = poly2.terms[j];
            j++;
        } else {
            sum.terms[k].coef = poly1.terms[i].coef + poly2.terms[j].coef;
            sum.terms[k].expo = poly1.terms[i].expo;
            i++;
            j++;
        }
        k++;
    }
    while (i < n1) {
        sum.terms[k] = poly1.terms[i];
        i++;
        k++;
    }
    while (j < n2) {
        sum.terms[k] = poly2.terms[j];
        j++;
        k++;
    }
    sum.count = k;
    return sum;
}

void printPolynomial(Polynomial poly) {
    //不能用i!=0,如果前面几项一直消的话就会出现加号
    int flag = 0;
    int n = poly.count;
    for (int i = 0; i < n; i++) {
        if (poly.terms[i].coef == 0) {
            if (flag == 1 && poly.terms[i + 1].coef > 0 && i != n - 1) {
                printf("+");
            }
        } else if (poly.terms[i].coef == 1) {
            if (poly.terms[i].expo == 0) {
                printf("1");
                flag = 1;
            } else if (poly.terms[i].expo == 1) {
                printf("X");
                flag = 1;
            } else {
                printf("X^%d", poly.terms[i].expo);
                flag = 1;
            }

            if (poly.terms[i + 1].coef > 0 && i != n - 1) {
                printf("+");
            }
        } else if (poly.terms[i].coef == -1) {
            if (poly.terms[i].expo == 0) {
                printf("1");
                flag = 1;
            } else if (poly.terms[i].expo == 1) {
                printf("-X");
                flag = 1;
            } else {
                printf("-X^%d", poly.terms[i].expo);
                flag = 1;
            }

            if (poly.terms[i + 1].coef > 0 && i != n - 1) {
                printf("+");
            }
        } else {
            if (poly.terms[i].expo == 0) {
                printf("%d", poly.terms[i].coef);
                flag = 1;
            } else if (poly.terms[i].expo == 1) {
                printf("%dX", poly.terms[i].coef);
                flag = 1;
            } else {
                printf("%dX^%d", poly.terms[i].coef, poly.terms[i].expo);
                flag = 1;
            }

            if (poly.terms[i + 1].coef > 0 && i != n - 1) {
                printf("+");
            }
        }
    }
}

Polynomial subtractPolynomials(Polynomial poly1, Polynomial poly2) {
    Polynomial diff;
    int n1 = poly1.count;
    int n2 = poly2.count;
    int maxSize = n1 + n2;
    diff.terms = malloc(sizeof(Term) * maxSize);
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (poly1.terms[i].expo < poly2.terms[j].expo) {
            diff.terms[k] = poly1.terms[i];
            i++;
        } else if (poly1.terms[i].expo > poly2.terms[j].expo) {
            diff.terms[k].coef = -poly2.terms[j].coef;
            diff.terms[k].expo = poly2.terms[j].expo;
            j++;
        } else {
            diff.terms[k].coef = poly1.terms[i].coef - poly2.terms[j].coef;
            diff.terms[k].expo = poly1.terms[i].expo;
            i++;
            j++;
        }
        k++;
    }
    while (i < n1) {
        diff.terms[k] = poly1.terms[i];
        i++;
        k++;
    }
    while (j < n2) {
        diff.terms[k].coef = -poly2.terms[j].coef;
        diff.terms[k].expo = poly2.terms[j].expo;
        j++;
        k++;
    }
    diff.count = k;
    return diff;
}

Polynomial multiplyPolynomials(Polynomial poly1, Polynomial poly2) {
    Polynomial product;
    int n1 = poly1.count;
    int n2 = poly2.count;
    //bug 如果只是简单的相加的话，会导致空间不够，或是free出问题
    int maxSize = n1 * n2;
    product.terms = malloc(sizeof(Term) * maxSize);
    int k = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            product.terms[k].coef = poly1.terms[i].coef * poly2.terms[j].coef;
            product.terms[k].expo = poly1.terms[i].expo + poly2.terms[j].expo;
            k++;
        }
    }
    product.count = k;
    sortPolynomial(&product);
    //暴力解法 相当于移除重复的元素
    for (int i = 0; i < product.count - 1; i++) {
        if (product.terms[i].expo == product.terms[i + 1].expo) {
            product.terms[i].coef += product.terms[i + 1].coef;
            for (int j = i + 1; j < product.count - 1; j++) {
                product.terms[j] = product.terms[j + 1];
            }
            i--;
            product.count--;
        }
    }
    return product;
}

int evaluatePolynomial(Polynomial poly, int x) {
    int result = 0;
    int n = poly.count;
    for (int i = 0; i < n; i++) {
        int coef = poly.terms[i].coef;
        int expo = poly.terms[i].expo;
        int termResult = coef;
        for (int j = 0; j < expo; j++) {
            termResult *= x;
        }
        result += termResult;
    }
    return result;
}

Polynomial differentiatePolynomial(Polynomial poly) {
    Polynomial derivative;
    int n = poly.count;
    //bug 之前用的i作为derivative的索引，导致数组有的位置被跳过了，没有存储数组
    int k = 0;
    derivative.terms = malloc(sizeof(Term) * n);
    for (int i = 0; i < n; i++) {
        int coef = poly.terms[i].coef;
        int expo = poly.terms[i].expo;
        if (expo > 0) {
            derivative.terms[k].coef = coef * expo;
            derivative.terms[k].expo = expo - 1;
            k++;
        }
    }
    derivative.count = k;
    return derivative;
}