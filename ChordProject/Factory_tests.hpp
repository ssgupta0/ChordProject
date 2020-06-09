

#ifndef __FACTORY_TESTS_HPP__
#define __FACTORY_TESTS_HPP__

#include "gtest/gtest.h"

#include "chordFactory.hpp"
#include "chord.hpp"
#include "chordFactory.hpp"

TEST(FactorySet, cFactory) {
    chord* tmp = new chord("C");
    
    chord* cMaj = tmp->chordFactory(maj);

    EXPECT_EQ(cMaj->note1, 0);
    EXPECT_EQ(cMaj->note2, 4);
    EXPECT_EQ(cMaj->note3, 7);
    EXPECT_EQ(cMaj->note4, 12);
}

TEST(FactorySet, dFactory) {
    chord* tmp = new chord("D");
    
    chord* cMaj = tmp->chordFactory(maj);

    EXPECT_EQ(cMaj->note1, 2);
    EXPECT_EQ(cMaj->note2, 6);
    EXPECT_EQ(cMaj->note3, 9);
    EXPECT_EQ(cMaj->note4, 14);
}

TEST(FactorySet, dbFactory) {
    chord* tmp = new chord("Db");
    
    chord* cMaj = tmp->chordFactory(maj);

    EXPECT_EQ(cMaj->note1, 1);
    EXPECT_EQ(cMaj->note2, 5);
    EXPECT_EQ(cMaj->note3, 8);
    EXPECT_EQ(cMaj->note4, 13);
}

TEST(FactorySet, eFactory) {
    chord* tmp = new chord("E");
    
    chord* cMaj = tmp->chordFactory(maj);

    EXPECT_EQ(cMaj->note1, 4);
    EXPECT_EQ(cMaj->note2, 8);
    EXPECT_EQ(cMaj->note3, 11);
    EXPECT_EQ(cMaj->note4, 16);
}

TEST(FactorySet, fFactory) {
    chord* tmp = new chord("F");
    
    chord* cMaj = tmp->chordFactory(maj);

    EXPECT_EQ(cMaj->note1, 5);
    EXPECT_EQ(cMaj->note2, 9);
    EXPECT_EQ(cMaj->note3, 12);
    EXPECT_EQ(cMaj->note4, 17);
}

TEST(FactorySet, gFactory) {
    chord* tmp = new chord("G");
    
    chord* cMaj = tmp->chordFactory(maj);

    EXPECT_EQ(cMaj->note1, 7);
    EXPECT_EQ(cMaj->note2, 11);
    EXPECT_EQ(cMaj->note3, 14);
    EXPECT_EQ(cMaj->note4, 19);
}

TEST(FactorySet, aSharpFactory) {
    chord* tmp = new chord("A#");
    
    chord* cMaj = tmp->chordFactory(maj);

    EXPECT_EQ(cMaj->note1, 10);
    EXPECT_EQ(cMaj->note2, 14);
    EXPECT_EQ(cMaj->note3, 17);
    EXPECT_EQ(cMaj->note4, 22);
}

TEST(FactorySet, cFactoryMin) {
    chord* tmp = new chord("C");
    
    chord* Min = tmp->chordFactory(min);

    EXPECT_EQ(Min->note1, 0);
    EXPECT_EQ(Min->note2, 3);
    EXPECT_EQ(Min->note3, 7);
    EXPECT_EQ(Min->note4, 12);
}

TEST(FactorySet, dFactoryMin) {
    chord* tmp = new chord("D");
    
    chord* Min = tmp->chordFactory(min);

    EXPECT_EQ(Min->note1, 2);
    EXPECT_EQ(Min->note2, 5);
    EXPECT_EQ(Min->note3, 9);
    EXPECT_EQ(Min->note4, 14);
}

TEST(FactorySet, dbFactoryMin) {
    chord* tmp = new chord("Db");
    
    chord* Min = tmp->chordFactory(min);

    EXPECT_EQ(Min->note1, 1);
    EXPECT_EQ(Min->note2, 4);
    EXPECT_EQ(Min->note3, 8);
    EXPECT_EQ(Min->note4, 13);
}

TEST(FactorySet, eFactoryMin) {
    chord* tmp = new chord("E");
    
    chord* Min = tmp->chordFactory(min);

    EXPECT_EQ(Min->note1, 4);
    EXPECT_EQ(Min->note2, 7);
    EXPECT_EQ(Min->note3, 11);
    EXPECT_EQ(Min->note4, 16);
}

TEST(FactorySet, fFactoryMin) {
    chord* tmp = new chord("F");
    
    chord* Min = tmp->chordFactory(min);

    EXPECT_EQ(Min->note1, 5);
    EXPECT_EQ(Min->note2, 8);
    EXPECT_EQ(Min->note3, 12);
    EXPECT_EQ(Min->note4, 17);
}

TEST(FactorySet, gFactoryMin) {
    chord* tmp = new chord("G");
    
    chord* Min = tmp->chordFactory(min);

    EXPECT_EQ(Min->note1, 7);
    EXPECT_EQ(Min->note2, 10);
    EXPECT_EQ(Min->note3, 14);
    EXPECT_EQ(Min->note4, 19);
}

TEST(FactorySet, aSharpFactoryMin) {
    chord* tmp = new chord("A#");
    
    chord* Min = tmp->chordFactory(min);

    EXPECT_EQ(Min->note1, 10);
    EXPECT_EQ(Min->note2, 13);
    EXPECT_EQ(Min->note3, 17);
    EXPECT_EQ(Min->note4, 22);
}





#endif //__FACTORY_TESTS_HPP__
