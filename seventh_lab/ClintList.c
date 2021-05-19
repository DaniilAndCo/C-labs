#include "ClintList.h"

struct Node_Client* NewClient(){
    struct Node_Client* newClient = (struct Node_Client*) malloc(sizeof(struct Node_Client));
    newClient->next = NULL;
    newClient->prev = NULL;
    newClient->data = NULL;
    return newClient;
}


bool AddClient(struct ClientList* list, struct Client* client){

    struct Node_Client* newClient = NewClient();
    newClient->data = (struct Client*) malloc(sizeof(struct Client));
    newClient->data = client;

    if(list->head == NULL){
        list->head = newClient;
        list->tail = list->head;
        return false;
    }

    list->head->prev = newClient;
    newClient->next = list->head;
    list->head = newClient;
    return true;
}


bool PrintClients(struct ClientList list){

    printf("\n____Printing Clients____\n\n");
    if(list.head == NULL){
        printf("Client List is empty!\n");
        return false;
    }

    struct Node_Client* temp = list.head;
    while(temp != NULL){
        PrintInfo(*temp->data);
        temp = temp->next;
    }
    printf("________________________\n");
    return true;
}


int PrintAllNames(struct ClientList list){

    printf("\n____Printing Clients By Name____\n");
    if(list.head == NULL){
        printf("Client List is empty!\n");
        return 0;
    }

    struct Node_Client* temp = list.head;
    int num = 1;
    while(temp != NULL){
        printf("%i. %s\n", num, temp->data->name);
        num ++;
        temp = temp->next;
    }
    printf("_____________________________\n");

    return num;

}

struct Node_Client* SearchClient(struct ClientList* list, struct Client* man){
    struct Node_Client *temp = list->head;

    while(temp->data != NULL && temp != NULL && temp->data != man){
        temp = temp->next;
        printf("%s\n", temp->data->name);
    }

    if(temp == NULL && temp->data == NULL){
        printf("No Client found\n");
        return NULL;
    }

    return temp;
}


bool DeleteClient(struct ClientList* list, struct Client* man){
    struct Node_Client* rmClient = SearchClient(list, man);

    if(rmClient == NULL){
        return false;
    }

    if(rmClient == list->tail){
        list->tail->prev->next = NULL;
        list->tail = rmClient->prev;
    }
    else if(rmClient == list->head){
        list->head->next->prev = NULL;
        list->head = rmClient->next;
    }
    else {
        rmClient->next->prev = rmClient->prev;
        rmClient->prev->next = rmClient->next;
    }

    printf("Client: <%s> is deleted\n\n", rmClient->data->name);
    free(rmClient);
    return true;
}

bool PrintInfo(struct Client client){
    printf("\tClient: %s\nPassport: %s\n\n", client.name, client.Passport);
    return true;
}
