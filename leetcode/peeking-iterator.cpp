//
//  peeking-iterator
//  https://leetcode.com/problems/peeking-iterator/
//
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
    bool cached;
    int cacheVal;
public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums) {
      // Initialize any member here.
      // **DO NOT** save a copy of nums and manipulate it directly.
      // You should only use the Iterator interface methods.
        cached = false;
  }

    // Returns the next element in the iteration without advancing the iterator.
  int peek() {
        if (cached) return cacheVal;
        cacheVal = Iterator::next();
        cached = true;
        return cacheVal;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
        if (!cached) return Iterator::next();
        cached = false;
        return cacheVal;
  }

  bool hasNext() const {
      return cached || Iterator::hasNext();
  }
};

int main(int argc, const char * argv[]) {
    return 0;
}
