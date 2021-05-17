#pragma once
#include <stdio.h>
#include "DublyLinkedList.h"
#include "ListStrings.h"
#include "Client.h"
#include "ClintList.h"
#include "Goods.h"
#include "GoodsList.h"

#define bool int
#define true 1
#define false 0

bool PrintMenu();
bool addGood(struct ClientList *clientList, struct GoodsList * goodsList);
bool removeGood(struct ClientList *clientList, struct GoodsList* goodsList);
bool AppendToFile(FILE *file, struct ClientList* clientLiist, struct GoodsList * goodsList);
bool Initialize(FILE *file, struct ClientList* clientList, struct GoodsList * goodsList);
bool readWord(char *buffer, FILE *file);
bool saveWord(FILE *file, char *str);
int CalculatePrice(struct GoodsList goodsList);
int CalculateMoney(struct GoodsList goodsList);
int CalcProfit(struct GoodsList goodsList);
