//
//  cracking-the-safe
//  https://leetcode.com/problems/cracking-the-safe/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string crackSafe(int n, int k) {
        // 要求能覆盖全部密码组合，就是要找欧拉路径
        // 每个节点有k条出边和k条入边，入度==出度，一定有欧拉回路
        // n-1位数作为节点，边是 (后n-1位数)+any['0'..'k')，下一节点是边的后n-1位数
        // 边的后序遍历编号等于逆欧拉回路
        unordered_set<string> visited;
        string str(n, '0');
        visited.insert(str);

        string ans;
        function<void(const string &)> dfs = [&](const string &prefix) {
            for (int i = 0; i < k; i++) { // 遍历所有出边
                string x = to_string(i);
                auto next = prefix + x;
                if (visited.count(next)) continue;
                visited.insert(next);

                dfs(next.substr(1));
                ans += x; // 后序遍历
            }
        };

        dfs(str.substr(1));
        ans += str; // 后序遍历
        reverse(begin(ans), end(ans));
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
