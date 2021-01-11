//
// Created by dcohe on 11/06/2020.
//

#ifndef MUSIC_MANAGER_2_ALLSONGSBYSTREAMSKEY_H
#define MUSIC_MANAGER_2_ALLSONGSBYSTREAMSKEY_H


class AllSongsByStreamsKey {
public:
    int songID;
    int artistID;
    int numStreams;

    AllSongsByStreamsKey(int songId, int artistId, int numStreams);

    friend bool operator<(const AllSongsByStreamsKey& lhs, const AllSongsByStreamsKey& rhs);
    friend bool operator>(const AllSongsByStreamsKey& lhs, const AllSongsByStreamsKey& rhs);
    friend bool operator==(const AllSongsByStreamsKey& lhs, const AllSongsByStreamsKey& rhs);
    friend bool operator!=(const AllSongsByStreamsKey& lhs, const AllSongsByStreamsKey& rhs);
};


#endif //MUSIC_MANAGER_2_ALLSONGSBYSTREAMSKEY_H
