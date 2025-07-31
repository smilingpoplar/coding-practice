//
//  find-k-closest-elements
//  https://leetcode.com/problems/find-k-closest-elements/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int j = lower_bound(begin(arr), end(arr), x) - begin(arr);  // arr[j]是第一个>=x的数
        int i = j - 1;
        while (k--) {
            if (i < 0) {
                j++;
            } else if (j >= arr.size()) {
                i--;
            } else if (x - arr[i] <= arr[j] - x) {
                i--;
            } else {
                j++;
            }
        }
        // (i,j)是前开后开区间
        return vector<int>(arr.begin() + i + 1, arr.begin() + j);
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
