//
//  card-flipping-game
//  https://leetcode.com/problems/card-flipping-game/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        // 除了正反相同的牌面不行，其他牌面都可以作为候选
        const int N = fronts.size();
        unordered_set<int> same;
        for (int i = 0; i < N; i++) {
            if (fronts[i] == backs[i]) 
                same.insert(fronts[i]);
        }
        
        int ans = INT_MAX;
        for (int f : fronts) 
            if (!same.count(f)) ans = min(ans, f);
        for (int b : backs) 
            if (!same.count(b)) ans = min(ans, b);     
        return ans != INT_MAX ? ans : 0;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
