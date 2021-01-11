//
// Created by dcohe on 11/06/2020.
//

#include "Lecture.h"

bool operator<(const Lecture &lhs, const Lecture &rhs) {
    if(lhs.viewTime > rhs.viewTime) return true;
    if(lhs.viewTime < rhs.viewTime) return false;
    if(lhs.courseID < rhs.courseID) return true;
    if(lhs.courseID > rhs.courseID) return false;
    return lhs.classID < rhs.classID;
}

bool operator==(const Lecture &lhs, const Lecture &rhs) {
    return lhs.courseID == rhs.courseID && lhs.classID == rhs.classID;
}

bool operator>(const Lecture &lhs, const Lecture &rhs) {
    return rhs < lhs;
}

bool operator!=(const Lecture &lhs, const Lecture &rhs) {
    return !(lhs == rhs);
}

Lecture::Lecture(int classID, int courseID, int viewTime) : classID(classID),
                                                            courseID(courseID),
                                                            viewTime(viewTime) {}


