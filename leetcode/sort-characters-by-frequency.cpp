//
//  sort-characters-by-frequency
//  https://leetcode.com/problems/sort-characters-by-frequency/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        for (char c : s) cnt[c]++;
        // 按频率分桶
        vector<vector<char>> buckets(s.size() + 1);
        for (auto& [key, freq] : cnt) 
            buckets[freq].push_back(key);
        
        ostringstream oss;
        for (int i = (int)buckets.size() - 1; i >= 0; i--) {
            if (buckets[i].empty()) continue;
            for (char c : buckets[i]) {
                oss << string(i, c);
            }
        }
        return oss.str();
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
