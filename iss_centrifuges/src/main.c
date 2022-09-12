#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "linkedlist.h"

int compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

void insertIntoChambers(int operationType, linkedlist **chamberList, int *specimensList, int specimens, int chambers);
double meanValue(int *massOfSpecimen, int size, int chambers);
linkedlist **createChambers(int chambers);
int *createSpecimensList(int *operationType, int *specimens, int chambers);
double imbalance(linkedlist **chamberList, int chambers);

int main() {
    int chambers, specimens;
    int setNumber = 1;

    while (scanf("%d %d\r\n", &chambers, &specimens) != EOF) {
        linkedlist **chamberList = createChambers(chambers);
        int operationType = 0;
        int *specimensList = createSpecimensList(&operationType, &specimens, chambers);

        double mean = meanValue(specimensList, specimens, chambers);

        insertIntoChambers(operationType, chamberList, specimensList, specimens, chambers);

        printf("Set #%d\n", setNumber);
        for (int i = 0; i < chambers; i++) {
            printf(" %d:", i);
            printList(chamberList[i]);
            printf("\n");
        }
        printf("IMBALANCE = %.5lf\n\n", imbalance(chamberList, chambers));

        setNumber++;

        free(specimensList);
        for (int i = 0; i < chambers; i++) {
            destroyList(chamberList[i]);
        }
        free(chamberList);
    }

    return EXIT_SUCCESS;
}

double imbalance(linkedlist **chamberList, int chambers) {
    double mean = 0;
    for (int i = 0; i < chambers; i++) {
        mean += chamberList[i]->totalMass;
    }
    mean /= chambers;

    double imbalance = 0;
    for (int i = 0; i < chambers; i++) {
        imbalance += fabs(chamberList[i]->totalMass - mean);
    }

    return imbalance;
}

void insertIntoChambers(int operationType, linkedlist **chamberList, int *specimensList, int specimens, int chambers) {
    if (operationType == 0) { // without dummies
        for (int i = 0; i < specimens; i++) {       
            addNode(chamberList[i % chambers], specimensList[i]);
        }
    } else { // with dummies
        int start = 0, end = specimens - 1;

        while (start <= end) {
            if (specimensList[start] != 0)
                addNode(chamberList[start], specimensList[start]);
            if (specimensList[end] != 0)
                addNode(chamberList[start], specimensList[end]);
            start++;
            end--;
        }
    }
}

double meanValue(int *massOfSpecimen, int size, int chambers) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += massOfSpecimen[i];
    }
    return sum / chambers;
}

linkedlist **createChambers(int chambers) {
    linkedlist **chamberList = malloc(sizeof(linkedlist *) * chambers);

    for (int i = 0; i < chambers; i++)
        chamberList[i] = createList();

    return chamberList;
}

int *createSpecimensList(int *operationType, int *specimens, int chambers) {
    int dummies = 0;
    if (*specimens <= 2 * chambers) {
        dummies = 2 * chambers - *specimens;
        *operationType = 1;
    }

    int *specimensList = malloc(sizeof(int) * (*specimens + dummies));

    for (int i = 0; i < *specimens; i++)
        scanf("%d", &specimensList[i]);

    for (int i = 0; i < dummies; i++)
        specimensList[*specimens + i] = 0;

    *specimens += dummies;

    qsort(specimensList, *specimens, sizeof(int), compare);

    return specimensList;
}