#include <vector>
#include <string>

using namespace std;

class Stack {
public:
    bool push(const string &elem);
    bool pop( string &elem );
    bool peek( string &elem);
    bool find(const string &elem);
    int count(const string &elem);

    bool empty(){
        return _stack.empty();
    }
    bool full(){
        return _stack.size() == _stack.max_size();
    }

    int size(){
        return _stack.size();
    }
private:
    vector<string> _stack;
};
