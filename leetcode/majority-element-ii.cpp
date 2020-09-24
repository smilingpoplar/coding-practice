//
//  majority-element-ii
//  https://leetcode.com/problems/majority-element-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // 一般化，找出现次数>N/k的元素
        // 用个map统计各候选的出现次数，当map.size()==k时删掉k个不同元素，
        // 最后剩下的为候选
        unordered_map<int, int> cnt;
        for (auto num : nums) {
            cnt[num]++;
            if (cnt.size() == 3) {
                auto it = cnt.begin();
                while (it != cnt.end()) {
                    it->second--;
                    if (it->second == 0) {
                        it = cnt.erase(it);
                    } else {
                        it++;
                    }
                }
            }
        }
        // 需要验证候选的出现次数
        for (auto &e : cnt) {
            e.second = 0; // 给候选重新计数
        }
        for (auto num : nums) {
            if (cnt.count(num)) cnt[num]++;
        }
        vector<int> ans;
        for (auto &e : cnt) {
            if (e.second > nums.size() / 3) {
                ans.push_back(e.first);
            }
        }
        return ans;
    }
};

/*
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = INT_MIN, cand2 = INT_MIN;
        int cnt1 = 0, cnt2 = 0;
        for (auto num : nums) {
            if (cand1 == num) {
                cnt1++;
            } else if (cand2 == num) {
                cnt2++;
            } else if (cnt1 == 0) { // cnt==0要放在后面判断，尽量不选新cand
                cand1 = num;
                cnt1++;
            } else if (cnt2 == 0) {
                cand2 = num;
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        // 验证cand的出现次数
        cnt1 = 0, cnt2 = 0;
        for (auto num : nums) {
            if (cand1 == num) {
                cnt1++;
            } else if (cand2 == num) {
                cnt2++;
            }
        }
        vector<int> ans;
        int theCnt = nums.size() / 3;
        if (cnt1 > theCnt) ans.push_back(cand1);
        if (cnt2 > theCnt) ans.push_back(cand2);
        return ans;
    }
};
*/

int main(int argc, const char * argv[]) {
    vector<int> nums = {0,1,2,0,1};
    Solution solution;
    auto result = solution.majorityElement(nums);
    for (auto num : result) {
        cout << num << " ";
    }
    
    return 0;
}
