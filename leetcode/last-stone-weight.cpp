//
//  last-stone-weight
//  https://leetcode.com/problems/last-stone-weight/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(begin(stones), end(stones));
        while (q.size() > 1) {
            int y = q.top(); q.pop();
            int x = q.top(); q.pop();
            if (y > x) q.push(y - x);
        }
        if (q.empty()) return 0;
        return q.top();
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
