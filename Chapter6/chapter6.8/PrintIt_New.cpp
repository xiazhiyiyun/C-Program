#include <string>
#include <iostream>

using namespace std;

template<typename OutStream>
class PrintIt_New
{
public:
    PrintIt_New( OutStream &os  ):_os(os) {}

    template<typename elemType>
    void print(const elemType &elem, char delimiter = '\n'){
	_os << elem << delimiter;
    }
private:
    OutStream & _os;
};

int main(){
    
    PrintIt_New<ostream> to_standard_out(cout);
    to_standard_out.print(1024);
    to_standard_out.print("string");
    string my = "my_string";
    to_standard_out.print(my);
}
