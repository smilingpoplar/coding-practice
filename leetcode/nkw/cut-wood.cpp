//
//  cut-wood
//  NC382 切割木头
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int cutWood(vector<int>& a, int k) {
        int lo = 0, hi = 1e9 + 1;
        while (lo + 1 < hi) {
            int m = lo + (hi - lo) / 2;
            if (!guess(m, a, k)) {
                hi = m;
            } else {
                lo = m;
            }
        }
        return lo;
    }

    // 随着m递增，cnt递减，cnt>=k返回形如 [1..1 0..0]
    // 最大的m，对应找最后一个1
    bool guess(int m, const vector<int>& a, int k) {
        int cnt = 0;
        for (int num : a) {
            cnt += num / m;
        }
        return cnt >= k;
    }
};