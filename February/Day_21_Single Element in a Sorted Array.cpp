class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(),i=0;
        while(i<n-1){
            if(nums[i]!=nums[i+1])return nums[i];
            i+=2;
        }
        return nums[i];
    }
};
