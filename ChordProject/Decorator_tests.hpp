
#ifndef __DECORATOR_TESTS_HPP__
#define __DECORATOR_TESTS_HPP__

#include "gtest/gtest.h"

#include "chordDecorator.hpp"
#include "chord.hpp"
#include "chordFactory.hpp"

TEST(DecoratorSet, SixChord) {
    chord* tmp = new chord("C");
    
    chord* cMaj = tmp->chordFactory(maj);

    sixChord* test = new sixChord(cMaj);

    EXPECT_EQ(test->note1, 4);
    EXPECT_EQ(test->note2, 7);
    EXPECT_EQ(test->note3, 12);
    EXPECT_EQ(test->note4, 16);

}

TEST(DecoratorSet, SevenChord) {
    chord* tmp = new chord("D");
    
    chord* cMaj = tmp->chordFactory(maj);

    sevenChord* test = new sevenChord(cMaj);

    EXPECT_EQ(test->note1, 2);
    EXPECT_EQ(test->note2, 6);
    EXPECT_EQ(test->note3, 9);
    EXPECT_EQ(test->note4, 12);

}

TEST(DecoratorSet, MinorSixChord) {
    chord* tmp = new chord("C");
    
    chord* cMin = tmp->chordFactory(min);

    sixChord* test = new sixChord(cMin);

    EXPECT_EQ(test->note1, 3);
    EXPECT_EQ(test->note2, 7);
    EXPECT_EQ(test->note3, 12);
    EXPECT_EQ(test->note4, 15);

}

TEST(DecoratorSet, MinorSevenChord) {
    chord* tmp = new chord("D");
    
    chord* cMin = tmp->chordFactory(min);

    sevenChord* test = new sevenChord(cMin);

    EXPECT_EQ(test->note1, 2);
    EXPECT_EQ(test->note2, 5);
    EXPECT_EQ(test->note3, 9);
    EXPECT_EQ(test->note4, 12);

}


#endif //__DECORATOR_TESTS_HPP__
