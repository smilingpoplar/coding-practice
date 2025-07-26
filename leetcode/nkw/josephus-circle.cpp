//
//  josephus-circle
//  NC132 环形链表的约瑟夫问题
//

#include <iostream>

using namespace std;

class Solution {
public:
    int ysf(int n, int m) {
        // 例如，(1+m) % len => 1，反过来就是 1 => (1+m) % len
        // 推广到 x => (x+m) % len
        int x = 0;  // 涉及到模运算，从0开始
        for (int i = 2; i <= n; i++) {
            x = (x + m) % i;
        }
        return x + 1;  // 从1开始编号
    }
};