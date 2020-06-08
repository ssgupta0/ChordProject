//
//  chord.cpp
//  ChordProject
//
//  Created by Shashvat Gupta on 6/7/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#ifndef chord_hpp
#define chord_hpp

enum chordType {maj, min};
enum Decorator {_, six, seven};


#include <stdio.h>
#include <string>
#include <iostream>

class chord {
public:
    int note1;
    int note2;
    int note3;
    int note4;
    
    std::string key;
    chordType type;
    Decorator dec;
    
public:
    chord();
    chord(std::string in) {
        note1=0;        //C4
        note2=0;
        note3=0;
        note4=0;
        key = in;
    }
    chord(std::string,int,int,int,int);
    
    std::string convertToNote(int note);
    int convertToNum(std::string note);
    bool compareNote(int a, int b);
    chord* chordFactory(chordType type);
    
    void printChord();
};

chord::chord() {
    note1=0;        //C1
    note2=0;
    note3=0;
    note4=0;
    key = "C";
}

chord::chord(std::string s ,int a, int b, int c, int d) {
    key=s;
    
    note1=a;
    note2=b;
    note3=c;
    note4=d;
}

std::string chord::convertToNote(int n) {
    int note = n%12;
    
    std::string letter[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    
    return ( letter[note] + std::to_string((int)n/12 + 4) );
}

int chord::convertToNum(std::string n) {
    std::string note = "";
    int num = 0;
    
    //std::cout << "n[1]: " << n[1];
    
    if(n.length()==3) {
        note=(n[0] + n[1]);
        num = n[2];
    }
    else if(n.length()==2) {
        if((n[1])=='#' || n[1]=='b') {
            note=n;
        }
        else {
            note=(n[0]);
            num = n[1];
        }
    }
    else if(n.length()==1) {
        note=n;
    }
    
    std::string letter[3][12] = {
        {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"},
        {"B#", "B##", "C##", "Fbb", "D##", "E#", "E##", "F##", "", "G##", "", "A##"},
        {"Dbb", "Db", "Ebb", "Eb", "Fb", "Gbb", "Gb", "Abb", "Ab", "Bbb", "Bb", "Cb"}
    };
    
    for(int i = 0; i<12; i++) {
        for(int w = 0; w<3; w++) {
            if(letter[w][i]==note) {
                return i + (num*12);
            }
        }
    }
    
    std::cout << n << " not present." << std::endl;
    return -1;
}

bool chord::compareNote(int a, int b) {
    if(a%12==b%12) {
        return true;
    }
    return false;
}

void chord::printChord() {
    std::string t = "";
    std::string d = "";
    if(type==0) {
        t="maj";
    }
    else if (type==1) {
        t="min";
    }
    
    if(this->dec==1) {
        d = "6";
    }
    else if (this->dec==2) {
        d = "7";
    }
    
    std::cout << key << t << d << ": " << "\n\t" << convertToNote(note4);
    std::cout << "\n\t" << convertToNote(note3);
    std::cout << "\n\t" << convertToNote(note2);
    std::cout << "\n\t" << convertToNote(note1) << std::endl;
}

#endif
