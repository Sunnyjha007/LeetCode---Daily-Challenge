class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        int ans =0 ;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)mp[tasks[i]]++;
        for(auto i:mp){
            if(i.second==1)return -1;
            else if(i.second%3==0)ans+=(i.second/3);
            else {
                ans+=(i.second/3+1);
            }
        }
        return ans;
    }
};
