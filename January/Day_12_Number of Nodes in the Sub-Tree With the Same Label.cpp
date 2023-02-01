class Solution {
public:
    vector<int> dfs(int node,vector<vector<int>> &adj,string &labels,vector<int> &output,vector<bool> &vis){
        vis[node]=true;
        int n=adj[node].size();
        vector<int> freq(26,0);
        for(int j=0;j<n;j++){
            if(!vis[adj[node][j]]){
                vector<int> cnt=dfs(adj[node][j],adj,labels,output,vis);
                for(int i=0;i<26;i++){
                    freq[i]+=cnt[i];
                }
            }
        }
        int val=labels[node]-'a';
        freq[val]++;
        output[node]=freq[val];
        return freq;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        vector<int> output(n,0);
        vector<bool> vis(n,0);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0,adj,labels,output,vis);
        return output;
    }

};
