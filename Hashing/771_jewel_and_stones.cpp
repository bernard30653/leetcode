#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;
/*
771. Jewels and Stones
You're given strings jewels representing the types of stones that are jewels,
and stones representing the stones you have. Each character in stones is a type of stone you have. 
You want to know how many of the stones you have are also jewels.
Example 1.
    
    Input: jewels = "aA", stones = "aAAbbbb"
    Output: 3

Example 2.

    Input: jewels = "z", stones = "ZZ"
    Output: 0


*/
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelSet(jewels.begin(),jewels.end());
        int jewelCount = 0;
        int stoneCount = stones.size();
        for(int i=0;i<stoneCount;i++){
            if (jewelSet.find(stones[i])!=jewelSet.end()){
                jewelCount += 1;
            }
        }
        return jewelCount;
    }
};
int main() {
    Solution solution;
    cout << solution.numJewelsInStones("aA", "aAAbbbb") << endl; // The output shall be 3
    cout << solution.numJewelsInStones("z", "ZZ") << endl; // The output shall be 0
    return 0;
}