//
//  k-empty-slots
//  https://leetcode.com/problems/k-empty-slots/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int kEmptySlots(vector<int> &flowers, int k) {
        const int N = flowers.size();
        // 桶排序，每个桶对应k+1个位置，
        // 这样所找的k个空槽两端有花的情况就不可能出现在桶内，而只能在桶间
        // 每个桶保留最大最小值
        unordered_map<int, vector<int>> buckets; // bucketIdx=>[minOfBucket,maxOfBucket]
        for (int i = 1; i <= N; i++) {
            int pos = flowers[i-1];
            int idx = pos / (k + 1);
            if (buckets.count(idx)) {
                buckets[idx][0] = min(buckets[idx][0], pos);
                buckets[idx][1] = max(buckets[idx][1], pos);
            } else {
                buckets[idx] = {pos, pos};
            }
            // 查看左右桶边界
            if (pos == buckets[idx][0] && buckets.count(idx-1) && pos - buckets[idx-1][1] - 1 == k) return i;
            if (pos == buckets[idx][1] && buckets.count(idx+1) && buckets[idx+1][0] - pos - 1 == k) return i;
        }
        return -1;
    }
};

/*
class Solution {
public:
    int kEmptySlots(vector<int> &flowers, int k) {
        const int N = flowers.size();
        set<int> st;
        for (int i = 1; i <= N; i++) {
            int pos = flowers[i-1];
            st.insert(pos);
            // 看前后位置是否相隔k
            auto it = st.find(pos);
            if (it != st.begin() && pos - *prev(it) - 1 == k) return i;
            if (next(it) != st.end() && *next(it) - pos - 1 == k) return i;
        }
        return -1;
    }
};
*/


int main(int argc, const char * argv[]) {
    return 0;
}
