//
//  longest-happy-string
//  https://leetcode.com/problems/longest-happy-string/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if (a) pq.push({a, 'a'});
        if (b) pq.push({b, 'b'});
        if (c) pq.push({c, 'c'});

        string ans;
        while (pq.size() >= 2) {
            auto [cnt1, ch1] = pq.top();  pq.pop();
            auto [cnt2, ch2] = pq.top();  pq.pop();

            int out1 = min(cnt1, 2);
            ans += string(out1, ch1);
            cnt1 -= out1;

            int out2 = cnt2 >= cnt1 && cnt2 >= 2 ? 2 : 1;
            ans += string(out2, ch2);
            cnt2 -= out2;

            if (cnt1) pq.push({cnt1, ch1});
            if (cnt2) pq.push({cnt2, ch2});
        }
        if (pq.empty()) return ans;
        auto [cnt1, ch1] = pq.top();  pq.pop();
        int out1 = min(cnt1, 2);
        ans += string(out1, ch1);
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
