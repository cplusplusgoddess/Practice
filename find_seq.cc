#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

using namespace std;

typedef string OP;

bool mypredicate (OP i, OP j) {
  return (i==j);
}
list<int> find_seq(list<OP> &l , vector<OP> &pat){

    list<int> ret;
    list<OP>::iterator lpos ;
    list<OP>::iterator pos = l.begin();

    while (lpos != l.end()){

       lpos = search(pos, l.end(), pat.begin(), pat.end(), mypredicate );// <---
       // fpos = find_first_of(pos, l.end(), pat.begin(), pat.end() );// <---

      // NOTE: might need a bool compare function at the end depending on our OP
        if (lpos != l.end()) {
            ret.push_back(distance(l.begin(), lpos));
            cout << "pos: " << distance(l.begin(), lpos) << endl;
            // ret.push_back(fpos);
		}
		pos ++;
    }
    ret.unique();
    return(ret);
}

int main(){
	list<OP> in  = { "sigmoid", "relu", "tanh", "sigmoid", 
					"relu", "relu", "tanh", "sigmoid", "relu", "sigmoid"};


    vector<OP> pat = {"relu", "sigmoid" };

	list<int> matches = find_seq(in, pat);
	cout << "For pattern:  " ;
	for( auto i = 0 ; i < pat.size(); i++ )
		cout << pat[i] << " " ;
	cout << "\nin list:  " ;
	for( auto i = in.begin() ; i != in.end(); i++ )
		cout << *i << " " ;
	cout << "\nMatches at pos:  " ;
	for( auto i = matches.begin() ; i != matches.end(); i++ )
		cout << *i << " " ;
	cout << endl;
	return(0);
}
