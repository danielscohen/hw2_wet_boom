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


StatusType CoursesManager::watchClass(int courseID, int classID, int time) {
    std::shared_ptr<HashTable<std::shared_ptr<Lecture>>> classTable = courseTable.get(courseID);
    if(classTable != nullptr && classID + 1 > classTable->getNumEntries()) return INVALID_INPUT;
    if(classTable == nullptr) return FAILURE;
    std::shared_ptr<Lecture> lecture = classTable->get(classID);

    if(lecture->viewTime > 0) rankedClassTree.remove(lecture);

    lecture->viewTime += time;

    try {
        rankedClassTree.insert(lecture);
    } catch (...){return ALLOCATION_ERROR;}


    return SUCCESS;

}

StatusType CoursesManager::timeViewed(int courseID, int classID, int *timeViewed) {

    std::shared_ptr<HashTable<std::shared_ptr<Lecture>>> classTable = courseTable.get(courseID);
    if(classTable != nullptr && classID + 1 > classTable->getNumEntries()) return INVALID_INPUT;
    if(classTable == nullptr) return FAILURE;

    *timeViewed = classTable->get(classID)->viewTime;
    return SUCCESS;

}

StatusType CoursesManager::getIthWatchedClass(int i, int *courseID, int *classID) {
    if(i > rankedClassTree.getSize()) return FAILURE;

    *courseID = rankedClassTree.select(i)->courseID;
    *classID = rankedClassTree.select(i)->classID;

    return SUCCESS;
}
