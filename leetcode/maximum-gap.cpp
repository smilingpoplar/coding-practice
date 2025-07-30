//
//  maximum-gap
//  https://leetcode.com/problems/maximum-gap/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        // 因为 maxGap >= ceiling((maxVal-minVal)/(n-1))，设后者为bucketSize
        // 由于桶是前闭后开区间，maxGap不可能在桶内取得，只能在桶间取得，每个桶只需保留其最大最小值
        // 桶个数为 (maxVal-minVal)/bucketSize + 1（+1因为桶是后开区间）
        // 数num会落在第 (num-minVal)/bucketSize 桶中

        // min和max
        int minVal = INT_MAX, maxVal = INT_MIN;
        for (int num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }
        if (maxVal == minVal) return 0;

        const int N = nums.size();
        int bucketSize = ceil(double(maxVal - minVal) / (N - 1));
        int bucketCnt = (maxVal - minVal) / bucketSize + 1;
        vector<vector<int>> buckets(bucketCnt);
        for (int num : nums) {
            int idx = (num - minVal) / bucketSize;
            auto& bucket = buckets[idx];
            // 每个桶只需保留其最大最小值
            if (bucket.empty()) {
                bucket.push_back(num);
                bucket.push_back(num);
            } else {
                bucket[0] = min(bucket[0], num);  // bucket min
                bucket[1] = max(bucket[1], num);  // bucket max
            }
        }

        // 在桶间求maxGap，首桶（含min）和尾桶（含max）肯定非空
        int maxGap = INT_MIN;
        int prev = 0;
        for (int i = 1; i < bucketCnt; i++) {
            if (buckets[i].empty()) continue;
            int gap = buckets[i][0] - buckets[prev][1];
            maxGap = max(maxGap, gap);
            prev = i;
        }
        return maxGap;
    }
};

int main(int argc, const char* argv[]) {
    vector<int> array = {1, 1, 1, 1, 1, 5, 5, 5, 5, 5};
    Solution solution;
    cout << solution.maximumGap(array);

    return 0;
}
