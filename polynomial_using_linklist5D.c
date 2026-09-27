#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

struct Term* createTerm(int coef, int exp) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));

    newTerm->coefficient = coef;
    newTerm->exponent = exp;
    newTerm->next = NULL;

    return newTerm;
}

void insertTerm(struct Term** poly, int coef, int exp) {
    if (coef == 0) {
        return;
    }

    struct Term* newTerm = createTerm(coef, exp);

    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        struct Term* current = *poly;
        struct Term* prev = NULL;

        while (current != NULL && current->exponent > exp) {
            prev = current;
            current = current->next;
        }

        if (current != NULL && current->exponent == exp) {
            current->coefficient += coef;
            free(newTerm);
        } else {
            newTerm->next = current;

            if (prev != NULL) {
                prev->next = newTerm;
            } else {
                *poly = newTerm;
            }
        }
    }
}

void displayPolynomial(struct Term* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);

        if (poly->next != NULL) {
            printf(" + ");
        }

        poly = poly->next;
    }

    printf("\n");
}

struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {

        if (poly1->exponent == poly2->exponent) {
            insertTerm(&result,
                       poly1->coefficient + poly2->coefficient,
                       poly1->exponent);

            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        else if (poly1->exponent > poly2->exponent) {
            insertTerm(&result,
                       poly1->coefficient,
                       poly1->exponent);

            poly1 = poly1->next;
        }

        else {
            insertTerm(&result,
                       poly2->coefficient,
                       poly2->exponent);

            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertTerm(&result,
                   poly1->coefficient,
                   poly1->exponent);

        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result,
                   poly2->coefficient,
                   poly2->exponent);

        poly2 = poly2->next;
    }

    return result;
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;
    struct Term* result = NULL;

    int coef, exp, terms;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &terms);

    printf("Enter the terms (coefficient exponent) for the first polynomial:\n");

    for (int i = 0; i < terms; i++) {
        scanf("%d %d", &coef, &exp);
        insertTerm(&poly1, coef, exp);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &terms);

    printf("Enter the terms (coefficient exponent) for the second polynomial:\n");

    for (int i = 0; i < terms; i++) {
        scanf("%d %d", &coef, &exp);
        insertTerm(&poly2, coef, exp);
    }

    printf("First polynomial: ");
    displayPolynomial(poly1);

    printf("Second polynomial: ");
    displayPolynomial(poly2);

    result = addPolynomials(poly1, poly2);

    printf("Result of addition: ");
    displayPolynomial(result);

    struct Term* temp;

    while (poly1 != NULL) {
        temp = poly1;
        poly1 = poly1->next;
        free(temp);
    }

    while (poly2 != NULL) {
        temp = poly2;
        poly2 = poly2->next;
        free(temp);
    }

    while (result != NULL) {
        temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}