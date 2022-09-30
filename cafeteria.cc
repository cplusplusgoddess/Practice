#include <vector>
#include <algorithm>
#include <iostream>
#include <print.hh>
using namespace std;
// Write any include statements here



long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S) {
  // Write your code here
  long long totalM = 0;
  std::sort(S.begin(), S.end());
  if(S[0] != 1){
    totalM += (S[0]-1)/ (K+1) ;
   cout << "Adding beginning seats total: " << totalM << endl;
  }
      
  for(int i = 1; i < M; i++){
    totalM += ((S[i]-S[i-1]) / (K+1))-1;
    cout << "Adding middle seats total: " << totalM << endl;
  }
  
  if(S[M-1] != N){
    totalM += (N - (S[M-1]))/ (K+1);
    cout << "Adding end seats total: " << totalM << endl;
  } 

  
  return (totalM);
}

int main(){

	printer<vector<long long>> p;
	long long K = 2;
	long long N = 100;
	vector<long long> S ;
	for(auto i = 7; i < N-1; i += 2*K+5){
		S.push_back(i);
    }
	int M = S.size();
	S.push_back(N);
	M++;
	N += K + 5;
    p.print("Seating chart: ", S);
	long long diners = getMaxAdditionalDinersCount(N, K, M, S) ;
	cout << diners << " added to a table seating " << N << endl;
	return(0);

}
