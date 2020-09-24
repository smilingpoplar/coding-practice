//
//  read-n-characters-given-read4-ii-call-multiple-times
//  https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
    char buffer[4];
    int bufferSize = 0;
    int bufferPos = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        // read()的下次调用能从上次结束位置继续读，read4()的调用结果要内部缓存起来
        int size = 0;
        while (size < n) {
            if (bufferPos == bufferSize) { // buffer[]空了
                bufferPos = 0;
                bufferSize = read4(buffer);
                if (bufferSize == 0) break;
            }
            buf[size++] = buffer[bufferPos++];
        }
        return size;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
