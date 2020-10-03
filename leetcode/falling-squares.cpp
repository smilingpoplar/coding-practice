//
//  falling-squares
//  https://leetcode.com/problems/falling-squares/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
    // left=>[right,height], [left,right)
    map<int, array<int, 2>> _ranges;
    using RI = map<int, array<int, 2>>::iterator;
    array<RI, 2> getOverlapRanges(int left, int right) {
        // 在端点重合处，不认为重叠
        auto l = _ranges.upper_bound(left); // toFind.left>left
        if (l != begin(_ranges) && prev(l)->second[0] > left) // toFind.left<=left&&toFind.right>left
            l = prev(l);
        auto r = _ranges.lower_bound(right); // toFind.left>=right
        return {l, r};
    }
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> ans;
        int highest = 0;
        for (auto &pos : positions) {
            int left = pos[0], right = pos[0] + pos[1], height = pos[1];
            auto [l, r] = getOverlapRanges(left, right);
            if (l != r) {
               int baseH = 0; // 重叠区间的最大高度是新块儿的放置高度
                for (auto i = l; i != r; i++) {
                    baseH = max(baseH, i->second[1]);
                }
                height += baseH;

                // 删除重叠区间
                int lo = min(left, l->first), loH = 0;
                if (lo < left) loH = l->second[1];
                int hi = max(right, prev(r)->second[0]), hiH = 0;
                if (right < hi) hiH = prev(r)->second[1];
                _ranges.erase(l, r);
                // 剩余不重叠区间
                if (lo < left) _ranges[lo] = {left, loH};
                if (right < hi) _ranges[right] = {hi, hiH};
            }
            _ranges[left] = {right, height};

            highest = max(highest, height);
            ans.push_back(highest);
        }
        return ans;
    }
};

/*
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& pos) {
        // 每个块儿看会不会和前面块儿重叠，重叠时要提高当前块儿的摆放高度
        const int N = pos.size();
        vector<int> high(N); // 每个块儿的高
        int highest = 0;
        vector<int> ans;
        for (int i = 0; i < N; i++) {
            int base = 0;
            int iL = pos[i][0], iR = pos[i][0] + pos[i][1];
            for (int j = 0; j < i; j++) {
                int jL = pos[j][0], jR = pos[j][0] + pos[j][1];
                if (iL < jR && jL < iR) base = max(base, high[j]);
            }
            high[i] = base + pos[i][1];
            highest = max(highest, high[i]);
            ans.push_back(highest);
        }
        return ans;
    }
};
*/

int main(int argc, const char * argv[]) {    
    return 0;
}
