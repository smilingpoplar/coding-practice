//
//  print-words-vertically
//  https://leetcode.com/problems/print-words-vertically/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> v;
        int maxlen = 0;
        istringstream ss(s);
        for (string w; ss >> w; ) {
            v.push_back(w);
            maxlen = max(maxlen, (int)w.size());
        }

        vector<string> ans(maxlen);
        for (int i = 0; i < maxlen; i++) {
            for (auto &w : v) {
                ans[i] += i < w.size() ? w[i] : ' ';
            }            
            while (ans[i].back() == ' ') ans[i].pop_back();
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
