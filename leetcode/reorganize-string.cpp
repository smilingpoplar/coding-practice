//
//  reorganize-string
//  https://leetcode.com/problems/reorganize-string/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        // 要可行，需要 最多的字符数-1<=其他所有字符数和
        // 即maxcount-1<=n-c，maxcount<=(n+1)/2
        unordered_map<int, int> count;
        for (char c : S) {
            count[c]++;
        }
        // 每次输出计数最多的两个字符即可
        auto cmp = [&count](char a, char b) { 
            return count[a] < count[b];
        };
        priority_queue<char, vector<char>, decltype(cmp)> pq(cmp);

        int maxcount = INT_MIN;
        for (auto &e : count) {
            maxcount = max(maxcount, e.second);
            if (maxcount > (S.size() + 1) / 2) return "";
            pq.push(e.first);
        }
        ostringstream oss;
        while (pq.size() >= 2) {
            char a = pq.top(); pq.pop();
            char b = pq.top(); pq.pop();
            oss << a << b;
            if (--count[a] > 0) pq.push(a);
            if (--count[b] > 0) pq.push(b);
        }
        if (!pq.empty()) {
            oss << pq.top();
            pq.pop();
        }
        return oss.str();
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
