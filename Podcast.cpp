//
// Created by Gustavo Diaz on 11/2/25.
//

#include "Podcast.h"
#include <sstream>
// Override toString() from the Media base class.
std::string Podcast::toString() const{
    std::stringstream ss;
    ss << "Podcast: " << episodeTitle
       << " | Host: " << host
       << " | Ep #: " << episodeNumber;
    return ss.str();
}

// Override play() to provide Podcast-specific behavior.
void Podcast::play() const {
    std::cout << "🎙️ Resuming episode " << episodeNumber << ": " << episodeTitle << " 🎙️" << std::endl;
}

