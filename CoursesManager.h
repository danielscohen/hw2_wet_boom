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

    HashTable<std::shared_ptr<HashTable<std::shared_ptr<Lecture>>>> courseTable;
    AVLRankTree<std::shared_ptr<Lecture>> rankedClassTree;

public:

    StatusType addCourse(int courseID);
    StatusType removeCourse(int courseID);
    StatusType addClass(int courseID, int *classID);
    StatusType watchClass(int courseID, int classID, int time);
    StatusType timeViewed(int courseID, int classID, int *timeViewed);
    StatusType getIthWatchedClass(int i, int *courseID, int *classID);

};


#endif //MUSIC_MANAGER_2_MUSICMANAGER_H
