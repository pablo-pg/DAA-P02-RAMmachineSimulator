# include <gtest/gtest.h>

#include <string>

TEST(TemplateTestSuite, always_true) {
  EXPECT_EQ(true, true);
  EXPECT_EQ(1, 1);
  EXPECT_GT(10, 0);
}


TEST(TemplateTestSuite, string_comparison) {
  std::string test_string{"abc"};
  EXPECT_EQ("a", "a");
  EXPECT_EQ(true, "a" == "a");
  EXPECT_EQ(3, test_string.size());
}
