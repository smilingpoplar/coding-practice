//
//  falling-squares
//  https://leetcode.com/problems/falling-squares/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& pos) {
        // 每个块儿看会不会和前面块儿重叠，重叠时要提高当前块儿的摆放高度
        const int N = pos.size();
        vector<int> high(N); // 每个块儿的高
        int highest = 0;
        vector<int> ans;
        for (int i = 0; i < N; i++) {
            int base = 0;
            int ileft = pos[i].first, iright = pos[i].first + pos[i].second;
            for (int j = 0; j < i; j++) {
                int jleft = pos[j].first, jright = pos[j].first + pos[j].second;
                if (ileft < jright && jleft < iright) base = max(base, high[j]);
            }
            high[i] = base + pos[i].second;
            highest = max(highest, high[i]);
            ans.push_back(highest);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
