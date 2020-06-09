//
//  main.cpp
//  ChordProject
//
//  Created by Shashvat Gupta on 6/7/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#include <iostream>

#include "chordFactory.hpp"
#include "chordDecorator.hpp"
#include "chordVisitor.h"


int main(int argc, const char * argv[]) {
    std::cout << "Input chord name\n";
    std::string in;
    
    std::cin >> in;
    
    chord* tmp = new chord(in);
    chord* Major = tmp->chordFactory(maj);
    chord* Minor = tmp->chordFactory(min);
    
    chord* Six = new sixChord(Major);
    chord* Seven = new sevenChord(Minor);

    
    Major->printChord();
    Minor->printChord();
    Six->printChord();
    Seven->printChord();

    std::cout<<"removing root"<<std::endl;
    MinChord* MinRemRoot = static_cast<MinChord*>(Minor);
    MinRemRoot->Accept(new remove1Visitor);
    MinRemRoot->printChord();
    

    return 0;
}
