#include <assert.h>
#include "../h-files/ClintList.h"
#include "../h-files/GoodsList.h"
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

    assert(PrintAllNames(list) == 3);

    struct Client client1 = {"1", "1", "1"};

    assert(!strcmp(SearchClient(&list, &client)->data->name, "0"));

    assert(DeleteClient(&list, &client) == true);

    assert(PrintInfo(client) == true);
////////////////////////////////////////////
    struct Node_Good temp1;
    temp1.next = NULL;
    temp1.prev = NULL;
    temp1.data = NULL;
    assert(NewGood()->data == temp1.data);

    struct GoodsList list1;
    list1.head = NULL;
    list1.tail = NULL;
    struct Good good = {"0", "0", 0, 0, "0", "0"};
    struct Good good2 = {"2", "2", 2, 2, "2", "2"};

    assert(PrintGoods(list1) == false);

    assert(PrintInfoGoods(good) == true);

    assert(AddGood(&list1, &good) == false);
    assert(AddGood(&list1, &good2) == true);

    assert(PrintGoods(list1) == true);


    struct Good good1 = {"3", "3", 3, 3, "3", "3"};

    assert(!strcmp(SearchGood(&list1, &good)->data->name, "0"));

    assert(DeleteGood(&list1, &good) == true);

    return 0;
}
