#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <regex>
#include <cctype>

#if defined(WITH_GTEST)
#include <gtest/gtest.h>
#endif

std::string longest_nap_function(std::istream &is, int num)
{
	std::string nap;

	return nap;
}

void solve_uva_problem(std::istream &is, std::ostream &os)
{
	while(1){
		std::string line;
		std::getline(is, line);
        int line_num = std::stoi(line);
		std::string nap = longest_nap_function(is, line_num);
		os << nap << std::endl;
	}
}

int main(int argc, char **argv)
{
#if !defined(WITH_GTEST)
    solve_uva_problem(std::cin, std::cout);
#else
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#endif
}
