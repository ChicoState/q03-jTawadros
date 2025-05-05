/**
 * Unit Tests for the class
 **/

#include "Guesser.h"
#include <gtest/gtest.h>

class GuesserTest : public ::testing::Test {
protected:
  GuesserTest() {}           // constructor runs before each test
  virtual ~GuesserTest() {}  // destructor cleans up after tests
  virtual void SetUp() {}    // sets up before each test (after constructor)
  virtual void TearDown() {} // clean up after each test, (before destructor)
};

TEST(GuesserTest, secret_too_long){
    // 30 char str
    Guesser object("abcdfghjdkjhsgdjfhgsdfsdfdsdfdsd this should be deleted");
    string input = "abcdfghjdkjhsgdjfhgsdfsdfdsdfdsd";
    ASSERT_TRUE(object.match(input));
}
TEST(GuesserTest, CorrectGuess) {
  Guesser object("tester");
  ASSERT_TRUE(object.match("tester"));
}
TEST(GuesserTest, InorrectGuess) {
  Guesser object("tester");
  ASSERT_FALSE(object.match("testxr"));
}
TEST(GuesserTest, BruteForceTest){
  Guesser object("tester");
  ASSERT_FALSE(object.match("asd;flkajs;dflkajsd;fk"));
  // if it locks than this should fail
  ASSERT_FALSE(object.match("tester"));
}

TEST(GuesserTest, Decrement_Remaining_Guesses) {
  Guesser object("tester");
  object.match("testar");
  ASSERT_EQ(object.remaining(), 2);
}

TEST(GuesserTest, Reset_Remaining) {
  Guesser object("tester");
  object.match("testar");
  object.match("testor");
  ASSERT_EQ(object.remaining(), 1);
  object.match("tester");  
  ASSERT_EQ(object.remaining(), 3);
}

TEST(GuesserTest, Remaining_Guesses_Locked) {
  Guesser object("tester");
  // Lock here
  object.match("wronginput");
  // Remaining still goes down according to the comments.
  object.match("wronginput");
  ASSERT_EQ(object.remaining(), 1);
}
TEST(GuesserTest, Short_Guess){
  Guesser object("tester");
  object.match("test");
  ASSERT_EQ(object.remaining(), 2);
}
// TEST(GuesserTest, distance_test){
//     string input = "mysecret";
//     Guesser object(input);
// }
