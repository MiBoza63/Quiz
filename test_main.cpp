#include <gtest/gtest.h>

struct Foo{
    int a = 2;
    int b = 4;
};

TEST(SanityCheck, BasicMath) {
    EXPECT_EQ(2 + 2, 5) << "Basic addition is broken";
    ASSERT_EQ(1, 12) << "This checks if one equals two — expected to fail";
}

// TEST(SanityCheck, BasicMath) {
//     Foo bar;
//     EXPECT_EQ(2 + 2, 4);    // Numerical Test
//     EXPECT_EQ(bar.a, 6);    // Object test
// }

TEST(SanityCheck, StringCompare) {
    EXPECT_STREQ("hello", "hello");
}
