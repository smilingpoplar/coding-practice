//
//  smallest-string-with-swaps
//  https://leetcode.com/problems/smallest-string-with-swaps/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        const int N = s.size();
        vector<int> uf(N, -1);
        for (auto &pair : pairs) {
            unite(pair[0], pair[1], uf);            
        }
        unordered_map<int, deque<char>> mp; // uf=>chars
        for (int i = 0; i < N; i++) {
            mp[find(i, uf)].push_back(s[i]);
        }
        for (auto &e : mp) {
            auto &chars = e.second;
            sort(chars.begin(), chars.end());
        }
        
        string ans;
        for (int i = 0; i < N; i++) {
            auto &chars = mp[find(i, uf)];
            ans += chars[0];
            chars.pop_front();
        }
        return ans;
    }
    
    int find(int x, vector<int> &uf) {
        if (uf[x] == -1) 
            uf[x] = x;
        
        if (uf[x] != x) 
            uf[x] = find(uf[x], uf);
        return uf[x];
    }
    
    void unite(int x, int y, vector<int> &uf) {
        int px = find(x, uf), py = find(y, uf);
        if (px != py) uf[py] = px;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
