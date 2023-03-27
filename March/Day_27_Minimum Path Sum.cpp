class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0] = grid[0][0];
        for(int i=1;i<m;i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int i=1;i<n;i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] =  grid[i][j] + min(dp[i-1][j],dp[i][j-1]) ;
            }
        }
        return dp[m-1][n-1];
    }
};
/*
class Solution {
private:
int solve(vector<vector<int>>& grid,int m,int n,int r,int c,vector<vector<int>>& dp){
    if(r>m||c>n)return INT_MAX;
    if(r==m&&c==n)return grid[r][c];
    if(dp[r][c]!=-1)return dp[r][c];
    return dp[r][c] = min(solve(grid,m,n,r+1,c,dp),solve(grid,m,n,r,c+1,dp)) + grid[r][c];
}
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(grid,m-1,n-1,0,0,dp);
    }
};
*/
/*
class Solution {
private:
int solve(vector<vector<int>>& grid,int m,int n,int r,int c){
    if(r>m||c>n)return INT_MAX;
    if(r==m&&c==n)return grid[r][c];
    return min(solve(grid,m,n,r+1,c),solve(grid,m,n,r,c+1)) + grid[r][c];
}
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        return solve(grid,m-1,n-1,0,0);
    }
};
*/
