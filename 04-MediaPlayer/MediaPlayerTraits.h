#pragma once

#include <iostream>

using namespace std;

class Song {
private:
    string title;
    string band;

public:
    Song(string title, string band) : title(title), band(band) {
    }

    void play() const {
        cout << "Playing " << title << " of band " << band << endl;
    }

    string getTitle() const {
        return title;
    }

    string getBand() const {
        return band;
    }

    void print() const {
        cout << "Song:" << title << " of band " << band << endl;
    }
};

class MediaPlayerTraits {
public:
    virtual void enqueue(Song song) = 0; // add to the end (append)

    virtual void put(string band, string title) = 0; // add to the end (append)

    virtual void remove(Song song) = 0; // remove a song from any place

    virtual void print() = 0;

    virtual unsigned countSongs() = 0;

    virtual void searchForTitle(string title) = 0;

    virtual void searchForBand(string band) = 0;

    virtual void play() = 0;

    virtual void first() = 0; // go to first song

    virtual void next() = 0; // go to next song

    virtual void previous() = 0; // go to previous song

    virtual void last() = 0; // go to last song

    virtual Song* getCurrentElement() = 0; // get current song
};