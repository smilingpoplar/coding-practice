//
//  shopping-offers
//  https://leetcode.com/problems/shopping-offers/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return shopping(price, special, needs, 0);
    }
    // special[idx..]子问题
    int shopping(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int idx) {
        int ans = buy(price, needs); // 不用offers
        for (int i = idx; i < special.size(); i++) {
            if (!canBuyOffer(special[i], needs)) continue;
            auto newNeeds = buyOffer(special[i], needs);
            ans = min(ans, special[i].back() + shopping(price, special, newNeeds, i)); 
        }
        return ans;
    }
    
    int buy(const vector<int> &price, const vector<int> &needs) {
        int sum = 0;
        for (int i = 0; i < needs.size(); i++) {
            sum += needs[i] * price[i];
        }        
        return sum;
    }
    
    bool canBuyOffer(const vector<int> &offer, const vector<int> &needs) {
        for (int i = 0; i < needs.size(); i++) {
            if (offer[i] > needs[i]) return false;
        }
        return true;
    }
    
    vector<int> buyOffer(const vector<int> &offer, const vector<int> &needs) {
        vector<int> res(needs);
        for (int i = 0; i < needs.size(); i++) {
            res[i] -= offer[i];
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
