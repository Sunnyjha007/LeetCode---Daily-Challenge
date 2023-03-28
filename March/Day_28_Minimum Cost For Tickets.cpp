class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1,0);
        dp[0] = min(costs[0],min(costs[1],costs[2]));
        int ans = INT_MAX;
        for(int i=1;i<n;i++){
            int ans = (costs[0] + dp[i-1]);
            int idx7 = upper_bound(days.begin(),days.begin()+i,days[i]-7)-days.begin();
            ans = min(ans,costs[1]+(idx7>0?dp[idx7-1]:0));
            int idx30 = upper_bound(days.begin(),days.begin()+i,days[i]-30)-days.begin();
            ans = min(ans,costs[2]+(idx30>0?dp[idx30-1]:0));
            dp[i] = ans;
        }
        return dp[n-1];
    }
};
