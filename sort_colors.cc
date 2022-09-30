#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	void best_sortColors(vector<int>& nums) {
        int h = nums.size()-1;
        int l= 0;
        int m = 0;
        while(m<=h){
            if(nums[m] == 0){
                swap(nums[m], nums[l]);
                l++;
                m++;
            }
            else if(nums[m] == 2){
                swap(nums[m], nums[h]);
                h--;
            }else{
                m++;
            }
        }
    }
	void optimal_sortColors(vector<int>& nums) {
        unordered_map<int,int> mapping;
        for(auto n : nums) {
            mapping[n]++;
        }
        
        int index = 0;
        for (size_t i = 0; i < 3; ++i) {
            for (size_t j = index; j < nums.size(); ++j) {
                if (nums[j] == i) {
                    swap(nums[j], nums[index]);
                    mapping[i]--;
                    index++;
                }
                
                if (mapping[i] == 0) {
                    break;
                }
            }
        }
    }
    void sortColors(vector<int>& nums) {
        size_t next_red_idx = 0;
        size_t next_blue_idx = nums.size() -1;
        vector<int> ord_nums(nums.size(), 1);
        
        for(auto i = 0 ; i < nums.size(); i++ ){
            if(nums[i]==0)
                ord_nums[next_red_idx++] = 0;
            else if( nums[i] == 2)
                ord_nums[next_blue_idx--] = 2;
        }
        nums = move(ord_nums);
    }
};

int main(){


	vector<int> nums = { 1, 2, 0, 0, 1, 1, 0, 0, 1};
 	Solution sol;
	sol.best_sortColors(nums);
}
