#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    vector<vector<int>> g;
public:
    int dfs(int x,int fa){
        int cnt = 1;
        for(auto & e : g[x]){
            if(e != fa){
                cnt += dfs(e,x);
            }
        }
        return cnt;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int> restrictedSet(restricted.begin(), restricted.end());
        g.resize(n);
        for(auto & el : edges){
            if(!restrictedSet.count(el[0]) && !restrictedSet.count(el[1])){
                // 不受限
                g[el[0]].push_back(el[1]);
                g[el[1]].push_back(el[0]);
            }
        }
        return dfs(0,-1);
    }
};

int main() {
    Solution s;
    int n = 7;
    vector<vector<int>>edges = {{0,1},{1,2},{3,1},{4,0},{0,5},{5,6}};
    vector<int>restricted = {4,5};
    cout << s.reachableNodes(n, edges, restricted) << endl;
    return 0;
}