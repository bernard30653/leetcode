#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    unordered_map<int, std::string> myMap = {{1, "one"}, {2, "two"}, {3, "three"}};
    auto it = myMap.find(2); // 正確的使用方式
    if (it != myMap.end()) {
        // 找到了元素，it 是一個指向該元素的迭代器
        cout << "Found: " << it->second << std::endl;
    } else {
        // 沒有找到元素
        cout << "Not found" << std::endl;
    }
    return 0;
}
