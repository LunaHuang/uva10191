#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <regex>
#include <cctype>
#include <map>

#if defined(WITH_GTEST)
#include <gtest/gtest.h>
#endif

class WorkTimeCmp
{
//typedefs
public:

public:
	WorkTimeCmp(){
}
// methods
public:

// data
private:
	std::pair<int, int>worktimep_;
};

typedef std::map<int, int> TimeMap;

std::pair<int, int> get_work_time(std::string line)
{
	std::string delimiter = " ";
	size_t pos = line.find(delimiter);
	std::string time = line.substr(0, pos);
    int hh, mm;
	std::pair<int, int>p;
	sscanf(time.c_str(),"%d:%d",&hh,&mm);
    p.first = hh * 60 + mm;
    line.erase(0, pos + delimiter.length());
	pos = line.find(delimiter);
	time = line.substr(0, pos);
	sscanf(time.c_str(),"%d:%d",&hh,&mm);
    p.second = hh * 60 + mm;
	return p;
}

std::string longest_nap_function(std::istream &is, int num)
{
	TimeMap map;
    while(num){
		std::string line;
		std::getline(is, line);
		map.insert(get_work_time(line));
		num--;
	}

    for(const auto& m : map)
        std::cout<<m.first<<","<<m.second<<std::endl;

	std::string nap ;//= counter_nap_time();
	return nap;
}

void solve_uva_problem(std::istream &is, std::ostream &os)
{
    int day = 0;
	while(1){
		std::string line;
		std::getline(is, line);
		if( line.length() == 0 )
			break;
        int line_num = std::stoi(line);
		day++;
		std::string nap_string = longest_nap_function(is, line_num);
		std::string nap; //= "Day #" << std::to_string(day) << (std::string)": " << nap_string;
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
