//
//  couples-holding-hands/
//  https://leetcode.com/problems/couples-holding-hands//
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        const int N = row.size();
        vector<int> pos(N);
        for (int i = 0; i < N; i++) {
            pos[row[i]] = i;
        }

        int ans = 0;
        for (int i = 0; i < N; i += 2) {
            int couple = row[i] ^ 1;
            if (row[i+1] == couple) continue;
            doSwap(i+1, pos[couple], row, pos);
            ans++;
        }
        return ans;
    }

    void doSwap(int idx1, int idx2, vector<int> &row, vector<int> &pos) {
        swap(pos[row[idx1]], pos[row[idx2]]);
        swap(row[idx1], row[idx2]);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
