#ifndef UTTERM_H
#define UTTERM_H

#include "atom.h"
#include "variable.h"
#include "number.h"

//test Number.value()
TEST (Number,ctor) {
    Number n(10);
    ASSERT_EQ("10", n.value());
}
//test Number.symbol()
TEST (Number, symbol) {
    Number n(10);
    ASSERT_EQ("10", n.symbol());
}
//?- 25=25.
//true.
TEST (Number, matchSuccess) {
    Number n1(25);
    Number n2(25);
    ASSERT_TRUE(n1.match(n2));
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
    Number n1(25);
    Number n2(0);
    ASSERT_FALSE(n1.match(n2));
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {
    Number n(25);
    Atom a("tom");
    ASSERT_FALSE(n.match(a));
}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar) {
    Number n(25);
    Variable x("X");
    ASSERT_TRUE(n.match(x));
}

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant) {
    Atom tom("tom");
    Number n(25);
    ASSERT_FALSE(tom.match(n));
}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {
    Atom tom("tom");
    Variable x("X");
    ASSERT_TRUE(tom.match(x));
}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
    Atom tom("tom");
    Variable x("X");
    EXPECT_TRUE(x.match(tom));
    EXPECT_TRUE(tom.match(x));
}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {
    Atom tom("tom");
    Atom jerry("jerry");
    Variable x("X");
    EXPECT_TRUE(x.match(jerry));
    EXPECT_FALSE(tom.match(x));
}

// ?- X = 5.
// X = 5.
TEST (Var, matchSuccessToNumber) {
    Number n(5);
    Variable x("X");
    ASSERT_TRUE(x.match(n));
}

// ?- X=25, X= 100.
// false.
TEST (Var, matchFailureToTwoDiffNumbers) {
    Number n1(25);
    Number n2(100);
    Variable x("X");
    EXPECT_TRUE(x.match(n1));
    EXPECT_FALSE(x.match(n2));
}

// ?- X=tom, X= 25.
// false.
TEST (Var, matchSuccessToAtomThenFailureToNumber) {
    Atom tom("tom");
    Number n(25);
    Variable x("X");
    EXPECT_TRUE(x.match(tom));
    EXPECT_FALSE(x.match(n));
}
//?- tom=X, 25=X.
//false.
TEST (Var, matchSuccessToAtomThenFailureToNumber2) {
    Atom tom("tom");
    Number n(25);
    Variable x("X");
    EXPECT_TRUE(tom.match(x));
    EXPECT_FALSE(n.match(x));
}
//?- X=tom, X=tom.
//true.
TEST(Var, reAssignTheSameAtom){
    Atom tom("tom");
    Variable x("X");
    ASSERT_TRUE(x.match(tom));
    ASSERT_TRUE(x.match(tom));
}
#endif
