#include "functions.h"

bool addGood(struct ClientList *clientList, struct GoodsList * goodsList){
    struct Good* newGood = (struct Good*) malloc(sizeof(struct Good));
    char string[20];

    while(getchar() != '\n');
    printf("Enter good name (1 word, Exmpl: Telephone): ");
    scanf("%s", newGood->name);

    while(getchar() != '\n');
    printf("Enter client ID (1word, Exmpl: id12345): ");
    scanf("%s", newGood->clientID);

    while(1) {
        printf("Enter its value in $ (1 number, Exmpl: 1000)\nValue: ");
        if(!scanf("%i", &newGood->value) || newGood->value < 1){
            printf("Wrong input! Enter a positive number!\n");
            while(getchar() != '\n');
            continue;
        }
        else{
            break;
        }
    }

    while(1) {
        printf("Enter amount of money will be gave to Client(1 number, Exmpl: 50)\nMoney: ");
        if(!scanf("%i", &newGood->money) || newGood->money < 1){
            printf("Wrong input! Enter a number!\n");
            while(getchar() != '\n');
            continue;
        }
        if (newGood->value <= newGood->money){
            printf("Our lambard couldn't give more money then good is costs\n"
                   "Suggest less money to Client (money < value)\n");
            continue;
        }
        break;
    }

    while(getchar() != '\n');
    printf("Enter today date (1word, Exmpl: 27_May): ");
    scanf("%s", newGood->date);

    while(getchar() != '\n');
    printf("For how long time give money to Client (1word, Exmpl: 2_month): ");
    scanf("%s", newGood->timeKeeping);

    printf("\n\nAlso we need few information about that client\n");

    struct Client* newClient = (struct Client*) malloc(sizeof(struct Client));

    while(getchar() != '\n');
    printf("What is Client's name? (1word, Exmpl: Vladislav)\nEnter: ");
    scanf("%s", newClient->name);

    while(getchar() != '\n');
    printf("What is Client's Passport number? (1word, Exmpl: AB123456)\nEnter: ");
    scanf("%s", newClient->Passport);

    AddClient(clientList, newClient);
    AddGood(goodsList, newGood);

    printf("All data saved successfully\n\n");
    return true;
}


bool removeGood(struct ClientList *clientList, struct GoodsList* goodsList){
    int num = PrintAllNames(*clientList);

    int choise;
    while(1) {
        if (!scanf("%i", &choise) || choise < 0 || choise > num) {
            printf("Error with input\n"
                   "Press any key to continue..\n");
            int ch = getchar();
            while (getchar() != '\n');
            while (getchar() != '\n');
            continue;
        }
        break;
    }

    struct Node_Client* tempClient = clientList->head;
    struct Node_Good* tempGood = goodsList->head;

    int i;
    for(i = 0; i < choise - 1; i++){
        tempGood = tempGood->next;
        tempClient = tempClient->next;
    }

    DeleteGood(goodsList, tempGood->data);
    DeleteClient(clientList, tempClient->data);

    printf("Element deleted!\n");
    return true;
}

bool AppendToFile(FILE *file, struct ClientList* clientLiist, struct GoodsList * goodsList){
    if((file = fopen("DataBase.txt", "w")) == NULL)
    {
        printf("ERROR. File isn't opened\n");
        return false;
    }

    struct Node_Client* tempClient = NewClient();
    tempClient = clientLiist->head;

    struct Node_Good * tempGood = NewGood();
    tempGood = goodsList->head;

    while(tempClient != NULL){
        fprintf(file, "%s %s %s", tempClient->data->name, tempClient->data->Passport, tempClient->data->history);
        tempClient = tempClient->next;

        fprintf(file, "%s %s %i %i %s %s\n", tempGood->data->name, tempGood->data->clientID, tempGood->data->value,
                tempGood->data->money, tempGood->data->date, tempGood->data->timeKeeping);
        tempGood = tempGood->next;
    }
    fclose(file);

    printf("All new Data saved to the file succefully !\n");

    return true;

}


bool Initialize(FILE *file, struct ClientList* clientList, struct GoodsList * goodsList){

//    if((file = fopen("DataBase.txt", "r")) == NULL)
//    {
//        printf("ERROR. File isn't opened\n");
//        return ;
//    }
//    else{
//        printf("\nFile opened successfully\n");
//    }

    int check = getc(file);
    if (check == EOF){
        printf("No Data to Initialize from file\n"
               "File is empty\n\n");
        return false;
    }
    else{
        rewind(file);
    }

    while(1){
        if(feof(file)){
            break;
        }

        struct Client* client = (struct Client*) malloc(sizeof(struct Client));
        struct Good* good = (struct Good*) malloc(sizeof(struct Good));

        saveWord(file, client->name);
        saveWord(file, client->Passport);
        saveWord(file, good->name);
        saveWord(file, good->clientID);

        char buffer[20] = "";
        readWord(buffer, file);
        int value;
        sscanf(buffer, "%d", &value);
        good->value = value;

        int money;
        strcpy(buffer, "");
        readWord(buffer, file);
        sscanf(buffer, "%d", &money);
        good->money = money;

        saveWord(file, good->date);
        saveWord(file, good->timeKeeping);


        AddClient(clientList, client);
        AddGood(goodsList, good);
        char ch = getc(file);
        if(ch == EOF){
            printf("Data from file initialized successfully!\n"
                   "PS: Initialized in 2 DublyLinkedList\n");
            break;
        }
        else{
            fseek(file, -1, SEEK_CUR);
        }
    }
    return true;
}


bool readWord(char *buffer, FILE *file){
    char ch = (char) fgetc(file);
    while(1){
        strncat(buffer, &ch, 1);
        ch = (char) fgetc(file);
        if((ch == ' ') || (ch == '\n')){
            break;
        }
    }
    return true;
}

bool saveWord(FILE *file, char str[]){
    char buffer[20] = "";
    readWord(buffer, file);
    strcpy(str, buffer);
    return true;
}


int CalculatePrice(struct GoodsList goodsList){
    int price = 0;
    struct Node_Good* current = goodsList.head;
    if(current == NULL){
        printf("List is empty, can't calculate\n");
        return 0;
    }
    else{
        while(current != NULL ){
            price += current->data->value;
            current = current->next;
        }
    }

    printf("\nThe cost of all stored items: %i $\n\n", price);

    return price;
}


int CalculateMoney(struct GoodsList goodsList){
    int price = 0;
    struct Node_Good* current = goodsList.head;
    if(current == NULL){
        printf("List is empty, can't calculate\n");
        return 0;
    }
    else{
        while(current != NULL ){
            price += current->data->money;
            current = current->next;
        }
    }
    return price;
}


int CalcProfit(struct GoodsList goodsList){
    int profit = CalculatePrice(goodsList) - CalculateMoney(goodsList);

    printf("Profit is: %i $\n", profit);
    return profit;
}


bool PrintMenu(){
    printf("\n1. Show all clients info\n"
           "2. Show all goods info\n"
           "3. Add Good and it's Client\n"
           "4. Delete Good\n"
           "5. Calculate Lambard Profit\n"
           "6. Calculate price of all Goods\n"
           "7. Close session\n\n");
    return true;
}