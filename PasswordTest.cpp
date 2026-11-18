/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/*
* Tests for Password::count_leading_characters()
*/
TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, long_repeating_leading_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZZZZZZZZZADJLADHLALHF");
	ASSERT_EQ(10, actual);
}

TEST(PasswordTest, leading_characters_are_case_sensitive)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AAaa");
	ASSERT_EQ(2, actual);
}

/*
* Tests for Password::has_mixed_case()
*/
TEST(PasswordTest, zero_lowercase_characters)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("AAAAAABADFKAFJA");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, zero_uppercase_characters)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("adafhdahldahfahve");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, empty_string)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, no_letters) 
{
	Password my_password;
	bool actual = my_password.has_mixed_case("21147317526065732165");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("AJlasghsfAFjsjajsdla");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, character_after_lowercase_range)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("{a");
    ASSERT_EQ(false, actual);
}