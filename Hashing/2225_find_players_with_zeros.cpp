#include <iostream>
#include <vector>
using namespace std;
/*
2225. Find Players With Zero or One Losses
You are given an integer array matches where matches[i] 
= [winneri, loseri] indicates that the player winneri defeated player loseri in a match.
Return a list answer of size 2 where:

answer[0] is a list of all players that have not lost any matches.
answer[1] is a list of all players that have lost exactly one match.
The values in the two lists should be returned in increasing order.


Note:

You should only consider the players that have played at least one match.
The testcases will be generated such that no two matches will have the same outcome.

Example 1:
    Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
    Output: [[1,2,10],[4,5,7,8]]
    Explanation:
    Players 1, 2, and 10 have not lost any matches.
    Players 4, 5, 7, and 8 each have lost one match.
    Players 3, 6, and 9 each have lost two matches.
    Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].

Example 2:
    Input: matches = [[2,3],[1,3],[5,4],[6,4]]
    Output: [[1,2,5,6],[]]
    Explanation:
    Players 1, 2, 5, and 6 have not lost any matches.
    Players 3 and 4 each have lost two matches.
    Thus, answer[0] = [1,2,5,6] and answer[1] = [].

*/
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> result(2); // 預設包含兩個空向量：勝者和僅輸一場的選手
        unordered_map<int, int> loseMap; // 記錄每個選手的輸球次數

        for (const auto& match : matches) {
            int winner = match[0];
            int loser = match[1];
            loseMap[winner] += 0; // 確保勝者也在loseMap中有記錄，但不增加輸球次數
            if (loseMap.find(loser) == loseMap.end()) {
                loseMap[loser] = 1; // 如果是第一次輸，初始化為1
            } else {
                loseMap[loser] += 1; // 否則，輸球次數加1
            }
        }

        for (const auto& p : loseMap) {
            if (p.second == 0) {
                result[0].push_back(p.first); // 無輸球記錄的加入勝者名單
            } else if (p.second == 1) {
                result[1].push_back(p.first); // 輸一場的加入僅輸一場名單
            }
        }
        sort(result[0].begin(), result[0].end());
        sort(result[1].begin(), result[1].end());
        return result;
    }
};

int main() {
    // 示例比賽數據
    vector<vector<int>> matches = {{1, 2}, {2, 3}, {3, 4}, {1, 5}, {6, 5}, {7, 6}};
    Solution solution;
    vector<vector<int>> winners = solution.findWinners(matches);
    
    // 打印沒有輸過的選手
    cout << "Players who have not lost any match: ";
    for (int player : winners[0]) {
        cout << player << " ";
    }
    cout << endl;
    // 打印僅輸一場的選手
    cout << "Players who have lost exactly one match: ";
    for (int player : winners[1]) {
        cout << player << " ";
    }
    cout << endl;

    return 0;
}