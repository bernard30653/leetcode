#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;
/*
1832. Check if the sentence is Pangram
A pangram is a sentence where every letter of the English alphabet appears at least once.
Given a string sentence containing only lowercase English letters, 
return true if sentence is a pangram, or false otherwise.

Example 1:
    Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
    Output: true
    Explanation: sentence contains at least one of every letter of the English alphabet.

Example 2:
    Input: sentence = "leetcode"
    Output: false
*/
class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> alphabetSet(sentence.begin(),sentence.end());
        return alphabetSet.size()==26;
    }
};
int main() {
    Solution solution;
    string sentence = "thequickbrownfoxjumpsoverthelazydog";
    if (solution.checkIfPangram(sentence)){
        cout << "The sentence is a pangram."<< endl;
    } else{
        cout << "The sentence is not a pangram"<< endl;
    }

    return 0;
}