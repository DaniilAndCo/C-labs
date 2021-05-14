#include "Album.h"

    Album::Album(const string &title) : title_(title)
    {

    }
    void Album::AddSong(const Song &song)
    {
        list_songs_.insert(make_pair(song.GetTitle(), song));
    }
    void Album::AddSong(const string &path, const string &title, const size_t &cost)
    {
        list_songs_.insert(make_pair(title, Song(path, title, cost)));
    }
    void Album::PrintAlbum() const
    {
        size_t i = 1;
        for (const auto &song : list_songs_)
        {
            cout << i++ << ") " << song.first << " - " << song.second.GetCost() << "$" << endl;
        }
    }
    Song Album::operator[](const string &title) const
    {
        return GetSongByName(title);
    }
    // Song& operator[](const string &title)
    // {
    //     return list_songs_[title];
    // }
    string Album::GetTitle() const
    {
        return title_;
    }
    Song Album::GetSongByName(const string &name) const
    {
        if (list_songs_.count(name))
            return list_songs_.at(name);
        else return Song("", NOSUCHSONG, 0);
    }
