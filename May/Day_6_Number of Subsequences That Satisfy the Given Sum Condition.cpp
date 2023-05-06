#define mod 1000000007
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        long long  n = nums.size(),si=0,ei=n-1,ans=0;
        sort(nums.begin(),nums.end());
         vector<int> dp(nums.size());
        dp[0] = 1;
        for(int i = 1; i < nums.size(); i++) {
            dp[i] = (dp[i-1] * 2)%mod;
        }
        while(si<=ei){
            if(nums[si]+nums[ei]<=target){
                ans+= (dp[ei-si]);
                ans = ans%mod;
                si++;
            }else{
                ei--;
            }
        }
        return ans%mod;
    }
};
