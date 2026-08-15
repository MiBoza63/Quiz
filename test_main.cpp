#include <gtest/gtest.h>

TEST(SanityCheck, BasicMath) {
    
    EXPECT_EQ(2 + 2, 4);
    EXPECT_TRUE(false);
}

TEST(SanityCheck, StringCompare) {
    EXPECT_STREQ("hello", "hello");
}   