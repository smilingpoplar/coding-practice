//
//  linked-list-components
//  https://leetcode.com/problems/linked-list-components/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        // 当p->val在G中、p->next->val不在G中，p是一个连通子图的结束
        unordered_set<int> st(G.begin(), G.end());
        int ans = 0;
        for (auto p = head; p; p = p->next) {
            if (st.count(p->val) && (p->next == NULL || !st.count(p->next->val))) {
                ans++;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
