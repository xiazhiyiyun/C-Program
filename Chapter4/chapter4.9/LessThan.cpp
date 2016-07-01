#include "LessThan.h"

using namespace std;

inline bool LessThan::operator()(int val) const{
    return val < _val;
}
