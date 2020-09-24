//
//  zigzag-iterator
//  https://leetcode.com/problems/zigzag-iterator/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class ZigzagIterator {
    queue<pair<vector<int>::iterator, vector<int>::iterator>> Q; // 保存非空行的<it, endIt>对
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) Q.push({ v1.begin(), v1.end() });
        if (!v2.empty()) Q.push({ v2.begin(), v2.end() });
    }

    int next() {
        auto its = Q.front(); Q.pop();
        auto it = its.first, endIt = its.second;
        int ans = *it++;
        if (it != endIt) Q.push({ it, endIt });
        return ans;
    }

    bool hasNext() {
        return !Q.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

int main(int argc, const char * argv[]) {
    return 0;
}
