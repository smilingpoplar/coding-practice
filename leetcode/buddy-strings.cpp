//
//  buddy-strings
//  https://leetcode.com/problems/buddy-strings/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        // 若A==B，需要交换两个相同字母
        const int N = A.size();
        if (A == B) return unordered_set<char>(A.begin(), A.end()).size() < N;
        // 需要仅有两处可交换
        vector<int> diff;
        for (int i = 0; i < N; i++) {
            if (A[i] != B[i]) {
                diff.push_back(i);
                if (diff.size() > 2) return false;
            }
        }
        return (diff.size() == 2 && A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]]);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
