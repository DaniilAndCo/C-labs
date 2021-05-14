#pragma once

#include "..\DatabasesClass\Database.h"
#include "..\PagesClasses\\MainPage.h"
class MP3Shop
{
private:
    MainPage *main_page_;
    DataBase *data_base_;
public:
    MP3Shop()
    {
        data_base_ = new DataBase(".\\MP3ShopClass\\database.txt");
        main_page_ = new MainPage(data_base_);
        main_page_->StartMainPage();

    }

};