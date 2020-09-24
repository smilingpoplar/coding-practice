//
//  least-number-of-unique-integers-after-k-removals
//  https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> cnt; // num=>count
        for (int num : arr) {
            cnt[num]++;
        }
        // 按照个数升序排
        auto cmp = [&cnt](int a, int b) {
            return cnt[a] > cnt[b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (auto &e : cnt) {
            pq.push(e.first);
        }
        while (k > 0) {
            k -= cnt[pq.top()];
            if (k >= 0) pq.pop();
        }
        return pq.size();
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
