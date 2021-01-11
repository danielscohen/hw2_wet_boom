//
// Created by dcohe on 11/06/2020.
//

#include "ArtistSongsByStreamsKey.h"


bool operator<(const ArtistSongsByStreamsKey &lhs, const ArtistSongsByStreamsKey &rhs) {
    if(lhs.numStreams > rhs.numStreams) return true;
    if(lhs.numStreams < rhs.numStreams) return false;
    return lhs.songID < rhs.songID;
}

bool operator==(const ArtistSongsByStreamsKey &lhs, const ArtistSongsByStreamsKey &rhs) {
    return lhs.songID == rhs.songID;
}

bool operator>(const ArtistSongsByStreamsKey &lhs, const ArtistSongsByStreamsKey &rhs) {
    return rhs < lhs;
}

bool operator!=(const ArtistSongsByStreamsKey &lhs, const ArtistSongsByStreamsKey &rhs) {
    return !(lhs == rhs);
}

ArtistSongsByStreamsKey::ArtistSongsByStreamsKey(int songId, int numStreams) : songID(songId), numStreams(numStreams) {}
