class Solution {
public:
    int solve(unordered_map<int,vector<int>>& adj,vector<bool>& hasApple,vector<int>& visited,int sv){
        visited[sv]=true;
        int ans=0;
        for(auto &i:adj[sv]){
            if(!visited[i]){
                ans+=solve(adj,hasApple,visited,i);
            }
        }
        return (ans>0||hasApple[sv])? ans+1:0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>> adj;
        vector<int> visited(n,false);
        for(int i=0;i<edges.size();i++){
            int f = edges[i][0];
            int s = edges[i][1];
            adj[f].push_back(s);
            adj[s].push_back(f);
        }
        int ans = solve(adj,hasApple,visited,0);
        return (ans==0)?0:2*(ans-1);
    }
};
