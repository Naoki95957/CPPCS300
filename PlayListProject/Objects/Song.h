//Name      :   Song.h
//Author    :   Naoki Lucas
//Date      :   10/02/2019
//Desc      :   Song object to simplify some code via name/artist/length
#include <string>

///A song object to hold a song name, artist name, and duration of song in seconds
class Song
{
    private:
        ///The name of the song
        std::string songName;
        ///The name of the artist/s
        std::string artistName;
        ///The length of the song in seconds
        ///
        ///uint32 is more than enough
        ///this should be able to handle over 23 million songs that avg 3min each
        uint32_t lengthOfSong;
    public:
        ///creates a song object with name/artist/duration
        Song(std::string songName, std::string artistName, uint16_t lengthOfSong)
            :songName(songName), artistName(artistName), lengthOfSong(lengthOfSong)
        {}
        ///Get the name of the song
        std::string getSongName() const;
        ///Get the name of the artist
        std::string getArtistName() const;
        ///Get duration of the song in seconds
        uint32_t getLengthOfSong() const;
        ///Comparator to see if the songs are equal
        bool operator==(Song other);
        ///prints the song
        friend std::ostream& operator<<(std::ostream& out, const Song& song);
};