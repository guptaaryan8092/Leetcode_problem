#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums){
            vector<vector<int>> result;
            sort(nums.begin(),nums.end());
            for(int i = 0; i < nums.size()-2; ++i){
                if (i > 0 && nums[i]== nums[i-1]) continue;

                int left = i+1;
                int right = nums.size() - 1;

                while (left < right) {
                    int sum = 
                }
            }
        }
};

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    return 0;
};