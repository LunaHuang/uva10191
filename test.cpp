#include <gtest/gtest.h>
#include <sstream>
#include <fstream>
#include "main.cpp"

TEST(TestCase1, Solution) {
  auto Solve = [](std::istream& is) -> std::string {
    std::ostringstream oss;
    solve_uva_problem(is,oss);
    return std::string("\n") + oss.str();
  };
  {
    std::stringstream fake_cin;
    fake_cin << R"(4
10:00 12:00 Lectures
12:00 13:00 Lunch, like always.
12:00 12:05 Boring lectures...
15:30 17:45 Reading
)";

    EXPECT_EQ(
        R"(
Day #1: the longest nap starts at 13:00 and will last for 2 hours and 30 minutes.
)",
Solve(fake_cin));
  }
}

TEST(TestCase2, Solution) {
  auto Solve = [](std::istream& is) -> std::string {
    std::ostringstream oss;
    solve_uva_problem(is,oss);
    return std::string("\n") + oss.str();
  };
  {
    std::stringstream fake_cin;
    fake_cin << R"(5
12:01 13:00 Meeting with Lucius Fox
13:00 15:00 Repairing batmobile
15:30 15:31 Posing for Financial Times
11:00 12:00 Exercise
12:00 12:01 Owning Joker
)";

    EXPECT_EQ(
        R"(
Day #1: the longest nap starts at 15:31 and will last for 2 hours and 29 minutes.
)",
Solve(fake_cin));
  }
}

TEST(TestCase3, Solution) {
  auto Solve = [](std::istream& is) -> std::string {
    std::ostringstream oss;
    solve_uva_problem(is,oss);
    return std::string("\n") + oss.str();
  };
  {
    std::stringstream fake_cin;
    fake_cin << R"(4
10:00 12:00 Lectures
12:00 13:00 Lunch, like always.
13:00 15:00 Boring lectures...
15:30 17:45 Reading
4
10:00 12:00 Lectures
12:00 13:00 Lunch, just lunch.
13:00 15:00 Lectures, lectures... oh, no!
16:45 17:45 Reading (to be or not to be?)
4
10:00 12:00 Lectures, as everyday.
12:00 13:00 Lunch, again!!!
13:00 15:00 Lectures, more lectures!
15:30 17:15 Reading (I love reading, but should I schedule it?)
1
12:00 13:00 I love lunch! Have you ever noticed it? :)
)";

    EXPECT_EQ(
        R"(
Day #1: the longest nap starts at 15:00 and will last for 30 minutes.
Day #2: the longest nap starts at 15:00 and will last for 1 hours and 45 minutes.
Day #3: the longest nap starts at 17:15 and will last for 45 minutes.
Day #4: the longest nap starts at 13:00 and will last for 5 hours and 0 minutes.
)",
Solve(fake_cin));
  }
}
