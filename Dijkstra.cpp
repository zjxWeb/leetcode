#include "template.h"

class Graph {
    vector<vector<int>> g;
public:
    Graph(int n, vector<vector<int>> &edges) {
        // 邻接矩阵（初始化为无穷大，表示 i 到 j 没有边）
        g = vector<vector<int>>(n, vector<int>(n, INT_MAX / 2));
        for (auto &e: edges)
            g[e[0]][e[1]] = e[2]; // 添加一条边（输入保证没有重边）
    }

    void addEdge(vector<int> e) {
        g[e[0]][e[1]] = e[2]; // 添加一条边（输入保证这条边之前不存在）
    }

    // 朴素 Dijkstra 算法（适用于稠密图）
    int shortestPath(int start, int end) {
       int n = g.size();
       vector<int> dis(n, INT_MAX / 2),vis(n);// vis记录是否被访问过
       // 还没算出来，初始化为0
       dis[start] = 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
       while(true){// 中途会跳出来，
            // 找到当前最短路，去更新它的邻居的最短路
            // 根据数学归纳法，dis[x] 一定是最短路长度
            int x = -1;// 进行标记，-1表示这个点还没有被访问
            for(int i = 0; i < n; i++){
                if(!vis[i] && (x < 0 || dis[i] < dis[x]))
                    x = i;// 找到了最短路
            }
            if(x < 0 || dis[x] == INT_MAX/2) // 所有从 start 能到达的点都被更新了
                return -1;
            if(x == end)
                return dis[x];// 找到终点，提前退出
            vis[x]= true;// 标记，在后续的循环中无需反复更新 x 到其余点的最短路长度
            for(int y = 0; y < n;y++){
                dis[y] = min(dis[y], dis[x] + g[x][y]);
            }
       }
    }
};

int main() {
    vector<vector<int>> edges = {{0, 1, 1}, {0, 2, 2}, {1, 2, 3}, {1, 3, 4}, {2, 3, 5}};
    Graph g(4, edges);
    cout << g.shortestPath(0, 3) << endl;
    return 0;
}
