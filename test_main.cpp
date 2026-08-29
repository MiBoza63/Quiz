#include <gtest/gtest.h>

int add(int a, int b) {
    return a + b;
}

TEST(MathTest, AddsTwoPositives) {
    EXPECT_EQ(add(2, 3), 5);
}

TEST(MathTest, AddsNegatives) {
    EXPECT_EQ(add(-2, -3), -5);
}