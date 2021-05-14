#ifndef BASKET_H
#define BASKET_H
#include "ConsoleDesign.h"
#include <vector>
#include <iostream>
#include "..\DatabasesClass\Song.h"
#include "..\PagesClasses\MainPage.h"
using std::vector;
using std::cout;
class MainPage;
class Basket
{
private:

    vector<Song> list_purchases_;
    size_t money_;
    MainPage *main_page_;
    void Close() const;
    
public:

    Basket(MainPage*, const size_t&);
    void Add(const Song&);
    void ShowBasket() const;

};

#endif