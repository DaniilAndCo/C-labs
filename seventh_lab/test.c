#include <assert.h>
//#include "functions.h"
#include "ClintList.h"
#include <string.h>

int main()
{
    struct Node_Client temp;
    temp.next = NULL;
    temp.prev = NULL;
    temp.data = NULL;
    assert(NewClient()->data == temp.data);

    struct ClientList list;
    list.head = NULL;
    list.tail = NULL;
    struct Client client = {"0", "0", "0"};
    struct Client client2 = {"2", "2", "2"};

    assert(PrintClients(list) == false);

    assert(PrintAllNames(list) == 0);

    assert(AddClient(&list, &client) == false);
    assert(AddClient(&list, &client2) == true);

    assert(PrintClients(list) == true);

    printf("%d", PrintAllNames(list));

    assert(PrintAllNames(list) == 3);

    struct Client client1 = {"1", "1", "1"};

    assert(!strcmp(SearchClient(&list, &client)->data->name, "0"));
    //assert(SearchClient(&list, &client1) == NULL);

    //assert(!strcmp(SearchMan(&list, "0")->data->name, "0"));
    //assert(SearchMan(&list, &client1) == NULL);

    assert(DeleteClient(&list, &client) == true);
    //assert(DeleteClient(&list, &client1) == false);

    assert(PrintInfo(client) == true);
    


    return 0;
}
