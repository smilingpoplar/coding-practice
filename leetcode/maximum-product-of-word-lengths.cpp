//
//  maximum-product-of-word-lengths
//  https://leetcode.com/problems/maximum-product-of-word-lengths/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> masks(words.size(), 0); // word中的字母 用mask中的1位表示
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            for (char c : words[i]) {
                masks[i] |= 1 << (c - 'a');
            }
            for (int j = 0; j < i; j++) {
                if ((masks[i] & masks[j]) == 0) {
                    int len = words[i].size() * words[j].size();
                    ans = max(ans, len);
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
