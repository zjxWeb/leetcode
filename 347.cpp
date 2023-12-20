/**
 * @file 347.cpp前 K 个高频元素
 * @author your name (you@domain.com)
 * @brief https://leetcode.cn/problems/top-k-frequent-elements/description/?envType=study-plan-v2&envId=top-100-liked
 * @version 0.1
 * @date 2023-12-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    // 小顶堆
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 统计出现的次数
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) m[nums[i]]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> q;
        for (auto it = m.begin(); it!= m.end(); it++) {
            q.push(make_pair(it->first, it->second));
            if (q.size() > k) q.pop();
        }
        // 找出前k个，倒序输出
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.top().first);
            q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> res = s.topKFrequent(nums, 2);
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
    cout << endl;
}