#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;
/*
525. Contiguous Array
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
Example 1.
    Input: nums = [0,1]
    Output: 2
    Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2.
    Input: nums = [0,1,0]
    Output: 2
    Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
    */
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> countMap;
        int n = nums.size();
        int count = 0, maxLen = 0;
              
        countMap[0] = -1;
        for(int i=0;i<n;i++){
            int num = nums[i];
            if(num==0){
                count--;
            }
            else if(num==1){
                count++;
            }
            if(countMap.find(count)!=countMap.end()){
                maxLen = max(maxLen,i-countMap[count]);
            } else{
                countMap[count] = i;
            }
        }
        return maxLen;
    }
};
int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {0,1};
    cout << "Example 1 Output: " << solution.findMaxLength(nums1) << endl;

    // Example 2
    vector<int> nums2 = {0,1,0};
    cout << "Example 2 Output: " << solution.findMaxLength(nums2) << endl;

    return 0;
}