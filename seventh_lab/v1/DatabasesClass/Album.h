#pragma once

#include "Song.h"
#include <vector>
#include <map>

#define NOSUCHSONG "no such song"

using std::vector;
using std::map;

class Album
{
private:

    string title_;
    map<string, Song> list_songs_;

public:

    Album(const string&);
    void AddSong(const Song&);
    void AddSong(const string&, const string&, const size_t&);
    void PrintAlbum() const;
    Song operator[](const string&) const;
    // Song& operator[](const string &title)
    // {
    //     return list_songs_[title];
    // }
    string GetTitle() const;
    Song GetSongByName(const string&) const;

};