#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main(){
    const int nm_size = 128;
    char user_name[nm_size];
    cout << "Please input your name: " << endl;
    cin >> setw( nm_size ) >> user_name;

    switch(strlen(user_name)){
        case 0:
	    cout << "Ah, the user with no name. "
	    	 << "Well, ok, hi, user with no name. " << endl;
	    break;
	case 1:
	    cout << "A 1-character name? Hmm, have you read Kafka?; "
	         << "hello, " << user_name << endl;
	    break;
	case 127:
	    cout << "That is a very big name,indeed -- "
	         << "we main have needed to shorten it!\n"
		 << "In any case, \n";
	default:
	    cout << "Hello, " << user_name
	         << " -- happy to make your acquaintance! " << endl;
	    break;
    }
    return 0;
}
