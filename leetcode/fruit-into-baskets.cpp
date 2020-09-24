//
//  fruit-into-baskets
//  https://leetcode.com/problems/fruit-into-baskets/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        // 题目：包含2个不同数的最长子段
        const int N = tree.size();
        unordered_map<int, int> cnt; // type=>count
        int needed = 2, ans = 0;
        for (int hi = 0, lo = 0; hi < N; hi++) {
            if (cnt[tree[hi]]++ == 0) needed--;;
            while (needed < 0) {
                if (--cnt[tree[lo]] == 0) needed++;
                lo++;
            }
            ans = max(ans, hi - lo + 1);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
