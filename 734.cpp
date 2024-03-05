#include "template.h"

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n); // 邻接表
        for(auto &el : times){
            g[el[0] - 1].emplace_back(el[1] - 1, el[2]);
        }
        vector<int> dis(n,INT_MAX);
        dis[k-1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, k-1);
        while(!pq.empty()){
            auto [dx, x] = pq.top();
            pq.pop();
            if(dx > dis[x]) {
                continue;
            }
            for(auto &[y, d] : g[x]) { // 尝试更新 x 的邻居的最短路
                int newDis = dx + d;
                if(newDis < dis[y]){
                    // 就目前来说，最短路必须经过 x
                    dis[y] = newDis;
                    pq.emplace(newDis, y);
                }
            }
        }
        int mx = 0;
        for(int i = 0; i < n; i++){
            mx = max(mx, dis[i]);
        }
        return mx < INT_MAX ? mx : -1;
    }
};

int maind() {
    vector<vector<int>> times = {{1,2,1},{2,3,1},{1,3,1},{1,4,1},{2,4,1},{3,4,1}};
    int n = 4;
    int k = 2;
    Solution s;
    cout << s.networkDelayTime(times, n, k) << endl;
}