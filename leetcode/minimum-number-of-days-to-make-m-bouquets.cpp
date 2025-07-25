//
//  minimum-number-of-days-to-make-m-bouquets
//  https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // 要在bloomDay中找出m个k长的子段
        if (bloomDay.size() < m * k) return -1;
        // 等待天数wait为各子段最大值的最小值，值范围[min(bloomDay),max(bloomDay)]
        int mn = INT_MAX, mx = INT_MIN;
        for (int day : bloomDay) {
            mn = min(mn, day);
            mx = max(mx, day);
        }

        // 二分搜索猜等待天数
        int lo = mn, hi = mx;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (enough(mid, bloomDay, m, k)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

    bool enough(int wait, vector<int>& bloomDay, int m, int k) {
        // 等待天数wait一确定，bloomDay根据开没开花变成10数组，
        // 就能统计有多少个k长的连续1的子段，count(wait)是关于wait的递增函数，
        // count(wait)>=m满足二分搜索的条件形式[0..0 1 1..]
        int adjacent = 0, count = 0;
        for (int day : bloomDay) {
            if (day <= wait) {
                adjacent++;
                if (adjacent >= k) {
                    count++;
                    adjacent = 0;
                }
            } else {
                adjacent = 0;
            }
        }
        return count >= m;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
