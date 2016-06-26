#include <map>
#include <set>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void initialize_exclusion_set( set<string> &);
void process_file( map<string,int> &,const set<string> &, ifstream &);
void user_query( const map<string,int> &);
void display_word_count( const map<string,int>&,ofstream &);
//void display_word_count(const map<string,int> &word_map,ofstream &os);

int main(){
    ifstream ifile("txt");
    ofstream ofile("out");
    if( !ifile || !ofile){
        cerr<<"Unable to open file -- bailng out!\n";
	return -1;
    }

    set<string> exclude_set;
    initialize_exclusion_set( exclude_set );

    map<string,int> word_count;

    process_file( word_count,exclude_set,ifile);
    user_query(word_count);
    display_word_count(word_count,ofile);
}

void initialize_exclusion_set( set<string> &exs){
    static string _exclude[6] = {"a","an","the","but","or","and"};
    exs.insert(_exclude,_exclude+6);
}

void process_file( map<string,int> &words_count,const set<string> &exs, ifstream &ifile){
    string word;
    while(ifile >> word){
        if( exs.count( word ))
	    continue;
	words_count[word]++;
    }
}

void user_query( const map<string,int> &words_count){
    string search_word;
    cout << "Please enter a word to seach (q to quit) : ";
    cin >> search_word;
    cout << endl;

    while(search_word.size() && search_word != "q"){
        
	map<string,int>::const_iterator it;
	if( ( it = words_count.find( search_word ) ) != words_count.end() ){
	    
	    cout << "Found! " << it -> first
	         << " occurs " << it -> second
		 << " times." << endl;
	}
  	else cout << search_word << " was  not found in text." << endl;
	cout << "\n Another searh? (q to quit): ";
	cin >> search_word;
        cout << endl;
    }
}

void display_word_count(const map<string,int> &word_map,ofstream &os){

    map<string,int>::const_iterator it = word_map.begin();
    for(;it != word_map.end();it++ ){
        os << it -> first << " ( "
	     << it -> second << " ) " << endl;
    }
    os << endl;
}
