/*
    797. 所有可能的路径
    给你一个有 n 个节点的 有向无环图（DAG），请你找出所有从节点 0 到节点 n-1 的路径并输出（不要求按特定顺序）
    graph[i] 是一个从节点 i 可以访问的所有节点的列表（即从节点 i 到节点 graph[i][j]存在一条有向边）。

    示例 1：
    输入：graph = [[1,2],[3],[3],[]]
    输出：[[0,1,3],[0,2,3]]
    解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3

    示例 2：
    输入：graph = [[4,3,1],[3,2,4],[3],[4],[]]
    输出：[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
    

    提示：
    n == graph.length
    2 <= n <= 15
    0 <= graph[i][j] < n
    graph[i][j] != i（即不存在自环）
    graph[i] 中的所有元素 互不相同
    保证输入为 有向无环图（DAG）
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph,0);
        return res;
    }
private:
    vector<vector<int>> res; // 收集符合条件的路径
    vector<int> path; // 0节点到终点的路径
    // x：目前遍历的节点
    // graph：存当前的图
    void dfs (vector<vector<int>>& graph, int x) {
        int n = graph.size();
        // 递归的结束点
        if(x == n-1){
            res.push_back(path);
            return ;
        }
        for (int i = 0; i < graph[x].size(); i++)
        {
            path.push_back(graph[x][i]);
            dfs(graph,graph[x][i]);
            // 回溯
            path.pop_back();
        }
        
    }
};


int main(){
    Solution s;
    vector<vector<int>>graph = {{1,2},{3},{3},{}};
    for(auto el : s.allPathsSourceTarget(graph))
    {
        for(auto e : el)
        {
            cout << e << "\t";
        }
        cout << endl;
    }
}