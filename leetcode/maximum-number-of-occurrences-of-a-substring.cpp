//
//  maximum-number-of-occurrences-of-a-substring
//  https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        // 满足条件的maxSize串一定有满足同样条件的minSize串，所以只要找minSize串
        const int N = s.size();
        unordered_map<string, int> count;
        int ans = 0;
        for (int i = 0; i <= N - minSize; i++) {
            auto sub = s.substr(i, minSize);
            if (isValid(sub, maxLetters)) {
                count[sub]++;
                ans = max(ans, count[sub]);
            }
        }
        return ans;
    }
    
    bool isValid(const string &s, int maxLetters) {
        vector<int> count(26, 0);
        int repeat = 0;
        for (char c : s) {
            if (count[c - 'a']) repeat++;
            count[c - 'a']++;
        }
        return s.size() - repeat <= maxLetters;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
