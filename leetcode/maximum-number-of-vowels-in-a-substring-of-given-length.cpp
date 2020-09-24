//
//  maximum-number-of-vowels-in-a-substring-of-given-length
//  https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int count = 0, ans = 0;
        for (int hi = 0, lo = 0; hi < s.size(); hi++) {
            if (vowels.count(s[hi])) count++;
            if (hi - lo + 1 > k) {
                if (vowels.count(s[lo++])) count--;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
