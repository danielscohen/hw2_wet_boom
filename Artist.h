//
// Created by dcohe on 14/06/2020.
//

#ifndef MUSIC_MANAGER_2_ARTIST_H
#define MUSIC_MANAGER_2_ARTIST_H


#include "AVLRankTree.h"
#include "ArtistSongsByIDKey.h"
#include "ArtistSongsByStreamsKey.h"
#include "memory"

class Artist {
public:
    AVLRankTree<std::shared_ptr<ArtistSongsByIDKey>> artistSongsByID;
    AVLRankTree<std::shared_ptr<ArtistSongsByStreamsKey>> artistSongsByStreams;

};


#endif //MUSIC_MANAGER_2_ARTIST_H
