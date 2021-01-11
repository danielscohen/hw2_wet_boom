//
// Created by dcohe on 14/06/2020.
//

#ifndef MUSIC_MANAGER_2_ARTIST_H
#define MUSIC_MANAGER_2_ARTIST_H


#include "memory"
#include "HashTable.h"
#include "Lecture.h"

class Course {
public:

    HashTable<std::shared_ptr<Lecture>> lectureTable;
};


#endif //MUSIC_MANAGER_2_ARTIST_H
