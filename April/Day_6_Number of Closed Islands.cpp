class Solution {
private:
bool checkBoundaryfunc(int r,int c,int m,int n){
    if(r==0||c==0||r==m-1||c==n-1)return false;
    return true;
}
void dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int r,int c,vector<int>& direction,bool &ans){
    if(r<0||c<0||r>=grid.size()||c>=grid[r].size()||visited[r][c]||grid[r][c]==1)return;
    ans = ans && checkBoundaryfunc(r,c,grid.size(),grid[0].size());
      visited[r][c] = true;
    for(int i=0;i<4;i++){
        int nr = r + direction[i];
        int nc = c + direction[i+1];
        dfs(grid,visited,nr,nc,direction,ans);
    }

}
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        vector<int> direction;
        direction = {0,1,0,-1,0};
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]&&grid[i][j]==0){
                    bool ans = true;
                    dfs(grid,visited,i,j,direction,ans);
                    cnt+=ans;
                }
            }
        }
        return cnt;
    }
};
