#pragma once
#include "Goods.h"
#include <malloc.h>
#include <stdio.h>
#define bool int
#define true 1
#define false 0

struct GoodsList {
    struct Node_Good {
        struct Good *data;
        struct Node_Good *next;
        struct Node_Good *prev;
    } *head, *tail;
};

struct Node_Good* NewGood();

bool AddGood(struct GoodsList*, struct Good*);

bool PrintGoods(struct GoodsList);

struct Node_Good* SearchGood(struct GoodsList*, struct Good*);

bool DeleteGood(struct GoodsList*, struct Good*);

bool PrintInfoGoods(struct Good);
