//
//  online-election
//  https://leetcode.com/problems/online-election/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class TopVotedCandidate {
    vector<int> times, winners;
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) : times(times) {
        const int N = times.size();
        vector<int> votes(N, 0);
        int winner = 0;
        for (int person : persons) {
            votes[person]++;
            if (votes[person] >= votes[winner]) {
                winner = person;
            }
            winners.push_back(winner);
        }
    }
    
    int q(int t) {
        // 找到<=t的时刻
        int idx = --upper_bound(times.begin(), times.end(), t) - times.begin();
        return winners[idx];
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
