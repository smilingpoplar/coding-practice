//
//  nested-list-weight-sum-ii
//  https://leetcode.com/problems/nested-list-weight-sum-ii/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        // 按层累加数值sum，每层再把*累加值*加到ans，这样越浅的层被累加了越多次、最深的层被累加了一次
        int ans = 0, sum = 0;
        while (!nestedList.empty()) {
            vector<NestedInteger> next;
            for (auto &ni : nestedList) {
                if (ni.isInteger()) {
                    sum += ni.getInteger();
                } else {
                    for (auto x : ni.getList()) {
                        next.push_back(x);
                    }
                }
            }
            ans += sum;
            swap(next, nestedList);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
