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

//===========================//
//=======---FACTORY---=======//
//===========================//

class major: public chord {
public:
     major(chord* c) {
         c->note1 = c->note2 = c->note3 = c->note4 = convertToNum(c->key);
         note1=c->note1;
         note2=c->note2;
         note3=c->note3;
         note4=c->note4;
         note2 += 4;
         note3 += 7;
         note4 += 12;
         
         type=maj;
    }
};

class minor: public chord {
    public:
     minor(chord* c) {
         c->note1 = c->note2 = c->note3 = c->note4 = convertToNum(c->key);
         note1=c->note1;
         note2=c->note2;
         note3=c->note3;
         note4=c->note4;
         note2 += 3;
         note3 += 7;
         note4 += 12;
         
         type=min;
     }
};

chord* chord::chordFactory(chordType type) {
    if(type==maj) {
        return new class major(this);
    }
    if(type==min) {
        return new class minor(this);
    }
    
    return nullptr;
}

#endif /* chordFactory_hpp */
