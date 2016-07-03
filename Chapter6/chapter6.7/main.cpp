#include <string>
#include <iostream>
#include "LessThan.h"
#include "LessThanPred.h"
#include "StringLen.h"

using namespace std;

int main(){
    LessThan<string> lts("yooh");

    cout << "lts.(\"library\") = " << lts("library") << endl;

    LessThanPred<string,StringLen> ltps("Pooh");

    cout << "ltps.(\"library\") = " << ltps("library") << endl;
/*
    */
    return 0;
}
