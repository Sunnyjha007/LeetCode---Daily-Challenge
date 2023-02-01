class Solution {
// private:
// int solve(vector<vector<int>>& v,int idx,int max_score,vector<vector<int>>& dp){
//     if(idx>=v.size())return 0;
//     if(dp[idx][max_score]!=-1)return dp[idx][max_score];
//     if(v[idx][1]>=max_score){
//         return dp[idx][max_score] = max(v[idx][0]+ solve(v,idx+1,v[idx][1],dp),solve(v,idx+1,max_score,dp));
//     }else{
//         return dp[idx][max_score] = solve(v,idx+1,max_score,dp);
//     }
// }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>> v;
        int m = scores.size();
        for(int i=0;i<scores.size();i++)v.push_back({scores[i],ages[i]});
        sort(v.begin(),v.end());
        // vector<vector<int>> dp(1001,vector<int>(1001,-1));
        // return solve(v,0,0,dp);
        vector<vector<int>> dp(1005,vector<int>(1005,0));
        for(int i=m-1;i>=0;i--){
            for(int j=1001;j>=0;j--){
                if(v[i][1]>=j){
                    dp[i][j] = max(v[i][0]+dp[i+1][v[i][1]],dp[i+1][j]);
                }else{
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
};
// [4,2,7,1,7,3,5,8,6,9]
// [1,1,1,1,1,1,1,1,1,1]
