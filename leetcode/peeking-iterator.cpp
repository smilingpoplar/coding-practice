//
//  peeking-iterator
//  https://leetcode.com/problems/peeking-iterator/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
  Data* data;
public:
  Iterator(const vector<int>& nums);
  Iterator(const Iterator& iter);
  virtual ~Iterator();
  // Returns the next element in the iteration.
  int next();
  // Returns true if the iteration has more elements.
  bool hasNext() const;
};


class PeekingIterator : public Iterator {
    bool hasCache;
    int cacheValue;
public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums) {
      // Initialize any member here.
      // **DO NOT** save a copy of nums and manipulate it directly.
      // You should only use the Iterator interface methods.
        hasCache = false;
  }

    // Returns the next element in the iteration without advancing the iterator.
  int peek() {
        if (hasCache) return cacheValue;
        if (!Iterator::hasNext()) return Iterator::next();
        cacheValue = Iterator::next();
        hasCache = true;
        return cacheValue;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
        if (!hasCache) return Iterator::next();
        hasCache = false;
        return cacheValue;
  }

  bool hasNext() const {
      return hasCache || Iterator::hasNext();
  }
};

int main(int argc, const char * argv[]) {
    return 0;
}
