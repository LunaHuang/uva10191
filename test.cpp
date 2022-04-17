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

TEST(TestCase4, Solution) {
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


#if 1
TEST(TestCase5, Solution) {
  auto Solve = []() -> std::string {
    std::ifstream fs("./data1");
    std::ostringstream oss;
    solve_uva_problem(fs,oss);
    return std::string("\n") + oss.str();
  };
  {
    EXPECT_EQ(
	R"(
Day #1: the longest nap starts at 10:00 and will last for 1 hours and 20 minutes.
Day #2: the longest nap starts at 10:00 and will last for 22 minutes.
Day #3: the longest nap starts at 10:00 and will last for 16 minutes.
Day #4: the longest nap starts at 10:00 and will last for 14 minutes.
Day #5: the longest nap starts at 10:00 and will last for 8 minutes.
Day #6: the longest nap starts at 10:00 and will last for 2 hours and 31 minutes.
Day #7: the longest nap starts at 10:00 and will last for 16 minutes.
Day #8: the longest nap starts at 10:00 and will last for 56 minutes.
Day #9: the longest nap starts at 10:00 and will last for 44 minutes.
Day #10: the longest nap starts at 10:00 and will last for 21 minutes.
Day #11: the longest nap starts at 17:09 and will last for 51 minutes.
Day #12: the longest nap starts at 16:26 and will last for 1 hours and 34 minutes.
Day #13: the longest nap starts at 16:00 and will last for 1 hours and 9 minutes.
Day #14: the longest nap starts at 17:57 and will last for 3 minutes.
Day #15: the longest nap starts at 17:59 and will last for 1 minutes.
Day #16: the longest nap starts at 16:18 and will last for 1 hours and 42 minutes.
Day #17: the longest nap starts at 17:28 and will last for 32 minutes.
Day #18: the longest nap starts at 17:42 and will last for 18 minutes.
Day #19: the longest nap starts at 16:47 and will last for 1 hours and 13 minutes.
Day #20: the longest nap starts at 17:26 and will last for 34 minutes.
Day #21: the longest nap starts at 17:57 and will last for 3 minutes.
Day #22: the longest nap starts at 10:00 and will last for 9 minutes.
Day #23: the longest nap starts at 17:51 and will last for 9 minutes.
Day #24: the longest nap starts at 10:00 and will last for 9 minutes.
Day #25: the longest nap starts at 17:52 and will last for 8 minutes.
Day #26: the longest nap starts at 16:39 and will last for 1 hours and 21 minutes.
Day #27: the longest nap starts at 13:10 and will last for 4 hours and 50 minutes.
Day #28: the longest nap starts at 17:51 and will last for 9 minutes.
Day #29: the longest nap starts at 17:13 and will last for 47 minutes.
Day #30: the longest nap starts at 17:42 and will last for 18 minutes.
Day #31: the longest nap starts at 17:50 and will last for 10 minutes.
Day #32: the longest nap starts at 10:00 and will last for 24 minutes.
Day #33: the longest nap starts at 10:00 and will last for 5 hours and 30 minutes.
Day #34: the longest nap starts at 10:00 and will last for 14 minutes.
Day #35: the longest nap starts at 10:00 and will last for 16 minutes.
Day #36: the longest nap starts at 17:45 and will last for 15 minutes.
Day #37: the longest nap starts at 17:46 and will last for 14 minutes.
Day #38: the longest nap starts at 10:00 and will last for 2 minutes.
Day #39: the longest nap starts at 10:00 and will last for 17 minutes.
Day #40: the longest nap starts at 17:50 and will last for 10 minutes.
Day #41: the longest nap starts at 10:00 and will last for 18 minutes.
Day #42: the longest nap starts at 10:00 and will last for 20 minutes.
Day #43: the longest nap starts at 17:55 and will last for 5 minutes.
Day #44: the longest nap starts at 10:00 and will last for 23 minutes.
Day #45: the longest nap starts at 17:55 and will last for 5 minutes.
Day #46: the longest nap starts at 17:31 and will last for 29 minutes.
Day #47: the longest nap starts at 10:00 and will last for 13 minutes.
Day #48: the longest nap starts at 10:00 and will last for 10 minutes.
Day #49: the longest nap starts at 16:38 and will last for 1 hours and 22 minutes.
Day #50: the longest nap starts at 17:47 and will last for 13 minutes.
Day #51: the longest nap starts at 17:30 and will last for 30 minutes.
Day #52: the longest nap starts at 10:00 and will last for 14 minutes.
Day #53: the longest nap starts at 17:15 and will last for 45 minutes.
Day #54: the longest nap starts at 10:00 and will last for 1 hours and 39 minutes.
Day #55: the longest nap starts at 17:52 and will last for 8 minutes.
Day #56: the longest nap starts at 10:00 and will last for 2 hours and 20 minutes.
Day #57: the longest nap starts at 10:00 and will last for 58 minutes.
Day #58: the longest nap starts at 17:00 and will last for 1 hours and 0 minutes.
Day #59: the longest nap starts at 17:41 and will last for 19 minutes.
Day #60: the longest nap starts at 16:08 and will last for 1 hours and 52 minutes.
Day #61: the longest nap starts at 10:00 and will last for 10 minutes.
Day #62: the longest nap starts at 10:00 and will last for 19 minutes.
Day #63: the longest nap starts at 17:59 and will last for 1 minutes.
Day #64: the longest nap starts at 10:00 and will last for 13 minutes.
Day #65: the longest nap starts at 17:33 and will last for 27 minutes.
Day #66: the longest nap starts at 10:00 and will last for 58 minutes.
Day #67: the longest nap starts at 10:00 and will last for 23 minutes.
Day #68: the longest nap starts at 17:18 and will last for 42 minutes.
Day #69: the longest nap starts at 10:00 and will last for 3 hours and 15 minutes.
Day #70: the longest nap starts at 10:00 and will last for 17 minutes.
Day #71: the longest nap starts at 10:00 and will last for 58 minutes.
Day #72: the longest nap starts at 10:00 and will last for 14 minutes.
Day #73: the longest nap starts at 10:00 and will last for 27 minutes.
Day #74: the longest nap starts at 17:36 and will last for 24 minutes.
Day #75: the longest nap starts at 17:34 and will last for 26 minutes.
Day #76: the longest nap starts at 10:00 and will last for 5 minutes.
Day #77: the longest nap starts at 17:26 and will last for 34 minutes.
Day #78: the longest nap starts at 10:47 and will last for 30 minutes.
Day #79: the longest nap starts at 17:36 and will last for 24 minutes.
Day #80: the longest nap starts at 17:51 and will last for 9 minutes.
Day #81: the longest nap starts at 10:00 and will last for 17 minutes.
Day #82: the longest nap starts at 17:57 and will last for 3 minutes.
Day #83: the longest nap starts at 17:55 and will last for 5 minutes.
Day #84: the longest nap starts at 10:00 and will last for 2 hours and 27 minutes.
Day #85: the longest nap starts at 10:00 and will last for 23 minutes.
Day #86: the longest nap starts at 16:48 and will last for 1 hours and 12 minutes.
Day #87: the longest nap starts at 16:54 and will last for 1 hours and 6 minutes.
Day #88: the longest nap starts at 17:14 and will last for 46 minutes.
Day #89: the longest nap starts at 10:00 and will last for 26 minutes.
Day #90: the longest nap starts at 17:52 and will last for 8 minutes.
Day #91: the longest nap starts at 17:39 and will last for 21 minutes.
Day #92: the longest nap starts at 10:00 and will last for 4 minutes.
Day #93: the longest nap starts at 17:51 and will last for 9 minutes.
Day #94: the longest nap starts at 10:00 and will last for 39 minutes.
Day #95: the longest nap starts at 17:33 and will last for 27 minutes.
Day #96: the longest nap starts at 10:00 and will last for 21 minutes.
Day #97: the longest nap starts at 15:53 and will last for 2 hours and 7 minutes.
Day #98: the longest nap starts at 10:00 and will last for 7 minutes.
Day #99: the longest nap starts at 10:00 and will last for 11 minutes.
Day #100: the longest nap starts at 17:47 and will last for 13 minutes.
Day #101: the longest nap starts at 10:00 and will last for 12 minutes.
Day #102: the longest nap starts at 17:52 and will last for 8 minutes.
Day #103: the longest nap starts at 10:00 and will last for 55 minutes.
Day #104: the longest nap starts at 17:24 and will last for 36 minutes.
Day #105: the longest nap starts at 15:40 and will last for 2 hours and 20 minutes.
Day #106: the longest nap starts at 10:00 and will last for 10 minutes.
Day #107: the longest nap starts at 17:54 and will last for 6 minutes.
Day #108: the longest nap starts at 10:00 and will last for 7 minutes.
Day #109: the longest nap starts at 14:33 and will last for 3 hours and 27 minutes.
Day #110: the longest nap starts at 10:00 and will last for 4 minutes.
Day #111: the longest nap starts at 10:00 and will last for 3 hours and 2 minutes.
Day #112: the longest nap starts at 10:00 and will last for 7 minutes.
Day #113: the longest nap starts at 17:53 and will last for 7 minutes.
Day #114: the longest nap starts at 10:00 and will last for 1 hours and 52 minutes.
Day #115: the longest nap starts at 10:00 and will last for 35 minutes.
Day #116: the longest nap starts at 10:00 and will last for 11 minutes.
Day #117: the longest nap starts at 17:47 and will last for 13 minutes.
Day #118: the longest nap starts at 10:00 and will last for 3 minutes.
Day #119: the longest nap starts at 10:00 and will last for 3 minutes.
Day #120: the longest nap starts at 10:00 and will last for 10 minutes.
Day #121: the longest nap starts at 10:00 and will last for 27 minutes.
Day #122: the longest nap starts at 10:00 and will last for 38 minutes.
Day #123: the longest nap starts at 10:00 and will last for 6 minutes.
Day #124: the longest nap starts at 17:58 and will last for 2 minutes.
Day #125: the longest nap starts at 17:17 and will last for 43 minutes.
Day #126: the longest nap starts at 10:00 and will last for 19 minutes.
Day #127: the longest nap starts at 10:00 and will last for 11 minutes.
Day #128: the longest nap starts at 15:16 and will last for 27 minutes.
)",
Solve());
  }
}
#endif
