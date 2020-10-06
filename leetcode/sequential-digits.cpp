//
//  sequential-digits
//  https://leetcode.com/problems/sequential-digits/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for (int i = 1; i <= 9; i++) {
            q.push(i);
        }

        vector<int> ans;
        while (!q.empty()) {
            int cur = q.front();  q.pop();
            if (cur > high) continue;
            if (cur >= low) {
                ans.push_back(cur);
            }
            int lastDigit = cur % 10;
            if (lastDigit < 9) {
                q.push(cur * 10 + (lastDigit + 1));
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
