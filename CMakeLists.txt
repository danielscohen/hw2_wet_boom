cmake_minimum_required(VERSION 3.15)
project(hw2_wet)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(hw2_wet
        AllSongsByStreamsKey.cpp
        AllSongsByStreamsKey.h
        Artist.cpp
        Artist.h
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
        MusicManager.cpp
        MusicManager.h
        out2.txt)
