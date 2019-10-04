//Name      :   Song.cpp
//Author    :   Naoki Lucas
//Date      :   10/02/2019
//Desc      :   Song object to simplify some code via name/artist/length
#include "Song.h"

std::string Song::getSongName() const
{
    return Song::songName;
}

std::string Song::getArtistName() const
{
    return Song::artistName;
}

uint32_t Song::getLengthOfSong() const
{
    return lengthOfSong;
}

bool Song::operator==(Song other)
{
    return (songName == other.getSongName());
        //&& (artistName == other.getArtistName())
        //&& (lengthOfSong == other.getLengthOfSong());
        //instructions seem to ignore these parts of the song for comparision
}

std::ostream& operator<<(std::ostream& out, const Song& song)
{
    out << "Title: " << song.getSongName() << "\n";
    out << "Artist: " << song.getArtistName() << "\n";
    out << "Duration: " << song.getLengthOfSong() << "\n";
    return out;
}