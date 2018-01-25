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
        // 从左到右处理pos，每个位置看会不会和后序位置重叠，重叠的话后序位置的基线要提高成当前位置高
        const int N = pos.size();
        vector<int> high(N, 0);
        for (int i = 0; i < N; i++) {
            high[i] += pos[i].second;
            int ileft = pos[i].first;
            int iright = pos[i].first + pos[i].second;
            for (int j = i + 1; j < N; j++) {
                int jleft = pos[j].first;
                int jright = pos[j].first + pos[j].second;
                if (ileft < jright && jleft < iright) {
                    high[j] = max(high[j], high[i]);
                }
            }
        }
        
        int highest = INT_MIN;
        vector<int> ans;
        for (int i = 0; i < N; i++) {
            highest = max(highest, high[i]);
            ans.push_back(highest);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
