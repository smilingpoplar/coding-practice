//
//  unique-morse-code-words
//  https://leetcode.com/problems/unique-morse-code-words/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> mapping = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> st;
        for (auto &word : words) {
            string code;
            for (char c : word) {
                code += mapping[c - 'a'];
            }
            st.insert(code);
        }
        return st.size();
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
