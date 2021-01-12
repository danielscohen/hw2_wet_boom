//
// Created by dcohe on 14/06/2020.
//

#include "CoursesManager.h"

StatusType CoursesManager::addCourse(int courseID) {
    if(courseTable.get(courseID) != nullptr) return FAILURE;
    return courseTable.insert(courseID, std::make_shared<HashTable<std::shared_ptr<Lecture>>>());
}

StatusType CoursesManager::removeCourse(int courseID) {
    if(courseTable.get(courseID) == nullptr) return FAILURE;
    std::shared_ptr<HashTable<std::shared_ptr<Lecture>>> classTable = courseTable.get(courseID);
    for(int i = 0; i < classTable->getNumEntries(); i++){
        std::shared_ptr<Lecture> lecture = classTable->get(i);
        if(lecture->viewTime > 0){
            rankedClassTree.remove(lecture);
        }
    }
    return courseTable.remove(courseID);
}

StatusType CoursesManager::addClass(int courseID, int *classID) {
    if(courseTable.get(courseID) == nullptr) return FAILURE;
    std::shared_ptr<HashTable<std::shared_ptr<Lecture>>> classTable = courseTable.get(courseID);
    std::shared_ptr<Lecture> lecture;
    *classID = classTable->getNumEntries();

    try {
         lecture = std::make_shared<Lecture>(Lecture(*classID, courseID, 0));
         classTable->insert(*classID, lecture);
         rankedClassTree.insert(lecture);
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


    return addClass(artistID, songID);
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
