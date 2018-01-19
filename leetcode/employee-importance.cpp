//
//  employee-importance
//  https://leetcode.com/problems/employee-importance/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;
        for (auto employee : employees) {
            mp[employee->id] = employee;
        }
        return getImportance(mp, id);        
    }
    
    int getImportance(unordered_map<int, Employee*> &mp, int id) {
        auto employee = mp[id];
        int ans = employee->importance;
        for (int sub : employee->subordinates) {
            ans += getImportance(mp, sub);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
