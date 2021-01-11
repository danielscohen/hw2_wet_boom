//
// Created by dcohe on 14/06/2020.
//

#include "MusicManager.h"

StatusType MusicManager::addArtist(int artistID) {
    if(artistsTable.get(artistID) != nullptr) return FAILURE;
    return artistsTable.insert(artistID, std::make_shared<Artist>(Artist()));
}

StatusType MusicManager::removeArtist(int artistID) {
    if(artistsTable.get(artistID) == nullptr || !artistsTable.get(artistID)->artistSongsByID.isEmpty()) return FAILURE;
    return artistsTable.remove(artistID);
}

StatusType MusicManager::addSong(int artistID, int songID, int numStreams) {
    std::shared_ptr<Artist> artist = artistsTable.get(artistID);
    std::shared_ptr<ArtistSongsByIDKey> songByID;
    std::shared_ptr<ArtistSongsByStreamsKey> songByStreams;
    std::shared_ptr<AllSongsByStreamsKey> song;

    try {
         songByID = std::make_shared<ArtistSongsByIDKey>(ArtistSongsByIDKey(songID, numStreams));
         songByStreams = std::make_shared<ArtistSongsByStreamsKey>(ArtistSongsByStreamsKey(songID, numStreams));
         song = std::make_shared<AllSongsByStreamsKey>(AllSongsByStreamsKey(songID, artistID, numStreams));
    } catch (...){return ALLOCATION_ERROR;}



    if(artist == nullptr || artist->artistSongsByID.isMember(songByID)) return FAILURE;


    try {
        artist->artistSongsByID.insert(songByID);
        artist->artistSongsByStreams.insert(songByStreams);
        rankedSongsTree.insert(song);
    } catch (...){return ALLOCATION_ERROR;}


    return SUCCESS;



}

StatusType MusicManager::removeSong(int artistID, int songID) {
    std::shared_ptr<Artist> artist = artistsTable.get(artistID);
    std::shared_ptr<ArtistSongsByIDKey> songByID;
    std::shared_ptr<ArtistSongsByStreamsKey> songByStreams;
    std::shared_ptr<AllSongsByStreamsKey> song;

    try {
        songByID = std::make_shared<ArtistSongsByIDKey>(ArtistSongsByIDKey(songID, 0));
    } catch (...){return ALLOCATION_ERROR;}



    if(artist == nullptr || !artist->artistSongsByID.isMember(songByID)) return FAILURE;

    int numStreams = artist->artistSongsByID.get(songByID)->numStreams;

    try {
        songByStreams = std::make_shared<ArtistSongsByStreamsKey>(ArtistSongsByStreamsKey(songID, numStreams));
        song = std::make_shared<AllSongsByStreamsKey>(AllSongsByStreamsKey(songID, artistID, numStreams));
    } catch (...){return ALLOCATION_ERROR;}

    artist->artistSongsByID.remove(songByID);
    artist->artistSongsByStreams.remove(songByStreams);
    rankedSongsTree.remove(song);


    return SUCCESS;
}

StatusType MusicManager::addToSongCount(int artistID, int songID, int count) {
    std::shared_ptr<Artist> artist = artistsTable.get(artistID);
    std::shared_ptr<ArtistSongsByIDKey> songByID;
    std::shared_ptr<ArtistSongsByStreamsKey> songByStreams;
    std::shared_ptr<AllSongsByStreamsKey> song;

    try {
        songByID = std::make_shared<ArtistSongsByIDKey>(ArtistSongsByIDKey(songID, 0));
    } catch (...){return ALLOCATION_ERROR;}



    if(artist == nullptr || !artist->artistSongsByID.isMember(songByID)) return FAILURE;

    int numStreams = artist->artistSongsByID.get(songByID)->numStreams;

    try {
        songByStreams = std::make_shared<ArtistSongsByStreamsKey>(ArtistSongsByStreamsKey(songID, numStreams));
        song = std::make_shared<AllSongsByStreamsKey>(AllSongsByStreamsKey(songID, artistID, numStreams));
    } catch (...){return ALLOCATION_ERROR;}

    artist->artistSongsByID.remove(songByID);
    artist->artistSongsByStreams.remove(songByStreams);
    rankedSongsTree.remove(song);


    return addSong(artistID, songID, numStreams + count);
}

StatusType MusicManager::getArtistBestSong(int artistID, int *songID) {
    std::shared_ptr<Artist> artist = artistsTable.get(artistID);

    if(artist == nullptr || artist->artistSongsByID.isEmpty()) return FAILURE;

    *songID = artist->artistSongsByStreams.getMax()->songID;

    return SUCCESS;

}

StatusType MusicManager::getRecommendedSongInPlace(int rank, int *artistID, int *songID) {
    if(rank > rankedSongsTree.getSize()) return FAILURE;

    *artistID = rankedSongsTree.select(rank)->artistID;
    *songID = rankedSongsTree.select(rank)->songID;

    return SUCCESS;
}
