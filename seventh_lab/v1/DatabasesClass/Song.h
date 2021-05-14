#pragma once
#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;

class Song
{
private:

    string title_;
    string text_string_;
    size_t cost_;

public:

    Song(const string&, const string&, const size_t&);
    void PrintText() const;
    string GetStrText() const;
    string GetTitle() const;
    string GetFullInfo() const;
    size_t GetCost() const;
    ~Song();

};