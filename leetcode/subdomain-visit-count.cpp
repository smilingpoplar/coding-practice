//
//  subdomain-visit-count
//  https://leetcode.com/problems/subdomain-visit-count/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> cnt;
        for (auto &cpdomain : cpdomains) {
            auto pos = cpdomain.find(' ');
            if (pos == string::npos) continue;
            int count = stoi(cpdomain.substr(0, pos));
            auto domain = cpdomain.substr(pos + 1);
            cnt[domain] += count;
            for (int i = 0; i < domain.size(); i++) {
                if (domain[i] == '.') cnt[domain.substr(i + 1)] += count;       
            }
        }
        
        vector<string> ans;
        for (auto &e : cnt) {
            ans.push_back(to_string(e.second) + " " + e.first);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
