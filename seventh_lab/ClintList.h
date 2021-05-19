#ifndef C_LANG_CLINTLIST_H
#define C_LANG_CLINTLIST_H

#include "Client.h"
#include <stdlib.h>
#include <stdio.h>

#define bool int
#define true 1
#define false 0

struct ClientList {
    struct Node_Client {
        struct Client *data;
        struct Node_Client *next;
        struct Node_Client *prev;
    } *head, *tail;
};

struct Node_Client* NewClient();

bool AddClient(struct ClientList* list, struct Client* client);

bool PrintClients(struct ClientList list);

int PrintAllNames(struct ClientList list);

struct Node_Client* SearchClient(struct ClientList* list, struct Client* man);

bool DeleteClient(struct ClientList* list, struct Client* man);

bool PrintInfo(struct Client client);

#endif //C_LANG_CLINTLIST_H