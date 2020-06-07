//
//  chord.cpp
//  ChordProject
//
//  Created by Shashvat Gupta on 6/7/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#ifndef chord_hpp
#define chord_hpp


#include <stdio.h>
#include <string>
#include <iostream>

class chord {
private:
    int note1;
    int note2;
    int note3;
    int note4;
    
    std::string key;
    
public:
    chord();
    chord(std::string,int,int,int,int);
    
    std::string convertToNote(int note);
    int convertToNum(std::string note);
    bool compareNote(int a, int b);
};

chord::chord() {
    note1=0;        //C4
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
    
    if(n.length()==3) {
        note=(n[0] + n[1]);
        num = std::stoi(n[2]);
    }
    else if(n.length()==2) {
        note=(n[0]);
        num = std::stoi(n[1]);
    }
    else if(n.length()==1) {
        note=n;
    }
    
    std::string letter[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    for(int i = 0; i<12) {
        if(letter[i]==note) {
            return i+num;
        }
    }
    
    std::cout << n << " not present." << std::endl;
}



#endif
