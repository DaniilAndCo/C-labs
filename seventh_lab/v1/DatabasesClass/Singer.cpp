#include "Singer.h"

    Singer::Singer(const string &name) : name_(name)
    {

    }
    void Singer::AddAlbum(const Album &album)
    {
        list_albums_.push_back(album);
    }
    void Singer::PrintAlbums() const
    {
        for (size_t i = 0; i < list_albums_.size(); ++i)
        {
            cout << i + 1 << ". " << list_albums_[i].GetTitle() << endl;
        }
    }
    Album Singer::operator[](int index) const
    {
        return list_albums_[index];
    }
    Album& Singer::operator[](int index)
    {
        return list_albums_[index];
    }
    size_t Singer::GetAmountAlbums() const
    {
        return list_albums_.size();
    }
    string Singer::GetName() const
    {
        return name_;
    }
    