#define mod 1000000007
class Solution {
private:
int solve(string &s,int k,int idx,vector<int>& dp){
    if(idx>=s.size())return 1;
    if(s[idx]=='0')return 0;
    if(dp[idx]!=-1)return dp[idx];
    int ans = 0;
    long long number = 0;
    for(int i=idx;i<s.size();i++){
        number = number*10 + s[i]-'0';
        if(number>k)break;
        ans = (ans+ solve(s,k,i+1,dp))%mod;
    }
    return dp[idx] =  ans;
}
public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        return solve(s,k,0,dp);
    }
};
