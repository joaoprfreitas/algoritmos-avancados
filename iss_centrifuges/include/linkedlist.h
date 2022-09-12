#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node {
    int mass;
    struct node *next;
} node;

typedef struct linkedlist {
    node *head;
    node *tail;
    int totalMass;
    int size;
} linkedlist;

linkedlist *createList();
void destroyList(linkedlist *list);
void addNode(linkedlist *list, int mass);
void printList(linkedlist *list);

#endif