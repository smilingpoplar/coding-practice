//
//  string-compression
//  https://leetcode.com/problems/string-compression/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        // 判断当前位置是不是所找串的末尾
        const int N = chars.size();
        int write = 0;
        int anchor = 0;
        for (int i = 0; i < N; ++i) {
            if (i == N - 1 || chars[i] != chars[i+1]) {
                chars[write++] = chars[anchor];
                int length = i - anchor + 1;
                anchor = i + 1;
                if (length == 1) continue;
                for (char c : to_string(length)) {
                    chars[write++] = c;
                }
            }
        }
        return write;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
