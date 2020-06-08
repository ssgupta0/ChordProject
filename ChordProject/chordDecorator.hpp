//
//  chordDecorator.cpp
//  ChordProject
//
//  Created by Shashvat Gupta on 6/7/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#ifndef chordDecorator_hpp
#define chordDecorator_hpp


#include <stdio.h>
#include "chord.hpp"


class chordDecorator: public chord {
public:
    chordDecorator(chord* c) : change(c) { }

protected:
    chord* change;
};

class sixChord: public chordDecorator {
public:
    sixChord(chord* c) : chordDecorator(c) {
        
        note1 = c->note1;
        note2 = c->note2;
        note3 = c->note3;
        note4 = c->note4;
        
        note1=note2;
        int tmp = note2;
        note2=note3;
        note3=note4;
        note4=tmp+12;
        
        type=c->type;
        dec=six;
    }
};

#endif
