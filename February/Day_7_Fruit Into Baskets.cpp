class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> mp;
        int ans=0,idx=0;
        for(int i=0;i<n;i++){
            mp[fruits[i]]++;
            if(mp.size()<3){
                int cnt=0;
                for(auto it:mp){
                    cnt+=it.second;
                }
                ans = max(ans,cnt);
            }else{
                while(mp.size()>2){
                    if(mp[fruits[idx]]==1){
                        mp.erase(fruits[idx]);
                    }else{
                        mp[fruits[idx]]--;
                    }
                    idx++;
                }
            }
        }
        return ans;
    }
};
