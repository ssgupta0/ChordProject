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

int main(int argc, const char * argv[]) {
    std::cout << "Input chord name\n";
    std::string in;
    
    std::cin >> in;
    
    chord* tmp = new chord(in);
    chord* Major = tmp->chordFactory(maj);
    chord* Minor = tmp->chordFactory(min);
    
    chord* Six = new sixChord(Major);
    chord* Six2 = new sixChord(Minor);

    
    Major->printChord();
    Minor->printChord();
    Six->printChord();
    Six2->printChord();

    return 0;
}
