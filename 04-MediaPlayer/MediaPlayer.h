#pragma once

#include "MediaPlayerTraits.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <string>
#include <vector>

using namespace std;

class MediaPlayer {
private:
    vector<Song> player;
    vector<Song>::iterator it = player.begin();

public:
    MediaPlayer() {
    }

    virtual ~MediaPlayer() {
    }

    void enqueue(Song song) {
        player.push_back(song);
    }

    void put(string band, string title) {
        player.push_back(Song(title, band));
    }

    void remove(Song song) {
        for (vector<Song>::iterator p = player.begin(); p != player.end();) {
            if (song.getTitle() == p->getTitle() && song.getBand() == p->getBand()) {
                p = player.erase(p);
            } else {
                ++p;
            }
        }
    }

    void print() {
        for (vector<Song>::const_iterator p = player.begin(); p != player.end(); ++p) {
            cout << p->getBand() << ' ' << p->getTitle() << endl;
        }
    }

    unsigned countSongs() {
        return player.size();
    }

    void searchForTitle(string title) {
        for (vector<Song>::const_iterator p = player.begin(); p != player.end(); ++p) {
            if (p->getTitle() == title) {
                cout << p->getTitle() << p->getBand() << endl;
            }
        }
    }

    void searchForBand(string band) {
        for (vector<Song>::const_iterator p = player.begin(); p != player.end(); ++p) {
            if (p->getBand() == band) {
                cout << p->getTitle() << p->getBand() << endl;
            }
        }
    }

    void play() {
        it->play();
    }

    void first() {
        if (player.size() > 0) {
            it = player.begin();
        }
    }

    void next() {
        if (it != player.end() - 1) {
            it = std::next(it, 1);
        } else {
            cout << "There is not any next song in Media player. Please select previous!" << endl;
        }
    }

    void previous() {
        if (it != player.begin()) {
            it = std::prev(it, 1);
        } else {
            cout << "There is not any previous song in Media player. Please select next!" << endl;
        }
    }

    void last() {
        it = player.end() - 1;
    }

    Song* getCurrentElement() {
        if (player.size() > 0 && it != player.end()) {
            return &*it;
        } else {
            return nullptr;
        }
    }
};
