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

class WorkTime
{
// typedefs
public:
    struct occurrence_t
    {
		int m_start;
		int m_end;

        // disable default constructor
        occurrence_t() = delete;
        occurrence_t(int start, int end)
			:m_start(start), m_end(end)
        { }
    };

public:
	std::map<int, int> const & map() const { return occurrences_; }
    std::vector<occurrence_t> to_vector() const
    {
        std::vector<occurrence_t> result;
        for (const auto & element : occurrences_)
        {
            result.push_back(occurrence_t{element.first, element.second});
        }
        return result;
    }

    WorkTime & operator<<(const std::string & line)
    {
		int hh, mm;
		size_t pos = line.find(" ");
		std::string time = line.substr(0, pos);
		sscanf(time.c_str(),"%d:%d",&hh,&mm);
		int first = hh * 60 + mm;
		time = line.substr(pos + 1, pos);
		sscanf(time.c_str(),"%d:%d",&hh,&mm);
		int second = hh * 60 + mm;

		for (auto& it : occurrences_) {
			if ((it.first == first) && (it.second > second)) {
                occurrences_.erase(first);
				second = it.second;
				break;
			}
			if (it.second == first) {
                occurrences_.erase(first);
				first = it.first;
				break;
			}
			if ((it.second > first) && (it.second < second)){
                occurrences_.erase(first);
				first = it.first;
				break;
			}
			if ((it.first < first) && (it.second > second))
				return *this;
		}

		if(first != second)
			occurrences_[first] = second;

        return *this;
    }

// data
private:
    std::map<int, int> occurrences_;
};

#define DAY_START 600
#define DAY_END 1080
struct NAP_TimeData {
	int nap_start;
	int nap_total;
};

std::string counter_nap_time(std::map<int, int> const & map)
{
	int last_end = 0;
	int count = 0;
	int tmp_nap;
	struct NAP_TimeData nap = {DAY_START,0};

    for (auto m = map.cbegin(); count != map.size(); ++m, ++count){
//std::cout << m->first << ":" << m->second << std::endl;
		if( m == map.cbegin() ){
			tmp_nap = m->first - DAY_START;
			if(tmp_nap > nap.nap_total){
				nap.nap_total = tmp_nap;
			}
		} else {
			tmp_nap = m->first - last_end;
			if(tmp_nap > nap.nap_total){
				nap.nap_total = tmp_nap;
				nap.nap_start = last_end;
			}
		}
		last_end = m->second;
		if( count == (map.size()-1) ){
			tmp_nap = DAY_END - m->second;
			if(tmp_nap > nap.nap_total){
				nap.nap_total = tmp_nap;
				nap.nap_start = m->second;
			}
		}
	}

	char buffer [512];
	int hh = nap.nap_total/60;
	if(hh == 0)
		snprintf(buffer, sizeof(buffer), "the longest nap starts at %02d:%02d and will last for %d minutes.",nap.nap_start/60, nap.nap_start%60, nap.nap_total%60);
	else
		snprintf(buffer, sizeof(buffer), "the longest nap starts at %02d:%02d and will last for %d hours and %d minutes.",nap.nap_start/60, nap.nap_start%60, hh, nap.nap_total%60);

	std::string nap_string(buffer);
	return nap_string;
}

std::string longest_nap_function(std::istream &is, int num)
{
    WorkTime work_time;
    while(num){
		std::string line;
		std::getline(is, line);
        work_time << line;
		num--;
	}

	std::string nap = counter_nap_time(work_time.map());
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
		std::string nap = "Day #" + std::to_string(day) + (std::string)": " + nap_string;
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
