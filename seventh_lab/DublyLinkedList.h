#pragma once
#include <stdlib.h>
#include <stdio.h>

struct DLinkList {

    struct Node {
        int data;
        struct Node *next;
        struct Node *prev;
    } *head, *tail;

//    struct Node *head;
//    struct Node *tail;
};


struct Node *GetNewNode(int data) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));

    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = data;

    return newNode;
};


void InsertAtHead(struct DLinkList *list, int data) {
    struct Node *newNode = GetNewNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        return;
    }

    list->head->prev = newNode;
    newNode->next = list->head;
    list->head = newNode;
};


void PrintAll(struct DLinkList list) {
    printf("Printing from Head...\n");

    struct Node *temp = list.head;
    while (temp != NULL) {

        printf("%i ", temp->data);
        temp = temp->next;

    }
    printf("Head - %i\n", list.head->data);
    printf("Tail - %i\n\n", list.tail->data);
}


void PrintReverse(struct DLinkList list) {
    printf("\nPrinting in Reverse order...\n");

    struct Node *temp = list.tail;
    while (temp != NULL) {
        printf("%i ", temp->data);
        temp = temp->prev;
    }
    printf("\n\n");
}


struct Node *Search(struct DLinkList list, int data) {
    struct Node *temp = list.head;

    while (temp->data != data) {
        temp = temp->next;
    }

    return temp;
}


void Delete(struct DLinkList * list, int data) {

    struct Node *rmNode = Search(*list, data);

    if (rmNode == list->head) {
        rmNode->next->prev = NULL;
        list->head = rmNode->next;
    } else if (rmNode == list->tail) {
        rmNode->prev->next = NULL;
        list->tail = rmNode->prev;
    } else {

        rmNode->prev->next = rmNode->next;
        rmNode->next->prev = rmNode->prev;
    }

    free(rmNode);
}