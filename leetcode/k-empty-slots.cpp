//
//  k-empty-slots
//  https://leetcode.com/problems/k-empty-slots/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        // 各个位置的花哪天开
        const int N = flowers.size();
        vector<int> days(N);
        for (int i = 0; i < N; i++) {
            days[flowers[i] - 1] = i + 1;
        }
        // 要找相隔k的两个位置left和right（right-left==k+1），使所有位置x（left<x<right）都满足days[x]>days[left]和days[x]>days[right]
        // 维持[left,right]的滑动窗口，测试left<x<right中x是否都满足条件。用一直往右移动的x下标，当x<right时触发不满足则右移窗口left=x；
        // 当x==right时也会触发不满足，这时其实窗口中都满足条件，记录答案，再右移窗口left=x。因为x==right时右移了窗口，不可能有x>right。
        int ans = INT_MAX;
        int left = 0, right = k + 1;
        for (int x = left + 1; right < N; x++) {
            if (days[x] > days[left] && days[x] > days[right]) continue;
            // x不满足条件了
            if (x == right) { // 窗口中都满足条件
                int day = max(days[left], days[right]);
                ans = min(ans, day);                
            }
            left = x, right = left + k + 1;
        }
        return ans != INT_MAX ? ans : -1;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
