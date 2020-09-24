//
//  bulb-switcher-ii
//  https://leetcode.com/problems/bulb-switcher-ii/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int flipLights(int n, int m) {
        // https://leetcode.com/problems/bulb-switcher-ii/solution/
        // 灯1 a+c+d
        // 灯2 a+b
        // 灯3 a+c
        // 灯4 a+b+d = 灯1+灯2-灯3
        // 灯5 a+c = 灯3
        // 灯6 a+b = 灯2
        // ...
        // 后面开始重复，可见，前三盏灯的状态决定了后序灯的状态
        n = min(n, 3);
        // 对三盏灯的四种操作分别是异或上(1,1,1), (0,1,0), (1,0,1), (1,0,0)
        // m==2时，四种操作两两结合，又有三种等价操作(0,0,0),(0,0,1),(0,1,1)
        if (m == 0) return 1;
        if (m == 1) return n == 1 ? 2 : n == 2 ? 3 : 4;
        if (m == 2) return n == 1 ? 2 : n == 2 ? 4 : 7;
        return n == 1 ? 2 : n == 2 ? 4 : 8;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
