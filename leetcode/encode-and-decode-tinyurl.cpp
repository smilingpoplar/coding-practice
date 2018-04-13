//
//  encode-and-decode-tinyurl
//  https://leetcode.com/problems/encode-and-decode-tinyurl/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    const string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const string baseHost = "http://tinyurl.com/";
    const int codeLen = 6;
    unordered_map<string, string> urlToCode;
    unordered_map<string, string> codeToUrl;
public:
    Solution() {
        srand(time(NULL));
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (!urlToCode.count(longUrl)) {
            auto code = randomStr();
            while (codeToUrl.count(code))
                code = randomStr();
            urlToCode[longUrl] = code;
            codeToUrl[code] = longUrl;
        }
        return baseHost + urlToCode[longUrl];
    }
    
    string randomStr() {
        string ans;
        for (int i = 0; i < codeLen; i++) {
            ans += alphabet[rand() % alphabet.size()];
        }
        return ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        auto code = shortUrl.substr(shortUrl.size() - codeLen);
        return codeToUrl[code];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main(int argc, const char * argv[]) {
    return 0;
}
