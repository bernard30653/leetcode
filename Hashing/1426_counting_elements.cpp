#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;
/*
1426. Counting Elements
Given an integer array arr, 
count how many elements x there are, 
such that x + 1 is also in arr. If there are duplicates in arr, count them separately.

Example 1:

    Input: arr = [1,2,3]
    Output: 2
    Explanation: 1 and 2 are counted cause 2 and 3 are in arr.

Example 2:
    Input: arr = [1,1,3,3,5,5,7,7]
    Output: 0
    Explanation: No numbers are counted, cause there is no 2, 4, 6, or 8 in arr.

*/
class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> numberSet(arr.begin(),arr.end());
        int count = 0;
        for(int elem:arr){
            if(numberSet.find(elem+1)!=numberSet.end()){
                count++;
            }
        }
        return count;
        /*
        Original Version
        unordered_map<int,int> occurrenceMap;
        int count = 0;
        for(int elem:arr){     
            if(occurrenceMap.find(elem)!=occurrenceMap.end()){
                occurrenceMap[elem] +=1;
            }
            else{
                occurrenceMap[elem] = 1;
                if(occurrenceMap.find(elem-1)!=occurrenceMap.end()){
                    count+=occurrenceMap[elem-1];
                }
            }
            if(occurrenceMap.find(elem+1)!=occurrenceMap.end()){
                count+=1;
            }
        }
        return count;
        */
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1,3,2,3,5,0};
    cout << "The count is: " << solution.countElements(arr) << endl;
    return 0;
}