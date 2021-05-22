#ifndef C_LANG_CLIENT_H
#define C_LANG_CLIENT_H

#define bool int
#define true 1
#define false 0

struct Client{
    char name[20];
    char Passport[20];
    char history[1000];
};

#endif //C_LANG_CLIENT_H
