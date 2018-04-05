//
//  design-in-memory-file-system
//  https://leetcode.com/problems/design-in-memory-file-system/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class FileSystem {
    struct Entry {
        bool isFile = false;
        map<string, Entry> entries; // 目录的内容
        string content; // 文件的内容
    };
    Entry root;
public:
    FileSystem() {
    }
    
    vector<string> ls(string path) {
        auto names = split(path);
        auto curr = &root;
        for (auto &name : names) {
            curr = &curr->entries[name];
        }
        if (curr->isFile) return { names.back() };

        vector<string> ans;
        for (auto &e : curr->entries) {
            ans.push_back(e.first);
        }
        return ans;
    }
    
    vector<string> split(string path) {
        istringstream iss(path);
        string s;
        vector<string> ans;
        while (getline(iss, s, '/')) {
            if (s.empty()) continue;
            ans.push_back(s);
        }
        return ans;
    }
    
    void mkdir(string path) {
        auto names = split(path);
        auto curr = &root;
        for (auto &name : names) {
            if (!curr->entries.count(name)) curr->entries[name] = {};
            curr = &curr->entries[name];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        auto names = split(filePath);
        auto curr = &root;
        for (auto &name : names) {
            if (!curr->entries.count(name)) curr->entries[name] = {};
            curr = &curr->entries[name];
        }
        curr->isFile = true;
        curr->content += content;
    }
    
    string readContentFromFile(string filePath) {
        auto names = split(filePath);
        auto curr = &root;
        for (auto &name : names) {
            curr = &curr->entries[name];
        }
        return curr->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */

int main(int argc, const char * argv[]) {
    return 0;
}
