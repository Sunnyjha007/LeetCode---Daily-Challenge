class Solution {
private:
int solve(vector<int>& nums,int idx,vector<int>& dp){
    if(idx>=nums.size()-1)return 0;
    if(nums[idx]==0)return dp[idx] = 1e9;
    if(dp[idx]!=1e9)return dp[idx];
    int mini = INT_MAX;
    for(int i=1;i<=nums[idx];i++){
        mini = min(mini,1+solve(nums,idx+i,dp));
    }
    return dp[idx] = mini;
}
int solvetab(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n+1,1e9);
    dp[0] = 0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=nums[i];j++){
            if(i+j<n){
                dp[i+j] = min(dp[i+j],1+dp[i]);
            }
        }
    }
    return dp[n-1];

}
public:
    int jump(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> dp(n+1,1e9);
        // return solve(nums,0,dp);
        return solvetab(nums);
    }
};
