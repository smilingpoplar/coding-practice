//
//  the-k-th-lexicographical-string-of-all-happy-strings-of-length-n
//  https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        if (k > 3 * (1 << (n - 1))) return "";
        deque<string> q{""};
        while (q[0].size() < n) {
            string s = q[0]; q.pop_front();
            for (char c = 'a'; c <= 'c'; c++) {
                if (c != s.back())
                    q.push_back(s + string(1, c));
            }
        }
        return q[k - 1];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
