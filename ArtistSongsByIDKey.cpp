//
// Created by dcohe on 11/06/2020.
//

#include "ArtistSongsByIDKey.h"

bool operator<(const ArtistSongsByIDKey &lhs, const ArtistSongsByIDKey &rhs) {
    return lhs.songID < rhs.songID;
}

bool operator==(const ArtistSongsByIDKey &lhs, const ArtistSongsByIDKey &rhs) {
    return lhs.songID == rhs.songID;
}

bool operator>(const ArtistSongsByIDKey &lhs, const ArtistSongsByIDKey &rhs) {
    return rhs < lhs;
}

bool operator!=(const ArtistSongsByIDKey &lhs, const ArtistSongsByIDKey &rhs) {
    return !(lhs == rhs);
}

ArtistSongsByIDKey::ArtistSongsByIDKey(int songId, int numStreams) : songID(songId), numStreams(numStreams) {}


