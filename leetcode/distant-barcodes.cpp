//
//  distant-barcodes
//  https://leetcode.com/problems/distant-barcodes/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        const int N = barcodes.size();
        unordered_map<int, int> cnt;
        for (int code : barcodes) {
            cnt[code]++;
        }

        auto cmp = [&cnt](int a, int b) { return cnt[a] < cnt[b]; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (auto &e : cnt) pq.push(e.first);

        vector<int> ans;
        queue<int> freezed;
        while (!pq.empty()) {
            int code = pq.top(); pq.pop();
            ans.push_back(code);
            cnt[code]--;
            
            freezed.push(code);
            if (freezed.size() >= 2) { // 相同项至少距离2
                int released = freezed.front(); freezed.pop();
                if (cnt[released] > 0) pq.push(released);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
