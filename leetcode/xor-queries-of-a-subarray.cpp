//
//  xor-queries-of-a-subarray
//  https://leetcode.com/problems/xor-queries-of-a-subarray/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // 前缀xor，[0..i]的范围xor放在prexor[i+1]
        const int N = arr.size();
        vector<int> prexor(N + 1, 0);
        for (int i = 0; i < N; i++) {
            prexor[i+1] = prexor[i] ^ arr[i];
        }
        
        vector<int> ans;
        for (auto &q : queries) {
            ans.push_back(prexor[q[1]+1] ^ prexor[q[0]]);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
