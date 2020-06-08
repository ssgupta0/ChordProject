//
//  chordFactory.hpp
//  ChordProject
//
//  Created by Shashvat Gupta on 6/7/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//


#ifndef chordFactory_hpp
#define chordFactory_hpp

#include "chord.hpp"

class major: public chord {
public:
     major(chord* c) {
         c->note1 = c->note2 = c->note3 = c->note4 = convertToNum(c->key);
         c->note2 += 4;
         c->note3 += 7;
         c->note4 += 13;
    }
};

class minor: public chord {
    public:
     minor(chord* c) {
         c->note1 = c->note2 = c->note3 = c->note4 = convertToNum(c->key);
         c->note2 += 3;
         c->note3 += 6;
         c->note4 += 13;
    }
};

chord* chord::chordFactory(chordType type) {
    if(type==maj) {
        return new class major(this);
    }
    
    return nullptr;
}

#endif /* chordFactory_hpp */
