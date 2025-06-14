// Copyright 2022
// By Dr. Rykalova
// Editted by Dr. Daly
// test.cpp for PS1a
// updated 5/12/2022

#include <iostream>
#include <string>

#include "FibLFSR.hpp"
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testStepInstr1) {
    FibLFSR l("1011011000110110");
    BOOST_REQUIRE_EQUAL(l.step(), 0);
    BOOST_REQUIRE_EQUAL(l.step(), 0);
    BOOST_REQUIRE_EQUAL(l.step(), 0);
    BOOST_REQUIRE_EQUAL(l.step(), 1);
    BOOST_REQUIRE_EQUAL(l.step(), 1);
    BOOST_REQUIRE_EQUAL(l.step(), 0);
    BOOST_REQUIRE_EQUAL(l.step(), 0);
    BOOST_REQUIRE_EQUAL(l.step(), 1);
}

BOOST_AUTO_TEST_CASE(testStepInstr2) {
    FibLFSR l2("1011011000110110");
    BOOST_REQUIRE_EQUAL(l2.generate(9), 51);
}

BOOST_AUTO_TEST_CASE(stepTest) {
    FibLFSR lfsr("1010101010101010");
    int newBit = lfsr.step();
    int testBit;
    BOOST_CHECK(newBit == testBit);
}

BOOST_AUTO_TEST_CASE(generateTest) {
    FibLFSR lfsr("1010101010101010");
    for (int i = 0; i < 10; i++) {
        int testBits = lfsr.generate(0);
        BOOST_CHECK(testBits == 0);
    }
    FibLFSR lfsr2("1010101010101010");
    for (int i = 0; i < 10; i++) {
        int extractedBits = lfsr2.generate(1);
        BOOST_CHECK(extractedBits == 1 || extractedBits == 0);
    }
}

BOOST_AUTO_TEST_CASE(stepStateTest) {
    FibLFSR flfsr("1011011000110110");
    std::string expected_states[] = {
          "0110110001101100",
          "1101100011011000",
          "1011000110110000",
          "0110001101100001",
          "1100011011000011",
          "1000110110000110",
          "0001101100001100",
          "0011011000011001",
          "0110110000110011",
          "1101100001100110"
    };
    for (int i = 0; i < 10; i++) {
        flfsr.step();
        BOOST_CHECK_EQUAL(flfsr, expected_states[i]);
    }
}

BOOST_AUTO_TEST_CASE(testStepFirstReturnBit) {
    FibLFSR flfsr("1010101010101010");
    int newBit = flfsr.step();
    BOOST_CHECK(newBit == 0);
}
