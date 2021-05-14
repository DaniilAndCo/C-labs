#include "Basket.h"

    void Basket::Close() const
    {
        system("cls");
        main_page_->StartMainPage();
    }
    
    Basket::Basket(MainPage *main_page, const size_t &money) : main_page_(main_page), money_(money)
    {
    }
    void Basket::Add(const Song &song)
    {
        if (money_ >= song.GetCost())
        {
            list_purchases_.push_back(song);
            money_ -= song.GetCost();
        }
        else
        {
            cout << "Insufficiency of money\n";
        }
        
    }
    void Basket::ShowBasket() const
    {
        SetDefaultConsole();
        cout << "Your money = " << money_ << "$\n";
        for (const auto &purchase : list_purchases_)
        {
            cout << purchase.GetFullInfo() << endl;
        }
        while (true)
        {
            if (getch() == '\b')
                Close();
        }
    }