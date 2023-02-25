class Solution {
private:
int solve(vector<int>& prices,int idx,int trans,int buy,vector<vector<int>>& dp){
    if(idx>=prices.size()||trans<=0)return 0;
    if(dp[idx][buy]!=-1)return dp[idx][buy];
    if(buy){
        return dp[idx][buy] = max(-prices[idx]+solve(prices,idx+1,trans,!buy,dp),solve(prices,idx+1,trans,buy,dp));
    }else{
        return dp[idx][buy] = max(+prices[idx]+solve(prices,idx+1,trans-1,!buy,dp),solve(prices,idx+1,trans,buy,dp));
    }
}
public:
    int maxProfit(vector<int>& prices) {
        int transaction = 1,buy=1,n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,0,transaction,buy,dp);
    }
};
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int buy = INT_MAX;
        for(int i=0;i<prices.size();i++){
            buy = min(buy,prices[i]);
            maxprofit = max(maxprofit,prices[i]-buy);
        } 
        return maxprofit;
    }
};
*/
