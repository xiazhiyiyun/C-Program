#include <string>

using namespace std;

class StringLen {
public:
     bool operator() (const string &s1,const string &s2) {
	return s1.size() < s2.size();
    }
};
