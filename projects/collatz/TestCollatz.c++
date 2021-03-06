// ------------------------------------
// projects/c++/collatz/TestCollatz.c++
// Copyright (C) 2017
// Glenn P. Downing
// ------------------------------------

// https://github.com/google/googletest
// https://github.com/google/googletest/blob/master/googletest/docs/Primer.md
// https://github.com/google/googletest/blob/master/googletest/docs/AdvancedGuide.md

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// ----
// read
// ----

TEST(CollatzFixture, read) {
    istringstream r("10\n");
    const int n = collatz_read(r);
    ASSERT_EQ(10, n);}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
    const int m = collatz_eval(10);
    ASSERT_EQ(10, m);}

TEST(CollatzFixture, eval_2) {
    const int m = collatz_eval(15);
    ASSERT_EQ(15, m);}

TEST(CollatzFixture, eval_3) {
    const int m = collatz_eval(20);
    ASSERT_EQ(20, m);}

// -----
// print
// -----

TEST(CollatzFixture, print) {
    ostringstream w;
    collatz_print(w, 10);
    ASSERT_EQ("10\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream r("3\n10\n15\n20\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("10\n15\n20\n", w.str());}
