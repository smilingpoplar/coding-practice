//
//  fruit-into-baskets
//  https://leetcode.com/problems/fruit-into-baskets/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        // 求含<=2种元素的最长子段，滑动窗口法
        unordered_map<int, int> cnt; // num=>count
        int ans = 0;
        // 有效窗口：cnt.size() <= 2
        for (int lo = 0, hi = 0; hi < tree.size(); hi++) {
            cnt[tree[hi]]++;
            while (cnt.size() > 2) {
                if (--cnt[tree[lo]] == 0) cnt.erase(tree[lo]);
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
