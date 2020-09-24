//
//  design-compressed-string-iterator
//  https://leetcode.com/problems/design-compressed-string-iterator/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class StringIterator {
    istringstream iss;
    char ch;
    int count = 0;
public:
    StringIterator(string compressedString) : iss(compressedString) { }
    
    char next() {
        if (!hasNext()) return ' ';
        count--;
        return ch;
    }
    
    bool hasNext() {
        return count || (iss >> ch >> count);
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */

int main(int argc, const char * argv[]) {
    return 0;
}
