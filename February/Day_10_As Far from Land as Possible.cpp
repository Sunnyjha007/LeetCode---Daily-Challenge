class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n =  grid.size();
        const pair<int,int> direction[4] = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>> visited(n,vector<int>(n,0));
        queue<pair<int,int>> pn;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j] = grid[i][j];
                if(grid[i][j])pn.push({i,j});
            }
        }
        int dist = -1;
        while(!pn.empty()){
            int size = pn.size();
            while(size--){
                auto front = pn.front();pn.pop();
                for(auto dir:direction){
                    int x = front.first + dir.first;
                    int y = front.second + dir.second;
                    if(x>=0&&y>=0&&x<n&&y<n&&!visited[x][y]){
                        visited[x][y] = 1;
                        pn.push({x,y});
                    } 
                }
            }
            dist++;
        }
        if(dist==0)return -1;
        return dist;
        
    }
};
