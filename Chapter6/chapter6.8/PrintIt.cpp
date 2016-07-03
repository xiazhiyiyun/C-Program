#include <string>
#include <iostream>

using namespace std;

class PrintIt
{
public:
    PrintIt( ostream &os  ):_os(os) {}

    template<typename elemType>
    void print(const elemType &elem, char delimiter = '\n'){
	_os << elem << delimiter;
    }
private:
    ostream& _os;
};

int main(){
    
    PrintIt to_standard_out(cout);
    to_standard_out.print(1024);
    to_standard_out.print("string");
    string my = "my_string";
    to_standard_out.print(my);
}
