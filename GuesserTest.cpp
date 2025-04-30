/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(GuesserTest, secret_too_long){
    // 30 char str
    Guesser object("abcdfghjdkjhsgdjfhgsdfsdfdsdfdsd this should be deleted");
    string input = "abcdfghjdkjhsgdjfhgsdfsdfdsdfdsd";
    ASSERT_EQ(input, object.m_secret);
    ASSERT_FALSE("abcdfghjdkjhsgdjfhgsdfsdfdsdfdsd this should be deleted" == object.m_secret);
}

// TEST(GuesserTest, distance_test){
//     string input = "mysecret";
//     Guesser object(input);
// }
