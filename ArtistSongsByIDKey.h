//
// Created by dcohe on 11/06/2020.
//

#ifndef MUSIC_MANAGER_2_ARTISTSONGSBYIDKEY_H
#define MUSIC_MANAGER_2_ARTISTSONGSBYIDKEY_H


class ArtistSongsByIDKey {
public:
    int songID;
    int numStreams;

    ArtistSongsByIDKey(int songId, int numStreams);

    friend bool operator<(const ArtistSongsByIDKey& lhs, const ArtistSongsByIDKey& rhs);
    friend bool operator>(const ArtistSongsByIDKey& lhs, const ArtistSongsByIDKey& rhs);
    friend bool operator==(const ArtistSongsByIDKey& lhs, const ArtistSongsByIDKey& rhs);
    friend bool operator!=(const ArtistSongsByIDKey& lhs, const ArtistSongsByIDKey& rhs);
};


#endif //MUSIC_MANAGER_2_ARTISTSONGSBYIDKEY_H
