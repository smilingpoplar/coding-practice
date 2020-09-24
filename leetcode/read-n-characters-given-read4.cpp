//
//  read-n-characters-given-read4
//  https://leetcode.com/problems/read-n-characters-given-read4/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        char tmp[4];
        int size = 0;
        while (size < n) {
            int count = read4(tmp);
            for (int i = 0; i < count; i++) {
                buf[size + i] = tmp[i];
            }
            size += count;
            if (count < 4) break;
        }
        return min(size, n);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
