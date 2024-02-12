#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;
/*
1189. Maximum Number of Balloons
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
You can use each character in text at most once. Return the maximum number of instances that can be formed.

Example 1.
    Input: text = "nlaebolko"
    Output: 1

Example 2.
    Input: text = "loonbalxballpoon"
    Output: 2

Example 3.
    Input: text = "leetcode"
    Output: 0
*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        //"b"*1, "a"*1,"l"*2,"o"*2,"n"*1
        unordered_map<char,int> occurrenceMap; 
        int max_balloons=INT_MAX;
        for(auto& character: text){
            if(character=='b' ||character=='a'||character=='l'||character=='o'||character=='n'){
                occurrenceMap[character]++;
            }
        }
        max_balloons = min(max_balloons,occurrenceMap['b']);
        max_balloons = min(max_balloons,occurrenceMap['a']);
        max_balloons = min(max_balloons,occurrenceMap['l']/2);
        max_balloons = min(max_balloons,occurrenceMap['o']/2);
        max_balloons = min(max_balloons,occurrenceMap['n']);
        return max_balloons;
    }
};
int main() {
    Solution solution;

    // Example 1
    string text1 = "nlaebolko";
    cout << "Example 1 Output: " << solution.maxNumberOfBalloons(text1) << endl;

    // Example 2
    string text2 = "loonbalxballpoon";
    cout << "Example 2 Output: " << solution.maxNumberOfBalloons(text2) << endl;

    // Example 3
    string text3 = "leetcode";
    cout << "Example 3 Output: " << solution.maxNumberOfBalloons(text3) << endl;

    return 0;
}