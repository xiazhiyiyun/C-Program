#include <iostream>
using namespace std;

bool fibon_elem(int pos,int &elem);
bool fibon_print(int pos);

int main(){
    int pos;
    int elem;
    bool again = true;

    while(again){
	cout << "Please enter a position: ";
	cin >> pos;
	if( fibon_elem(pos,elem) ){
	    cout << "element " << pos
	     << " is " << elem << endl;
	    fibon_print(pos);
	}
	else{
	    cout << "Sorry, couldn't calculate element # "
	     << pos << endl;
	}
	bool enter = true;

	while(enter){
	    string res;
	    cout << "Would you try again? y/n ?";
	    cin >> res;
	    if(res == "y" || res == "Y"){
		again = true;
		enter = false;
	    }
	    else if(res == "n" || res == "N"){
		again = false;
		enter = false;
	    }
	    else{ 
		cout << "Invalid response! Please enter again. " << endl;
		enter = true;
	    }
	}
    }
}

bool fibon_elem(int pos,int &elem){
    if(pos <= 0 || pos > 1024){
	cout << "Invalid position: " << pos
	     << " -- cannot handle request!\n";
        elem = 0;
	return false;
    }
    elem = 1;
    int n_1 = 1,n_2 = 1;
    for(int ix = 3;ix <= pos;ix++){
        elem = n_1 + n_2;
	n_1 = n_2;
	n_2 = elem;
    }
    return true;
}

bool fibon_print(int pos){
    if(pos <= 0 || pos > 1024){
	cout << "Invalid position: " << pos
	     << " -- cannot print the sequence!\n";
	return false;
    }
    cout << "The Fibonacci Sequence for " << pos
         << " position: \n\t";
    switch(pos){
        default:
        case 2:
	    cout << "1 ";
        case 1:
	    cout << "1 ";
	    break;
    }
    int elem;
    int n_1 = 1,n_2 = 1;
    for(int ix = 3;ix <= pos;ix++){
        elem = n_1 + n_2;
	n_1 = n_2;
	n_2 = elem;
	cout << elem << ( !(ix % 10) ? "\n\t":" ") ;
    }
    cout << endl;
    return true;
}
