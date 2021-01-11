//
// Created by dcohe on 14/06/2020.
//

#ifndef MUSIC_MANAGER_2_MUSICMANAGER_H
#define MUSIC_MANAGER_2_MUSICMANAGER_H



#include "AVLRankTree.h"
#include "AllSongsByStreamsKey.h"
#include "HashTable.h"
#include "Artist.h"

class MusicManager {

    HashTable<std::shared_ptr<Artist>> artistsTable;
    AVLRankTree<std::shared_ptr<AllSongsByStreamsKey>> rankedSongsTree;

public:

    StatusType addArtist(int artistID);
    StatusType removeArtist(int artistID);
    StatusType addSong(int artistID, int songID, int numStreams);
    StatusType removeSong(int artistID, int songID);
    StatusType addToSongCount(int artistID, int songID, int count);
    StatusType getArtistBestSong(int artistID, int *songID);
    StatusType getRecommendedSongInPlace(int rank, int *artistID, int *songID);

};


#endif //MUSIC_MANAGER_2_MUSICMANAGER_H
