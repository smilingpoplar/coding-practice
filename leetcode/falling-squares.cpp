//
//  falling-squares
//  https://leetcode.com/problems/falling-squares/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
    struct Interval {
        int left;
        int right;
        int height;
    };
    struct Cmp {
        bool operator()(const Interval &a, const Interval &b) const {
            return a.right < b.right;
        }
    };
    set<Interval, Cmp> st;
    
    bool isOverlap(const Interval &a, const Interval &b) {
        return a.left < b.right && b.left < a.right;
    }
public:
    vector<int> fallingSquares(vector<vector<int>>& pos) {
        vector<int> ans;
        int highest = 0;
        for (auto &p : pos) {
            int left = p[0], right = p[0] + p[1], height = p[1];
            // 删除[left,right)区间
            // 首个与[left,right)重叠的区间toFind.right > left
            auto it = st.upper_bound({INT_MIN, left, 0});
            Interval removing({left, right});
            vector<Interval> remain;
            int base = 0; // 新块儿放置的高度是重叠区间的最大高度
            while (it != st.end() && isOverlap(*it, removing)) {
                if (it->left < removing.left) 
                    remain.push_back({ it->left, removing.left, it->height });
                if (removing.right < it->right)
                    remain.push_back({ removing.right, it->right, it->height });
                base = max(base, it->height);
                it = st.erase(it);
            }
            st.insert(remain.begin(), remain.end());
            // 插入新块儿
            height += base;
            st.insert({left, right, height});

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
