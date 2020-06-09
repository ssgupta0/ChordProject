

#ifndef __CHORD_TESTS_HPP__
#define __CHORD_TESTS_HPP__

#include "gtest/gtest.h"

#include "chordDecorator.hpp"
#include "chord.hpp"
#include "chordFactory.hpp"
#include "chordVisitor.hpp"

TEST(CombinationSet, Cchord) {
    chord* test = new chord("C");

    EXPECT_EQ(test->note1, 0);
    EXPECT_EQ(test->note2, 0);
    EXPECT_EQ(test->note3, 0);
    EXPECT_EQ(test->note4, 0);

}

TEST(CombinationSet, cMaj) {
    chord* tmp = new chord("C");
    chord* test = tmp->chordFactory(maj);


    EXPECT_EQ(test->note1, 0);
    EXPECT_EQ(test->note2, 4);
    EXPECT_EQ(test->note3, 7);
    EXPECT_EQ(test->note4, 12);

}

TEST(CombinationSet, DecMaj) {
    chord* tmp = new chord("C");
    chord* cMaj = tmp->chordFactory(maj);
    sixChord* test = new sixChord(cMaj);


    EXPECT_EQ(test->note1, 4);
    EXPECT_EQ(test->note2, 7);
    EXPECT_EQ(test->note3, 12);
    EXPECT_EQ(test->note4, 16);

}

TEST(CombinationSet, DropDecMaj) {
    chord* tmp = new chord("C");
    chord* cMaj = tmp->chordFactory(maj);
    chord* tmp2 = new sixChord(cMaj);
    
    MajChord* test = static_cast<MajChord*>(tmp2);
    test->Accept(new dropRootVisitor);

    EXPECT_EQ(test->note1, 4);
    EXPECT_EQ(test->note2, 7);
    EXPECT_EQ(test->note3, 12);
    EXPECT_EQ(test->note4, 16);

}

TEST(CombinationSet, DropDecMajC4) {
    chord* tmp = new chord("C4");
    chord* cMaj = tmp->chordFactory(maj);
    chord* tmp2 = new sixChord(cMaj);
    
    MajChord* test = static_cast<MajChord*>(tmp2);
    test->Accept(new dropRootVisitor);

    EXPECT_EQ(test->note1, 40);
    EXPECT_EQ(test->note2, 55);
    EXPECT_EQ(test->note3, 60);
    EXPECT_EQ(test->note4, 64);

}

TEST(CombinationSet, Rem4DropDecMajC4) {
    chord* tmp = new chord("C4");
    chord* cMaj = tmp->chordFactory(maj);
    chord* tmp2 = new sixChord(cMaj);
    
    MajChord* test = static_cast<MajChord*>(tmp2);
    test->Accept(new dropRootVisitor);
    test->Accept(new remove4Visitor);

    EXPECT_EQ(test->note1, 40);
    EXPECT_EQ(test->note2, 55);
    EXPECT_EQ(test->note3, 60);
    EXPECT_EQ(test->note4, -1);

}


#endif //__DECORATOR_TESTS_HPP__
