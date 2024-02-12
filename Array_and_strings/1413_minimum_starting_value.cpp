#include <vector>
#include <iostream>
using namespace std;
/*
1413. Minimum Value to Get Positive Step by Step Sum
Example 1
    Input: nums = [-3,2,-3,4,2]
    Output: 5
    Explanation: If you choose startValue = 4, in the third iteration your step by step sum is less than 1.
    step by step sum
    startValue = 4 | startValue = 5 | nums
    (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
    (1 +2 ) = 3  | (2 +2 ) = 4    |   2
    (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
    (0 +4 ) = 4  | (1 +4 ) = 5    |   4
    (4 +2 ) = 6  | (5 +2 ) = 7    |   2

Example 2
    Input: nums = [1,2]
    Output: 1
    Explanation: Minimum start value should be positive. 

Example 3
    Input: nums = [1,-2,-3]
    Output: 5
*/
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int prefix_min_elem=nums[0];
        vector<int> prefix(n,0);
        prefix[0] = nums[0];
        
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
            prefix_min_elem = min(prefix[i],prefix_min_elem);
        }
        
        return max(1-prefix_min_elem,1);
    }
};
int main() {
    Solution solution;
    vector<int> arr = {-3,2,-3,4,2};
    cout << "The minimum positive starting value is: " << solution.minStartValue(arr)<< endl;
    return 0;
}