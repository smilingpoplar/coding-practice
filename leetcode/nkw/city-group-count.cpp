//
//  city-group-count
//  NC345 城市群数量
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int citys(vector<vector<int> >& m) {
        // 并查集
        const int N = m.size();
        vector<int> uf(N);
        for (int i = 0; i < N; i++) {
            uf[i] = i;
        }
        int ans = N;

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (m[r][c] == 1) {
                    int pr = parent(r, uf), pc = parent(c, uf);
                    if (pr != pc) {
                        uf[pr] = pc;  // unite
                        ans--;
                    }
                }
            }
        }
        return ans;
    }

    int parent(int x, vector<int>& uf) {
        if (x != uf[x]) {
            uf[x] = parent(uf[x], uf);
        }
        return uf[x];
    }
};