#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

linkedlist *createList() {
    linkedlist *list = malloc(sizeof(linkedlist));

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->totalMass = 0;

    return list;
}

void destroyList(linkedlist *list) {
    node *current = list->head;
    node *next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

void addNode(linkedlist *list, int mass) {
    node *newNode = malloc(sizeof(node));
    newNode->mass = mass;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        list->tail->next = newNode;
    }

    list->tail = newNode;

    list->size++;
    list->totalMass += mass;
}

void printList(linkedlist *list) {
    node *current = list->head;

    while (current != NULL) {
        printf(" %d", current->mass);
        current = current->next;
    }
}