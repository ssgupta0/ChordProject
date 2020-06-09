//
//  chordVisitor.h
//  ChordProject
//
//  Created by Shashvat Gupta on 6/8/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#ifndef chordVisitor_h
#define chordVisitor_h

#include "chord.hpp"
#include <array>

class MajChord;
class chord;

//===========================//
//=======---VISITOR---=======//
//===========================//


class MajChord;
class MinChord;

class chordVisitor {
public:
    virtual void VisitRemove1( MajChord *element) = 0;
    virtual void VisitRemove1( MinChord *element) = 0;
};


class MinChord : public chord {
public:
    void Accept(chordVisitor *visitor) {
        visitor->VisitRemove1(this);
    }
};
class MajChord : public chord {
public:
    void Accept(chordVisitor *visitor) {
        visitor->VisitRemove1(this);
    }
};

class remove1Visitor : public chordVisitor {
public:
    void VisitRemove1( MajChord *element) override {
        element->note1=-1;
    }
    void VisitRemove1( MinChord *element) override {
        element->note1=-1;
    }
};


#endif /* chordVisitor_h */
