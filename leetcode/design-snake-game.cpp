//
//  design-snake-game
//  https://leetcode.com/problems/design-snake-game/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class SnakeGame {
    int width;
    int height;
    vector<pair<int, int>> food;
    int foodIdx = 0;
    // 蛇体坐标保存两份，snakeQ存着坐标，snakeSet用于碰撞检测
    deque<pair<int, int>> snakeQ;
    set<pair<int, int>> snakeSet;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        this->width = width;
        this->height = height;
        this->food = food;
        
        snakeQ.push_back({0, 0});
        snakeSet.insert({0, 0});
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto &head = snakeQ.front();
        int row = head.first, col = head.second;
        if (direction == "U") row--;
        else if (direction == "L") col--;
        else if (direction == "R") col++;
        else if (direction == "D") row++;
        
        // 允许"头咬尾"的情况，先把tail从snakeSet中移除
        snakeSet.erase(snakeQ.back());
        if (row < 0 || row >= height || col < 0 || col >= width || snakeSet.count({row, col})) return -1;
        // 吃到食物时：头增长、尾不变，没吃到时：头增长、尾移除
        snakeQ.push_front({row, col});
        snakeSet.insert({row, col});
        if (foodIdx < food.size() && food[foodIdx].first == row && food[foodIdx].second == col) {
            snakeSet.insert(snakeQ.back());
            foodIdx++;
        } else {
            snakeQ.pop_back();
        }
        
        return snakeQ.size() - 1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */

int main(int argc, const char * argv[]) {
    return 0;
}
