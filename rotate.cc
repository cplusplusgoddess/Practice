
// 
// Rotate a matrix clockwise
//


#include <vector>
#include "print.hh"

using namespace std;

printer <vector<int>> p;
#define SWAP(a,b)({a = a+b;b=a-b; a -= b;})

	void reverseElementsRowWise(vector<vector<int>> & matrix) {
      int N = matrix.size();
      for(int i = 0; i < N; ++i) {
          for(int j = 0; j < N / 2; ++j) {
              SWAP(matrix[i][N - j - 1], matrix[i][j]);
          }
      }
	}

  void transpose(vector<vector<int>> &matrix) {
      int N = matrix.size();
      for(int i = 0; i < N; ++i) {
         for(int j = i + 1; j < N; ++j) {
            SWAP(matrix[i][j], matrix[j][i]);
         }
      }
  }

  void rotate90(vector<vector<int>>& matrix) {
	if( (matrix.size() == 0) || (matrix.size() != matrix[0].size() ) )
		return;
		
    cout << "Matrix before rotation\n";
    for( int i = 0; i < matrix.size(); i++)
		p.print("\t", matrix[i]);
	transpose(matrix);
	reverseElementsRowWise( matrix);
    cout << "Matrix after rotation\n";
    for( int i = 0; i < matrix.size(); i++)
		p.print("\t", matrix[i]);

  }

  void rotate(vector<vector<int>>& matrix) {
    int s = matrix.size()-1;
    for(int i = 0; i<matrix.size()/2;++i)
    {
       for(int j = i; j<matrix.size()-i-1;++j)
       {
                SWAP(matrix[i][j],  matrix[s-j][i]);
                SWAP(matrix[s-j][i], matrix[s-i][s-j]);
                SWAP(matrix[s-i][s-j], matrix[j][s-i]);
       }
    }
  }
	


int main(){

	vector<vector<int>> m = { {1, 2, 3},
							  {4, 5, 6},
							  {7, 8, 9} };

    rotate90(m);
	vector<vector<int>> m2= { {1,  2,  3,  4},
							  {5,  6,  7,  8},
							  {9, 10, 11, 12},
							  {13,14, 15, 16} };

    rotate90(m2);
    return(0);
}
static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
