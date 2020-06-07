//
//  chordFactory.hpp
//  ChordProject
//
//  Created by Shashvat Gupta on 6/7/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#ifndef chordFactory_hpp
#define chordFactory_hpp

#include <stdio.h>
#include "chord.hpp"

class major: public chord {
public:
     major(chord* c) {
         
         
        //return new chord(); //major
    }
};

class minor: public chord {
    
};


#endif /* chordFactory_hpp */
