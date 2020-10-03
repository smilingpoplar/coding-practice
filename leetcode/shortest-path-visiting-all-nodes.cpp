//
//  shortest-path-visiting-all-nodes
//  https://leetcode.com/problems/shortest-path-visiting-all-nodes/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        // 编码所有节点的访问状态到二进制covered，当前节点为cur
        // bfs的"状态"为 (covered,cur)
        const int N = graph.size();
        const int VISIT_ALL = (1 << N) - 1;

        vector<vector<bool>> visited(1 << N, vector<bool>(N, false));
        queue<array<int, 2>> q;
        for (int i = 0; i < N; i++) {
            q.push({1 << i, i});
        }

        int dist = 0;
        while (!q.empty()) {
            for (int sz = q.size(); sz > 0; sz--) {
                auto [covered, cur] = q.front(); q.pop();                
                if (visited[covered][cur]) continue;
                visited[covered][cur] = true;

                if (covered == VISIT_ALL) return dist;
                for (auto next : graph[cur]) {
                    q.push({covered | (1 << next), next});
                }
            }
            dist++;
        }
        return -1;
    }
};

/*
class Solution {
    const int INF = 1e9;
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        const int N = graph.size();
        vector<vector<int>> dist(N, vector<int>(N, INF));
        for (int i = 0; i < N; i++) {
            for (int j : graph[i]) {
                dist[i][j] = 1;
            }
        }
        
        floyd(dist);        
        return shortestHamilton(dist);
    }
    
    void floyd(vector<vector<int>> &dist) {
        // floyd求所有点对最短距离
        const int N = dist.size();
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    int shortestHamilton(vector<vector<int>> &dist) {
        // dp求哈密顿路径
        // 设dp[group][dst]表示经过集合group中的所有节点、
        // 并最终停在group中dst节点的最短路径，
        // 在group中选一节点u、在group外选一节点v，u松弛v
        // dp[group+{v}][v] = min( dp[group][u] + dist[u][v] )
        // 其中dist[u][v]表示u->v的最短路径，可用Floyd算法三重循环松弛得到
        const int N = dist.size();
        vector<vector<int>> dp(1<<N, vector<int>(N, INF));
        for (int i = 0; i < N; i++) {
            dp[1<<i][i] = 0;
        }
        for (int group = 1; group < (1<<N); group++) {
            // group中选一点u，group外选一点v，u松弛v
            for (int u = 0; u < N; u++) {
                int umask = 1<<u;
                if (!(group & umask)) continue;
                for (int v = 0; v < N; v++) {
                    int vmask = 1<<v;
                    if (group & vmask) continue;
                    dp[group|vmask][v] = min(dp[group|vmask][v],
                                             dp[group][u] + dist[u][v]);
                }
            }
        }
        
        // 从所有点出发的最小值
        int ans = INF;
        for (int i = 0; i < N; i++) {
            ans = min(ans, dp[(1<<N)-1][i]);
        }
        return ans;    
    }
};
*/

/*
int shortestHamilton(vector<vector<int>> &dist) {
    // dp求哈密顿路径
    // 设dp[group][dst]表示经过集合group中的所有节点、
    // 并最终停在group中dst节点的最短路径，
    // 在group中选一节点u、在group-{u}中选一点k，k松弛u
    // dp[group][u] = min( dp[group-{u}][k] + dist[k][u] )
    // 其中dist[u][v]表示u->v的最短路径，可用Floyd算法三重循环松弛得到
    const int N = dist.size();
    vector<vector<int>> dp(1<<N, vector<int>(N, INF));
    for (int i = 0; i < N; i++) {
        dp[1<<i][i] = 0;
    }
    for (int group = 1; group < (1<<N); group++) {
        // group中选一点u、group-{u}中选一点k，k松弛u
        for (int u = 0; u < N; u++) {
            int umask = 1<<u;
            if (!(group & umask)) continue;
            for (int k = 0; k < N; k++) {
                int kmask = 1<<k;
                if (!(group ^ umask) & kmask) continue;
                dp[group][u] = min(dp[group][u],
                                    dp[group^umask][k] + dist[k][u]);
            }
        }
    }
    
    // 从所有点出发的最小值
    int ans = INF;
    for (int i = 0; i < N; i++) {
        ans = min(ans, dp[(1<<N)-1][i]);
    }
    return ans;    
}
*/

int main(int argc, const char * argv[]) {
    return 0;
}
