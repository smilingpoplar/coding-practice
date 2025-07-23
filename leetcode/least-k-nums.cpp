//
//  least-k-nums
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) {
        vector<int> ans;
        if (input.empty() || k == 0) return ans;

        priority_queue<int, vector<int>> Q;  // 最大堆
        for (int a : input) {
            if (Q.size() < k) {
                Q.push(a);
            } else {
                if (a < Q.top()) {
                    Q.pop();
                    Q.push(a);
                }
            }
        }

        while (!Q.empty()) {
            ans.push_back(Q.top());
            Q.pop();
        }
        return ans;
    }
};