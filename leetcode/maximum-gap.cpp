//
//  maximum-gap.cpp
//  https://leetcode.com/problems/maximum-gap/
//
//  Created by smilingpoplar on 15/5/1.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        
        // 桶排序，因为 maxGap >= ceiling((max-min)/(n-1))，设后者为bucketLength，则 maxGap >= bucketLength
        // 因为每个桶是半闭半开的区间，桶内gap < bucketLength <= maxGap，maxGap只能在桶间取得，每个桶只需保留其最大最小值
        // 桶的个数为 (max-min)/bucketLength + 1（+1是因为桶是半闭半开区间），数num会落在第 (num-min)/bucketLength 个桶中
        
        // min和max
        int min = INT_MAX;
        int max = INT_MIN;
        for (int num : nums) {
            if (num < min) min = num;
            if (num > max) max = num;
        }
        if (max == min) return 0;

        int bucketLength = ceil(double(max - min) / (nums.size() - 1));
        int bucketCount = (max - min) / bucketLength + 1;
        vector<vector<int>> buckets(bucketCount, vector<int>());
        for (int num : nums) {
            int bucketIndex = (num - min) / bucketLength;
            auto &bucket = buckets[bucketIndex];
            // 每个桶只需保留其最大最小值
            if (bucket.empty()) {
                bucket.push_back(num);
                bucket.push_back(num);
            } else {
                if (num < bucket[0]) bucket[0] = num; // bucket min
                if (num > bucket[1]) bucket[1] = num; // bucket max
            }
        }
        
        // 在桶间求maxGap，首桶和尾桶肯定非空
        int maxGap = INT_MIN;
        size_t prev = 0;
        for (size_t i = 1; i < bucketCount; i++) {
            if (buckets[i].empty()) continue;
            int gap = buckets[i][0] - buckets[prev][1];
            if (gap > maxGap) maxGap = gap;
            prev = i;
        }
        
        return maxGap;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> array = {1, 1, 1, 1, 1, 5, 5, 5, 5, 5};
    Solution solution;
    cout << solution.maximumGap(array);

    return 0;
}
