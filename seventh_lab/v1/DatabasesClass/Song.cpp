#include "Song.h"

    Song::Song(const string &path, const string &title, const size_t &cost) : title_(title), cost_(cost)
    {
        std::ifstream filein(".\\MP3ShopClass\\" + path);
        for (std::string line; std::getline(filein, line); ) 
        {
            text_string_ += line;
            text_string_.push_back('\n');
        }     
        filein.close();
    }
    void Song::PrintText() const
    {
        cout << text_string_;
    }
    string Song::GetStrText() const
    {
        return text_string_;
    }
    string Song::GetTitle() const
    {
        return title_;
    }
    string Song::GetFullInfo() const
    {
        return title_ + " - " + std::to_string(cost_) + "$";
    }
    size_t Song::GetCost() const
    {
        return cost_;
    }
    Song::~Song()
    {
    }
