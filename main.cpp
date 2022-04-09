#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <regex>
#include <cctype>

#if defined(WITH_GTEST)
#include <gtest/gtest.h>
#endif

bool is_number(const std::string &str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

void tokenize(const std::string &str, const char* delim,
            std::vector<int> &out, int count)
{
    char *token = strtok(const_cast<char*>(str.c_str()), delim);
    while (token != nullptr)
    {
        out.push_back(std::stoi(std::string(token)));
        token = strtok(nullptr, delim);
		count --;
		if(count == 0)
			break;
    }
}

unsigned int add_all_function(const std::string &input, int count)
{	
	const char* delim = " ";
	std::vector<int> out;
    tokenize(input, delim, out, count);

	unsigned int total = 0;
	unsigned int total_cost = 0;
	while(out.size() > 1){
		std::sort(out.begin(), out.end(), std::less<int>());
		total = out[0] + out[1];
		out.erase(out.begin(),out.begin()+2);
		out.push_back(total);
		total_cost = total_cost + total;
    }
    return total_cost;
}

void solve_uva_problem(std::istream &is, std::ostream &os)
{
	while(1){
		std::string input;
		std::getline(is, input);
		if ((input == "0") || !is_number(input))
			return;

		int amount = std::stoi(input);
		std::getline(is, input);

		unsigned int cost = add_all_function(input, amount);
		os << cost << std::endl;
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
