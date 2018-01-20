//
//  top-k-frequent-words
//  https://leetcode.com/problems/top-k-frequent-words/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for (auto &w : words) {
            ++count[w];
        }
        
        /*
        // 排序，取前k项
        vector<string> keys;
        for (auto &e : count) {
            keys.push_back(e.first);
        }
        sort(keys.begin(), keys.end(), [&count](const string &a, const string &b){
            if (count[a] == count[b]) return a.compare(b) < 0; // a<b时返回true
            return count[a] > count[b];
        });
        return vector<string>(keys.begin(), keys.begin() + k);
        */
       
        // c++中优先队列，堆顶跟比较函数排序出的正相反
        auto cmp = [&count](const string &a, const string &b) {
            if (count[a] == count[b]) return (a.compare(b) < 0);
            return (count[a] > count[b]);
        };
        priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);
        for (auto &e : count) {
            pq.push(e.first);
            if (pq.size() > k) pq.pop();
        }
        
        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
