class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        nums.push_back(-1);
        int n = nums.size();
        long long ans = 0,cnt=0;
       for(int i=0;i<n;i++){
           if(nums[i]==0){
               cnt++;
           }else{
               ans+= ((cnt)*(cnt+1))/2;
               cnt=0;
           }
       }
       return ans;
    }
};
