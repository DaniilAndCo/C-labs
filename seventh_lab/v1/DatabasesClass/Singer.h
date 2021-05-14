#pragma once
#include "Album.h"
#include <vector>

using std::vector;

class Singer
{
private:

    string name_;
    vector<Album> list_albums_;

public:

    Singer(const string&);
    void AddAlbum(const Album&);
    void PrintAlbums() const;
    Album operator[](int) const;
    Album& operator[](int);
    size_t GetAmountAlbums() const;
    string GetName() const;
    
};