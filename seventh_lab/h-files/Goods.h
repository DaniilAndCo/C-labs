#ifndef C_LANG_GOODS_H
#define C_LANG_GOODS_H

#define bool int
#define true 1
#define false 0

struct Good{
    char name[20];
    char clientID[20];
    int value;
    int money;
    char date[20];
    char timeKeeping[20];
};

#endif //C_LANG_GOODS_H