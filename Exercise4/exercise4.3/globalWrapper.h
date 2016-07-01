#include <string>

using namespace std;

class globalWrapper {
    public:
        static string program_name() {
	    return _program_name;
	} 
	static string version_stamp() {
	    return _version_stamp;
	}
	static int version_number() {
	    return _version_number;
	} 
	static int tests_run() {
	    return _tests_run;
	} 
	static int tests_passed() {
	    return _tests_passed;
	}
        
        static void program_name(string program_name) {
	    _program_name = program_name;
	} 
	static void version_stamp(string version_stamp) {
	    _version_stamp = version_stamp;
	}
	static void version_number( int version_number) {
	    _version_number = version_number;
	} 
	static void tests_run( int tests_run) {
	    _tests_run = tests_run;
	} 
	static void tests_passed(int tests_passed) {
	    _tests_passed = tests_passed;
	}
    private:
        static string _program_name;
	static string _version_stamp;
	static int _version_number;
	static int _tests_run;
	static int _tests_passed;
}
