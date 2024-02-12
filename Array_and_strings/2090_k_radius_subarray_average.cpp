#include <iostream>
#include <vector>
using namespace std;
/*
2090. K Radius Subarray Averages
Example 1:
    Input: nums = [7,4,3,9,1,8,5,2,6], k = 3
    Output: [-1,-1,-1,5,4,4,-1,-1,-1]
    Explanation:
    - avg[0], avg[1], and avg[2] are -1 because there are less than k elements before each index.
    - The sum of the subarray centered at index 3 with radius 3 is: 7 + 4 + 3 + 9 + 1 + 8 + 5 = 37.
    Using integer division, avg[3] = 37 / 7 = 5.
    - For the subarray centered at index 4, avg[4] = (4 + 3 + 9 + 1 + 8 + 5 + 2) / 7 = 4.
    - For the subarray centered at index 5, avg[5] = (3 + 9 + 1 + 8 + 5 + 2 + 6) / 7 = 4.
    - avg[6], avg[7], and avg[8] are -1 because there are less than k elements after each index.
Example 2:
    Input: nums = [100000], k = 0
    Output: [100000]
    Explanation:
    - The sum of the subarray centered at index 0 with radius 0 is: 100000.
    avg[0] = 100000 / 1 = 100000.

Example 3:
    Input: nums = [8], k = 100000
    Output: [-1]
    Explanation: 
    - avg[0] is -1 because there are less than k elements before and after index 0.
*/

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int len = 2*k+1; // The length of the subarrays
        vector<int> result(n, -1);
        vector<long long int> prefixSum(n, 0);
        if (n <= k) {
            return result;
        }
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }
        for (int i = k; i+k <= n-1; i++) {
            long long sum = prefixSum[i+k] - (i-k-1 >= 0 ? prefixSum[i-k-1] : 0);
            result[i] = sum / len;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 2, 6, -1, 4, 1, 8, 2}; // 定義數組
    int k = 2; // 定義半徑
    vector<int> avgs = solution.getAverages(nums, k); // 獲取平均值結果

    cout << "k-radius averages: ";
    for (int avg : avgs) {
        cout << avg << " ";
    }
    cout << endl;

    return 0;
}
