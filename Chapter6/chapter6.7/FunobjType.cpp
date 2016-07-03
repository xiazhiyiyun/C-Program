#include <iostream>

using namespace std;

class FunObjType  
{  	
public:  
    void operator() ()  
    {  
            cout<<"Hello C++!"<<endl;  
    }  
};

class FunobjType;

int main() {
    FunObjType val;
    val();
}
