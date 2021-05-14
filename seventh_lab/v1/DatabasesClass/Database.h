#pragma once
#include <string>
#include <fstream>
#include <map>
#include "Singer.h"
#include "Album.h"
using std::string;
using std::ifstream;
using std::vector;
using std::map;
using std::make_pair;
#define NOSUCHSONG "no such song"
#define NOSUCHSINGER "no such singer"
class DataBase
{
private:

    map<string, Singer> list_singers;

public:
    
    DataBase(const string&);
    Singer GetSingerByName(const string&) const;
    Song GetSongByName(const string&) const;
    
};