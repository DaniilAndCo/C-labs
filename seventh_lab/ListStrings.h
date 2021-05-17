//#include <ntsid.h>
#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct ListString {

    struct Node_s {
        char *data;
        struct Node_s *next;
        struct Node_s *prev;
    } *head, *tail;

//    struct Node_s *head;
//    struct Node_s *tail;
};


struct Node_s *GetNewNode_s() {
    struct Node_s *newNode = (struct Node_s *) malloc(sizeof(struct Node_s));

    newNode->next = NULL;
    newNode->prev = NULL;


    return newNode;
};


void InsertAtHead_s(struct ListString *list, char *data) {
    struct Node_s *newNode = GetNewNode_s();
    newNode->data = (char*) malloc(sizeof(char*));
    newNode->data = data;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;

        return;
    }

    list->head->prev = newNode;
    newNode->next = list->head;
    list->head = newNode;
};


void PrintAll_s(struct ListString list) {
    printf("Printing from Head...\n");

    struct Node_s *temp = list.head;
    while (temp != NULL) {

        printf("%s ", temp->data);
        temp = temp->next;

    }
    printf("Head - %s\n", list.head->data);
    printf("Tail - %s\n\n", list.tail->data);
}


void PrintReverse_s(struct ListString list) {
    printf("\nPrinting in Reverse order...\n");

    struct Node_s *temp = list.tail;
    while (temp != NULL) {
        printf("%s ", temp->data);
        temp = temp->prev;
    }
    printf("\n\n");
}


struct Node_s *Search_s(struct ListString list, char *data) {
    struct Node_s *temp = list.head;

    while (!strcmp(temp->data, data)) {
        temp = temp->next;
    }

    return temp;
}


void Delete_s(struct ListString * list, char *data) {

    struct Node_s *rmNode = Search_s(*list, data);

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