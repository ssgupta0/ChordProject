

#ifndef __VISITOR_TESTS_HPP__
#define __VISITOR_TESTS_HPP__

#include "gtest/gtest.h"

#include "chordDecorator.hpp"
#include "chord.hpp"
#include "chordFactory.hpp"
#include "chordVisitor.hpp"

TEST(VisitorRemoveSet, remove1) {
    chord* tmp = new chord("A");
    
    chord* cMaj = tmp->chordFactory(maj);

    MajChord* test = static_cast<MajChord*>(cMaj);
    test->Accept(new remove1Visitor);

    EXPECT_EQ(test->note1, -1);
    EXPECT_EQ(test->note2, 13);
    EXPECT_EQ(test->note3, 16);
    EXPECT_EQ(test->note4, 21);
}

TEST(VisitorRemoveSet, remove2) {
    chord* tmp = new chord("A");
    
    chord* cMaj = tmp->chordFactory(maj);

    MajChord* test = static_cast<MajChord*>(cMaj);
    test->Accept(new remove2Visitor);

    EXPECT_EQ(test->note1, 9);
    EXPECT_EQ(test->note2, -1);
    EXPECT_EQ(test->note3, 16);
    EXPECT_EQ(test->note4, 21);
}

TEST(VisitorRemoveSet, remove3) {
    chord* tmp = new chord("A");
    
    chord* cMaj = tmp->chordFactory(maj);

    MajChord* test = static_cast<MajChord*>(cMaj);
    test->Accept(new remove3Visitor);

    EXPECT_EQ(test->note1, 9);
    EXPECT_EQ(test->note2, 13);
    EXPECT_EQ(test->note3, -1);
    EXPECT_EQ(test->note4, 21);
}

TEST(VisitorRemoveSet, remove4) {
    chord* tmp = new chord("A");
    
    chord* cMaj = tmp->chordFactory(maj);

    MajChord* test = static_cast<MajChord*>(cMaj);
    test->Accept(new remove4Visitor);

    EXPECT_EQ(test->note1, 9);
    EXPECT_EQ(test->note2, 13);
    EXPECT_EQ(test->note3, 16);
    EXPECT_EQ(test->note4, -1);
}

TEST(VisitorMoveSet, dropRoot) {
    chord* tmp = new chord("A4");
    
    chord* cMaj = tmp->chordFactory(maj);

    MajChord* test = static_cast<MajChord*>(cMaj);
    test->Accept(new dropRootVisitor);

    EXPECT_EQ(test->note1, 45);
    EXPECT_EQ(test->note2, 61);
    EXPECT_EQ(test->note3, 64);
    EXPECT_EQ(test->note4, 69);
}

TEST(VisitorMoveSet, raiseSop) {
    chord* tmp = new chord("A4");
    
    chord* cMaj = tmp->chordFactory(maj);

    MajChord* test = static_cast<MajChord*>(cMaj);
    test->Accept(new RaiseSopVisitor);

    EXPECT_EQ(test->note1, 57);
    EXPECT_EQ(test->note2, 61);
    EXPECT_EQ(test->note3, 64);
    EXPECT_EQ(test->note4, 81);
}

#endif //__VISITOR_TESTS_HPP__
