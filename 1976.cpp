#include "template.h"

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<long long>>g(n,vector<long long>(n,LLONG_MAX /2));
        for(auto &el : roads){
            g[el[0]][el[1]] = el[2];
            g[el[1]][el[0]] = el[2];
        }
        vector<long long> dis(n,LLONG_MAX / 2);
        dis[0] = 0;
        vector<bool> vis(n),f(n);//f[i] 表示节点 0 到节点 i 的最短路个数。
        f[0]=0;
        while(true){
            int x = -1;
            for(int i = 0; i < n;i++){
                 if(!vis[i] && (x < 0 || dis[i] < dis[x]))
                    x = i;// 找到了最短路
            }
            if(x < 0 || dis[x] == LLONG_MAX/2) // 所有从 start 能到达的点都被更新了
                return -1;
            if(x == n - 1)
                return f[x];// 找到终点，提前退出
            vis[x]= true;// 标记，在后续的循环中无需反复更新 x 到其余点的最短路长度
            // dp
            for(int y = 0;y < n;y++){
                long long newDis = dis[x] + g[x][y];
                if(newDis < dis[y]){
                    dis[y] = newDis;
                    f[y] = f[x];
                }else if (newDis == dis[y])
                {
                    // 和之前求的最短路一样长
                    f[y] = (f[y] + f[x]) % 1'000'000'007;
                }
                
            }
        }
    }
};



//写法二：堆优化 Dijkstra（适用于稀疏图）
class Solution {
public:
    int countPaths(int n, vector<vector<int>> &roads) {
        vector<vector<pair<int, int>>> g(n); // 邻接表
        for (auto &r : roads) {
            int x = r[0], y = r[1], d = r[2];
            g[x].emplace_back(y, d);
            g[y].emplace_back(x, d);
        }

        vector<long long> dis(n, LLONG_MAX);
        dis[0] = 0;
        vector<int> f(n);
        f[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(0, 0);
        while (true) {
            auto [dx, x] = pq.top();
            pq.pop();
            if (x == n - 1) {
                // 不可能找到比 dis[n-1] 更短，或者一样短的最短路了（注意本题边权都是正数）
                return f[n - 1];
            }
            if (dx > dis[x]) {
                continue;
            }
            for (auto &[y, d] : g[x]) { // 尝试更新 x 的邻居的最短路
                long long new_dis = dx + d;
                if (new_dis < dis[y]) {
                    // 就目前来说，最短路必须经过 x
                    dis[y] = new_dis;
                    f[y] = f[x];
                    pq.emplace(new_dis, y);
                } else if (new_dis == dis[y]) {
                    // 和之前求的最短路一样长
                    f[y] = (f[y] + f[x]) % 1'000'000'007;
                }
            }
        }
    }
};


int main(){
    Solution s;
    int n = 7;
    vector<vector<int>> roads = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    cout << s.countPaths(n,roads) << endl;
}