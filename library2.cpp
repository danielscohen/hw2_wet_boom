//
// Created by dcohe on 12/01/2021.
//


#include "library2.h"
#include "CoursesManager.h"

void *Init() {
   CoursesManager *DS = new CoursesManager();
   return (void*)DS;
}

StatusType AddCourse(void *DS, int courseID) {
    if(DS == nullptr || courseID <= 0) return INVALID_INPUT;
    return ((CoursesManager *)DS)-> addCourse(courseID);
}

StatusType RemoveCourse(void *DS, int courseID) {
    if(DS == nullptr || courseID <= 0) return INVALID_INPUT;
    return ((CoursesManager *)DS)-> removeCourse(courseID);
}

StatusType AddClass(void *DS, int courseID, int *classID) {
    if(DS == nullptr || courseID <= 0) return INVALID_INPUT;
    return ((CoursesManager *)DS)-> addClass(courseID, classID);
}

StatusType WatchClass(void *DS, int courseID, int classID, int time) {
    if(DS == nullptr || courseID <= 0 || classID < 0 || time <= 0) return INVALID_INPUT;
    return ((CoursesManager *)DS)-> watchClass(courseID, classID, time);
}

StatusType TimeViewed(void *DS, int courseID, int classID, int *timeViewed) {
    if(DS == nullptr || courseID <= 0 || classID < 0) return INVALID_INPUT;
    return ((CoursesManager *)DS)-> timeViewed(courseID, classID, timeViewed);
}

StatusType GetIthWatchedClass(void *DS, int i, int *courseID, int *classID) {
    if(DS == nullptr || i <= 0) return INVALID_INPUT;
    return ((CoursesManager *)DS)-> getIthWatchedClass(i, courseID, classID);
}

void Quit(void **DS) {
    delete ((CoursesManager*)*DS);
    *DS = nullptr;
}

