#include <iostream> 
#include <map>
#include <set>
#include <string>
#include <iterator>

using namespace std;

int main(){
    map<string,int> words;
    string st;
    int exclu_size = 6;
    string exclu[] = {"a","an","or","the","and","but"};
    set<string> word_exclusion(exclu,exclu + exclu_size);
    
    while(cin >> st){
        if( word_exclusion.count(st) )
	    continue;
	words[st]++;
    }

    //find
    bool again = true;
    while(again){
        cout << "Do you want to query if the word in the map? y/n? " << endl;
        char res = 'y';
   	cin >> res;
    	bool query;

    	if(res == 'y' || res == 'Y'){
	    query = true;
	    again = false;
	}
	else if(res == 'n' || res == 'N'){
	    query = false;
	    again = false;
	}
	else {
	    cerr << "ircorrect input, please input again,y/n? " << endl;
	    again = true;
	    continue;
	}
	if(query){
	    cout << "Input the word to find: "<< endl;
	    string search_word;
	    int count;
	    cin >> search_word;
	    if(words.count( search_word ))
	        count = words[search_word];
	    cout << search_word << "is in the word. " 
	         << "count[ "<< search_word << " ]"
		 << " = " << count << endl;
	}
    }

    //display
    map<string,int>::iterator it = words.begin();
    for(;it != words.end();it++){
        cout << '\n' <<  "key: " << it->first << "\t\t"
	     << "count: " << it->second << endl;
    }
}
