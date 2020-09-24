//
//  encode-and-decode-strings
//  https://leetcode.com/problems/encode-and-decode-strings/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Codec {
  public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        for (auto &s : strs) {
            ans += to_string(s.size()) + ':' + s;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while (i < s.size()) {
            auto pos = s.find(':', i);
            if (pos == string::npos) break;
            int size = stoi(s.substr(i, pos - i));
            ans.push_back(s.substr(pos + 1, size));
            i = pos + 1 + size;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

int main(int argc, const char * argv[]) {
    return 0;
}
