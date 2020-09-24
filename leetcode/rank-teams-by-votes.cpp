//
//  rank-teams-by-votes
//  https://leetcode.com/problems/rank-teams-by-votes/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        // 各字符先按位置0的计数排、再按位置1的计数排、...，
        // 若所有位置计数都相等，最后按字符大小排
        // count[c][i]表示字符c在位置i的计数，0<=i<M
        // count[c][M]=c，最后放字符c，表示按字符大小排
        const int M = votes[0].size();
        vector<vector<int>> count(26, vector<int>(M + 1));
        for (char c = 'A'; c <= 'Z'; c++) {
            count[c - 'A'][M] = c;
        }
        
        for (auto &s : votes) {
            for (int i = 0; i < M; i++) {
                count[s[i] - 'A'][i]--; // 倒序排列
            }
        }
        
        sort(count.begin(), count.end());
        string ans;
        for (int i = 0; i < M; i++) {
            ans += count[i][M];
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
