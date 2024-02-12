#include <iostream>
#include <vector>
using namespace std;
/*
1133. Largest Unique Number
Example 1. 
    Input: nums = [5,7,3,9,4,9,8,3,1]
    Output: 8
    Explanation: The maximum integer in the array is 9 but it is repeated. The number 8 occurs only once, so it is the answer.
Example 2.
    Input: nums = [9,9,8,8]
    Output: -1
    Explanation: There is no number that occurs only once.
*/
class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map<int,int> occurrenceMap;
        int max_elem=-1;
        for(auto& num:nums){
            if(occurrenceMap.find(num)!=occurrenceMap.end()){
                occurrenceMap[num] +=1;
            } else{
                occurrenceMap[num]=1;
            }
        }
        for(auto& pair:occurrenceMap){
            
            if(pair.second==1){
                max_elem = max(max_elem,pair.first);
            };
        }
        return max_elem;
    }
};
int main(){
    // Example 1
    vector<int> nums1 = {5,7,3,9,4,9,8,3,1};
    Solution solution;
    cout << "Example 1 Output: " << solution.largestUniqueNumber(nums1) << endl;

    // Example 2
    vector<int> nums2 = {9,9,8,8};
    cout << "Example 2 Output: " << solution.largestUniqueNumber(nums2) << endl;
    return 0;
}