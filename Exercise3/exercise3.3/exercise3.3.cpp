#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

typedef vector<string> vstring;

void populate_map(ifstream&,map<string,vstring>&);
void display_map( const map<string,vstring>&,ostream&);
void query_map(const string&,const map<string,vstring>&);

int main(){
    ifstream ifile("exercise3.3.in");

    if(!ifile){
        cerr << "\nUnable to open file. -- Bailing out!\n";
	return -1;
    }

    map<string,vstring> families;

    populate_map(ifile,families);

    string name;

    while(1){

        cout << "\nPlease enter a family name or q to quit : ";
	cin >> name;
	if(name == "q"){
	    break;
	}
	query_map(name,families);
    }

    display_map(families,cout);
}

void populate_map(ifstream &ifile,map<string,vstring> &families){

    typedef vector<string> vstring;
    string textline;
    while( getline(ifile,textline) ){
        string fam_name;
	vector<string> child;
	string::size_type
	    pos =0,prev_pos = 0,text_size = textline.size();

	while( ( pos = textline.find_first_of(' ',pos) ) != string::npos ){

	    string::size_type end_pos = pos - prev_pos;

	    if(!prev_pos){
	        fam_name = textline.substr( prev_pos,end_pos );
	    }
	    else
	        child.push_back(textline.substr( prev_pos,end_pos ));
	    prev_pos = ++pos;
	}
	
	if(prev_pos < text_size)
	        child.push_back(textline.substr( prev_pos,text_size - prev_pos ));
	
	if(!families.count( fam_name ))
	    families[fam_name] = child;
	else cerr << "Oops! We already have a " 
	          << fam_name << " family in our map!\n";
    }
}

void display_map( const map<string,vstring> &families,ostream &os){
    map<string,vstring>::const_iterator fam_it = families.begin();
    map<string,vstring>::const_iterator fam_it_end = families.end();

    while( fam_it != fam_it_end ){
        os << "\nThe " << fam_it->first << " family ";
	if(fam_it->second.empty())
	    os << "has no child! " << endl;
	else{
	    os << "has " << fam_it->second.size() << " child! " << endl;
	    vector<string>::const_iterator child_it = fam_it -> second.begin();
	    vector<string>::const_iterator child_it_end = fam_it -> second.end();
	    while( child_it != child_it_end ){
	        os << *child_it << ' ';
		child_it++;
	    }
	    os << endl;
	}
	fam_it++;
    }
}

void query_map(const string &family,const map<string,vstring> &families){

    map<string,vstring>::const_iterator fam_it = families.find(family);

    if(fam_it == families.end()){
        cout << "\nSorry. The " << family
	     << " is not currently entered." << endl;
	return;
    }

    cout << "The " << family << "has " 
         << fam_it->second.size() << " child! " << endl;

    vector<string>::const_iterator child_it = fam_it -> second.begin();
    vector<string>::const_iterator child_it_end = fam_it -> second.end();

    while( child_it != child_it_end ){
	cout << *child_it << ' ';
	child_it++;
    }
    cout << endl;
}
