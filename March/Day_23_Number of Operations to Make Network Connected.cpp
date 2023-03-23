class Solution {
private:
    void bfs(vector<int> adj[],vector<bool>& visited,int sv){
        queue<int> pn;
        pn.push(sv);
        while(!pn.empty()){
            int front = pn.front();pn.pop();
            for(auto i:adj[front]){
                if(!visited[i]){
                    visited[i] = 1;
                    pn.push(i);
                }
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n>connections.size()+1)return -1;
        //vector<vector<int>> adj(n);
        vector<int> adj[n];
        for(auto e:connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int con=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                con++;
                bfs(adj,visited,i);
            }
        }
        return con-1;
    }
};
