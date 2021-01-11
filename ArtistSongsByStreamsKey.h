//
// Created by dcohe on 11/06/2020.
//

#ifndef MUSIC_MANAGER_2_ARTISTSONGSBYSTREAMSKEY_H
#define MUSIC_MANAGER_2_ARTISTSONGSBYSTREAMSKEY_H


class ArtistSongsByStreamsKey {
public:
    int songID;
    int numStreams;

    ArtistSongsByStreamsKey(int songId, int numStreams);

    friend bool operator<(const ArtistSongsByStreamsKey& lhs, const ArtistSongsByStreamsKey& rhs);
    friend bool operator>(const ArtistSongsByStreamsKey& lhs, const ArtistSongsByStreamsKey& rhs);
    friend bool operator==(const ArtistSongsByStreamsKey& lhs, const ArtistSongsByStreamsKey& rhs);
    friend bool operator!=(const ArtistSongsByStreamsKey& lhs, const ArtistSongsByStreamsKey& rhs);
};


#endif //MUSIC_MANAGER_2_ARTISTSONGSBYSTREAMSKEY_H
