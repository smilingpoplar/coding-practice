//
//  special-binary-string
//  https://leetcode.com/problems/special-binary-string/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string makeLargestSpecial(string S) {
        // 遇1上坡、遇0下坡，若下坡到地平线则得到一座山峰
        // 若S由许多山峰并排，则递归处理山峰、并按大小排这些山峰
        // 处理一座山峰时，可将山峰砍掉最下一层（去掉开始的1、最后的0），递归处理子问题
        if (S.size() <= 0) return "";
        vector<string> mountains;
        int count = 0;
        int start = 0;
        for (int i = 0; i < S.size(); i++) {
            count += (S[i] == '1') ? 1 : -1;
            if (count == 0) {
                string mountain = S.substr(start, i - start + 1);
                start = i + 1;
                mountain = "1" + makeLargestSpecial(mountain.substr(1, mountain.size() - 2)) + "0";
                mountains.push_back(mountain);
            }
        }
        sort(mountains.begin(), mountains.end(), greater<string>());
        
        string ans;
        for (auto &mountain : mountains) {
            ans += mountain;
        }
        return ans;
    }    
};

int main(int argc, const char * argv[]) {    
    return 0;
}
