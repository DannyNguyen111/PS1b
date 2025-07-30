// Copyright 2022
// By Dr. Rykalova
// Editted by Dr. Daly
// test.cpp for PS1a
// updated 1/8/2024

#include <iostream>
#include <string>

#include "FibLFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

using PhotoMagic::FibLFSR;

BOOST_AUTO_TEST_CASE(testStepInstr) {
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

BOOST_AUTO_TEST_CASE(testGenerateInstr) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.generate(9), 51);
}

// Test invalid constructor input: seed with invalid characters
BOOST_AUTO_TEST_CASE(testConstructorInvalidSeed) {
  BOOST_CHECK_THROW(FibLFSR("1020101010101010"), std::invalid_argument);
  BOOST_CHECK_THROW(FibLFSR("abcdefghijklmnoq"), std::invalid_argument);
  BOOST_CHECK_THROW(FibLFSR(""), std::invalid_argument);
}

// Test generate() throws on invalid k (e.g., negative or zero)
BOOST_AUTO_TEST_CASE(testGenerateInvalidK) {
  FibLFSR l("1011011000110110");
  BOOST_CHECK_THROW(l.generate(0), std::invalid_argument);
  BOOST_CHECK_THROW(l.generate(-5), std::invalid_argument);
}

// Test operator<< outputs correct string representation of the register
BOOST_AUTO_TEST_CASE(testOutputOperator) {
  FibLFSR l("1011011000110110");
  std::ostringstream oss;
  oss << l;
  BOOST_CHECK_EQUAL(oss.str(), "1011011000110110");
}

// Test multiple steps produce expected sequence
BOOST_AUTO_TEST_CASE(testMultipleSteps) {
  FibLFSR l("1011011000110110");
  // Call step 10 times and store bits
  std::string bits;
  for (int i = 0; i < 10; i++) {
    bits += std::to_string(l.step());
  }
  // Compare the bits with expected output
  BOOST_CHECK_EQUAL(bits, "0001100110");
}

