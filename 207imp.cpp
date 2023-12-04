/**
 * @file 207.cpp 课程表
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-03
 * @cite https://leetcode.cn/problems/course-schedule/?envType=study-plan-v2&envId=top-100-liked
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 「未搜索」：我们还没有搜索到这个节点； 0
// 「搜索中」：我们搜索过这个节点，但还没有回溯到该节点，即该节点还没有入栈，还有相邻的节点没有搜索完成）；  1
// 「已完成」：我们搜索过并且回溯过这个节点，即该节点已经入栈，并且所有该节点的相邻节点都出现在栈的更底部的位置，满足拓扑排序的要求。 2
// class Solution {
// private:
//     vector<vector<int>> edge;
//     vector<int> visited;
//     bool valid = true;
//     // 深度优先搜索完成
//     void dfs(int u) {
//         visited[u] = 1;
//         for (int el: edge[u]) {
//             if (visited[el] == 0) {
//                 dfs(el);
//                 if (!valid) {
//                     return;
//                 }
//             }
//             else if (visited[el] == 1) {
//                 valid = false;
//                 return;
//             }
//         }
//         visited[u] = 2;
//     }
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         edge.resize(numCourses);
//         visited.resize(numCourses);
//         for(const auto & e : prerequisites) edge[e[1]].push_back(e[0]);
//         for (int i = 0; i < numCourses && valid; ++i)  if (!visited[i])  dfs(i);
//         return valid;
//     }
// };


// bfs
class Solution {
private:
    vector<vector<int>> edges; // 邻接表
    vector<int> indeg;// 入度
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 放入邻接表中
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for(const auto & e : prerequisites){
            edges[e[1]].push_back(e[0]);
            ++indeg[e[0]];
        }
        queue<int> q;
        for(int i = 0; i < numCourses; ++i){
            if(indeg[i] == 0) q.push(i);
        }
        int visted = 0; // 记录被放入答案数组的节点个数
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ++visted;
            for(int v : edges[u]){
                --indeg[v];
                if(indeg[v] == 0) q.push(v);
            }
        }
        return visted == numCourses;
    }
};
int main() {
    Solution s;
    vector<vector<int>> prerequisites = {{1,0},{0,1}};
    cout << s.canFinish(2, prerequisites) << endl;
    return 0;
}