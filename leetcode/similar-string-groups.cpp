//
//  similar-string-groups
//  https://leetcode.com/problems/similar-string-groups/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    class UnionFind {
        vector<int> parent;
        int cnt;
    public:
        UnionFind(int sz) : parent(sz), cnt(sz) {
            for (int i = 0; i < sz; i++) {
                parent[i] = i;
            }
        }
        
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        
        void unite(int x, int y) {
            int px = find(x), py = find(y);
            if (px == py) return;
            parent[px] = py;
            cnt--;
        }
        
        int count() {
            return cnt;
        }
    };
public:
    int numSimilarGroups(vector<string>& A) {
        const int N = A.size();
        UnionFind uf(N);
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (isSimilar(A[i], A[j])) {
                    uf.unite(i, j);
                }
            }
        }
        return uf.count();
    }
    
    bool isSimilar(const string &a, const string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                if (++diff > 2) return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
