class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v(2*n,0);
        int k=0;
        for(int i=0;i<n;i++){
            v[k++] = (nums[i]);
            v[k++] = (nums[n+i]);
        }
        return v;
    }
};
