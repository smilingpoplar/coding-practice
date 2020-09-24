//
//  ip-to-cidr
//  https://leetcode.com/problems/ip-to-cidr/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        // ip二进制最后一位1表示的数，就是一次可输出的最大范围，block=2^k
        // 若block>n，不断block/=2直到block<=n，然后先输出block个地址
        vector<string> ans;
        auto ipNum = ipToUint(ip);
        while (n) {
            int block = ipNum & -ipNum; // 最后一位1表示的数
            while (block > n) block /= 2;
            ans.push_back(getCIDR(ipNum, block));
            ipNum += block;
            n -= block;
        }
        return ans;
    }
    
    unsigned int ipToUint(const string &ip) {
        istringstream iss(ip);
        string seg;
        unsigned int ans = 0;
        while (getline(iss, seg, '.')) {
            unsigned int num = stoi(seg);
            ans = (ans << 8) | num;
        }
        return ans;
    }
    
    string getCIDR(unsigned int num, int block) {
        vector<string> reverse;
        for (int i = 0; i < 4; i++) {
            reverse.push_back(to_string(num & 255));
            num >>= 8;
        }
        
        int len = 33;
        while (block) {
            block >>= 1;
            len--;
        }
        
        string ans;
        for (int i = 3; i >= 0; i--)
            ans += reverse[i] + '.';
        ans.pop_back();
        ans += '/' + to_string(len);
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
