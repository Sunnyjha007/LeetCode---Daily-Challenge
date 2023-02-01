class SummaryRanges {
    unordered_set<int> st;
public:
    SummaryRanges() {}
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<int> nums;
       for(auto itr = st.begin();itr!=st.end();itr++){
           nums.push_back(*itr);
       }
       sort(nums.begin(),nums.end());
       vector<vector<int>> ans;
       int i = 0;
       while(i<nums.size()){
           int start = nums[i];
           while((i+1)<nums.size()&&nums[i]+1==nums[i+1])i++;
           ans.push_back({start,nums[i]});
           i++;
       }
       return ans;
    }
};
