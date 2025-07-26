//
//  stack-sort
//  NC115 栈和排序
//  字典序最大的出栈序列
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> solve(vector<int>& arr) {
        const int N = arr.size();
        vector<int> rMax(N + 1, INT_MIN);
        for (int i = N - 1; i >= 0; i--) {
            rMax[i] = max(arr[i], rMax[i + 1]);
        }

        stack<int> stk;
        vector<int> ans;
        for (int i = 0; i < N; i++) {
            stk.push(arr[i]);
            // 如果栈顶元素比i后面所有元素都大，就出栈
            while (!stk.empty() && stk.top() > rMax[i + 1]) {
                ans.push_back(stk.top());
                stk.pop();
            }
        }
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};
