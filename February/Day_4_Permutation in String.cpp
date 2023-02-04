class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(),n2 = s2.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n1;i++)mp[s1[i]]++;
        int j=0,i=0,total = n1;
        while(j<n2){
            if(mp[s2[j]]>0){
                total--;
            }
            mp[s2[j]]--;
            // cout<<mp[s2[j]]<<" ";
            j++;
            if(total==0)return true;
            if(j-i==n1&&mp[s2[i++]]++>=0){
                // cout<<i<<" ";
                total++;
                // i++;
                //  mp[s2[i]]++;
                //  i++;
            }
            // if(j-i==n1)i++;   
        }
        return false;
    }
};
