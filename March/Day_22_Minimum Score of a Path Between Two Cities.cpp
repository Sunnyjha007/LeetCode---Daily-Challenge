class Solution {
private:
int dfs(vector<vector<pair<int,int>>> &adj,vector<bool> &visited,int idx){
    int ans = INT_MAX;
    visited[idx] = 1;
    for(auto &[node,dist]:adj[idx]){
        ans = min(ans,dist);
        if(!visited[node]){
            visited[node] = 1;
            ans = min(ans,dfs(adj,visited,node));
        }
    }
    return ans;
}
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &road:roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }
        vector<bool> visited(n,0);
        return dfs(adj,visited,1);
    }
};
