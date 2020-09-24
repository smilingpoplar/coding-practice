//
//  h-index-ii
//  https://leetcode.com/problems/h-index-ii/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        // 题目中的h-index定义很绕，参见下面链接里来自wikipedia的定义
        // https://leetcode.com/problems/h-index-ii/discuss/71063/Standard-binary-search/73201
        // 已知citations[]升序排列，设想有降序排列的索引[N..1]，citations[i]对应索引N-i，
        // h-index就是第一个citations[i]>=N-i的位置N-i
        const int N = citations.size();
        int l = 0, u = N - 1;
        while (l <= u) {
            int mid = l + (u - l) / 2;
            if (citations[mid] >= N - mid) {
                u = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return N - l;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
