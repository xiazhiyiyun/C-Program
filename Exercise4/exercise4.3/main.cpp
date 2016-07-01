#include "globalWrapper.h"
#include <string>
#include <iostream>

using namespace std;

string globalWrapper::_program_name = "AIDS";
string globalWrapper::_version_stamp = "1.0";
int globalWrapper::_version_number = 1;
int globalWrapper::_tests_run = 10;
int globalWrapper::_tests_passed = 20;

int main(){

    cout << globalWrapper::program_name() << endl;
    cout << globalWrapper::version_stamp() << endl;
    cout << globalWrapper::version_number() << endl;
    cout << globalWrapper::tests_run() << endl;
    cout << globalWrapper::tests_passed() << endl;

    globalWrapper::program_name("IDS");
    globalWrapper::version_stamp("2.0");
    globalWrapper::version_number(2);
    globalWrapper::tests_run(20); 
    globalWrapper::tests_passed(30);

    cout << globalWrapper::program_name() << endl;
    cout << globalWrapper::version_stamp() << endl;
    cout << globalWrapper::version_number() << endl;
    cout << globalWrapper::tests_run() << endl;
    cout << globalWrapper::tests_passed() << endl;
}
