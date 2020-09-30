//
//  string-compression
//  https://leetcode.com/problems/string-compression/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        const int N = chars.size();
        int lo = 0, out = 0;
        for (int i = 0; i < N; i++) {
            if (i == N - 1 || chars[i] != chars[i+1]) {
                chars[out++] = chars[lo];
                int len = i - lo + 1;
                lo = i + 1;
                if (len == 1) continue;
                for (char c : to_string(len)) {
                    chars[out++] = c;
                }
            }
        }
        return out;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
