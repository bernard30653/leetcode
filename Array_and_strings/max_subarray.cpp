#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max_sum = 0;
        double curr_sum = 0;
        int n = nums.size();
        for(int i = 0; i < k; i++) {
            curr_sum += nums[i];
        }
        max_sum = curr_sum;

        // 從第k個元素開始迭代
        for(int i = 1; i+k <= n; i++) {
            curr_sum = curr_sum - nums[i-1] + nums[i+k-1];
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum / k;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    cout << "The maximum average is: " << solution.findMaxAverage(nums, k) << endl;
    return 0;
}
