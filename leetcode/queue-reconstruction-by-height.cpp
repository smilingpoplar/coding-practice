//
//  queue-reconstruction-by-height
//  https://leetcode.com/problems/queue-reconstruction-by-height/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        // 先排高个再插低个，低个的无论怎么插队都不会影响已排好队的那些人
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
