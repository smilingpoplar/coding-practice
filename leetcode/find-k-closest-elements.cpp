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
        // 双指针法
        int i = 0, j = (int)arr.size() - 1;
        while (j - i >= k) {  // 循环结束后 j-i+1 == k
            if (abs(x - arr[i]) <= abs(arr[j] - x)) {
                j--;
            } else {
                i++;
            }
        }

        vector<int> ans;
        for (int l = i; l <= j; l++) {
            ans.push_back(arr[l]);
        }
        return ans;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
