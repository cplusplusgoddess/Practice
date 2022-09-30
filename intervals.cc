#include <algorithm>
#include <vector>
#include <iostream>
#include "print.hh"
#define MAX(a,b)((a>b)?a:b)

using namespace std;
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }

	vector<vector<int>> merge(vector<vector<int>>& intervals) {
    size_t N = intervals.size();
    if( N <= 1)
          return(intervals);

    vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end(), compare);
          // [] (const std::vector<int> &a, const std::vector<int> &b)
          // {
              // return a[0] < b[0];
          // });
        int s = intervals[0][0] ;
        int end = intervals[0][1] ;
        for( auto i = 1; i < N; i++){
			vector<int> next = intervals[i];
			if( next[1] > end ){ //下一个区间和现在的不重叠
				ret.push_back(vector<int>{s,end});
				s = next[0];
				end = next[1];
            } else //重叠，更新e
				end = MAX(end, next[1]);
		}	
		ret.push_back(vector<int>{s,end});
        return(ret);

    }

int main(){

   printer <vector<int>> p;
   vector<vector<int>> test = {{2,3},{4,5},{6,7},{8,9},{1,10}};
   //vector<vector<int>> test = { {1,3},{2,6},{8,10},{15,18} };
   cout << "intervals before merge\n";
   for( int i = 0; i < test.size(); i++)
		p.print("\t", test[i]);
    test = 	merge(test);
   cout << "Matrix after merge\n";
   for( int i = 0; i < test.size(); i++)
		p.print("\t", test[i]);

	return(0);
}
