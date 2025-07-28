//
//  count-of-shortest-path
//  NC249 拜访
//

#include <iostream>

using namespace std;

class Solution {
public:
    int countPath(vector<vector<int>> &cityMap, int n, int m) {
        int ans = 0;
        int currlen = 0, minlen = INT_MAX;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (cityMap[r][c] == 1) {  // 经理
                    search(cityMap, n, m, r, c, 0, minlen, ans);
                }
            }
        }
        return ans;
    }

    void search(vector<vector<int>> &cityMap, int n, int m, int r, int c, int currlen, int &minlen, int &ans) {
        if (r < 0 || r >= n || c < 0 || c >= m || cityMap[r][c] == -9 || cityMap[r][c] == -1 || currlen > minlen) return;

        if (cityMap[r][c] == 2) {  // 商家
            if (currlen < minlen) {
                minlen = currlen;
                ans = 1;
            } else if (currlen == minlen) {
                ans++;
            }
            return;
        }

        int oldVal = cityMap[r][c];
        cityMap[r][c] = -9;  // visited
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto &d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            search(cityMap, n, m, nr, nc, currlen + 1, minlen, ans);
        }
        cityMap[r][c] = oldVal;  // 回溯
    }
};