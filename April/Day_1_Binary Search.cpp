class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int si = 0,ei = n-1;
        while(si<=ei){
            int mid = si + (ei-si)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target)ei = mid-1;
            else si = mid+1;
        }
        return -1;
    }
};
