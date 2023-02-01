class Solution {
void solve(vector<int>& nums,vector<vector<int>>& ans,vector<int>& v,int idx){
    if(idx==nums.size()){
        if(v.size()>=2)ans.push_back(v);
        return;
    }
    // pick
    if(!v.size()||nums[idx]>=v[v.size()-1]){
        v.push_back(nums[idx]);
        solve(nums,ans,v,idx+1);
        v.pop_back();
    }
    //not pick
    if(!v.size()||v[v.size()-1]!= nums[idx])solve(nums,ans,v,idx+1);
}
  
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(nums,ans,v,0);
        return ans;
    }
};
