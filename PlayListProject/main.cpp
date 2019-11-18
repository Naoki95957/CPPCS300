#include <iostream>
#include <iomanip>
#include "Lists/LinkedList.hpp"
#include "Objects/Option.h"
#include "Objects/Song.h"

///responsible for keeping the appilcation going
bool applicationRunning = true;
///List of options to use in the applicatoin
LinkedList<Option> options = LinkedList<Option>();
///list to store the songs in the application
LinkedList<Song> songs = LinkedList<Song>();

Node<Song> *pCurrentlyPlayingSong = nullptr;
///just a simple call so I don't have to type "..." over and over
///and can flush the buffer with endl
void lineBreak();
///sets up all options
void initOptions();
///prints all avalible options
void printOptions();

int main()
{   
    std::cout << "Welcome to CS@BC Radio Station" << std::endl;

    initOptions();
    printOptions();

    std::string input;
    //main application loop
    while(applicationRunning)
    {
        std::cout << "Choose an operation: ";
        std::cin >> input;
        std::cout << std::endl;

        Node<Option> * node = options.getFrontNode();
        ///used to see if any input will trigger one of the options
        bool inputAccepted = false;
        //tests input against all possible option triggers
        while(node != nullptr)
        {
            //if triggers matach
            if(node->data.testTrigger(input))
            {
                inputAccepted = true;
                //run the appropriate trigger
                node->data.executeOption();
            }
            node = node->tail;
        }
        //if no options were triggered
        if(!inputAccepted)
        {
            std::cout << "Sorry, that was not an option. Please try again" << "\n";
            lineBreak();
        }
        //if we're still running, re-print the options
        if(applicationRunning)
        {
            printOptions();
        }
    }
    std::cout << "Thanks for using the application!" << std::endl;
    return 0;
}

void lineBreak()
{
    std::cout << ".........................." << std::endl;
}

void initOptions()
{
    //set up for each option and their function via lambdas
    auto quitFn = []()
    {
        applicationRunning = false;
        lineBreak();
    };
    auto addSongFn = []()
    {
        std::string title = "", artist = "";
        uint32_t duration = 0;

        std::cout << "Enter title: ";
        std::getline(std::cin.ignore(), title);

        std::cout << "Enter artist: ";
        std::getline(std::cin, artist);
        std::cout.flush();

        bool acceptableInput = false;
        std::string inputText = "";
        while(!acceptableInput)
        {
            std::cout << "Enter duration: ";
            std::getline(std::cin, inputText);

            duration = std::atoi (inputText.c_str());

            if(duration == 0)
            {
                //failure
                std::cout << "Please enter a valid integer" << "\n";
            }
            else
            {
                //success
                acceptableInput = true;
            }
        }

        songs.insertLast(Song(title, artist, duration));

        lineBreak();
        std::cout << "Song is added ot the playlist" << "\n";
        lineBreak();

    };
    auto deleteSongFn = []()
    {
        if(!songs.isEmpty())
        {
            std::string title = "", artist = "";
            std::cout << "Enter title: ";
            std::getline(std::cin.ignore(), title);

            std::cout << "Enter artist: ";
            std::getline(std::cin, artist);

            Song temp = Song(title, artist, 0);
            int result = songs.removeAll(temp);

            lineBreak();
            switch (result)
            {
            case -1:
                std::cout << "Song is not found." << "\n";
                break;
            case 1:
                std::cout << "Song is deleted" << "\n";
                break;
            default:
                std::cout << result << " songs deleted." << "\n";
                break;
            }
            lineBreak();
        }
        else
        {
            std::cout << "There are no songs added!" << "\n";
            lineBreak();
        }
    };
    auto searchForSongFn = []()
    {
        if(!songs.isEmpty())
        {
            std::string searchParam = "";
            std::cout << "Enter title: ";
            std::getline(std::cin.ignore(), searchParam);
            
            lineBreak();

            Song tempSong = Song(searchParam, "", 0);
            int index = songs.searchFor(tempSong);
            if(index != -1)
            {
                switch ((index + 1) % 10)
                {
                //first
                case 1:
                    std::cout << "Song is " << index + 1 << "st in the playlist" << "\n";
                    break;
                //second
                case 2:
                    std::cout << "Song is " << index + 1 << "nd in the playlist" << "\n";
                    break;
                //third
                case 3:
                    std::cout << "Song is " << index + 1 << "rd in the playlist" << "\n";
                    break;
                default:
                    std::cout << "Song is " << index + 1 << "th in the playlist" << "\n";
                    break;
                }
            }
            else
            {
                std::cout << "Song is not found" << "\n";
            }
            lineBreak();
        }
        else
        {
            std::cout << "There are no songs added!" << "\n";
            lineBreak();
        }
    };
    auto playNextSongFn = []()
    {
        if((!songs.isEmpty()) && pCurrentlyPlayingSong == nullptr)
        {
            pCurrentlyPlayingSong = songs.getFrontNode();

            std::cout << "Playing \"" 
                << pCurrentlyPlayingSong->data.getSongName()
                << "\" by " << pCurrentlyPlayingSong->data.getArtistName()
                << " (" << pCurrentlyPlayingSong->data.getLengthOfSong()
                << " seconds...)" << "\n";

            //rotates song to the back of the playlist
            //when done playing
            //Song dataPreservation = pCurrentlyPlayingSong->data;
            songs.remove(0);
            //songs.insertLast(dataPreservation);
            pCurrentlyPlayingSong = nullptr;
            
            lineBreak();
        }
        else
        {
            std::cout << "There are no songs added!" << "\n";
            lineBreak();
        }
        
    };
    auto listAllSongsFn = []()
    {
        Node<Song> * pSongNode = songs.getFrontNode();
        std::cout << songs.size() << " song(s)." << "\n";
        //to put a gap between multiple songs (easier reading)
        bool space = false;
        while(pSongNode != nullptr)
        {
            if(space) std::cout << "\n";
            std::cout << pSongNode->data;
            pSongNode = pSongNode->tail;
            space = true;
        }
        lineBreak();
    };
    auto listTotalPlayTimeFn = []()
    {
        Node<Song> * pSongNode = songs.getFrontNode();
        uint32_t accumulation = 0;
        while(pSongNode != nullptr)
        {
            accumulation += pSongNode->data.getLengthOfSong();
            pSongNode = pSongNode->tail;
        }

        std::cout << "Total number of songs: " << songs.size() << "\n";
        std::cout << "Total time: " << accumulation << " seconds" << "\n";
        std::cout <<  "Total time (mm:ss): " 
            << std::setw(2) << std::setfill('0') << accumulation / 60 << ":" 
            << std::setw(2) << std::setfill('0') << accumulation % 60 << "\n";
        lineBreak();
    };

    ///init for all options
    Option addSong = Option(addSongFn, "Add song", "a");
    Option deleteSong = Option(deleteSongFn, "Delete song", "b");
    Option searchForSong = Option(searchForSongFn, "Search for a song", "c");
    Option playNextSong = Option(playNextSongFn, "Play next song", "d");
    Option listAllSongs = Option(listAllSongsFn, "List all songs in playlist", "e");
    Option listTotalPlayTime = Option(listTotalPlayTimeFn, "List total time of playlist", "f");
    Option quit = Option(quitFn, "Quit", "q");

    //insert last just so the order matches the output on terminal
    options.insertLast(addSong);
    options.insertLast(deleteSong);
    options.insertLast(searchForSong);
    options.insertLast(playNextSong);
    options.insertLast(listAllSongs);
    options.insertLast(listTotalPlayTime);
    options.insertLast(quit);
}

void printOptions()
{   
    Node<Option> *pOption = options.getFrontNode();
    while(pOption->tail != nullptr)
    {
        std::cout << pOption->data; 
        pOption = pOption->tail;
    }
    std::cout << pOption->data << std::endl; 
}