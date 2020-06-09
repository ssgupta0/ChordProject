//
//  chordVisitor.h
//  ChordProject
//
//  Created by Shashvat Gupta on 6/8/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#ifndef chordVisitor_hpp
#define chordVisitor_hpp

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
    virtual void visit( MajChord *element) = 0;
    virtual void visit( MinChord *element) = 0;
};


class MinChord : public chord {
public:
    void Accept(chordVisitor *visitor) {
        visitor->visit(this);
    }
};
class MajChord : public chord {
public:
    void Accept(chordVisitor *visitor) {
        visitor->visit(this);
    }
};

//removing note functions

class remove1Visitor : public chordVisitor {
public:
    void visit( MajChord *element)  {
        element->note1=-1;
    }
    void visit( MinChord *element)  {
        element->note1=-1;
    }
};
class remove2Visitor : public chordVisitor {
public:
    void visit( MajChord *element)  {
        element->note2=-1;
    }
    void visit( MinChord *element)  {
        element->note2=-1;
    }
};

class remove3Visitor : public chordVisitor {
public:
    void visit( MajChord *element)  {
        element->note3=-1;
    }
    void visit( MinChord *element)  {
        element->note3=-1;
    }
};

class remove4Visitor : public chordVisitor {
public:
    void visit( MajChord *element)  {
        element->note4=-1;
        if(element->dec==2)
            element->dec=_;
    }
    void visit( MinChord *element)  {
        element->note4=-1;
        if(element->dec==2)
            element->dec=_;
    }
};

class dropRootVisitor : public chordVisitor {
    void visit(MajChord *element) {
        if(element->note1-12 < 0) {
            std::cout<<"Cannot drop root as it would be too low"<<std::endl;
            return;
        }
        element->note1-=12;
    }
    void visit(MinChord *element) {
        if(element->note1-12 < 0) {
            std::cout<<"Cannot drop root as it would be too low"<<std::endl;
            return;
        }
        element->note1-=12;
    }
};

class RaiseSopVisitor : public chordVisitor {
    void visit(MajChord *element) {
        
        element->note4+=12;
    }
    void visit(MinChord *element) {
        
        element->note4+=12;
    }
};



#endif /* chordVisitor_hpp */
