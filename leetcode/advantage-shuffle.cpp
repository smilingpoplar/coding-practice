//
//  advantage-shuffle
//  https://leetcode.com/problems/advantage-shuffle/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        // 选A中比b稍大的，若没有则选A中最小的
        multiset<int> ms(A.begin(), A.end());
        vector<int> ans;
        for (int b : B) {
            auto it = ms.upper_bound(b);
            if (it == ms.end()) it = ms.begin();
            ans.push_back(*it);
            ms.erase(it);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
