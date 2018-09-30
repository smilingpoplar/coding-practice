//
//  maximum-frequency-stack
//  https://leetcode.com/problems/maximum-frequency-stack/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class FreqStack {
    // 每个频率一个桶；"有多个最大频率时，离栈顶近的先弹出"，所以桶中是一个栈
    unordered_map<int, stack<int>> buckets; // freq=>stack
    unordered_map<int, int> freq; // num=>freq
    int maxfreq = 0;
public:
    FreqStack() {
    }
    
    void push(int x) {
        buckets[++freq[x]].push(x);
        if (freq[x] > maxfreq) maxfreq = freq[x];
    }
    
    int pop() {
        int x = buckets[maxfreq].top(); buckets[maxfreq].pop();
        freq[x]--;
        if (buckets[maxfreq].empty()) maxfreq--;
        return x;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
