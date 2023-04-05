class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long sum=0,ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            sum+= nums[i];
            ans = max(ans,(sum+i)/(i+1));
        }
        return ans;
    }
};
