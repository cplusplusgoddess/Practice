//
// Permutations of a string
//
// Search for permutations/anagrams of a pattern in a string

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#define CMAX 256

bool compare(char h1[CMAX], char h2[CMAX] ){
   bool ret = true;
   for(int i = 0; i<CMAX; i++){
		if( h1[i] != h2[i]){
			ret = false;
			break;
		}
   }
   return(ret);
}

void search(string txt, string pat ){
  int M = pat.size();
  int N = txt.size();
  char patH[CMAX] = { 0 };
  char winH[CMAX] = { 0 };
  for(int i = 0; i < M; i++){
	patH[pat[i]]++;
	winH[txt[i]]++;
  }
  cout << "Found at index "  ;
  for(int win = M; win < N; win++){
    if(compare(patH, winH) == true)
		cout <<  win - M << ", ";
    winH[txt[win]]++;
	winH[txt[win-M]]--;

  }
  if(compare(patH, winH) == true)
	cout << N - M ;
  cout << endl;
}

void permute(string str){

 while(1){
	if(!next_permutation(begin(str), end(str)))
		break;
	cout << str << " ";
 }
 cout << endl;

}

int main(){
	string txt = "ABCDACCBDAAA";
	string pat = "ABCD";

	cout << "Searching for all anagrams of pattern: " << pat << " in text: "<< txt << endl;
	search( txt, pat);
	cout << "Permutations for ABC ";
	permute("ABC");
	return(0);
}

// OUTPUT:
// Searching for all anagrams of pattern: ABCD in text: ABCDACCBDAAA
// Found at index 0, 1, 6, 
// Permutations for ABC ACB BAC BCA CAB CBA 
