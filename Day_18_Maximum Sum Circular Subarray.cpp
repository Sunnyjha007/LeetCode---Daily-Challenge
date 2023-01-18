class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int currmaxsum=nums[0],maxsum=nums[0],currminsum = nums[0],minsum = nums[0];
        for(int i=1;i<n;i++){
            currmaxsum = max(nums[i],currmaxsum+nums[i]);
            maxsum = max(maxsum,currmaxsum);
            currminsum = min(nums[i],currminsum+nums[i]);
            minsum = min(minsum,currminsum);
        }
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(minsum==sum)return maxsum;
        return max(maxsum,sum-minsum);
    }
};
// class Solution {
// private:
// int kadanealgo(vector<int>& nums){
//     int n = nums.size();
//     int currsum=0,maxsum=INT_MIN;
//     for(int i=0;i<n;i++){
//         currsum+=nums[i];
//         maxsum = max(maxsum,currsum);
//         if(currsum<0)currsum=0;
//     }
//     return maxsum;
// }
// public:
//     int maxSubarraySumCircular(vector<int>& nums) {
//         int n = nums.size();
//         int ans1 = kadanealgo(nums);
//         if(ans1<0)return ans1;
//         int sum=0;
//         for(int i=0;i<n;i++){
//             sum+=nums[i];
//             nums[i] = -nums[i];
//         }
//         int ans2 = sum + kadanealgo(nums);
//         return max(ans1,ans2);
//     }
// };
