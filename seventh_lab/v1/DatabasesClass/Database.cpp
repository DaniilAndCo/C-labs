#include "Database.h"

    DataBase::DataBase(const string& path)
    {
        std::ifstream data_base(path);
        string buff;
        std::getline(data_base, buff);
        auto amount_singers = atoi(buff.c_str());  

        for (auto i = 0; i < amount_singers; ++i)
        {
            getline(data_base, buff);
            string singer_name = buff; 
            list_singers.insert(make_pair(singer_name, Singer(singer_name)));
            getline(data_base, buff);
            auto amount_albums = atoi(buff.c_str()); 
            for (auto i1 = 0; i1 < amount_albums; ++i1)
            { 
                getline(data_base, buff);
                list_singers.at(singer_name).AddAlbum(Album(buff));
                getline(data_base, buff);
                auto amount_songs = atoi(buff.c_str());
                for (auto i2 = 0; i2 < amount_songs; ++i2)
                {
                    getline(data_base, buff);
                    string song_name;
                    getline(data_base, song_name);
                    string cost;
                    getline(data_base, cost);
                    list_singers.at(singer_name)[i1].AddSong(Song(buff, song_name, atoi(cost.c_str())));
                } 
            }
        }
    }
    Singer DataBase::GetSingerByName(const string& name) const
    {
        if (list_singers.count(name))
            return list_singers.at(name);
        else return Singer(NOSUCHSINGER);
    }
    Song DataBase::GetSongByName(const string& name) const
    {
        for (const auto &singer :list_singers)
        {
            for (auto i = 0; i < singer.second.GetAmountAlbums(); ++i)
            {
                auto album = singer.second[i];
                auto song = album.GetSongByName(name);
                if (song.GetTitle() != NOSUCHSONG)
                    return song;
            }
        }
        return Song("", NOSUCHSONG, 0);
    }