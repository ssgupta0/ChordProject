
#ifndef __DECORATOR_HPP__
#define __DECORATOR_TESTS_HPP__

#include "gtest/gtest.h"

#include "chordDecorator.hpp"

TEST(DecoratorSet, SixChord) {
    chord* tmp = new chord("C");
    
    chord* cMaj = tmp->chordFactory(maj);
    
    chord* test = sixChord(cMaj);
    
    EXPECT_EQ(test->note1, 0);
}





#endif //__DECORATOR_TESTS_HPP__
