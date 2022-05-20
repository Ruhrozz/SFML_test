#include <gtest/gtest.h>

TEST(basic_check, test_eq) {
    EXPECT_EQ(1, 1);
    EXPECT_EQ(1+1, 2);
    EXPECT_EQ(2 + 2 * 2, 6);
}