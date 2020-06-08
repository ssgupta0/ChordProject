//
//  main.cpp
//  ChordProject
//
//  Created by Shashvat Gupta on 6/7/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#include <iostream>
#include "chordFactory.hpp"

int main(int argc, const char * argv[]) {
    std::cout << "Input chord name\n";
    std::string in;
    
    std::cin >> in;
    
    chord* tmp = new chord(in);
    chord* Major = tmp->chordFactory(maj);
    
    
    
    
    return 0;
}
