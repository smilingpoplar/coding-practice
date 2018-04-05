//
//  design-excel-sum-formula
//  https://leetcode.com/problems/design-excel-sum-formula/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Excel {
    map<pair<int, char>, vector<string>> formulas; // 保存公式
    vector<vector<int>> values; // 保存值
public:
    Excel(int H, char W) {
        values = vector<vector<int>>(H, vector<int>(W - 'A' + 1, 0));
    }
    
    void set(int r, char c, int v) {
        formulas.erase({r, c});
        values[r-1][c-'A'] = v;
    }
    
    int get(int r, char c) {
        if (formulas.count({r, c})) return sum(r, c, formulas[{r, c}]); // formulas优先
        return values[r-1][c-'A'];
    }
    
    int sum(int r, char c, vector<string> strs) {
        formulas[{r, c}] = strs;
        int ans = 0;
        for (auto &str : strs) {
            auto pos = str.find(':');
            if (pos == string::npos) { // 单个值
                auto idx = getIdx(str);
                ans += get(idx.first, idx.second);
            } else { // 范围
                auto tl = getIdx(str.substr(0, pos));
                auto br = getIdx(str.substr(pos + 1));
                for (int r = tl.first; r <= br.first; r++) {
                    for (char c = tl.second; c <= br.second; c++) {
                        ans += get(r, c);
                    }
                }
            }
        }
        return ans;
    }
    
    pair<int, char> getIdx(const string &colRow) {
        return { stoi(colRow.substr(1)) , colRow[0] };
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */

int main(int argc, const char * argv[]) {
    return 0;
}
