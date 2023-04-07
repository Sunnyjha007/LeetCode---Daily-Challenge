class Solution {
private:
// void dfs(vector<vector<int>>& grid,int r,int c){
//     if(r<0||c<0||r>=grid.size()||c>=grid[0].size()||grid[r][c]!=1)return;
//     grid[r][c] = -1;
//     dfs(grid,r+1,c);
//     dfs(grid,r,c+1);
//     dfs(grid,r-1,c);
//     dfs(grid,r,c-1);
// }
void bfs(vector<vector<int>>& grid,int r,int c){
    int m = grid.size(),n = grid[0].size();
    grid[r][c] = -1;
    queue<pair<int,int>> pn;
    pn.push({r,c});
    while(!pn.empty()){
        auto front = pn.front();pn.pop();
        int x = front.first;
        int y = front.second;
            if(x+1<m&&grid[x+1][y]==1){
                pn.push({x+1,y});
                grid[x+1][y] = -1;
            }
            if(x-1>=0&&grid[x-1][y]==1){
                pn.push({x-1,y});
                grid[x-1][y] = -1;
            }
            if(y+1<n&&grid[x][y+1]==1){
                pn.push({x,y+1});
                grid[x][y+1] = -1;
            }
            if(y-1>=0&&grid[x][y-1]==1){
                pn.push({x,y-1});
                grid[x][y-1] = -1;
            }  
    }

}
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||i==m-1||j==0||j==n-1){
                    if(grid[i][j]==1){
                        // dfs(grid,i,j);
                        bfs(grid,i,j);
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)cnt++;
            }
        }
        return cnt;
    }
};
