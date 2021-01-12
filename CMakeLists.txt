cmake_minimum_required(VERSION 3.15)
project(hw2_wet)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(hw2_wet
        Lecture.cpp
        Lecture.h
        Course.cpp
        Course.h
        ArtistSongsByIDKey.cpp
        ArtistSongsByIDKey.h
        ArtistSongsByStreamsKey.cpp
        ArtistSongsByStreamsKey.h
        AVLRankTree.h
        HashTable.h
        in2.txt
        library2.h
        List.h
        main2.cpp
        CoursesManager.cpp
        CoursesManager.h
        out2.txt library2.cpp)
