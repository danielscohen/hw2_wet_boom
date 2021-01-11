//
// Created by dcohe on 14/06/2020.
//

#include "CoursesManager.h"

StatusType CoursesManager::addCourse(int courseID) {
    if(courseTable.get(courseID) != nullptr) return FAILURE;
    return courseTable.insert(courseID, std::make_shared<Course>(Course()));
}

StatusType CoursesManager::removeArtist(int artistID) {
    if(courseTable.get(artistID) == nullptr || !courseTable.get(artistID)->artistSongsByID.isEmpty()) return FAILURE;
    return courseTable.remove(artistID);
}

StatusType CoursesManager::addSong(int artistID, int songID, int numStreams) {
    std::shared_ptr<Course> artist = courseTable.get(artistID);
    std::shared_ptr<ArtistSongsByIDKey> songByID;
    std::shared_ptr<ArtistSongsByStreamsKey> songByStreams;
    std::shared_ptr<Lecture> song;

    try {
         songByID = std::make_shared<ArtistSongsByIDKey>(ArtistSongsByIDKey(songID, numStreams));
         songByStreams = std::make_shared<ArtistSongsByStreamsKey>(ArtistSongsByStreamsKey(songID, numStreams));
         song = std::make_shared<Lecture>(Lecture(songID, artistID, numStreams));
    } catch (...){return ALLOCATION_ERROR;}



    if(artist == nullptr || artist->artistSongsByID.isMember(songByID)) return FAILURE;


    try {
        artist->artistSongsByID.insert(songByID);
        artist->artistSongsByStreams.insert(songByStreams);
        rankedClassTree.insert(song);
    } catch (...){return ALLOCATION_ERROR;}


    return SUCCESS;



}

StatusType CoursesManager::removeSong(int artistID, int songID) {
    std::shared_ptr<Course> artist = courseTable.get(artistID);
    std::shared_ptr<ArtistSongsByIDKey> songByID;
    std::shared_ptr<ArtistSongsByStreamsKey> songByStreams;
    std::shared_ptr<Lecture> song;

    try {
        songByID = std::make_shared<ArtistSongsByIDKey>(ArtistSongsByIDKey(songID, 0));
    } catch (...){return ALLOCATION_ERROR;}



    if(artist == nullptr || !artist->artistSongsByID.isMember(songByID)) return FAILURE;

    int numStreams = artist->artistSongsByID.get(songByID)->numStreams;

    try {
        songByStreams = std::make_shared<ArtistSongsByStreamsKey>(ArtistSongsByStreamsKey(songID, numStreams));
        song = std::make_shared<Lecture>(Lecture(songID, artistID, numStreams));
    } catch (...){return ALLOCATION_ERROR;}

    artist->artistSongsByID.remove(songByID);
    artist->artistSongsByStreams.remove(songByStreams);
    rankedClassTree.remove(song);


    return SUCCESS;
}

StatusType CoursesManager::addToSongCount(int artistID, int songID, int count) {
    std::shared_ptr<Course> artist = courseTable.get(artistID);
    std::shared_ptr<ArtistSongsByIDKey> songByID;
    std::shared_ptr<ArtistSongsByStreamsKey> songByStreams;
    std::shared_ptr<Lecture> song;

    try {
        songByID = std::make_shared<ArtistSongsByIDKey>(ArtistSongsByIDKey(songID, 0));
    } catch (...){return ALLOCATION_ERROR;}



    if(artist == nullptr || !artist->artistSongsByID.isMember(songByID)) return FAILURE;

    int numStreams = artist->artistSongsByID.get(songByID)->numStreams;

    try {
        songByStreams = std::make_shared<ArtistSongsByStreamsKey>(ArtistSongsByStreamsKey(songID, numStreams));
        song = std::make_shared<Lecture>(Lecture(songID, artistID, numStreams));
    } catch (...){return ALLOCATION_ERROR;}

    artist->artistSongsByID.remove(songByID);
    artist->artistSongsByStreams.remove(songByStreams);
    rankedClassTree.remove(song);


    return addSong(artistID, songID, numStreams + count);
}

StatusType CoursesManager::getArtistBestSong(int artistID, int *songID) {
    std::shared_ptr<Course> artist = courseTable.get(artistID);

    if(artist == nullptr || artist->artistSongsByID.isEmpty()) return FAILURE;

    *songID = artist->artistSongsByStreams.getMax()->songID;

    return SUCCESS;

}

StatusType CoursesManager::getRecommendedSongInPlace(int rank, int *artistID, int *songID) {
    if(rank > rankedClassTree.getSize()) return FAILURE;

    *artistID = rankedClassTree.select(rank)->courseID;
    *songID = rankedClassTree.select(rank)->classID;

    return SUCCESS;
}
