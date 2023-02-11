#define RED 1
#define BLUE 0
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        //creating adjacency list with {node, color}
        vector<pair<int,int>> adj[n];
        for(auto edge:redEdges){
            adj[edge[0]].push_back({edge[1],RED});
        }
        for(auto edge:blueEdges){
            adj[edge[0]].push_back({edge[1],BLUE});
        }
        queue<pair<int,int>> pn;
        pn.push({0,-1});
        vector<int> answer(n,INT_MAX);
        vector<vector<int>> visited(n,vector<int>(2,0));
        visited[0][0] = 1;
        visited[0][1] = 1;
        int distance = 0;
        while(!pn.empty()){
            int size = pn.size();
            while(size--){
                auto node = pn.front().first;
                int color = pn.front().second;
                pn.pop();
                answer[node] = min(answer[node],distance);
                for(auto edge:adj[node]){
                    if(!visited[edge.first][edge.second]&&edge.second!=color){
                        pn.push(edge);
                        visited[edge.first][edge.second] = 1;
                    }
                }
            }
            distance++;
        }
        for(auto &it:answer){
            if(it==INT_MAX)it=-1;
        }
        return answer;
    }
};
  
