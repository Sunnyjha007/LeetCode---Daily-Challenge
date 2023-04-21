#define Mod 1000000007
class Solution {
private:
int solve(vector<int>& group, vector<int>& profit,int minProfit,int n,int idx,vector<vector<vector<int>>>& dp){
    if(n<0)return 0;
    if(idx==group.size()){
        if(minProfit<=0)return 1;
        return 0;
    }
    if(minProfit<0)minProfit = 0;
    if(dp[minProfit][n][idx]!=-1)return dp[minProfit][n][idx];
    int pick = solve(group, profit, minProfit - profit[idx], n - group[idx], idx + 1,dp);
    int non_pick = solve(group, profit, minProfit, n, idx + 1,dp);
    return dp[minProfit][n][idx]  = (pick + (long long) non_pick)%Mod; 
}
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int size = group.size();
        vector<vector<vector<int>>> dp(minProfit+1,vector<vector<int>>(n+1,vector<int>(size+1,-1)));
        return solve(group, profit, minProfit, n, 0,dp);   
    }
};
