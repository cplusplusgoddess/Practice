#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define OUT_BOUNDS(pt, mx)(((pt < 0) || (pt >= mx))?true:false)

    int explore_map(vector<vector<char>> & grid, size_t r, size_t c, 
                   vector<vector<int>> &visited) {
        if( (OUT_BOUNDS(r, grid.size())) || (OUT_BOUNDS(c, grid[0].size())))
            return(0);
        // cout << "grid[" << r << "][" << c << "] = " << grid[r][c] << endl;

        if(grid[r][c] == '0') //water
            return(0);
        
        if(visited[r][c] == 1)
            return(0);
        
        visited[r][c] = 1;
        int dummy; // make dummy a running total if island size needed
        dummy = explore_map(grid, r, c-1, visited);  //left
        dummy = explore_map(grid, r, c+1, visited);  //right
        dummy = explore_map(grid, r-1, c, visited);  //top
        dummy = explore_map(grid, r+1, c, visited);  //bottom
        return(1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        size_t m = grid.size();
        size_t n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0)); //  = {{0}};
        for(size_t i = 0; i < m; i++){        
            for(size_t j = 0; j < n ; j++){
              count += explore_map(grid, i, j, visited);   
            }
        }
        return(count);
    }
int main(){
   vector<vector<char>> grid = {{'1','1','1','1','0'},
								{'1','1','0','1','0'},
								{'1','1','0','0','0'},
								{'0','0','0','0','0'}};

   cout << "Num islands: " << numIslands(grid) << endl;

// {{"1","1","0","0","0"},{"1","1","0","0","0"},{"0","0","1","0","0"},{"0","0","0","1","1"}}
   return(0);
}
