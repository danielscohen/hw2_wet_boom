//
// Created by dcohe on 11/06/2020.
//

#include "AllSongsByStreamsKey.h"

bool operator<(const AllSongsByStreamsKey &lhs, const AllSongsByStreamsKey &rhs) {
    if(lhs.numStreams > rhs.numStreams) return true;
    if(lhs.numStreams < rhs.numStreams) return false;
    if(lhs.artistID < rhs.artistID) return true;
    if(lhs.artistID > rhs.artistID) return false;
    return lhs.songID < rhs.songID;
}

bool operator==(const AllSongsByStreamsKey &lhs, const AllSongsByStreamsKey &rhs) {
    return lhs.artistID == rhs.artistID && lhs.songID == rhs.songID;
}

bool operator>(const AllSongsByStreamsKey &lhs, const AllSongsByStreamsKey &rhs) {
    return rhs < lhs;
}

bool operator!=(const AllSongsByStreamsKey &lhs, const AllSongsByStreamsKey &rhs) {
    return !(lhs == rhs);
}

AllSongsByStreamsKey::AllSongsByStreamsKey(int songId, int artistId, int numStreams) : songID(songId),
                                                                                       artistID(artistId),
                                                                                       numStreams(numStreams) {}


