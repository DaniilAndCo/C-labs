#include "functions.h"


int main() {

    FILE *file;
    if((file = fopen("DataBase.txt", "r")) == NULL)
    {
        printf("ERROR. File isn't opened\n");
        return 1;
    }
    else{
        printf("\nFile opened successfully\n");
    }

    struct GoodsList* goodsList = (struct GoodsList*) malloc(sizeof(struct GoodsList));
    struct ClientList* clientList = (struct ClientList*) malloc(sizeof(struct ClientList));

    goodsList->head = NULL;
    goodsList->tail = NULL;
    clientList->head = NULL;
    clientList->tail = NULL;

    Initialize(file, clientList, goodsList);

    while(1){
        PrintMenu();
        int choise;
        printf("Enter: ");
        if(!scanf("%i", &choise)){
            printf("Error with input\n"
                   "Press any key to continue..\n");
            int ch = getchar();
            while(getchar() != '\n');
            while(getchar() != '\n');
            continue;
        }

        switch (choise) {
            case 1:
                PrintClients(*clientList);
                break;
            case 2:
                PrintGoods(*goodsList);
                break;
            case 3:
                addGood(clientList, goodsList);
                break;
            case 4:
                removeGood(clientList, goodsList);
                break;
            case 5:
                CalculatePrice(*goodsList);
                break;
            case 6:
                CalcProfit(*goodsList);
                break;
            case 7:
                //AppendToFile(file, clientList, goodsList);
                fclose(file);
                return 0;
            default:
                printf("Wrong Input\n"
                       "Press any key to continue...");
                int ch = getchar();
                while(getchar() != '\n');
                continue;
        }


        printf("Press any key to continue...\n");
        int ch = getchar();
        while(getchar() != '\n');
    }

}

