//
//  find-permutation
//  https://leetcode.com/problems/find-permutation/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findPermutation(string s) {
        // 将连续D对应的子段翻转
        const int N = s.size();
        vector<int> ans;
        for (int i = 0; i <= N; i++)
            ans.push_back(i + 1);
        
        for (int i = 0; i < N; i++) {
            if (s[i] == 'D') {
                int start = i;
                while (i < N && s[i] == 'D')
                    i++;
                reverse(ans, start, i);
            }
        }
        return ans;
    }
    
    void reverse(vector<int> &v, int left, int right) {
        while (left < right) {
            swap(v[left++], v[right--]);
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
