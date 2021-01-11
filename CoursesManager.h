//
// Created by dcohe on 14/06/2020.
//

#ifndef MUSIC_MANAGER_2_MUSICMANAGER_H
#define MUSIC_MANAGER_2_MUSICMANAGER_H



#include "AVLRankTree.h"
#include "Lecture.h"
#include "HashTable.h"
#include "Course.h"

class CoursesManager {

    HashTable<std::shared_ptr<Course>> courseTable;
    AVLRankTree<std::shared_ptr<Lecture>> rankedClassTree;

public:

    StatusType addCourse(int courseID);
    StatusType removeArtist(int artistID);
    StatusType addSong(int artistID, int songID, int numStreams);
    StatusType removeSong(int artistID, int songID);
    StatusType addToSongCount(int artistID, int songID, int count);
    StatusType getArtistBestSong(int artistID, int *songID);
    StatusType getRecommendedSongInPlace(int rank, int *artistID, int *songID);

};


#endif //MUSIC_MANAGER_2_MUSICMANAGER_H
