#include <iostream>
#include <vector>
using namespace std;
/*
1004. Max Consecutive Ones III
Given a binary array nums and an integer k, 
return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
Example 1:
    Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
    Output: 6
    Explanation: [1,1,1,0,0,1,1,1,1,1,1]
    Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:
    Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
    Output: 10
    Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
    Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/

class Solution {
public:
    void printArray(vector<int> &array){
        int n = array.size();
        for(int i=0;i<n;i++){
            cout << array[i] << " ";
        }
        cout<<endl;
    }
    int longestOnes(vector<int>& nums, int k) {
        int zeroCount=0;// recording the number of zeros 
        int left= 0,result = 0,right=0;
        while(right<nums.size()){
            if(nums[right]==0){
                zeroCount++;
            }
            while(zeroCount>k){
                if(nums[left]==0){
                    zeroCount--;
                }
                left++;
            } 
            result = max(result,right-left+1);
            right++;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1,1,1,0,0,0,1,1,1,1,0};
    int k1 = 2;
    cout << "Example 1: " << solution.longestOnes(nums1, k1) << endl;
    
    vector<int> nums2 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k2 = 3;
    cout << "Example 2: " << solution.longestOnes(nums2, k2) << endl;
    
    return 0;
}
