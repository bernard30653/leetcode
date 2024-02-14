#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
/*
383. Ransom Note
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote.

Example 1.
    Input: ransomNote = "a", magazine = "b"
    Output: false

Example 2.
    Input: ransomNote = "aa", magazine = "ab"
    Output: false

Example 3. 
    Input: ransomNote = "aa", magazine = "aab"
    Output: true
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> ransomMap; 
        unordered_map<char,int> magazineMap;
        for(auto& character:ransomNote){
            if (ransomMap.find(character)==ransomMap.end()){
                ransomMap[character] =1;
            } else{
                ransomMap[character] +=1;
            }
        }
        for(auto& character:magazine){
            if (magazineMap.find(character)==magazineMap.end()){
                magazineMap[character] = 1;
            } else{
                magazineMap[character] += 1;
            }
        }
        for(auto& pair:ransomMap){
            char key=pair.first;
            if(magazineMap.find(key)==magazineMap.end()|| magazineMap[key]<pair.second){
                return false;
            }
        }
        return true;
    }

};

int main() {
    Solution solution;
    cout << boolalpha; //Make sure that the boolean is true/false and not 1/0

    string ransomNote1 = "a";
    string magazine1 = "b";
    cout << "Example 1: " << solution.canConstruct(ransomNote1, magazine1) << endl; // output shall be false

    string ransomNote2 = "aa";
    string magazine2 = "ab";
    cout << "Example 2: " << solution.canConstruct(ransomNote2, magazine2) << endl; // output shall be false

    string ransomNote3 = "aa";
    string magazine3 = "aab";
    cout << "Example 3: " << solution.canConstruct(ransomNote3, magazine3) << endl; // output shall be true

    return 0;
}