//
//  queue-reconstruction-by-height
//  https://leetcode.com/problems/queue-reconstruction-by-height/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        // 从高到低插入排序，低个的无论插哪儿都不影响已排好队的
        sort(people.begin(), people.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        });
        vector<pair<int, int>> ans;
        for (auto &p : people) {
            ans.insert(ans.begin() + p.second, p);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
