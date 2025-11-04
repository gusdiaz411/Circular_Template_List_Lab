#include <iostream>
#include <string>
#include <limits>   // needed for std::numeric_limits
#include "Media.h"
#include "Podcast.h"
#include "Song.h"
#include "LinkedList.h"

// Utility function to safely get string input
std::string getLineInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);
    return input;
}

// Utility function to safely get integer input
int getIntInput(const std::string& prompt) {
    int value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return value;
}

int main() {
    LinkedList<Media*> myPlaylist; // Templated list of Media* pointers
    int choice = 0;

    std::cout << "Welcome to the Playlist Manager (Polymorphic Circular Edition)!" << std::endl;

    // Initial playlist
    myPlaylist.insert(new Song("Bohemian Rhapsody", "Queen", 355));
    myPlaylist.insert(new Podcast("The Daily: AI Ethics", "Michael Barbiero", 145));
    myPlaylist.insert(new Song("Stairway to Heaven", "Led Zeppelin", 482));

    // Optional circular test
    std::cout << "\nPlaying first 5 media items (circular test):\n";
    for (int i = 0; i < 5; ++i) {
        myPlaylist.playNext();
    }

    do {
        std::cout << "\n--- Menu ---" << std::endl;
        std::cout << "1. Add a new Song" << std::endl;
        std::cout << "2. Add a new Podcast" << std::endl;
        std::cout << "3. Display Playlist" << std::endl;
        std::cout << "4. Play Next" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Exiting." << std::endl;
            choice = 5;
        }

        switch (choice) {
            case 1: {
                std::string title = getLineInput("Enter Song Title: ");
                std::string artist = getLineInput("Enter Artist Name: ");
                int duration = getIntInput("Enter duration in seconds: ");

                myPlaylist.insert(new Song(title, artist, duration));
                std::cout << "[Song added successfully!]" << std::endl;
                break;
            }
            case 2: {
                std::string title = getLineInput("Enter Podcast Episode Title: ");
                std::string host = getLineInput("Enter Host Name: ");
                int episodeNum = getIntInput("Enter Episode Number: ");

                myPlaylist.insert(new Podcast(title, host, episodeNum));
                std::cout << "[Podcast added successfully!]" << std::endl;
                break;
            }
            case 3:
                myPlaylist.displayList();
                break;
            case 4:
                myPlaylist.playNext(); // circular playback
                break;
            case 5:
                std::cout << "Exiting Playlist Manager..." << std::endl;
                break;
            default:
                std::cout << "Invalid menu choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
