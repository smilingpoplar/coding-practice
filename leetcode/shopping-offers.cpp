//
//  shopping-offers
//  https://leetcode.com/problems/shopping-offers/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
        int money = directBuy(price, needs); // 不用offers
        for (int i = idx; i < special.size(); i++) {
            auto result = buyOffer(special[i], needs);
            if (!result.first) continue;
            money = min(money, special[i].back() + shopping(price, special, result.second, i)); 
        }
        return money;
    }
    
    int directBuy(const vector<int> &price, const vector<int> &needs) {
        int money = 0;
        for (int i = 0; i < needs.size(); i++) {
            money += needs[i] * price[i];
        }        
        return money;
    }
    
    pair<bool, vector<int>> buyOffer(const vector<int> &offer, const vector<int> &needs) {
        vector<int> newNeeds(needs);
        for (int i = 0; i < needs.size(); i++) {
            if (offer[i] > needs[i]) return { false, {}};
            newNeeds[i] -= offer[i];
        }
        return { true, newNeeds };
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
