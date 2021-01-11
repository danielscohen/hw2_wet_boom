//
// Created by dcohe on 11/06/2020.
//

#ifndef MUSIC_MANAGER_2_ALLSONGSBYSTREAMSKEY_H
#define MUSIC_MANAGER_2_ALLSONGSBYSTREAMSKEY_H


class Lecture {
public:
    int classID;
    int courseID;
    int viewTime;

    Lecture(int classID, int courseID, int viewTime);

    friend bool operator<(const Lecture& lhs, const Lecture& rhs);
    friend bool operator>(const Lecture& lhs, const Lecture& rhs);
    friend bool operator==(const Lecture& lhs, const Lecture& rhs);
    friend bool operator!=(const Lecture& lhs, const Lecture& rhs);
};


#endif //MUSIC_MANAGER_2_ALLSONGSBYSTREAMSKEY_H
